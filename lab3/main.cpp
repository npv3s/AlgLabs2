#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>

int main() {

    std::string str = "2 0 /";

    std::vector<std::string> equation;
    std::string word;
    for (auto x : str) {
        if (x == ' ') {
            equation.push_back(word);
            word = "";
        } else {
            word += x;
        }
    }
    equation.push_back(word);


    std::stack<float> stack;
    try {
        for (auto x : equation) {
            if ((x == "+") or
                (x == "-") or
                (x == "*") or
                (x == "/") or
                (x == "^")) {
                float op2 = stack.top();
                stack.pop();
                float op1 = stack.top();
                stack.pop();
                float answer;
                switch (x[0]) {
                    case '+':
                        answer = op1 + op2;
                        break;
                    case '-':
                        answer = op1 - op2;
                        break;
                    case '*':
                        answer = op1 * op2;
                        break;
                    case '/':
                        if (op2 == 0)
                            throw std::runtime_error("Деление на ноль");
                        answer = op1 / op2;
                        break;
                    case '^':
                        answer = std::pow(op1, op2);
                        break;
                }
                stack.push(answer);
            } else {
                stack.push(std::stoi(x));
            }
        }
    } catch (const std::runtime_error &error) {
        std::cout << "Выражение не может быть посчитано.\n"
                     "Ошибка: " << error.what() << std::endl;
        exit(1);
    } catch (...) {
        std::cout << "Выражение не может быть посчитано.\n"
                     "Неизвестная ошибка" << std::endl;
        exit(1);
    }

    std::cout << stack.top() << std::endl;

    return 0;
}
