// Part2.cpp : inthis file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <vector>

void bubbleSort(int toSort[], int size) {
    bool didSwap;

    for (int i = 0; i < size - 1; ++i) {
        didSwap = false;
        for (int j = 0; j < size - 1; ++j) {
            if (toSort[i] > toSort[i + 1]) {
                std::swap(toSort[i], toSort[i + 1]);
                didSwap = true;
            }
        }
        if (!didSwap) {
            break;
        }
    }
}
void selectionSort(int toSort[]){
    for (int i = 0; i < sizeof(toSort) / sizeof(*toSort) - 1; ++i)
    {
        int minNum = i;
        for (int j = i + 1; j < sizeof(toSort) / sizeof(*toSort); ++j)
        {
            if (toSort[j] < toSort[minNum])
                minNum = j;
        }
        if (minNum != i)
            std::swap(toSort[minNum], toSort[i]);
    }
}
void insertionSort(int toSort[]) {
    for (int i = 1; i < sizeof(toSort) / sizeof(*toSort); ++i) {
        int key = toSort[i];
        int j = i - 1;

        while (j >= 0 && toSort[j] > key) {
            toSort[j + 1] = toSort[j];
            j = j - 1;
        }
        toSort[j + 1] = key;
    }
}
void merge(int toSort[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    std::vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = toSort[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = toSort[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            toSort[k] = L[i];
            i++;
        }
        else {
            toSort[k] = R[j];
            j++;
        }
        k++;
    }
}

void mergeSort(int toSort[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(toSort, left, mid);
    mergeSort(toSort, mid + 1, right);
    merge(toSort, left, mid, right);
}
void quickSort(int toSort[]) {

}

void printOut(int toSort[]) {
    std::cout << "[";
    for (int i = 0; i < 8; ++i) {
        std::cout << toSort[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    int array1[] = { 2,31,4,5,2,39,12,23 };
    int size =  sizeof(array1) / sizeof(*array1);
    //mergeSort(array1, 0, sizeof(array1) / sizeof(*array1) - 1);

    bubbleSort(array1, size);
    printOut(array1);

}
