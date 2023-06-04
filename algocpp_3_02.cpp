#include <iostream>

void quick_sort(int* arr, int size) {
    if (size <= 1) 
    {
        return;
    }
    int pivot = arr[size / 2];
    int left = 0, right = size - 1;
    while (left <= right) 
    {
        while (arr[left] < pivot) 
        {
            ++left;
        }

        while (arr[right] > pivot) 
        {
            --right;
        }

        if (left <= right) 
        {
            std::swap(arr[left++], arr[right--]);
        }
    }

    quick_sort(arr, right + 1);
    quick_sort(arr + left, size - left);
}

void arrPrint(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    };
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    int arr[]{24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    int size = 0;
    size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Исходный массив: ";
    arrPrint(arr, size);
    quick_sort(arr, size);
    std::cout << "Отсортированный массив: ";
    arrPrint(arr, size);
    return 0;
}