/*№15 “Рекурсивные обходы (прямой, центральный, концевой)”*/
#include <iostream>
#include <string>

const std::string Numerals = { "1234567890" };
//заполняем бинарное дерево
struct Node {
    int value;
    Node* left = nullptr, * right = nullptr; //левый и правый дочерние узлы
    Node(std::string& s) {
        //записываем преобразованные числа
        value = getValue(s);
        //удаляем корень
        s.erase(0, cut(value));
        if (s[0] == '(') {  //расскрываем скобки
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
    //считывание строки
    bool isDigit(char c) {
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
    //записываем дерево
    int getValue(std::string& s) {
        int i = 0, tmp = 0;
        for (int i = 0; i < s.size(); i++)
            if (isDigit(s[i])) {
                //переводим числа из типа string в тип int
                tmp = tmp * 10 + int(s[i] - 48);
                if (!isDigit(s[i + 1])) {
                    return tmp;
                }
            }
    }
    //удаляем открывающуюся скобку с закрывающейся
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
    Node* root = nullptr; //корень

public:
    BinaryTree(std::string s) {
        root = new Node(s);
    }

    void preorder() {
        PreorderTreeWalk(root);
        std::cout << std::endl;
    }
    void inorder() {
        InorderTreeWalk(root);
        std::cout << std::endl;
    }
    void postorder() {
        PostorderTreeWalk(root);
        std::cout << std::endl;
    }


    //обход в прямом порядке, при котором сначала выводится корень, а потом — значения левого и правого поддерева
    void PreorderTreeWalk(Node* n) {
        if (!n) {
            return;
        }
        std::cout << n->value << " ";
        PreorderTreeWalk(n->left);
        PreorderTreeWalk(n->right);
    }
    // центральное -сначала в левое поддерево потом в корень и в правое поддерево
    void InorderTreeWalk(Node* n) {
        if (!n) {
            return;
        }
        InorderTreeWalk(n->left);
        std::cout << n->value << " ";
        InorderTreeWalk(n->right);
    }
    //Обход в обратном порядке- первыми выводятся значения левого и правого поддерева, а уже затем — корня
    void PostorderTreeWalk(Node* n) {
        if (!n) {
            return;
        }
        PostorderTreeWalk(n->left);
        PostorderTreeWalk(n->right);
        std::cout << n->value << " ";
    }
};
int main() {
    std::string s = "8(3(1,6(4,7)),10(,14(13,)))";
    BinaryTree tree(s);
    tree.preorder();
    tree.inorder();
    tree.postorder();

    return 0;
}