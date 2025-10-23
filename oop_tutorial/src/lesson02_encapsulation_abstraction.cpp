#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

class BankAccount {
private:
    std::string owner_;
    double balance_{};

    void ensureSufficientFunds(double amount) const {
        if (balance_ < amount) {
            throw std::runtime_error("Insufficient funds for withdrawal");
        }
    }

public:
    explicit BankAccount(std::string owner, double initialBalance = 0.0)
        : owner_(std::move(owner)), balance_(initialBalance) {
        if (initialBalance < 0.0) {
            throw std::invalid_argument("Initial balance cannot be negative");
        }
    }

    void deposit(double amount) {
        if (amount < 0.0) {
            throw std::invalid_argument("Cannot deposit a negative amount");
        }
        balance_ += amount;
    }

    void withdraw(double amount) {
        if (amount < 0.0) {
            throw std::invalid_argument("Cannot withdraw a negative amount");
        }
        ensureSufficientFunds(amount);
        balance_ -= amount;
    }

    [[nodiscard]] double getBalance() const noexcept { return balance_; }
    [[nodiscard]] const std::string& getOwner() const noexcept { return owner_; }
};

void printAccount(const BankAccount& account) {
    std::cout << "Account for " << account.getOwner() << ": $"
              << std::fixed << std::setprecision(2)
              << account.getBalance() << '\n';
}

int main() {
    BankAccount account{"Alex", 1000.0};
    printAccount(account);

    account.deposit(250.0);
    account.withdraw(150.0);
    printAccount(account);

    try {
        account.withdraw(2000.0);
    } catch (const std::exception& ex) {
        std::cout << "Withdrawal failed: " << ex.what() << '\n';
    }

    printAccount(account);
}
