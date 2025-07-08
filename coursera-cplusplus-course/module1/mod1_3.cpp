/******************************************************************************

Write a composition of views that describe the coordinates x of n grid points covering the interval [0,1].

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>

using namespace std; // É uma prática melhor evitar 'using namespace std;' em programas maiores.

int main()
{
    // here we map the values 0,1,..,n-1 to the the interval [a,b]
    auto a=0.;
    auto b=1.;
    auto n=11;

    auto rescale=[a,b,n](double x){
        return a + (b-a)*x/(n-1);
    };

    // composition of views 
    auto coord=views::iota(0,n)|views::transform(rescale);

    cout<<"coord=";
    ranges::for_each(coord, [](double x){cout << x << " ";});
    cout<<endl;

    return 0;
}