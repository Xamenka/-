#include <iostream>
#include <string>
#include <sstream>  // Подключаем для работы с istringstream

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved = 0); 
    FlightBooking();  
    void printStatus();
    bool reserveSeats(int number_of_seats); // Резервує місця
    bool cancelReservations(int number_of_seats); // Відміняє бронь
    int getId() { return id; } // Повертає ID рейса

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking() {
    id = 0;
    capacity = 0;
    reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;

    if (reserved < 0) {
        this->reserved = 0;
    } else if (reserved > capacity * 1.05) {
        this->reserved = capacity * 1.05;
    } else {
        this->reserved = reserved;
    }
}

void FlightBooking::printStatus() {
    double percentage = (static_cast<double>(reserved) / capacity) * 100;
    std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << percentage << "%) seats reserved\n";
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    if (reserved + number_of_seats > capacity * 1.05) {
        std::cout << "Cannot perform this operation: capacity reached\n";
        return false;
    }
    reserved += number_of_seats;
    return true;
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    if (reserved - number_of_seats < 0) {
        std::cout << "Cannot perform this operation: insufficient reserved seats\n";
        return false;
    }
    reserved -= number_of_seats;
    return true;
}

int main() {
    FlightBooking booking[10];  // Массив для хранения рейсов
    std::string command;

    while (true) {
        bool flightFound = false;
        std::cout << "What would you like to do?: ";
        std::getline(std::cin, command); 

        std::string action;
        int id, seats;

        std::istringstream stream(command); 
        stream >> action;

        if (action == "quit") {
            break;
        } else if (action == "create") {
            stream >> id >> seats;
            if (id == 0) {
                std::cout << "Cannot perform this operation: invalid flight id\n";
                continue;
            }

            // Пошук вільного місця для нового рейса
            bool created = false;
            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == 0) {
                    booking[i] = FlightBooking(id, seats);
                    created = true;
                    break;
                }
            }

            if (!created) {
                std::cout << "Cannot perform this operation: flight limit reached\n";
            }
        } else if (action == "delete") {
            stream >> id;
            bool deleted = false;

            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == id) {
                    booking[i] = FlightBooking(); // Скидуєм рейс
                    deleted = true;
                    break;
                }
            }

            if (!deleted) {
                std::cout << "Cannot perform this operation: flight " << id << " not found\n";
            }
        } else if (action == "add") {
            stream >> id >> seats;
            bool added = false;

            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == id) {
                    added = booking[i].reserveSeats(seats);
                    break;
                }
            }

            if (!added) {
                std::cout << "Cannot perform this operation: flight " << id << " not found or invalid\n";
            }
        } else if (action == "cancel") {
            stream >> id >> seats;
            bool cancelled = false;

            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == id) {
                    cancelled = booking[i].cancelReservations(seats);
                    break;
                }
            }

            if (!cancelled) {
                std::cout << "Cannot perform this operation: flight " << id << " not found or insufficient seats\n";
            }
        } else {
            std::cout << "Invalid command\n";
        }

        // Вивід всіх рейсів
        bool anyFlights = false;
        for (int i = 0; i < 10; i++) {
            if (booking[i].getId() != 0) {
                booking[i].printStatus();
                anyFlights = true;
            }
        }

        if (!anyFlights) {
            std::cout << "No flights in the system\n";
        }
    }

    return 0;
}
