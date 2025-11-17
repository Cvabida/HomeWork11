#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() 
{
    setlocale(LC_CTYPE, "RUS");
    int n;

    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ошибка: размер массива должен быть положительным\n");
        return 1;
    }

    // Выделение памяти под массив
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    // Ввод элементов массива
    printf("Введите %d целых чисел (положительных и отрицательных):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Вывод исходного массива
    printf("\nИсходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Поиск первого положительного элемента
    int first_positive = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            first_positive = i;
            break;
        }
    }

    // Поиск последнего положительного элемента
    int last_positive = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            last_positive = i;
            break;
        }
    }

    // Проверка наличия положительных элементов
    if (first_positive == -1 || last_positive == -1) {
        printf("В массиве нет положительных элементов\n");
        free(arr);
        return 0;
    }

    // Проверка, что между первым и последним положительными есть элементы
    if (first_positive >= last_positive) {
        printf("Между первым и последним положительными элементами нет других элементов\n");
        free(arr);
        return 0;
    }

    // Вычисление суммы элементов между первым и последним положительными
    int sum = 0;
    printf("Элементы между первым и последним положительными: ");
    for (int i = first_positive + 1; i < last_positive; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];
    }
    printf("\n");

    // Вывод результатов
    printf("Первый положительный элемент: arr[%d] = %d\n", first_positive, arr[first_positive]);
    printf("Последний положительный элемент: arr[%d] = %d\n", last_positive, arr[last_positive]);
    printf("Сумма элементов между ними: %d\n", sum);

    // Освобождение памяти
    free(arr);

    return 0;
}