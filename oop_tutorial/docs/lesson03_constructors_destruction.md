# Lesson 3: Constructors, Destructors, and RAII

Constructors and destructors manage the lifetime of your objects. **Resource Acquisition Is Initialization (RAII)** is a C++ idiom that uses object lifetime to control resources such as memory, files, or network sockets.

## Constructors

Constructors initialize objects when they are created. They can:

- Provide default values (default constructor).
- Accept parameters to customize initialization (parameterized constructor).
- Copy or move data from other objects (copy/move constructors).

Read the `Resource` class in `src/lesson03_constructors_destruction.cpp`. It demonstrates:

- A default constructor that acquires a resource.
- A parameterized constructor for custom names.
- Copy and move constructors to control how resources are duplicated or transferred.

## Destructors

Destructors clean up resources automatically when objects go out of scope. The `Resource` destructor logs when the held resource is released. This pattern ensures resources are freed even if exceptions are thrown.

## RAII in Practice

The accompanying `FileGuard` class wraps an `std::fstream`. When a `FileGuard` object is destroyed, its destructor closes the file automatically, preventing leaks.

## Rule of Zero/Three/Five

- **Rule of Zero**: If your class manages no resources directly, rely on compiler-generated special member functions.
- **Rule of Three**: If you define a destructor, copy constructor, or copy assignment operator, you often need all three.
- **Rule of Five**: In modern C++, also consider move constructor and move assignment operator when managing resources.

## Practice Ideas

- Implement move assignment for `Resource` and observe how ownership transfers.
- Wrap another resource (such as dynamic memory via `new` or a network handle) to solidify RAII.
- Experiment with `std::unique_ptr` and `std::shared_ptr` to see RAII in the Standard Library.

You now have the foundations to explore relationships between classes via inheritance and composition in Lesson 4.
