#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Vehicle {
public:
    Vehicle(std::string make, std::string model)
        : make_(std::move(make)), model_(std::move(model)) {}
    virtual ~Vehicle() = default;

    virtual void describe() const {
        std::cout << "Vehicle: " << make_ << ' ' << model_ << '\n';
    }

protected:
    std::string make_;
    std::string model_;
};

class Car : public Vehicle {
public:
    Car(std::string make, std::string model, int doors)
        : Vehicle(std::move(make), std::move(model)), doors_(doors) {}

    void describe() const override {
        std::cout << "Car: " << make_ << ' ' << model_ << ", " << doors_ << " doors\n";
    }

private:
    int doors_;
};

class Truck : public Vehicle {
public:
    Truck(std::string make, std::string model, double capacityTons)
        : Vehicle(std::move(make), std::move(model)), capacityTons_(capacityTons) {}

    void describe() const override {
        std::cout << "Truck: " << make_ << ' ' << model_ << ", payload "
                  << capacityTons_ << " tons\n";
    }

private:
    double capacityTons_;
};

class Fleet {
public:
    template <typename VehicleType, typename... Args>
    void addVehicle(Args&&... args) {
        vehicles_.push_back(std::make_unique<VehicleType>(std::forward<Args>(args)...));
    }

    void describeAll() const {
        std::cout << "Fleet overview:\n";
        for (const auto& vehicle : vehicles_) {
            vehicle->describe();
        }
    }

private:
    std::vector<std::unique_ptr<Vehicle>> vehicles_;
};

int main() {
    Fleet fleet;
    fleet.addVehicle<Car>("Honda", "Civic", 4);
    fleet.addVehicle<Truck>("Volvo", "FH16", 18.0);
    fleet.addVehicle<Car>("Mini", "Cooper", 2);

    fleet.describeAll();
}
