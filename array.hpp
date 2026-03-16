#ifndef ARRAY_H_
#define ARRAY_H_

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T, size_t N> class Array {
  private:
    T data[N];
    size_t currentSize;

  public:
    /*
     * There are two different constructors
     * One for non argument
     * The last one is copy constructor
     */
    Array() : currentSize(N) {
        for (size_t i = 0; i < N; i++)
            data[i] = T();
    }

    Array(const Array &other) : currentSize(other.currentSize) {
        if (other.currentSize != currentSize)
            throw std::invalid_argument("Other array has incompetible size");
        for (size_t i = 0; i < N; i++)
            data[i] = other.data[i];
    }

    void set_size(size_t newSize) {
        if (newSize > N)
            throw std::invalid_argument("Size too large");
        currentSize = newSize;
    }

    /*
     * Operators overload
     */
    T &operator[](int index) {
        if (index < 0 || index >= N)
            throw std::out_of_range("Index might be from 0 to " +
                                    std::to_string(N - 1));
        return data[index];
    }

    const T &operator[](int index) const {
        if (index < 0 || index >= N)
            throw std::out_of_range("Index might be from 0 to " +
                                    std::to_string(N - 1));
        return data[index];
    }

    Array operator/(const Array &other) const {
        if (currentSize != other.currentSize)
            throw std::invalid_argument("Arrays must have same size");

        Array result;
        for (size_t i = 0; i < N; i++) {
            if (other.data[i] == T())
                throw std::invalid_argument("Division by zero at " +
                                            std::to_string(i));
            result.data[i] = data[i] / other.data[i];
        }
        return result;
    }

    Array operator+(const Array &other) const {
        if (currentSize != other.currentSize)
            throw std::invalid_argument("Arrays must have same size");

        Array res;
        for (size_t i = 0; i < N; i++)
            res.data[i] = data[i] + other.data[i];

        return res;
    }

    /*
      Getter for size
    */
    const size_t get_size() const { return N; }

    void print() const {
        std::cout << "[ ";
        for (size_t i = 0; i < currentSize; i++) {
            std::cout << data[i];
            std::cout << (i < currentSize - 1 ? ", " : " ");
        }
        std::cout << " ]" << std::endl;
    }
};

#endif // ARRAY_H_
