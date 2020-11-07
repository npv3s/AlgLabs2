#include "user.hpp"

int main() {
    User first = User("Vasya", "Ivanov");
    User second = User("Ivan",
                       "Ivanovich",
                       "ivanivanich",
                       "ivanivanich@mail.ru",
                       "qwerty12345");
    first.print();
    second.print();
    return 0;
}
