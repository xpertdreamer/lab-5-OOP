// #include "conversion.hpp"
#include "person.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    try {
        Person p1("Иванов", "Иван", "Иванович", 52);
        // std::cout << "Creating person with age 125" << std::endl;
        // Person p2("Stepanov", "Stepan", "Stepanich", 125);
        // std::cout << "Creating person with age -4" << std::endl;
        // Person p3("Zaharov", "Zahar", "Zaharichevv", -4);

        p1.set_age(125);
        p1.set_age(-1);
    } catch (const std::range_error &err) {
        std::cout << "Error: " << err.what() << std::endl;
    }

    // Converter converter;
    // std::string input;

    // std::cout << "Type an ternary real number > ";
    // std::getline(std::cin, input);

    // try {
    //     std::string res = converter.convert(input);
    //     std::cout << "Result (14) > " << res << std::endl;
    // } catch (const std::runtime_error &error) {
    //     std::cerr << "Error: " << error.what() << std::endl;
    // }

    return 0;
}
