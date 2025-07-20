/******************************************************************************

Define a vector of Person objects, and write a function ageOfOldest() which takes this vector as an argument, 
and returns the age of oldest individual.

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
    int age;

    Person(string n) : name(n) {}
    Person(string n, int a) : name(n), age(a) {}

    string getName() const { return name; }
    int getAge() const { return age; }
};

int ageOfOldest(const vector<Person>& persons)
{
    if(persons.empty()) return 0; // Se o vetor estiver vazio, retorna 0.

    auto maxAge=0;
    for(const auto& person:persons)
    {
        if(person.getAge() > maxAge)
        {
            maxAge = person.getAge();
        }
    }
    return maxAge;
}

int main()
{
   Person person1("Alice", 30);
   Person person2("Bob", 25);
   Person person3("Charlie", 35);

    vector<Person> persons = {person1, person2, person3};

    cout << "The age of the oldest person is: " 
            << ageOfOldest(persons) << " years." << endl;

    return 0;
}

// g++ -std=c++20 -o module1/mod1_7 module1/mod1_7.cpp