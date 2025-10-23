# Lesson 5: Polymorphism

**Polymorphism** allows code to treat objects of different classes uniformly while relying on each object to perform its specialized behavior. C++ supports **compile-time** and **runtime** polymorphism.

## Compile-Time Polymorphism

- **Function Overloading**: Multiple functions share the same name but differ in parameter lists. The compiler selects the correct overload at compile time.
- **Operator Overloading**: Customize operators (like `+` or `<<`) for user-defined types.
- **Templates**: Generate functions or classes that operate with any type meeting the required interface.

## Runtime Polymorphism

Runtime polymorphism relies on base class pointers or references calling virtual functions implemented by derived classes.

In `src/lesson05_polymorphism.cpp` you will find:

- A hierarchy where `Shape` has a pure virtual `area()` function, making it an **abstract base class**.
- Derived classes `Rectangle` and `Circle` that implement `area()` differently.
- A `printArea` helper that accepts a `const Shape&`. Calling `area()` dispatches to the correct derived implementation at runtime.

### Virtual Destructors

When using polymorphism, always declare the base class destructor as `virtual`. This ensures derived objects are cleaned up correctly when deleted through a base pointer.

## Practice Ideas

- Add another derived class such as `Triangle` and include it in the collection of shapes.
- Introduce an overloaded `scale` function that demonstrates compile-time polymorphism alongside the runtime features.
- Convert the `printArea` function to a function template that prints area for any type implementing `area()` to compare template-based polymorphism with virtual functions.

Next, you will learn how to extend the language syntax and generalize behaviors with operator overloading and templates in Lesson 6.
