#include <iostream>

void selectionSort(int tab[], int size)
{
    int k;
    for (int i = 0; i < size; i++)
    {
        k = i;
        for (int j = i + 1; j < size; j++)
            if (tab[j] < tab[k])
                k = j;

        std::swap(tab[k], tab[i]);
    }
}

void bubbleSort(int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (tab[j] > tab[j + 1])
                std::swap(tab[j], tab[j + 1]);

        }
    }
}

void insertionSort(int tab[], int size)
{
    int temp, j;

    for (int i = 1; i < size; i++)
    {
        temp = tab[i];

        for (j = i - 1; j >= 0 && tab[j] > temp; j--)
            tab[j + 1] = tab[j];

        tab[j + 1] = temp;
    }
}

int arr[12] = { 3,6,33,1,22,333,777,4,2,33,44,22 };
int main()
{
    int arr[12] = { 3,6,33,1,22,333,777,4,2,33,44,22 };
    bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        std::cout << arr[i] << " ";

    }
}

