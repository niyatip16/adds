#include <iostream>
#include "autocomplete.h"

int main() {
    Autocomplete autocomplete;
    autocomplete.insert("bin");
    autocomplete.insert("ball");
    autocomplete.insert("ballet");

    // Test autocomplete with partial words
    std::vector<std::string> suggestions;

    suggestions = autocomplete.getSuggestions("b");
    for (const std::string& suggestion : suggestions) {
        std::cout << suggestion << " ";
    }
    std::cout << std::endl;

    suggestions = autocomplete.getSuggestions("ba");
    for (const std::string& suggestion : suggestions) {
        std::cout << suggestion << " ";
    }
    std::cout << std::endl;

    suggestions = autocomplete.getSuggestions("bal");
    for (const std::string& suggestion : suggestions) {
        std::cout << suggestion << " ";
    }
    std::cout << std::endl;

    suggestions = autocomplete.getSuggestions("balle");
    for (const std::string& suggestion : suggestions) {
        std::cout << suggestion << " ";
    }
    std::cout << std::endl;

    return 0;
}
