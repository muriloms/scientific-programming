/******************************************************************************

Without using ranges::reverse, use ranges::for_each and view::iota to reverse 
the order of the elements in a vector v.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>

// using namespace std; // É uma prática melhor evitar 'using namespace std;' em programas maiores.

int main()
{
    std::vector<int> v = {2, 4, 1, 6, 9, 0, 10};
    int l = v.size();

    // A lambda para trocar os elementos
    auto transpose = [&v, l](int i)
    {
        auto tmp = v[i];
        v[i] = v[l - 1 - i];
        v[l - 1 - i] = tmp;
    };

    // Gera uma sequência de índices da metade inicial do vetor (0, 1, 2)
    auto index = std::views::iota(0, l / 2);

    // Aplica a função 'transpose' para cada índice gerado
    std::ranges::for_each(index, transpose);

    std::cout << "v=";
    for(int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}