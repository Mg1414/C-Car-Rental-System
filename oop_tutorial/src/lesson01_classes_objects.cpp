#include <iostream>
#include <string>
#include <vector>

class Vehicle {
private:
    std::string make_;
    std::string model_;
    int year_{};

public:
    Vehicle() = default;

    void setMake(const std::string& make) { make_ = make; }
    void setModel(const std::string& model) { model_ = model; }
    void setYear(int year) { year_ = year; }

    const std::string& getMake() const { return make_; }
    const std::string& getModel() const { return model_; }
    int getYear() const { return year_; }

    void printSummary() const {
        std::cout << year_ << " " << make_ << " " << model_ << '\n';
    }
};

int main() {
    Vehicle sedan;
    sedan.setMake("Toyota");
    sedan.setModel("Camry");
    sedan.setYear(2022);

    Vehicle suv;
    suv.setMake("Ford");
    suv.setModel("Explorer");
    suv.setYear(2021);

    std::vector<Vehicle> inventory{sedan, suv};
    inventory.emplace_back();
    inventory.back().setMake("Tesla");
    inventory.back().setModel("Model 3");
    inventory.back().setYear(2023);

    std::cout << "Inventory summary:\n";
    for (const auto& vehicle : inventory) {
        vehicle.printSummary();
    }

    return 0;
}
