#include <iostream>
#include <string>

class shape
{
protected:
    std::string color;

public:
    shape()
    {
        color = "white";
    }
    shape(std::string color)
    {
        this->color = color;
    }
    std::string getColor()
    {
        return color;
    }
    void setColor(std::string color)
    {
        this->color = color;
    }
    void print()
    {
        std::cout << "color : " << color << std::endl;
    }
};
class Circle : public shape
{
private:
    int radius;

public:
    Circle()
    {
        radius = 0;
    }
    Circle(std::string color, int radius)
    {
        this->color = color;
        this->radius = radius;
    }
    int getRadius()
    {
        return radius;
    }
    void setRadius(int radius)
    {
        this->radius = radius;
    }
    int perimeter()
    {
        return 2 * 3 * radius;
    }
    int area()
    {
        return 3 * radius * radius;
    }
    std::string print()
    {
        shape::print();
        std::cout << "perimeter : " << perimeter() << std::endl;
        std::cout << "area : " << area() << std::endl;
        return "done";
    }
};
class Rectangle : public shape
{
private:
    int width;
    int height;

public:
    Rectangle()
    {
        width = 0;
        height = 0;
    }
    Rectangle(std::string color, int width, int height)
    {
        this->color = color;
        this->width = width;
        this->height = height;
    }
    int getWidth()
    {
        return width;
    }
    void setWidth(int width)
    {
        this->width = width;
    }
    int getHeight()
    {
        return height;
    }
    void setHeight(int height)
    {
        this->height = height;
    }
    int perimeter()
    {
        return 2 * width + 2 * height;
    }
    int area()
    {
        return width * height;
    }
    std::string print()
    {
        shape::print();
        std::cout << "perimeter : " << perimeter() << std::endl;
        std::cout << "area : " << area() << std::endl;
        return "done";
    }
};

int main()
{
    std::string sh;
    std::cin >> sh;
    if (sh == "Circle")
    {
        int r;
        std::string color;
        std::cin >> r >> color;
        Circle circle(color, r);
        circle.print();
    }
    else
    {
        int a, b;
        std::string color;
        std::cin >> a >> b >> color;
        Rectangle rectangle(color, a, b);
        rectangle.print();
    }
    return 0;
}
