#include <iostream>
#include <string>
#include <cctype>

bool has_upper(const std::string &password) {
    for (char ch : password) {
        if (std::isupper(ch)) return true;
    }
    return false;
}

bool has_lower(const std::string &password) {
    for (char ch : password) {
        if (std::islower(ch)) return true;
    }
    return false;
}

bool has_digit(const std::string &password) {
    for (char ch : password) {
        if (std::isdigit(ch)) return true;
    }
    return false;
}

bool has_special(const std::string &password) {
    std::string special_chars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/\\`~";
    for (char ch : password) {
        if (special_chars.find(ch) != std::string::npos) return true;
    }
    return false;
}

int main() {
    std::string password;
    std::getline(std::cin, password);

    bool valid = true;

    if (password.length() < 8) {
        std::cout << "The password must be at least 8 characters long" << std::endl;
        valid = false;
    }
    if (!has_upper(password)) {
        std::cout << "The password must contain at least one uppercase letter" << std::endl;
        valid = false;
    }
    if (!has_lower(password)) {
        std::cout << "The password must contain at least one lowercase letter" << std::endl;
        valid = false;
    }
    if (!has_digit(password)) {
        std::cout << "The password must contain at least one digit" << std::endl;
        valid = false;
    }
    if (!has_special(password)) {
        std::cout << "The password must contain at least one special character" << std::endl;
        valid = false;
    }

    if (valid) {
        std::cout << "The password is valid" << std::endl;
    }

    return 0;
}
