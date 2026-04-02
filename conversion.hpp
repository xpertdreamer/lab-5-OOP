#ifndef CONVERSION_H_
#define CONVERSION_H_

#include <algorithm>
#include <cctype>
#include <cmath>
#include <stdexcept>
#include <string>

class Converter {
  private:
    const int precision = 6;

    std::string trim(const std::string &str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        if (first == std::string::npos)
            return "";
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, (last - first + 1));
    }

    void validate(const std::string &str, int base) {
        if (str.empty() == true)
            throw std::runtime_error("Not valid: the string is empy!");

        int dotCounter = 0;
        for (char c : str) {
            if (c == '.') {
                dotCounter++;
                if (dotCounter > 1)
                    throw std::runtime_error(
                        "Not valid: the string contains more than one dot!");
                continue;
            }

            int value = char_to_value(c);
            if (value >= base)
                throw std::runtime_error(
                    "Not valid: char '" + std::string(1, c) +
                    "' not acceptable for base " + std::to_string(base));
        }
    }

    int char_to_value(char c) {
        if (std::isdigit(c))
            return c - '0';
        if (c >= 'A' && c <= 'D')
            return c - 'A' + 10;
        if (c >= 'a' && c <= 'd')
            return c - 'a' + 10;
        throw std::runtime_error("Unknown symbol: " + std::string(1, c));
    }

    char value_to_char(int val) {
        return (val <= 9) ? val + '0' : val - 10 + 'A';
    }

  public:
    std::string convert(std::string input) {
        input = trim(input);
        validate(input, 3);

        size_t dotPos = input.find('.');
        std::string intPart =
            dotPos == std::string::npos ? input : input.substr(0, dotPos);
        std::string fracPart =
            dotPos == std::string::npos ? "" : input.substr(dotPos + 1);

        double decimal = 0;
        for (char c : intPart)
            decimal = decimal * 3 + char_to_value(c);
        for (size_t i = 0; i < fracPart.length(); i++)
            decimal += char_to_value(fracPart[i]) / std::pow(3, i + 1);

        long long intPartTriad = decimal;
        double fracPartTriad = decimal - intPartTriad;

        std::string res = "";
        if (intPartTriad == 0)
            res = "0";
        while (intPartTriad > 0) {
            res += value_to_char(intPartTriad % 14);
            intPartTriad /= 14;
        }

        std::reverse(res.begin(), res.end());

        if (fracPartTriad > 1e-9) {
            res += ".";
            for (int i = 0; i < precision; i++) {
                fracPartTriad *= 14;
                int digit = static_cast<int>(fracPartTriad);
                res += value_to_char(digit);
                fracPartTriad -= digit;
                if (fracPartTriad < 1e-9)
                    break;
            }
        }

        return res;
    }

    Converter() = default;
    ~Converter() = default;
};

#endif
