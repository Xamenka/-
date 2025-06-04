#include <iostream>
#include <string>
using namespace std;

class Square
{
public:
    Square(double side);
    void setSide(double side);  // метод для зміни сторони
    double getSide() const;  // метод для отримання сторони
    double getArea() const;  // метод для отримання площі
    void print() const;  // метод для виведення даних

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
    if (side > 0)  // перевірка, щоб сторона була позитивною
    {
        this->side = side;
        this->area = side * side;  // оновлення площі
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
    s.print();  // Виведемо початкові значення
    s.setSide(2.0);
    s.print();  // Виведемо нові значення після зміни сторони
    s.setSide(-33.0);  // Спробуємо задати негативну сторону
    s.print();  // Перевіримо результат
    return 0;
}
