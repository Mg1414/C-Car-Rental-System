# Lesson 1: Classes and Objects

Object-Oriented Programming (OOP) starts with the idea of **modeling real-world entities** as software objects. An object bundles two things: **state** (data) and **behavior** (functions that operate on that data). In C++, the blueprint for objects is called a **class**.

## Key Concepts

- **Class**: Defines the structure and behavior common to all objects of that type.
- **Object**: A specific instance of a class with its own copy of the class's data members.
- **Members**: Variables and functions defined inside the class body.
- **Access Specifiers**: `public`, `protected`, and `private` control which parts of your program can access a member. By default, class members are `private` in C++.

## Example Walkthrough

Study `src/lesson01_classes_objects.cpp`. It defines a `Vehicle` class with both data and behaviors. Notice how we:

1. Declare **private** member variables to protect the internal state.
2. Provide **public** member functions so users can interact with the object safely.
3. Create multiple `Vehicle` objects in `main` to show that each one has independent state.

While reading the source, pay attention to:

- How the constructor-like initialization is performed using member functions (`setMake`, `setModel`).
- The difference between `const` member functions (which promise not to modify the object) and non-`const` functions.
- How objects can be copied by value and stored in standard containers like `std::vector`.

## Practice Ideas

- Extend `Vehicle` by adding attributes like `fuelType` or `odometer` and corresponding behaviors.
- Write a `display` function that prints all information about a vehicle in one go.
- Create another class such as `Driver` and consider how it might relate to `Vehicle` through composition.

Move to Lesson 2 once you are comfortable defining simple classes and creating objects.
