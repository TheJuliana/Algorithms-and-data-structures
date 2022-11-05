#include <iostream>
#include <vector>
/*
№10 Сортировка слиянием
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

void copyMas(std::vector<int>& mas1, std::vector<int>& mas2) {
    if (mas2.empty()) {
        for (auto &i: mas1) {
            mas2.push_back(i);
        }
    } else {
        for (auto &i: mas1) {
            mas2[i] = i;
        }
    }
}

void mergeSort(std::vector<int>& mas, int l, int h) { //l-позиция первого эл-та в массиве, р-позиция последнего желмента в массиве
    if (h<=l) {
        return;
    }
    int m = l + (h-l)/2;//средний элемент
    mergeSort(mas, l, m);
    mergeSort(mas, m+1, h);

    std::vector<int> buf;
    copyMas(mas, buf);

    int i = l;
    int j = m + 1;
    for (int k = l; k <= h; k++) {
        if (i>m) {
            mas[k] = buf[j];
            j++;
        } else if (j>h) {
            mas[k] = buf[i];
            i++;
        } else if (buf[j]<buf[i]) {
            mas[k] = buf[j];
            j++;
        } else {
            mas[k] = buf[i];
            i++;
        }
    }
}
int main() {
    std::vector<int> mas;
    createMas(mas, 10);
    printMas(mas);
    mergeSort(mas, 0, mas.size()-1);
    printMas(mas);
    return 0;
}
