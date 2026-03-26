#ifndef CARS_H_
#define CARS_H_

#include <iostream>
#include <list>
#include <string>

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

#endif // CARS_H_
