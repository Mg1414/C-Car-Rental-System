# Lesson 7: Exception Safety

Exceptions signal errors and unexpected conditions. Writing exception-safe OOP code ensures that your objects remain in valid states when operations fail.

## Basics of Exceptions in C++

- Use `throw` to signal an error.
- Use `try`/`catch` blocks to handle exceptions where recovery is possible.
- Catch exceptions by (const) reference to avoid slicing and unnecessary copying.

## Exception Safety Guarantees

1. **Basic Guarantee**: Invariants hold, and no resources leak, but state may change.
2. **Strong Guarantee**: Either the operation completes successfully or has no effect (transactional behavior).
3. **No-Throw Guarantee**: The operation never throws an exception.

In `src/lesson07_exception_safety.cpp`, observe:

- The `Transaction` class uses RAII to roll back changes when an exception occurs.
- The `Account` class provides exception-safe operations by validating inputs before mutating state.
- Custom exception types derived from `std::runtime_error` deliver descriptive error messages.

## Writing Exception-Safe Classes

- Prefer value semantics and RAII-managed resources.
- Validate arguments before mutating data members.
- Provide strong guarantees where practical; document behavior when only basic guarantees are offered.

## Practice Ideas

- Add logging to the rollback mechanism to trace exception handling paths.
- Modify the example to use `std::unique_ptr` resources and observe destructor-based cleanup.
- Experiment with exception specifications (`noexcept`) and how they interact with move operations.

Finish your OOP journey with Lesson 8, which ties principles together through design guidelines and small patterns.
