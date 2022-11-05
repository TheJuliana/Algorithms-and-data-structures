#include <iostream>
#include <vector>
/*
№9 Пирамидальная сортировка
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

//создание кучи
void heapify(std::vector<int>& mas, int n, int root) {
    int largest = root; // Инициализируем наибольший элемент как корень
    int l = 2*root+1;
    int r = 2*root+2;

    // Если левый дочерний элемент больше корня
    if (l<n && mas[l] > mas[largest]) {
        largest = l;
    }
    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r<n && mas[r] > mas[largest]) {
        largest = r;
    }
    // Если самый большой элемент не корень
    if (largest != root) {
        std::swap(mas[root], mas[largest]);
        heapify(mas, n, largest); // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
    }


}

//сортировка
void heapSort(std::vector<int>& mas, int n) {
    // Построение кучи (перегруппируем массив)
    for (int i = n/2-1; i >= 0; i--) {
        heapify(mas, n, i);
    }
    // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        std::swap(mas[0], mas[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(mas, i, 0);
    }
}
int main() {
    std::vector<int> mas;
    createMas(mas, 10);
    printMas(mas);
    heapSort(mas, mas.size());
    printMas(mas);
    return 0;
}
