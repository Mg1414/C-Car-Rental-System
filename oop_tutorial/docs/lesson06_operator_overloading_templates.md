# Lesson 6: Operator Overloading and Templates

Operator overloading and templates help you write expressive and reusable code for your classes.

## Operator Overloading

Operator overloading lets you redefine the meaning of operators for user-defined types while keeping intuitive syntax.

In `src/lesson06_operator_overloading_templates.cpp`, the `Vector2D` class implements:

- `operator+` to add vectors component-wise.
- `operator==` to compare equality.
- `operator<<` as a friend function to print vectors with `std::ostream`.

### Best Practices

- Keep overloaded operators intuitive; unexpected semantics make code hard to read.
- Prefer non-member functions when symmetric conversions are desired (`operator+`).
- Use `explicit` constructors to avoid accidental implicit conversions.

## Templates

Templates parameterize code with types. They provide compile-time polymorphism.

The lesson demonstrates:

- A function template `maxValue` that works with any type supporting comparison operators.
- A class template `Box<T>` that stores a value and provides type-safe access.
- How to specialize behavior using template parameters, including alias templates (`using`) for convenience.

## Practice Ideas

- Implement subtraction and scalar multiplication operators for `Vector2D`.
- Create a template-based math utility class that operates on any `Box<T>` containing numeric types.
- Explore partial specialization by creating a `Box<std::string>` specialization that tracks string length separately.

Next, reinforce your understanding of robustness and error handling with Lesson 7 on exception safety.
