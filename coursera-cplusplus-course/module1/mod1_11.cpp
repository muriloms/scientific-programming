/******************************************************************************

Based on the example of Circle and Rectangle, define a virtual function "left_of(double x)" which return true if the object is entirely on the left of the given x-coordinate, 
and false otherwise. 
Also, define a virtual function "whoAmI()" which prints "Circle" or "Rectangle" according to the type of the shape.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <ranges>
#include <array>

using namespace std; // É uma prática melhor evitar 'using namespace std;' em programas maiores.

struct Shape
{
    virtual ~Shape() = default; // Virtual destructor for proper cleanup of derived classes

    virtual bool left_of(double x) const = 0; // Pure virtual function to check if the shape is entirely on the left of x
    virtual void whoAmI() const = 0; // Pure virtual function to identify the shape type
};

struct Circle : public Shape
{
    double cx{}, cy{}, radius{};
    Circle(double x, double y, double r) : cx(x), cy(y), radius(r) {}

    virtual bool left_of(double xLimit) const override
    {
        {return cx + radius < xLimit;} // Check if the leftmost point of the circle is to the left of x
    }

    virtual void whoAmI() const override
    {
        cout << "Circle" << endl; // Print the type of the shape
    }
};

struct Rectangle : public Shape
{
    double x1{}, y1{}, x2{}, y2{};
    Rectangle(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    virtual bool left_of(double xLimit) const override
    {
        return x2 < xLimit; // Check if the rightmost point of the rectangle is to the left of x
    }

    virtual void whoAmI() const override
    {
        cout << "Rectangle" << endl; // Print the type of the shape
    }
};


int main()
{
    auto myShape=vector<unique_ptr<Shape>>{};
    myShape.push_back(make_unique<Circle>( Circle{1, 3, 4} ) );
    myShape.push_back(make_unique<Rectangle>( Rectangle{0, 0, 4, 5} ) );
    myShape.push_back(make_unique<Circle>( Circle(3, 5, 1) ) );

    auto xLimit = double{5.};

    // for each of the 3 shapes, write true/false depending if they
    // are entirely on the left of xLimit 
    ranges::for_each(myShape, 
    [xLimit](auto& shape){
        cout << boolalpha << shape->left_of(xLimit) <<endl;
        shape->whoAmI();

    });
    // we get: false true true
   
   return 0;
}

// g++ -std=c++20 -o module1/mod1_7 module1/mod1_7.cpp