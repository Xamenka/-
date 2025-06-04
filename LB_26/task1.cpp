#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class IPAddress {
protected:
    string address;

public:
    IPAddress(string addr) : address(addr) {}

    IPAddress(const IPAddress& other) {
        address = other.address;
    }

    virtual void print() {
        cout << address;
    }

    virtual ~IPAddress() {}
};

class IPAddressChecked : public IPAddress {
    bool isCorrect;

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
    IPAddressChecked(string addr) : IPAddress(addr) {
        isCorrect = validateIP(addr);
    }

    IPAddressChecked(const IPAddressChecked& other) : IPAddress(other) {
        isCorrect = other.isCorrect;
    }

    void print() override {
        IPAddress::print(); // виклик методу з базового класу
        cout << " - " << (isCorrect ? "Correct" : "Not Correct");
    }
};

int main() {
    string ip1, ip2, ip3;

    cout << "Enter three IP addresses:\n";
    cin >> ip1 >> ip2 >> ip3;

    IPAddress ip(ip1);
    IPAddressChecked ipChecked1(ip2);
    IPAddressChecked ipChecked2(ip3);

    ip.print(); cout << endl;
    ipChecked1.print(); cout << endl;
    ipChecked2.print(); cout << endl;

    return 0;
}
