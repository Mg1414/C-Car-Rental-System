# Lesson 8: Design Principles and Patterns

Understanding principles and design patterns helps you apply OOP techniques to larger systems. This lesson provides a practical overview rather than an exhaustive reference.

## SOLID Principles

1. **Single Responsibility Principle (SRP)**: A class should have one reason to change. Keep responsibilities focused.
2. **Open/Closed Principle (OCP)**: Entities should be open for extension but closed for modification. Use inheritance, composition, and polymorphism to extend behavior without editing existing code.
3. **Liskov Substitution Principle (LSP)**: Derived classes must be usable anywhere the base class is expected without altering desirable behavior.
4. **Interface Segregation Principle (ISP)**: Prefer small, specific interfaces over large, general ones.
5. **Dependency Inversion Principle (DIP)**: Depend on abstractions, not concrete implementations.

## Design Patterns in C++

The sample in `src/lesson08_design_principles_patterns.cpp` demonstrates:

- **Strategy Pattern**: Encapsulates algorithms behind a common interface (`PricingStrategy`). Different strategies (`FlatRate`, `WeekendDiscount`) can be swapped at runtime.
- **Factory Function**: A helper that constructs strategies based on configuration, keeping creation logic separate from usage.
- **Dependency Injection**: The `RentalService` receives a strategy via constructor, honoring DIP and enabling easy unit testing.

## Testing and Extensibility

- Because `RentalService` depends on an interface, you can inject mock strategies during testing.
- Adding a new pricing strategy requires only creating a new class derived from `PricingStrategy` and wiring it into the factory.

## Practice Ideas

- Implement additional patterns such as Observer for notifications or Decorator for augmenting behavior.
- Apply SRP by splitting `RentalService` into smaller services (e.g., billing, notifications) and coordinating them.
- Use smart pointers (`std::unique_ptr`) to manage strategy ownership automatically.

Congratulations! You now have a broad tour of OOP in modern C++. Revisit earlier lessons whenever you encounter these concepts in real projects.
