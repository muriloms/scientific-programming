/******************************************************************************

Consider a vector p of pointers on 2-element arrays, so that p[i] points to array {i, i+1}. 
Create a vector q of unique pointers so that each element of q points to a copy of the arrays pointed by each element of p.


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
    auto n=10; // choose a value for the vector size

    // declare a vector of pointers to 2-int arrays 
    auto p=vector<unique_ptr<array<int,2>>>(n);

    // Initialize p so that p[i] points to an array with components i and i+1
    for(int i=0; i<n; i++)
    {
        p[i]=make_unique<array<int,2>>( array<int,2>{i, i+1} );
    };

    // create q as a copy of p
    auto q=vector< unique_ptr< array<int,2> > >(n);
    for(int i=0; i<n; i++)
    {
        q[i]=make_unique<array<int,2>>( *(p[i]) );
    };  

    // modify p[1] 
    *(p[1])=array<int,2>{10,100};

    // check that q has not changed
    cout << "*(q[1]) = ("<< (*(q[1]))[0] <<","<< (*(q[1]))[1] <<")" << endl;
    // *(q[1]) = (1,2)

    // check that p has changed
    cout << "*(p[1]) = ("<< (*(p[1]))[0] <<","<< (*(p[1]))[1] <<")" << endl;
    // *(p[1]) = (10,100)

    return 0;
}