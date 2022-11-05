
#include <iostream>
#include <vector>
/*
№5 Вставками
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

void insertionSort(std::vector<int>& mas) {
    for (int i = 2; i < mas.size(); i++) {
        int key = mas[i];
        int j = i;
        while ( j > 1 && mas[j-1]>key) {
            mas[j]=mas[j-1];
            j--;
        }
        mas[j] = key;
    }
}

int main() {
    std::vector<int> mas;
    createMas(mas, 10);
    printMas(mas);
    insertionSort(mas);
    printMas(mas);
    return 0;
}
