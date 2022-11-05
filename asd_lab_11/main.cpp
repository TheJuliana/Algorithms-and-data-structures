#include <iostream>
#include <vector>
/*
№11 Быстрая сортировка
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

int Medium(int a, int b, std::vector<int> & set) {
        return ((rand()*rand())%(b-a+1))+a; //32767*32767=1 073 676 289 - необходимое максимально возможное число, так как max n = 1 000 000
    };

void quickSort(int a, int b, std::vector<int> & set) {
        if (a>=b) {return;}
        int m = Medium(a, b, set);
        int k = set[m];
        int l = a-1;
        int r = b+1;
        while(true) {
            do {l++;} while (set[l]<k) ;
            do {r--;} while (set[r]>k) ;
            if (l>=r) {break;}
            std::swap(set[l], set[r]);
        }
        r = l;
        l = l-1;
        quickSort(a, l, set);
        quickSort(r, b, set);
    };

int main() {
    std::vector<int> mas;
    createMas(mas, 10);
    printMas(mas);
    quickSort(0, mas.size()-1, mas);
    printMas(mas);
    return 0;
}
