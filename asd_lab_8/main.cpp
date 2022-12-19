//№8 Поразрядная сортировка
#include <iostream>
#include <cmath>
#include <vector>

void createMas(std::vector<int>& mas, int n) { //создаем рандомный массив длиной n
    for(int i = 0; i < n; i++) {
        mas.push_back(rand());
    }
}

void printMas(std::vector<int>& mas) { //функция для печати массива
    std::cout<< "Sequence: " << std::endl;
    for (auto& i : mas) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int getMax(std::vector<int>& mas) { //получаем максимальное число из массива
    int max = mas[0];
    for (int i = 1; i < mas.size(); i++) {
        if (mas[i]>max) {
            max = mas[i];
        }
    }
    return max;
}

void CountSort(std::vector<int>& mas, int exp) {
    std::vector<int> output; //вспомогательный массив
    //Массив count будет подсчитывать количество чисел из массива, имеющих цифру «i» на их (exp)-м месте.
    std::vector<int> count;
    for (auto i : mas) { //делаем output размером как входной mas
        output.push_back(0);
    }
    for (int i = 0; i<10; i++) { //массив count будет размером 10 (т.к. цифр всего 10)
        count.push_back(0);
    }

    // Подсчитаем, сколько раз каждая цифра встречалась на (exp)-м месте в каждом вводе.
    for (int i = 0; i < mas.size(); i++) {
        count[(mas[i]/exp)%10]++;
    }

    //подсчитываем их суммарное количество
    for (int i = 1; i < 10; i++) {
        count[i]+=count[i-1];
    }
    //Распределяем исходные числа по этим спискам в зависимости от величины младшего разряда по возрастанию
    //Собираем числа в той последовательности, в которой они находятся после распределения
    //повторяем пункты выше для более страших разрядов
    for (int i = mas.size()-1; i >=0; i--) {
        output[count[(mas[i]/exp)%10]-1] = mas[i];
        count[(mas[i]/exp)%10]--;
    }
    //присваиваем результат исходному массиву
    for (int i = 0; i < mas.size(); i++) {
        mas[i] = output[i];
    }

}
void RadixSort(std::vector<int>& mas) {
    int exp, m;
    m = getMax(mas);
    //Вызов countSort() для цифры на (exp)-м месте в каждом вводе
    for (exp = 1; m/exp > 0; exp *=10) {
        CountSort(mas, exp);
    }

}
int main() {
    std::vector<int> mas;
    createMas(mas, 10);
    printMas(mas);
    RadixSort(mas);
    printMas(mas);
    return 0;
}
