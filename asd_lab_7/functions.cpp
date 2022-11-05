#include "functions.hpp"
namespace fn {
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

    void shellSort(std::vector<int>& mas) {
        int h=1;
        while (h<(mas.size()/d)) {
            h=3*h+1;
        }
        while (h>0) {
            for (int k=0; k < h; k++) {
                int i=k+h;
                while (i <= mas.size()) {
                    int y=mas[i];
                    int j=i-h;
                    while (j>0 && mas[j]>y) {
                        mas[j+h] = mas[j];
                        j=j-h;
                    }
                    mas[j+h]=y;
                    i=i+h;
                }
            }
            h=(int)(h/3);
        }
    }

}