/*
Лаба №1 "Задача о скобках"
На вход подаётся строка, состоящая из скобок.
Программа должна определить правильность введённого скобочного выражения.
Савкин сказал, что программа должна работать на русском языке:
"Введите строку", "Строка не существует", "Строка существует" и т.п.
*/

#include <iostream>
#include <stack>
#include <string>

int main() {
    setlocale(LC_ALL, "rus");
    std::stack<char> brackets;

    std::string open{"({["};
    std::string close{")}]"};
    std::string input;
    char c;
    bool err = false;

    std::cout << "Введите строку: " << std::endl;
    std::getline(std::cin, input);

    //посимвольный просмотр строки слева на право
    for (auto i: input) {
        int pos;
        pos = open.find(i);

        //Если скобка открывающаяся -> на вершину стека
        if (pos >= 0) {
            brackets.push(i);
        }
        pos = close.find(i);

        //Если скобка закрывающаяся:
        if (pos >= 0) {
            //если стек пуст -> выражение неверное
            if (brackets.empty()) { err = true; }
            else {
                //иначе если соответствует открывающейся -> снимаем ее со стека
                c = brackets.top();
                brackets.pop();
                //если не соответствует -> выражение неверное
                if (pos != open.find(c)) {
                    err = true;;
                }
            }
            //если выражение неверное -> досрочное закрытие
            if (err) {
                break;
            }
        }
    }
    //результат
    if (!err){
        std::cout << "Строка существует" << std::endl;
    } else {
        std::cout << "Строка не существует" << std::endl;
    }

    return 0;
}
