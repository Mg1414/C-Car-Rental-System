# C++ Object-Oriented Programming Tutorial

Welcome to the C++ Object-Oriented Programming (OOP) tutorial bundled with this project. The material is organized into lessons that combine conceptual explanations with hands-on code samples. Each lesson builds on the previous one, so follow the numerical order for the smoothest learning experience.

## How to Use This Tutorial

1. Read the corresponding lesson file in `docs/` to understand the concept.
2. Explore the matching code sample in `src/` to see the idea applied in practice.
3. Compile and run the sample with a C++17 compiler:

   ```bash
   g++ -std=c++17 -Wall -Wextra -pedantic -o lessonN oop_tutorial/src/lessonNN_*.cpp
   ./lessonN
   ```

   Replace `lessonNN_*` with the actual filename for the lesson you are studying. Each file includes a `main` function designed to demonstrate the lesson topic.

4. Experiment with the examples by modifying class members or adding new objects. Hands-on practice is the best way to solidify OOP concepts.

## Lesson Overview

| Lesson | Topic | Description |
| ------ | ----- | ----------- |
| 1 | Classes & Objects | Model entities with data and behavior while managing access. |
| 2 | Encapsulation & Abstraction | Hide implementation details and expose clean interfaces. |
| 3 | Constructors, Destructors & RAII | Manage resource lifetime and initialization safely. |
| 4 | Inheritance & Composition | Reuse code via hierarchical relationships and object composition. |
| 5 | Polymorphism | Achieve flexible behavior with function overloading and overriding. |
| 6 | Operator Overloading & Templates | Extend syntax and generalize behavior through templates. |
| 7 | Exception Safety | Write robust OOP code with structured error handling. |
| 8 | Design Principles & Patterns | Apply SOLID principles and small patterns to real projects. |

Each document also ends with practice suggestions to deepen your understanding. Enjoy learning!
