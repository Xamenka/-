#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

int main() {
    std::string values, text_template;
    std::getline(std::cin, values);  
    std::getline(std::cin, text_template);  

    std::unordered_map<std::string, std::string> replacements;
    std::stringstream ss(values);
    std::string key_value;

    while (std::getline(ss, key_value, ',')) {
        size_t pos = key_value.find('=');
        if (pos != std::string::npos) {
            replacements[key_value.substr(0, pos)] = key_value.substr(pos + 1);
        }
    }

    std::string result;
    size_t start = 0, end;
    
    while ((start = text_template.find('[', start)) != std::string::npos) {
        result += text_template.substr(0, start); 
        end = text_template.find(']', start); 
        if (end == std::string::npos) break; 

        std::string key = text_template.substr(start + 1, end - start - 1);
        
        result += replacements.count(key) ? replacements[key] : "[" + key + "]";

        text_template = text_template.substr(end + 1); 
        start = 0; // Починаємо пошук знову
    }

    result += text_template;

    std::cout << result << std::endl;

    return 0;
}
