/******************************************************************************

/*
We consider a 2D grid of size nx × ny, where nx is the number of columns (x-axis)
and ny is the number of rows (y-axis). Each cell in the grid has an associated value vij,
located at coordinates (i, j).

For efficiency reasons, the 2D data vij are often stored in memory as a 1D vector v.
The mapping from 2D coordinates (i, j) to the 1D vector index k is defined by the formula:

    k = i * nx + j

This means that v[k] corresponds to vij.

Write a stateful function f(i, j) that returns the index k. The function should use nx 
as an internal state to compute the 1D index.



*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <ranges>
#include <array>

using namespace std; // É uma prática melhor evitar 'using namespace std;' em programas maiores.

struct convert
{
    int nx{};
    int operator()(int i, int j) const
    {
        return i * nx + j;
    }
};

int main()
{
    auto nx = 5; // Número de colunas
    auto f=convert{nx};

    cout << "Index for (2, 3): " << f(2, 3) << endl; // Deve imprimir 13
    cout << "Index for (1, 4): " << f(1, 4) << endl; // Deve imprimir 9
    

    return 0;
}

// g++ -std=c++20 -o module1/mod1_7 module1/mod1_7.cpp