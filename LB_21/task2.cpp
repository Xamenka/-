#include <iostream>
#include <sstream>
#include <string>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_ob_seats);
    bool cancelReservations(int number_ob_seats);
private:
    int id;
    int capacity;
    int reserved;
};

// Constructor
FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    if (reserved < 0) {
        this->reserved = 0;
    } else if (reserved > static_cast<int>(capacity * 1.05)) {
        this->reserved = static_cast<int>(capacity * 1.05);
    } else {
        this->reserved = reserved;
    }
}

// Print flight status
void FlightBooking::printStatus() {
    std::cout << "Flight " << this->id << ": " << this->reserved
              << "/" << this->capacity << " ("
              << static_cast<int>((static_cast<double>(this->reserved) / this->capacity) * 100)
              << "%) seats reserved" << std::endl;
}

// Add reservations
bool FlightBooking::reserveSeats(int number_ob_seats) {
    if (this->reserved + number_ob_seats > static_cast<int>(capacity * 1.05)) {
        return false;
    } else {
        this->reserved += number_ob_seats;
        return true;
    }
}

// Cancel reservations
bool FlightBooking::cancelReservations(int number_ob_seats) {
    if (this->reserved - number_ob_seats < 0) {
        return false;
    } else {
        this->reserved -= number_ob_seats;
        return true;
    }
}

int main() {
    int reserved = 0, capacity = 0;
    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;
    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;

    // Create FlightBooking instance
    FlightBooking booking(1, capacity, reserved);

    std::string command, action;
    int value;

    std::cin.ignore();

    while (command != "quit")
    {
        booking.printStatus();
        std::cout << "What would you like to do?: ";
        std::getline(std::cin, command);

        std::istringstream iss(command);
        iss >> action >> value;

        if (action == "add") {
            if (!booking.reserveSeats(value)) {
                std::cout << "Cannot perform this operation" << std::endl;
            }
        } else if (action == "cancel") {
            if (!booking.cancelReservations(value)) {
                std::cout << "Cannot perform this operation" << std::endl;
            }
        }
    }

    return 0;
}