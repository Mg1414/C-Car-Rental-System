# Lesson 2: Encapsulation and Abstraction

Encapsulation and abstraction help you manage complexity by hiding unnecessary details. They make your code easier to reason about and safer to modify.

## Encapsulation

Encapsulation means bundling data and functions that operate on that data within the same class, and restricting access to the class's internals. You:

- Declare member variables as `private` so they cannot be accessed directly from outside the class.
- Expose public member functions (getters/setters or domain-specific behaviors) for controlled interaction.

This prevents external code from corrupting the object's state and allows you to change the class's internals without breaking dependent code.

## Abstraction

Abstraction focuses on exposing only the essential features of an object. Rather than revealing how something works, you provide a simplified interface that describes **what** it does.

Consider the `BankAccount` class in `src/lesson02_encapsulation_abstraction.cpp`:

- Users can deposit or withdraw money via public functions.
- The class internally validates operations (e.g., prevents overdrafts) without exposing the underlying logic.
- Because `balance` is private, callers cannot set it to an invalid value directly.

## const Member Functions

Marking a member function as `const` promises that calling the function will not modify the object. Use it for methods that simply return information (`getBalance()`), reinforcing safe read-only access.

## Practice Ideas

- Add transaction history tracking within `BankAccount` while keeping the history implementation private.
- Experiment with friend functions to understand when they break encapsulation and why you should use them sparingly.
- Create an `ATM` class that uses `BankAccount` through its public API, demonstrating abstraction in action.

Once you appreciate how to control access, you are ready for constructors, destructors, and resource management in Lesson 3.
