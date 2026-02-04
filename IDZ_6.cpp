#include <iostream>

int ipow(int base, int exp) {
    if (exp == 0) 
        return 1;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) 
            result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

bool isArmstrong(int n) {
    if (n <= 0) 
        return false;

    int num_copy = n;
    int count = 0;
    while (num_copy > 0) {
        count++;
        num_copy /= 10;
    }

    num_copy = n;
    int sum = 0;
    while (num_copy > 0) {
        int digit = num_copy % 10;
        sum += ipow(digit, count);
        num_copy /= 10;
    }

    return sum == n;
}

int main() {
    int k;
    std::cout << "Введите k (верхняя граница поиска): ";
    std::cin >> k;

    std::cout << "Числа Армстронга от 1 до " << k << ": ";
    bool found = false;
    for (int i = 1; i <= k; ++i) {
        if (isArmstrong(i)) {
            std::cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        std::cout << "нет";
    }
    std::cout << std::endl;

    return 0;
}
