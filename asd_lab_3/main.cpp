//Лабораторная работа №3 "Задача о простых множителях"
//На вход дается одно число х, нужно вывести все числа от 1 до х, удовлетворяющие условию :
//3 ^ K * 5 ^ L * 7 ^ M = xi
//
//где K, L, M - натуральные числа или могут быть равны 0.

#include <iostream>
#include <cmath>
#include <vector>

int Medium(int a, int b, std::vector<int> & set) {
    return ((rand()*rand())%(b-a+1))+a; //32767*32767=1 073 676 289 - необходимое максимально возможное число, так как max n = 1 000 000
};

void QuickSort(int a, int b, std::vector<int> & set) {
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
    QuickSort(a, l, set);
    QuickSort(r, b, set);

};

void getNumbers(std::vector<int>& numbers) {
    int num; //входное число
    std::cout << "Enter number: " <<std::endl;
    std::cin >> num; //считывавем с консоли

    std::vector<int> factors = {3, 5, 7}; //множители
    std::vector<int> counters; //счетчики для множителей

    for (int factor : factors) {
        int num1 = num; //копируем число чтобы узнать количество каждого множителя
        int n = 0; //счетчик для текущего множителя
        while (num1 >= factor) { //находим количество каждого множителя в числе
            num1 /= factor;
            n++;
        }
        counters.push_back(n);//помещаем итоговое количество текущего множителя
    }

    for (int K = 0; K <= counters[0]; K++) //перебираем все варианты 3^K
    {
        for (int L = 0; L <= counters[1]; L++)//5^L
        {
            for (int M = 0; M <= counters[2]; M++)//7^M
            {
                int i = pow(factors[0], K)*pow(factors[1], L)*pow(factors[2], M); //3^K * 5^L * 7^M
                if (i <= num)//проверяем чтобы не выйти за границу num
                {
                    numbers.push_back(i); //помещаем полученные числа в итоговый массив
                }
            }
        }
    }

    QuickSort(0, numbers.size()-1, numbers); //сортируем итоговый массив для наглядности
};

void printMas(std::vector<int>& mas) { //функция для вывода массива в консоль
    std::cout<< "Sequence: " << std::endl;
    for (auto& i : mas) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> numbers;
    getNumbers(numbers);
    printMas(numbers);

	return 0;
}