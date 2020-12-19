#include <iostream>
#include <chrono>
#include <array>
#include <vector>
#include <random>

double vec_bech(void (*f)(std::vector<int>), std::vector<int> vec) {
    auto start = std::chrono::steady_clock::now();
    f(std::move(vec));
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();
}

int main() {
    std::array<unsigned, 5> array{};
    for (auto &i : array) {
        std::cin >> i;
    }

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    std::vector<int> vec;
    vec.reserve(100);
    for (int i = 0; i < 100; i++) {
        vec.push_back(dist(mt));
    }

    std::cout << "Вставка в начало (100 элементов): "
              << vec_bech([](std::vector<int> vec) {
                  vec.insert(vec.begin(), 1);
              }, vec) << "s\n";

    std::cout << "Расширение вектора до 1000 элементов: "
              << vec_bech([](std::vector<int> vec) {
                  vec.reserve(1000);
              }, vec) << "s\n";

    std::cout << "Вставка в начало (1000 элементов): "
              << vec_bech([](std::vector<int> vec) {
                  vec.insert(vec.begin(), 1);
              }, vec) << "s\n";

}