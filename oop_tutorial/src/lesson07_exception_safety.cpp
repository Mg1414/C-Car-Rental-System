#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

class AccountError : public std::runtime_error {
public:
    explicit AccountError(const std::string& message) : std::runtime_error(message) {}
};

class Account {
public:
    explicit Account(double balance) : balance_(balance) {
        if (balance < 0.0) {
            throw AccountError("Balance cannot be negative");
        }
    }

    double balance() const noexcept { return balance_; }

    void deposit(double amount) {
        if (amount < 0.0) {
            throw AccountError("Deposit must be positive");
        }
        balance_ += amount;
    }

    void withdraw(double amount) {
        if (amount < 0.0) {
            throw AccountError("Withdrawal must be positive");
        }
        if (balance_ < amount) {
            throw AccountError("Insufficient funds");
        }
        balance_ -= amount;
    }

private:
    double balance_;
};

class Transaction {
public:
    Transaction(Account& account, double change)
        : account_(account), change_(change), committed_(false) {
        // Apply optimistic change but remember how to rollback
        account_.deposit(change_);
    }

    ~Transaction() {
        if (!committed_) {
            try {
                account_.withdraw(change_);
            } catch (const std::exception& ex) {
                std::cerr << "Rollback failed: " << ex.what() << '\n';
            }
        }
    }

    void commit() { committed_ = true; }

private:
    Account& account_;
    double change_;
    bool committed_;
};

int main() {
    try {
        Account account{100.0};
        std::cout << "Initial balance: " << account.balance() << '\n';

        try {
            Transaction transaction{account, 50.0};
            std::cout << "After provisional deposit: " << account.balance() << '\n';

            // Simulate an error before commit
            throw std::runtime_error("Network failure");

            transaction.commit();
        } catch (const std::exception& ex) {
            std::cout << "Transaction aborted: " << ex.what() << '\n';
        }

        std::cout << "Balance after rollback: " << account.balance() << '\n';

        account.withdraw(200.0);
    } catch (const AccountError& ex) {
        std::cout << "Account error: " << ex.what() << '\n';
    }
}
