#include "cars.hpp"
#include "util.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::list<Car> cars;
    std::list<Car> cars2;

    std::cout << "Variant 2 (doubly linked list with cars)\n";

    std::cout << "#1 How many cars you want to enter > ";
    fill_list(cars);

    std::cout << "#2 View container\n";
    if (display_cars(cars) == false)
        std::exit(1);

    std::cout << "#3 Modifying the container\n";
    std::cout << "\nRemove cars at specific indices\n";
    if (cars.empty() == false) {
        std::vector<int> idxs_rem = input_indicies(cars.size());
        if (!idxs_rem.empty()) {
            std::cout << "Removing ";
            for (int idx : idxs_rem)
                std::cout << idx << " ";
            std::cout << "\n";

            if (remove_by_indicies(cars, idxs_rem))
                std::cout << "Removed!\n";
        } else
            std::cout << "No valid indicies to remove\n";
        if (display_cars(cars) == false)
            std::exit(1);

        std::cout << "\nReplace cars at specific indices\n";
        std::vector<int> idxs_swap = input_indicies(cars.size());
        if (!idxs_swap.empty()) {
            std::vector<Car> newC;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            for (size_t i = 0; i < idxs_swap.size(); ++i) {
                std::cout << "\nEnter new data for car at index "
                          << idxs_swap[i] << ":\n";
                Car newCar;
                newCar.input_new_data();
                newC.push_back(newCar);
            }

            if (swap_by_indicies(cars, idxs_swap, newC))
                std::cout << "Replaced specified cars!\n";
        } else
            std::cout << "No indices to replace\n";
    }

    if (display_cars(cars) == false)
        std::exit(1);

    std::cout << "#5 How many cars you want to enter to second > ";
    fill_list(cars2);
    std::cout << "Second list: \n";
    if (display_cars(cars2) == false)
        std::exit(1);

    std::cout << "#6 Modify first: delete n after and merge with second\n";
    int startIdx, count;
    std::cout << "Enter starting index (0-based): ";
    std::cin >> startIdx;
    std::cout << "How many elements to remove after this index: ";
    std::cin >> count;
    std::cin.ignore();

    if (delete_n_after(cars, startIdx, count) == false)
        std::exit(1);
    std::cout << "\nAfter removing elements:\n";
    if (!display_cars(cars))
        std::exit(1);

    cars.insert(cars.end(), cars2.begin(), cars2.end());
    std::cout << "\nAfter merging:\n";
    if (!display_cars(cars))
        std::exit(1);

    std::cout << "#7 View both\n";
    std::cout << "First container after all modifications:\n";
    if (!display_cars(cars))
        std::exit(1);

    std::cout << "Second container after all modifications:\n";
    if (!display_cars(cars2))
        std::exit(1);

    return 0;
}
