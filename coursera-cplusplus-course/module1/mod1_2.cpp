/******************************************************************************

Write a composition of views which takes a view on the multiples of 18, filter those that are multiple of 27, 
and select the first 2 elements that verify this property.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>

using namespace std; // É uma prática melhor evitar 'using namespace std;' em programas maiores.

int main()
{
    auto multiplyBy18=[](int i){return 18*i;};
    auto isMultipleOf27=[](int i){return i%27==0;};

    auto multipleOf18= views::iota(1) | views::transform(multiplyBy18);

    cout<<"The first two multiples of 18 and 27 are:"<<endl;
    ranges::for_each(multipleOf18 | views::filter(isMultipleOf27) | views::take(2),
        [](int i){
            cout << i <<" ";
        } );
    cout<<endl;

    return 0;
}