#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double computePrice(double baseRate, int days) const = 0;
};

class FlatRate : public PricingStrategy {
public:
    double computePrice(double baseRate, int days) const override {
        return baseRate * days;
    }
};

class WeekendDiscount : public PricingStrategy {
public:
    double computePrice(double baseRate, int days) const override {
        const int weekendDays = days / 7 * 2; // rough calculation
        const int weekdayDays = days - weekendDays;
        return weekdayDays * baseRate + weekendDays * baseRate * 0.7;
    }
};

class RentalService {
public:
    RentalService(std::string name, std::unique_ptr<PricingStrategy> strategy)
        : name_(std::move(name)), strategy_(std::move(strategy)) {
        if (!strategy_) {
            throw std::invalid_argument("strategy must not be null");
        }
    }

    double quote(double baseRate, int days) const {
        return strategy_->computePrice(baseRate, days);
    }

    void setStrategy(std::unique_ptr<PricingStrategy> strategy) {
        if (!strategy) {
            throw std::invalid_argument("strategy must not be null");
        }
        strategy_ = std::move(strategy);
    }

    void printQuote(double baseRate, int days) const {
        std::cout << name_ << " quote for " << days << " day(s): $"
                  << quote(baseRate, days) << '\n';
    }

private:
    std::string name_;
    std::unique_ptr<PricingStrategy> strategy_;
};

std::unique_ptr<PricingStrategy> makeStrategy(const std::string& type) {
    if (type == "flat") {
        return std::make_unique<FlatRate>();
    }
    if (type == "weekend") {
        return std::make_unique<WeekendDiscount>();
    }
    throw std::invalid_argument("Unknown strategy type: " + type);
}

int main() {
    RentalService service{"City Cars", makeStrategy("flat")};
    service.printQuote(45.0, 5);

    service.setStrategy(makeStrategy("weekend"));
    service.printQuote(45.0, 10);

    try {
        auto unknown = makeStrategy("holiday");
        service.setStrategy(std::move(unknown));
    } catch (const std::exception& ex) {
        std::cout << "Failed to update strategy: " << ex.what() << '\n';
    }
}
