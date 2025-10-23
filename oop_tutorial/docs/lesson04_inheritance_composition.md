# Lesson 4: Inheritance and Composition

Classes rarely exist in isolation. OOP encourages reusing code and modeling relationships through **inheritance** and **composition**.

## Inheritance

Inheritance creates an "is-a" relationship between a base class and derived classes. The derived class automatically has the base class's members (subject to access specifiers) and can extend or customize behavior.

In `src/lesson04_inheritance_composition.cpp`:

- `Vehicle` acts as a base class with common state and functions.
- `Car` and `Truck` derive from `Vehicle`, adding specialized data and behavior.
- The `describe` function is `virtual`, allowing derived classes to provide their own implementations.

### Access Control in Inheritance

- `public` inheritance keeps the base class interface accessible to users of the derived class.
- `protected` members remain accessible to derived classes but not to users of the derived class.
- `private` inheritance is rare and models an "implemented-in-terms-of" relationship.

## Composition

Composition models a "has-a" relationship. A class contains other objects to reuse functionality without inheriting.

Our sample adds a `Fleet` class that **has** multiple `Vehicle` objects. Composition is often more flexible than inheritance because it avoids tight coupling and supports runtime behavior changes.

## Practice Ideas

- Add another derived type, such as `Motorcycle`, and override `describe` with its specifics.
- Experiment with `protected` data members to observe how access works in derived classes.
- Combine inheritance and composition by creating a `DeliveryTruck` that inherits from `Truck` and composes a `CargoHold` helper class.

With inheritance understood, you are ready for dynamic behavior through polymorphism in Lesson 5.
