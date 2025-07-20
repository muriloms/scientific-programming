/******************************************************************************

Let us have a vector "persons" of instances of the structure Person. Write a view which describe the persons whose age is less than 20.

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

    Person() : name(""), age(0) {} // Construtor padrão

    Person(string n) : name(n) {}
    Person(string n, int a) : name(n), age(a) {}

    string getName() const { return name; }
    int getAge() const { return age; }
};


int main()
{
   vector<Person> persons(3);
   persons[0] = Person("Alice", 18);
   persons[1] = Person("Bob", 22);
   persons[2] = Person("Charlie", 19);
   
   auto limit_age = 20;
   auto ageLimit = [limit_age](Person& p){return p.getAge() < limit_age;};

   // views::filter aplica a funcao ageLimit a cada elemento de persons, retornando apenas aqueles que satisfazem a condicao.
   auto my_view = persons | views::filter(ageLimit);

   auto myPrint = [](const Person p){cout << p.getName() << " is " << p.getAge() << " years old." << endl;};
   
   ranges::for_each(my_view, myPrint);
   
   return 0;
}

// g++ -std=c++20 -o module1/mod1_7 module1/mod1_7.cpp