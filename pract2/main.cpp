#include "student.hpp"

int main() {
    Student ivan = Student("Ivan",
                         "Ivanovich",
                         "ivanivanich",
                         "ivanivanich@mail.ru",
                         "qwerty12345",
                         2331,
                         true);
    ivan.print();
    return 0;
}
