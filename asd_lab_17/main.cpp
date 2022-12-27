/*
№17 “Операции над БНП: поиск, добавление, удаление”
Дерево вводится в программу в формате линейно-скобочной записи.
 Затем появляется меню, в котором доступна операция добавления, удаления и поиска вершины БДП.
 После выполнения операции программа должна возвращаться снова в меню.
 При выходе их него до завершения программы на экран должно быть выведено БДН любым способом
 (в виде линейно-скобочной записи или в графической форме).
*/
#include <iostream>
#include <string>
#include <vector>

struct Node {
	int value;
	Node* left = nullptr, * right = nullptr;

	Node(int x) {
        value = x;
    }

public:
	//добавляем число в лево или право или делаем его корнем
	void addNode(int x) {
		if (value < x && right != nullptr) {
            right->addNode(x);
        }
		if (value < x && right == nullptr) {
            right = new Node(x);
        }
		if (value > x && left != nullptr) {
            left->addNode(x);
        }
		if (value > x && left == nullptr) {
            left = new Node(x);
        }
	}

	Node* find(int x) {
		//если корень подходящее число
		if (value == x) {
            return this;
        }
		//если число больше корня ищем справа
		if (value < x && right != nullptr) {
            return right->find(x);
        }
		//если число меньше корня ищем слева
		if (value > x && left != nullptr) {
            return left->find(x);
        }
		return nullptr;
	}
	//вставка слева или справа
	void TreeInsert(std::vector <int>& v) {
		v.push_back(value);
		if (left != nullptr) {
            left->TreeInsert(v);
        }
		if (right != nullptr) {
            right->TreeInsert(v);
        }
	}
	//если нашли нужное число удаляем его,если нет продолжаем идти по ветке,которой шли
	void TreeDelete(int x) {
		if (value < x && right != nullptr && right->value != x) {
            right->TreeDelete(x);
        }
		if (value < x && right != nullptr && right->value == x) {
            right = nullptr;
        }
		if (value > x && left != nullptr && left->value != x) {
            left->TreeDelete(x);
        }
		if (value > x && left != nullptr && left->value == x) {
            left = nullptr;
        }
	}

};

class BinaryTree {
	Node* root = nullptr;

public:
	//вывод в консоль последовательности
	void print() {
		std::string str = "";
		walk(root, str);
		int i = 0;
		//если встретили  подряд идущие ( ,) удаляем их
		while (i < str.size()) {
			if (str[i] == '(' && str[i + 1] == ',' && str[i + 2] == ')') {
                str.erase(i, 3);
            }
			i++;
		}
		std::cout << str << "\n";
	}

	void walk(Node* n, std::string& s) {
		if (!n) {
            return;
        }
		//загружаем корень
		s += std::to_string(n->value);
		//выводим скобоку и следующий предок слева
		s += '(';
		walk(n->left, s);
		//выводим запятую
		s += ',';
		//выводим следующий предок справа и скобку
		walk(n->right, s);
		s += ')';
	}
	//если корня нет,число становится корнем
	//иначе становится влево или вправо взависимости от самого числа
	void add(int x) {
		if (root == nullptr) {
            root = new Node(x);
        }
		else {
            root->addNode(x);
        }
	}

	void del(int x) {
		//ищем число ,если не нашли выводим ошибку
		Node* n = root->find(x);
		if (n == nullptr) {
			std::cout << "Not found " << x << std::endl;
			return;
		}
		//ищем слева и справа
		std::vector <int> v;
		if (n->left != nullptr) {
            n->left->TreeInsert(v);
        }
		if (n->right != nullptr) {
            n->right->TreeInsert(v);
        }
		//если число - корень
		if (n == root) {
            root = nullptr;
        } else {
            root->TreeDelete(x);
        }
		for (int i = 0; i < v.size(); i++) {
            add(v[i]);
        }
	}

	void find(int x) {
		if (root->find(x) == nullptr) {
            std::cout << "Not found " << x << std::endl;
        } else {
            std::cout << "Found " << x << std::endl;
        }
	}

};

int main() {
	std::string s;
	int x;
	BinaryTree tree;
	while (true) {
		std::cout << "Available commands: add 'x', del 'x', find 'x'.\nYour command: ";
		std::cin >> s >> x;
		if (s == "add") {
            tree.add(x);
        }
		else if (s == "del") {
            tree.del(x);
        }
		else if (s == "find") {
            tree.find(x);
        }
		else {
			std::cout << "Not avaible command\n";
			break;
		}
		tree.print();
	}
	tree.print();

	return 0;
}