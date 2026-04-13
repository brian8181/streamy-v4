#include <iostream>

class Point
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Declaring friend functions for private member access
    friend std::ostream &operator<<(std::ostream &os, const Point &p);
    friend std::istream &operator>>(std::istream &is, Point &p);
};

// Global implementation
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Point &p)
{
    is >> p.x >> p.y;
    return is;
}

int main()
{
    Point p1(10, 20);
    std::cout << "The point is: " << p1 << std::endl; // Chaining supported
    return 0;
}
