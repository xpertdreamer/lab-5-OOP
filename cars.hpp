#ifndef CARS_H_
#define CARS_H_

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <string>
#include <vector>

struct Car {
    std::string brand;
    std::string model;
    int year;
    double price;

    Car(const std::string b = "", const std::string m = "", const int y = 0,
        const int p = 0.0)
        : brand(b), model(m), year(y), price(p) {}

    void print() const {
        std::cout << brand << " " << model << " (" << year << ") > " << price;
    }
};

inline bool display_cars(const std::list<Car> &cars) {
    if (cars.empty()) {
        std::cout << "This container is empty" << std::endl;
        return false;
    }

    int index = 1;
    auto it = cars.cbegin();
    while (it != cars.cend()) {
        std::cout << index++ << ".";
        it->print();
        std::cout << "\n";
        ++it;
    }

    std::cout << "Total: " << cars.size() << "\n";
    return true;
}

inline bool remove_by_indicies(std::list<Car> &cars,
                               const std::vector<int> &indicies) {
    if (indicies.empty())
        return false;

    std::set<int> deleteIdxs(indicies.begin(), indicies.end());

    int size = cars.size();
    for (const auto i : deleteIdxs) {
        if (i < 0 || i >= size) {
            std::cout << "Error: Index " << i << " is out-of-bounds\n";
            return false;
        }
    }

    std::vector<int> sorted(deleteIdxs.begin(), deleteIdxs.end());
    std::sort(sorted.begin(), sorted.end(), std::greater<int>());
    for (const auto i : sorted) {
        auto it = cars.begin();
        std::advance(it, i);
        cars.erase(it);
    }

    return true;
}

#endif // CARS_H_
