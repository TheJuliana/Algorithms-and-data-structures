/*Реализовать сортировку и оцените ее сложность.
Вариант 2
Сортировка Шелла.*/

#include "functions.hpp"

//Сложность O(N²) - N² возникает при h=1

int main() {
    std::vector<int> seq;

    fn::createMas(seq, 20);
    fn::printMas(seq);

    Timer t1;
    fn::shellSort(seq);
    std::cout << "Time elapsed: " << t1.elapsed() << '\n';

    fn::printMas(seq);
    return 0;
}
