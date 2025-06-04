#include <iostream>
#include <string>
using namespace std;

class Square
{
public:
    Square(double side);
    void setSide(double side);  
    double getSide() const; 
    double getArea() const; 
    void print() const;  
private:
    double side;
    double area;
};

Square::Square(double side)
{
    this->side = side;
    this->area = side * side;
}

void Square::setSide(double side)
{
    if (side > 0)  
    {
        this->side = side;
        this->area = side * side;  
    }
    else
    {
        cout << "Side length must be positive." << endl;
    }
}

double Square::getSide() const
{
    return side;
}

double Square::getArea() const
{
    return area;
}

void Square::print() const
{
    cout << "Square: side=" << side << " area=" << area << endl;
}

int main()
{
    Square s(4);
    s.print(); 
    s.setSide(2.0);
    s.print();  
    s.setSide(-33.0);  
    s.print();  
    return 0;
}
