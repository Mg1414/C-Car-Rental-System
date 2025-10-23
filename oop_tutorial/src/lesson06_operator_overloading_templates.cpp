#include <iostream>
#include <type_traits>
#include <utility>

class Vector2D {
public:
    constexpr Vector2D(double x, double y) : x_(x), y_(y) {}

    double x() const { return x_; }
    double y() const { return y_; }

    friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
        return Vector2D{lhs.x_ + rhs.x_, lhs.y_ + rhs.y_};
    }

    friend bool operator==(const Vector2D& lhs, const Vector2D& rhs) {
        return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
        return os << '(' << vec.x_ << ", " << vec.y_ << ')';
    }

private:
    double x_;
    double y_;
};

template <typename T>
T maxValue(const T& a, const T& b) {
    return (a < b) ? b : a;
}

template <typename T>
class Box {
public:
    template <typename... Args>
    explicit Box(Args&&... args) : value_(std::forward<Args>(args)...) {}

    const T& get() const { return value_; }
    void set(const T& value) { value_ = value; }

private:
    T value_;
};

using Point = Box<Vector2D>;

int main() {
    Vector2D a{1.0, 2.0};
    Vector2D b{3.5, -1.0};
    Vector2D c = a + b;

    std::cout << a << " + " << b << " = " << c << '\n';
    std::cout << std::boolalpha << "a == c? " << (a == c) << '\n';

    std::cout << "maxValue(4, 9): " << maxValue(4, 9) << '\n';
    std::cout << "maxValue('A', 'Z'): " << maxValue('A', 'Z') << '\n';

    Point point{Vector2D{5.0, 6.0}};
    std::cout << "Point holds: " << point.get() << '\n';

    if constexpr (std::is_copy_assignable_v<Box<Vector2D>>) {
        point.set(Vector2D{0.0, 0.0});
        std::cout << "After reset: " << point.get() << '\n';
    }
}
