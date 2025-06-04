#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

int main() {
    // Зчитуємо вхідні дані
    std::string values, text_template;
    std::getline(std::cin, values);  // Вводимо список ключ=значення
    std::getline(std::cin, text_template);  // Вводимо шаблон для підстановки у вигляді [ключ]

    // Розбираємо ключі і значення та зберігаємо їх у словнику (unordered_map)
    std::unordered_map<std::string, std::string> replacements;
    std::stringstream ss(values);
    std::string key_value;

    // Проходимо по кожній парі ключ=значення
    while (std::getline(ss, key_value, ',')) {
        size_t pos = key_value.find('=');
        if (pos != std::string::npos) {
            // Додаємо пару ключ-значення до словника
            replacements[key_value.substr(0, pos)] = key_value.substr(pos + 1);
        }
    }

    // Замінюємо в шаблоні відповідні значення
    std::string result;
    size_t start = 0, end;
    
    // Пошук кожного символу '[', щоб знайти місце для заміни
    while ((start = text_template.find('[', start)) != std::string::npos) {
        result += text_template.substr(0, start); // Додаємо текст до [
        end = text_template.find(']', start); // Знаходимо закриваючу скобку ']'
        if (end == std::string::npos) break; // Якщо ] немає, припиняємо обробку

        // Витягуємо ключ з шаблону (між [] )
        std::string key = text_template.substr(start + 1, end - start - 1);
        
        // Якщо ключ знайдений у словнику, підставляємо відповідне значення
        // Якщо ключ не знайдений, залишаємо [ключ] без змін
        result += replacements.count(key) ? replacements[key] : "[" + key + "]";

        // Обрізаємо оброблену частину шаблону
        text_template = text_template.substr(end + 1); 
        start = 0; // Починаємо пошук знову
    }

    // Додаємо залишок тексту, який не містить квадратних дужок
    result += text_template;
    
    // Виводимо результат
    std::cout << result << std::endl;

    return 0;
}
