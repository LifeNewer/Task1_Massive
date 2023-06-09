﻿#include <iostream>
#include <locale.h>

//Напишите функцию, выполняющую действие в соответствии с вашим вариантом. Напишите
//функцию main, в которой примените вашу функцию для нескольких массивов :
// Для встроенных массивов, количество и значения элементов которых заданы при
//инициализации.Создайте несколько массивов, чтобы протестировать различные случаи.
// Для массива, размещённого в динамической памяти, количество элементов которого
//должно быть введено с клавиатуры, а значения элементов сгенерированы случайно


void rearrangeArray(int arr[], int size) {
    int i = 0;
    int j = size - 1;
    while (i < j) {
        // Пропускаем четные элементы с начала массива
        while (i < size && arr[i] % 2 == 0) {
            i++;
        }

        // Пропускаем нечетные элементы с конца массива
        while (j >= 0 && arr[j] % 2 != 0) {
            j--;
        }

        // Если индексы еще не пересеклись, меняем местами элементы
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int main() {
    // Пример с встроенными массивами
    setlocale(LC_ALL, "Russian");
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    rearrangeArray(arr1, size1);

    std::cout << "Преобразованный массив: ";
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Пример с динамическим массивом
    int size2;
    std::cout << "Введите количество элементов массива: ";
    std::cin >> size2;

    if (size2 <= 0) {
        std::cout << "Ошибка: введено некорректное значение размера массива." << std::endl;
        return 1; // Возвращаем ненулевой код, чтобы указать на ошибку
    }
    std::cin >> size2;

    int* arr2 = new int[size2];
    std::cout << "Сгенерированный массив: ";
    for (int i = 0; i < size2; i++) {
        arr2[i] = rand() % 100; // Генерация случайных чисел от 0 до 99
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    rearrangeArray(arr2, size2);

    std::cout << "Преобразованный массив: ";
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr2; // Освобождение памяти, выделенной под динамический массив

    return 0;
}
