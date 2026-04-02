#ifndef PERSON_H_
#define PERSON_H_

#include <stdexcept>
#include <string>

class Person {
  private:
    std::string lastname;
    std::string firstname;
    std::string middlename;
    int age;

  public:
    Person(const std::string &l, const std::string &f, const std::string &m,
           const int a)
        : lastname(l), firstname(f), middlename(m) {
        if (a < 0 || a > 120)
            throw std::range_error("Age must be at range from 0 to 120");
        age = a;
    }

    ~Person() = default;

    std::string get_lastname() const { return lastname; }
    std::string get_firstname() const { return firstname; }
    std::string get_middlename() const { return middlename; }
    int get_age() const { return age; }

    void set_lastname(const std::string &l) { lastname = l; }
    void set_firstname(const std::string &f) { firstname = f; }
    void set_middlename(const std::string &m) { middlename = m; }
    void set_age(const int a) {
        if (a < 0 || a > 120)
            throw std::range_error("Age must be at range from 0 to 120");
        age = a;
    }
};

#endif // PERSON_H_
