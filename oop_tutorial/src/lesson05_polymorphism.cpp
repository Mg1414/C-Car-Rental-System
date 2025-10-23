#include <iostream>
#include <memory>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0; // pure virtual makes Shape abstract
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double area() const override { return width_ * height_; }

    double width() const { return width_; }
    double height() const { return height_; }

private:
    double width_;
    double height_;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}

    double area() const override { return pi * radius_ * radius_; }

    double radius() const { return radius_; }

private:
    double radius_;
    static constexpr double pi = 3.14159265358979323846;
};

void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << '\n';
}

// Compile-time polymorphism via overloading
void scale(Rectangle& rect, double factor) {
    rect = Rectangle{rect.width() * factor, rect.height() * factor};
}

void scale(Circle& circle, double factor) {
    circle = Circle{circle.radius() * factor};
}

int main() {
    Rectangle rect{4.0, 5.0};
    Circle circle{3.0};

    printArea(rect);
    printArea(circle);

    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_unique<Rectangle>(2.0, 6.0));
    shapes.emplace_back(std::make_unique<Circle>(1.5));

    std::cout << "Polymorphic dispatch:\n";
    for (const auto& shape : shapes) {
        printArea(*shape);
    }

    scale(rect, 2.0);
    scale(circle, 1.5);

    std::cout << "After scaling:\n";
    printArea(rect);
    printArea(circle);
}
