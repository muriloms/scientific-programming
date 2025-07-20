/******************************************************************************

    Declare an array p of 10 unique pointers to integers.

    Initialize this array p with a ranges::for_each algorithm so that each pointer points to int{1}.

    Declare a function f that takes as argument an array p of 10 unique pointers to integers, and adds 1 to each pointed int.

    Can you call this function with the array p previously declared? If not what should be changed?


*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <ranges>
#include <array>

using namespace std; // É uma prática melhor evitar 'using namespace std;' em programas maiores.

int main()
{
    //1
    auto p=array<unique_ptr<int>,10>{};

    //2
    ranges::for_each(p, [](unique_ptr<int>& q){
        q=make_unique<int>(1);
    });

    //3
    auto f=[](array<unique_ptr<int>,10> p){
        for(auto& i:p) *i += 1;
    };

    // 4. No because by default p is passed by copy, which is not possible for unique pointers.
    // A solution is to pass p by reference:
    //auto f=[](array<unique_ptr<int>, 10>& p){for(auto&& i:p) *i += 1};
         // Note the double && as i is a reference on a reference. Otherwise, shared pointers can be passed by value, as a copy.

    return 0;
}