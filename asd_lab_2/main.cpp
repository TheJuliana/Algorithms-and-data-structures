/*
Лаба №2 "Задача об арифметическом выражении"
На вход подаётся математическое выражение. Элементы - числа. Операции - "+ - * /".
Также есть скобочки. Окончанием выражения служит "=".
Программа должна вывести результат выражения

Пример ввода:
2+7*(3/9)-5=

Замечание:
Программа также должна делать "проверку на дурака": нет деления на 0, все скобки стоят верно (см лабу №1) и т.п.
*/


#include <iostream>
#include <stack>
#include <string>

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <map>
#include <cctype>

bool Check(std::string& input) { //из лабы 1
    std::stack<char> brackets;
    std::string open{"({["};
    std::string close{")}]"};

    char c;
    bool err = false;

    //посимвольный просмотр строки слева на право
    for (auto i: input) {
        if (i != input.back()) { //Проверка деления на 0
            if (i == '/' && input[i+1] == '0') {
                err = true;
            }
        }

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
            if (brackets.empty()) {
                err = true;
            } else {
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
        return true;
    } else {
        return false;
    }
}



void ToRPN(std::string& input, std::string& output) {//преобразуем введенное выражение к виду обратной польской записи
    std::string functions{"+-*/"};
    std::string open{"({["};
    std::string close{")}]"};
    std::string numbers{"1234567890"};
    std::stack<char> stack;
    char end = '=';

    for (auto i: input) {
        if (i == end) {
            break;
        }
        int pos;
        pos = functions.find(i);
        //если считываемый символ - операция
        if (pos >= 0) {
            if (stack.empty()) {
                stack.push(i); //помещаем операцию в стек
            } else {
                if (stack.empty()) {break;}
                //while (!stack.empty()) { //операция на вершине стека приоритетнее или такого же уровня приоритета
                while ((stack.top()== functions[2]) || (stack.top() == functions[3])) { //операция на вершине стека приоритетнее или такого же уровня приоритета
                    output.push_back(stack.top());
                    stack.pop(); // выталкиваем верхний элемент стека в выходную строку
                    if (stack.empty()) {break;}
                }
                stack.push(i); //помещаем операцию в стек
            }
        }
        pos = open.find(i);
        //если считываемый символ - откр. скобка
        if (pos >= 0) {
            stack.push(i); //помещаем ее в стек
        }
        pos = close.find(i);
        //если считываемый символ - закр. скобка
        if (pos >= 0) {
            if (stack.empty()) {break;}
            while (open[pos] != stack.top()) { //До тех пор, пока верхним элементом стека не станет открывающая скобка, выталкиваем элементы из стека в выходную строку
                output.push_back(stack.top());
                stack.pop();
            }
            stack.pop();//При этом открывающая скобка удаляется из стека, но в выходную строку не добавляется
        }
        pos = numbers.find(i);
        //если символ - число
        if (pos>=0) {
            output.push_back(i);
        }
    }

    //Когда входная строка закончилась, выталкиваем все символы из стека в выходную строку
    while (!stack.empty()) {
        output.push_back(stack.top());
        stack.pop();
    }

    std::cout << "Reverse Polish notation: ";
    for (auto i: output) {
        std::cout << i;
    }
    std::cout << std::endl;
}

int Calculate(std::string& input) {
    std::stack<char> stack;
    std::string functions{"+-*/"};
    std::string numbers{"1234567890"};

    for (auto i: input) {
        int pos;
        pos = numbers.find(i);
        //если символ - число
        if (pos>=0) {
            stack.push(i);
        }
        pos = functions.find(i);
        //если символ - операция
        if (pos>=0) {
            if (pos == 0) {
               int num1 = stack.top()-48;
               stack.pop();
               int num2 = stack.top()-48;
               stack.pop();
                int num = num1+num2+48;
               stack.push((num));
            }
            if (pos == 1) {
                int num1 = stack.top()-48;
                stack.pop();
                int num2 = stack.top()-48;
                stack.pop();
                int num = num1*num2+48;
                stack.push((num));
            }
            if (pos == 2) {
                int num1 = stack.top()-48;
                stack.pop();
                int num2 = stack.top()-48;
                stack.pop();
                int num = num1*num2+48;
                stack.push((num));
            }
            if (pos == 3) {
                int num1 = stack.top()-48;
                stack.pop();
                int num2 = stack.top()-48;
                stack.pop();
                int num = num1/num2+48;
                stack.push((num));
            }
        }
    }
    int num = stack.top()-48;
    return num;
}


int main() {
    std::string input{"(1+2)*4+3="};
    std::string output;
    if (Check(input)){
        ToRPN(input, output);
        std::cout << "Result:" << Calculate(output) << std::endl;
    } else {
        std::cout << "Error: wrong input data" << std::endl;
    }
    return 0;
}
