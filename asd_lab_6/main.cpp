#include <iostream>
#include <vector>
/*
№6 Сортировка посредством выбора
*/

void createMas(std::vector<int>& mas, int n) {
    for(int i = 0; i < n; i++) {
        mas.push_back(rand());
    }
}

void printMas(std::vector<int>& mas) {
    std::cout<< "Sequence: " << std::endl;
    for (auto& i : mas) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void selectionSort(std::vector<int>& mas) {
    for (int i = 0; i < mas.size()-1; i++) {
        int minI = i;
        for (int j = i + 1; j < mas.size(); j++) {
            if (mas[j]<mas[minI]) {
                minI = j;
            }
        }
        if (minI != i) {
            std::swap(mas[i], mas[minI]);
        }
    }
}
int main() {
    std::vector<int> mas;
    createMas(mas, 10);
    printMas(mas);
    selectionSort(mas);
    printMas(mas);
    return 0;
}
