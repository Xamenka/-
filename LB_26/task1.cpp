#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Базовий клас IPAddress
class IPAddress {
protected:
    string address;

public:
    // Конструктор
    IPAddress(string addr) : address(addr) {}

    // Копі-конструктор
    IPAddress(const IPAddress& other) {
        address = other.address;
    }

    // Віртуальний метод для виводу
    virtual void print() {
        cout << address;
    }

    // Віртуальний деструктор
    virtual ~IPAddress() {}
};

// Похідний клас IPAddressChecked
class IPAddressChecked : public IPAddress {
    bool isCorrect;

    // Допоміжна функція для перевірки IP
    bool validateIP(const string& addr) {
        istringstream ss(addr);
        string token;
        int count = 0;

        while (getline(ss, token, '.')) {
            ++count;
            if (token.empty() || token.size() > 3) return false;

            for (char c : token) {
                if (!isdigit(c)) return false;
            }

            int num = stoi(token);
            if (num < 0 || num > 255) return false;
        }

        return count == 4;
    }

public:
    // Конструктор
    IPAddressChecked(string addr) : IPAddress(addr) {
        isCorrect = validateIP(addr);
    }

    // Копі-конструктор
    IPAddressChecked(const IPAddressChecked& other) : IPAddress(other) {
        isCorrect = other.isCorrect;
    }

    // Перевизначення методу print
    void print() override {
        IPAddress::print(); // виклик методу з базового класу
        cout << " - " << (isCorrect ? "Correct" : "Not Correct");
    }
};

int main() {
    string ip1, ip2, ip3;

    // Ввід з клавіатури
    cout << "Enter three IP addresses:\n";
    cin >> ip1 >> ip2 >> ip3;

    // Створення об'єктів
    IPAddress ip(ip1);
    IPAddressChecked ipChecked1(ip2);
    IPAddressChecked ipChecked2(ip3);

    // Вивід результатів
    ip.print(); cout << endl;
    ipChecked1.print(); cout << endl;
    ipChecked2.print(); cout << endl;

    return 0;
}
