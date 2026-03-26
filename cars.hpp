#ifndef CARS_H_
#define CARS_H_

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <string>
#include <utility>
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

    void input_new_data() {
        std::cout << "Enter new brand: ";
        getline(std::cin, brand);
        std::cout << "Enter new model: ";
        getline(std::cin, model);
        std::cout << "Enter new year: ";
        std::cin >> year;
        std::cout << "Enter new price: ";
        std::cin >> price;
        std::cin.ignore();
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

inline bool swap_by_indicies(std::list<Car> &cars,
                             const std::vector<int> &indicies,
                             const std::vector<Car> &n_cars) {
    if (indicies.size() != n_cars.size()) {
        std::cout << "Error: Number of indices and new cars don't match!\n";
        return false;
    }

    std::vector<std::pair<int, Car>> repl;
    for (size_t i = 0; i < indicies.size(); i++) {
        if (indicies[i] >= 0 && indicies[i] < cars.size())
            repl.push_back({indicies[i], n_cars[i]});
        else
            std::cout << "Warning: Index " << indicies[i]
                      << " is out of range and will be skipped\n";
    }

    std::sort(repl.begin(), repl.end(),
              [](const std::pair<int, Car> &a, const std::pair<int, Car> &b) {
                  return a.first > b.first;
              });
    for (const auto &r : repl) {
        auto it = cars.begin();
        std::advance(it, r.first);
        *it = r.second;
        std::cout << "Replaced car at index " << r.first << "\n";
    }

    return true;
}

inline bool delete_n_after(std::list<Car> &cars, int startIdx, int count) {
    if (startIdx < 0 || startIdx >= static_cast<int>(cars.size())) {
        std::cout << "Invalid index! Index must be between 0 and "
                  << cars.size() - 1 << "\n";
        return false;
    }

    auto start = cars.begin();
    std::advance(start, startIdx + 1);
    if (start == cars.end()) {
        std::cout << "No elements after index " << startIdx << "\n";
        return false;
    }

    auto end = start;
    int removed = 0;
    while (removed < count && end != cars.end()) {
        end++;
        removed++;
    }

    cars.erase(start, end);
    std::cout << "Removed " << removed << " elements after index " << startIdx
              << "\n";
    return true;
}

#endif // CARS_H_
