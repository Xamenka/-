#include <iostream>
using namespace std;

class Tree {
public:
    virtual char getSymbol() = 0; // чиста віртуальна функція: символ для побудови
    virtual ~Tree() {}

    void draw(int height) {
        cout << "Drawing tree with symbol '" << getSymbol() << "' and height " << height << ":\n";
        for (int i = 0; i < height; ++i) {
            // Виводимо пробіли
            for (int j = 0; j < height - i - 1; ++j)
                cout << " ";
            // Виводимо символи
            cout << "/";
            for (int j = 0; j < 2 * i; ++j)
                cout << getSymbol();
            cout << "\\" << endl;
        }
    }
};

class TreeStar : public Tree {
public:
    char getSymbol() override {
        return '*';
    }
};

class TreePlus : public Tree {
public:
    char getSymbol() override {
        return '+';
    }
};

class TreeAt : public Tree {
public:
    char getSymbol() override {
        return '-';
    }
};

int main() {
    int height;
    cout << "Enter the height of the trees: ";
    cin >> height;

    Tree* trees[3];
    trees[0] = new TreeStar();
    trees[1] = new TreePlus();
    trees[2] = new TreeAt();

    for (int i = 0; i < 3; ++i) {
        trees[i]->draw(height);
        cout << endl;
    }

    // Звільнення пам’яті
    for (int i = 0; i < 3; ++i) {
        delete trees[i];
    }

    return 0;
}
