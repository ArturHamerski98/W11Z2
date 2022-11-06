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
void quick_sort(int* tab, int left, int right)
{
    if (right <= left) return;

    int i = left - 1, j = right + 1,
        pivot = tab[(left + right) / 2]; 

    while (1)
    {
     
        while (pivot > tab[++i]);
        while (pivot < tab[--j]);
        if (i <= j)
      
            std::swap(tab[i], tab[j]);
        else
            break;
    }

    if (j > left)
        quick_sort(tab, left, j);
    if (i < right)
        quick_sort(tab, i, right);
}

int arr[12] = { 3,6,33,1,22,333,777,4,2,33,44,22 };


void mergeSort(int* tab, int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = tab[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = tab[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            tab[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            tab[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        tab[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        tab[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void heapSort(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapSort(arr, n, largest);
    }
}


int main()
{
    int arr[12] = { 3,6,33,1,22,333,777,4,2,33,44,22 };
    mergeSort(arr, 0,5, 11);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        std::cout << arr[i] << " ";

    }
}

