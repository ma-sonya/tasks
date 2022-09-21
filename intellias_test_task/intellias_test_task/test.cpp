/*#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    const int SIZE = 10;
    int MAS[SIZE] = { 1, 5, 3, 1, 1, 7, 5, 9, 3, 8 };
    std::vector <int> vec(MAS, MAS + SIZE);

    std::cout << "Before: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator <int>(std::cout, " "));
    std::cout << std::endl;

    std::vector <int> ::iterator it1 = vec.begin() + 2; // на третий элемент, к примеру.
    std::vector <int> ::iterator it2 = vec.end() - 1; // на последний.
    *it1 = *it2;

    std::cout << "After: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator <int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}*/