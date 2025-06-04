#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;
};

void print(const Person* person)
{
    cout << person->name << " is " << person->age << " years old" << endl;
}

int main()
{
    // Створення об'єктів класу Person
    Person person1;
    person1.name = "Harry";
    person1.age = 23;

    Person person2;
    person2.name = "Alice";
    person2.age = 30;

    Person person3;
    person3.name = "Bob";
    person3.age = 27;

    // Виклик функції print для кожного об'єкта
    print(&person1);
    print(&person2);
    print(&person3);

    return 0;
}
