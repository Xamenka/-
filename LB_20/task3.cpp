#include <iostream>
using namespace std;

class AdHocSquare
{
public:
    AdHocSquare(double side);
    void set_side(double side);
    double get_area();
    
private:
    double side;
};

AdHocSquare::AdHocSquare(double side) : side(side) {}

void AdHocSquare::set_side(double side)
{
    this->side = side;
}

double AdHocSquare::get_area()
{
    return side * side;
}

class LazySquare
{
public:
    LazySquare(double side);
    void set_side(double side); 
    double get_area(); 

private:
    double side;
    double area;
    bool side_changed;
    void update_area();
};

LazySquare::LazySquare(double side) : side(side), area(side * side), side_changed(false) {}

void LazySquare::set_side(double side)
{
    if (this->side != side)
    {
        this->side = side;
        this->side_changed = true;
    }
}

void LazySquare::update_area()
{
    if (side_changed)
    {
        area = side * side;
        side_changed = false;
    }
}

double LazySquare::get_area()
{
    update_area();
    return area;
}

int main()
{
    AdHocSquare square1(4);
    cout << "AdHocSquare area: " << square1.get_area() << endl;
    square1.set_side(5);
    cout << "AdHocSquare area after change: " << square1.get_area() << endl;
    
    LazySquare square2(6);
    cout << "LazySquare area: " << square2.get_area() << endl;
    square2.set_side(5);
    cout << "LazySquare area after change: " << square2.get_area() << endl;
    square2.set_side(2);
    cout << "LazySquare area without change: " << square2.get_area() << endl;
    
    return 0;
}
