#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    setlocale(LC_ALL, "RU");
    int repetitions;
    int row;

    std::cout << "Введите количество строк:" << std::endl;
    std::cin >> row;
    std::cout << "Введите количество столбцов:" << std::endl;
    std::cin >> repetitions;

    int* numbers = new int[row * repetitions];
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << std::endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < repetitions; j++) {
            numbers[i * repetitions + j] = std::rand() % 6;
            std::cout << numbers[i * repetitions + j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;
    for (int i = 0; i < row * repetitions - 1; ++i) {
        if (numbers[i] == numbers[i + 1] && (i + 1) % repetitions != 0) {
            std::cout << numbers[i] << " " << numbers[i + 1] << std::endl;
        }
        else if ((i + 1) % repetitions == 0 && numbers[i] == numbers[i + repetitions]) {
            std::cout << numbers[i] << " " << numbers[i + repetitions] << std::endl;
        }
    }

    delete[] numbers;

    return 0;
}
