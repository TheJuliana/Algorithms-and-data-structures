/*
№16 “Не рекурсивный прямой обход” (реализуется с помощью стека).
В качестве выходных данных формируется строка обхода. Например:
Бинарное дерево поиска
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

const std::string Numerals = { "1234567890" };

struct Node {
    int value;
    Node* left = nullptr, * right = nullptr;

    Node(std::string& s) {
        //записываем преобразованные числа
        value = getValue(s);
        //удаляем корень
        s.erase(0, cut(value));
        //расскрываем скобки
        if (s[0] == '(') {
            s = unbracket(s);
        }
        else {
            return;
        }
        //заполняем левый
        if (isDigit(s[0])) {
            left = new Node(s);
        }
        //заполняем правый
        if (s[0] == ',' && isDigit(s[1])) {
            //удаляем запятую
            s.erase(0, 1);
            right = new Node(s);
        }
    }

private:
    bool isDigit(char c) {//считывание строки
        return Numerals.find(c) != std::string::npos;
    }
    //считаем сколько корень содержит чисел в цифре ,чтобы удалить затем его
    int cut(int n) {
        int i = 0;
        if (n == 0) {
            return 1;
        }
        while (n > 0) {
            n /= 10;
            i++;
        }
        return i;
    }

    int getValue(std::string& s) { //записываем дерево
        int i = 0, tmp = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isDigit(s[i])) {
                //переводим числа из типо string в тип int
                tmp = tmp * 10 + int(s[i] - 48);
                if (!isDigit(s[i + 1])) {
                    return tmp;
                }
            }
        }
    }

    std::string unbracket(std::string s) {
        int brackets = 0;
        for (int i = 0; i < s.size(); i++) {
            //считаем кол-во открывающихся скобок
            if (s[i] == '(') {
                brackets++;
            }
            //считаем кол-во закрывающихся скобок
            if (s[i] == ')') {
                brackets--;
            }
            //удаляем парные скобки
            if (!brackets) {
                s.erase(0, 1);
                s.erase(i - 1, 1);
                return s;
            }
        }
        return s;
    }
};
class BinaryTree {
    Node* root = nullptr;//голова

public:
    BinaryTree(std::string s) {
        root = new Node(s);
    }

    void PreorderTreeWalk() { //выводим обход с помощью стека
        //обход в прямом порядке, при котором сначала выводится корень, а потом — значения левого и правого поддерева
        std::stack <Node*> stack;
        Node* tmp;
        stack.push(root);
        while (!stack.empty()) {
            tmp = stack.top();
            stack.pop();
            std::cout << tmp->value << ' ';
            if (tmp->left != nullptr) {
                stack.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                stack.push(tmp->right);
            }
        }
    }

};
int main() {
    std::string s = "8(3(1,6(4,7)),10(,14(13,)))";
    BinaryTree tree(s);
    tree.PreorderTreeWalk();

    return 0;
}