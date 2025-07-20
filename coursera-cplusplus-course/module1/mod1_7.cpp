/******************************************************************************

Write a function that takes two objects of type Person and returns true if they have the same name, and false otherwise.


*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <ranges>
#include <array>

using namespace std; // É uma prática melhor evitar 'using namespace std;' em programas maiores.

struct Person{
    string name;
    Person(string n) : name(n) {}
    string getName() const { return name; }
};

bool haveSameName(Person p1, Person p2)
{
    return p1.getName() == p2.getName();
}

int main()
{
   Person person1("Alice");
   Person person2("Alice");

   std::cout << "Do person1 and person2 have the same name? "
                << (haveSameName(person1, person2) ? "Yes" : "No") << std::endl;

    return 0;
}

// g++ -std=c++20 -o module1/mod1_7 module1/mod1_7.cpp