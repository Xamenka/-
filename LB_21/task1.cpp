#include <iostream>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    
    void printStatus();

private:
    int id;        // Ідентифікатор рейсу
    int capacity;  // Загальна кількість місць
    int reserved;  // Кількість зарезервованих місць
};

// Реалізація конструктора класу
FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;
}

// Метод для виведення статусу рейсу
void FlightBooking::printStatus() {
    double percentage = (static_cast<double>(reserved) / capacity) * 100; // Обчислення відсотка зайнятих місць
    std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << percentage << "%) seats reserved\n";
}

int main() {
    int reserved = 0, capacity = 0;
    
    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;
    
    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;
    
    FlightBooking booking(1, capacity, reserved);
    
    booking.printStatus();
    
    return 0;
}
