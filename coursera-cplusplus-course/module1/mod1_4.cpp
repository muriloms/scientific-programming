/******************************************************************************

Allocate a vector through a smart pointer. How do you invoke the push_back() and size() method for this vector?

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>

using namespace std; // É uma prática melhor evitar 'using namespace std;' em programas maiores.

int main()
{
    auto p=make_unique<vector<int>>(vector{1,2,3,4,5});
    p->push_back(6);
    cout << "vector size=" << p->size() << endl;

    // alternatively
    (*p).push_back(10);
    cout << "vector size=" << (*p).size() << endl; 

    return 0;
}