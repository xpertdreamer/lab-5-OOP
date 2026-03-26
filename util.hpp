#ifndef UTIL_H_
#define UTIL_H_

#include "cars.hpp"
#include <limits>
#include <list>
#include <sstream>
#include <string>
#include <vector>

inline void fill_list(std::list<Car> &cars) {
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        std::string _brand, _model;
        int _year;
        double _price;

        std::cout << "Enter data for " << i + 1 << " >\n";
        std::cout << "Brand > ";
        std::getline(std::cin, _brand);
        std::cout << "Model > ";
        std::getline(std::cin, _model);
        std::cout << "Year >";
        std::cin >> _year;
        std::cout << "Price > ";
        std::cin >> _price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cars.push_back(Car(_brand, _model, _year, _price));
    }
}

inline std::vector<int> input_indicies(int maxIdx) {
    std::cout << "Enter indicies separated by space > ";
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> res;
    std::stringstream ss(input);
    int idx;

    while (ss >> idx) {
        if (idx >= 0 && idx < maxIdx)
            res.push_back(idx);
        else
            std::cout << "Warning: Index " << idx
                      << " will be ignored (out-of-range)\n";
    }

    return res;
}
#endif // UTIL_H_
