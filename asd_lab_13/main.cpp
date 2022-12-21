/*
Дан текстовый файл с некоторым текстом на русском или английском языках произвольной длины (организовать чтение).
Выбрав некоторую хеш-функцию, создать хеш-таблицу с:
№13 “с наложением”
*/
// Надеюсь что я правильно поняла, что "с наложением" это просто разрешение коллизий методом открытой адресации
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
int N = 10;

struct HashElem {
    bool deleted; //поле deleted для последующего создания функции удаления
    //*т.к. в задании указано просто создать таблицу из файла, то функции вставки и удаления я не реализовывала
    int key;
    std::string data;

    HashElem(bool deleted = false, int key = 0, std::string data = "") : deleted(deleted), key(key), data(data) {} // конструктор

};

void PrintTable(std::vector<HashElem>& table) {
    for (auto i : table) {
        std::cout << "Key: " << i.key << " Word:" << i.data << std::endl;
    }
};

int CreateKey(std::string& a) { //хэш функция
    int k = 0;//используем метод деления для расчета ключа
    for (int i = 0; i < a.size(); i++) {
        k += (int)a[i]; // разбиваем строку на символы и с помощью кодировки сопоставлям ему числовой код
    }
    k = k % N; // делим это число на количество ячеек в таблице чтобы k был меньше N
    return k;
}
void CreateTable(std::vector<HashElem>& table) {  //хэш-таблица
    std::ifstream input; //входной файл
    std::ofstream output; //выходной файл
    std::string a; // слова
    for (int i = 0; i < N; i++) { // создаем пустую таблицу размером N
        table.emplace_back(HashElem(false,i,""));
    }
    PrintTable(table);
    std::cout << "------------" << std::endl;
    input.open("../input.txt");

    while (input >> a) { //считываем слова
        int k = CreateKey(a); //генерируем для них ключ с помощью хэш-функции
        if (table[k].data == ""){ //если есть место - заполняем ячейку в таблице словом
            table[k] = HashElem(false, k, a);
        } else if ((table[k].data != a) && (table[k].data != "")) { //если ячейка уже занята - коллизия -> используем метод открытой адресации
            while (table[k].data == "") {
                k++; // используем линейное пробирование, т.е присваиваем значение в следующей пустой ячейке
            }
            if (k < N) { //строгое равенство т.к. отсчет с 0
                table[k] = HashElem(false, k, a);
            } else { // если все последующие ячейки заняты - расширяем таблицу
                table.emplace_back(HashElem(false, k, a));
                N++;
            }
        } else if (table[k].data == a){
            std::cout << "!Dublicate " << "'"<< a << "'" << std::endl;
            //если ячейка заполнена таким же словом
        }
    }

    input.close();
    output.open("../output.txt");
    for (auto i : table) {
        output << "Key: " << i.key << " Word:" << i.data << "\n";
    }
}



int main() {
    std::vector<HashElem> table;
    CreateTable(table);
    PrintTable(table);
    return 0;
}
