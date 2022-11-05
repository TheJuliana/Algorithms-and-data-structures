#include <iostream>
#include <vector>
/*
№4 Сортировка методом прочесывания
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

void comb(std::vector<int> &data) // data — название вектора  (передаём по ссылке, чтобы вызов comb(array) менял вектор array)
{
    double factor = 1.2473309; // фактор уменьшения
    int step = data.size() - 1; // шаг сортировки

    //Последняя итерация цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
    while (step >= 1)
    {
        for (int i = 0; i + step < data.size(); i++)
        {
            if (data[i] > data[i + step])
            {
                std::swap(data[i], data[i + step]);
            }
        }
        step /= factor;
    }
}

int main() {
    std::vector<int> mas;
    createMas(mas, 10);
    printMas(mas);
    comb(mas);
    printMas(mas);
    return 0;
}
