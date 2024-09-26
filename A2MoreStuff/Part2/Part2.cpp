// Part2.cpp : inthis file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(int toSort[], int size) {
    bool didSwap;

    do
    {
        didSwap = false;
        for (int i = 0; i < size - 1; ++i) {
            if (toSort[i] > toSort[i + 1]) {
                swap(toSort[i], toSort[i + 1]);
                didSwap = true;
            }
        }
    } while (didSwap);
}
void selectionSort(int toSort[]){
    int minIndex;

    for (int j = 0; j < 10; ++j) {
        minIndex = j;
        for (int i = j; i < 10; ++i) {
            if (toSort[i] < toSort[minIndex]) {
                minIndex = i;
            }
        }
        swap(toSort[j], toSort[minIndex]);
    }
}
void insertionSort(int toSort[]) {
    for (int i = 1; i < 10; ++i) {
        int currentIndex = i;
        while (toSort[currentIndex - 1] > toSort[currentIndex]) {
            swap(toSort[currentIndex - 1], toSort[currentIndex]);
            currentIndex--;
        }
    }
}

void merge(int toSort[], int start, int mid, int end) {
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    double *left = new double[n1];
    double *right = new double[n2];

    for (i = 0; i < n1; i++)
    {
        left[i] = toSort[start + i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = toSort[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            toSort[k] = left[i];
            i++;
        }
        else {
            toSort[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        toSort[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        toSort[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int toSort[], int start, int end) {
    if (start < end) {
        int midIndex = (start + end) / 2;

        mergeSort(toSort, start, midIndex);
        mergeSort(toSort, midIndex + 1, end);
        merge(toSort, start, midIndex, end);
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
}



void printOut(int toSort[]) {
    std::cout << "[";
    for (int i = 0; i < 10; ++i) {
        if (i == 9) {
            cout << toSort[i];
        }
        else {
            cout << toSort[i] << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int getSize(int toSort[]) {
    return sizeof(toSort) / sizeof(*toSort);
}



int main()
{
    int size = 10;
    int myArray[10] = { 100,20,304,55,60,1, 999,809, 9323,7 };
    
    cout << "Choose a sorting algorithm by inputting the corresponding number: " << endl << "1. Bubble Sort" << endl
        << "2. Selection Sort" << endl << "3. Insertion Sort" << endl << "4. Merge Sort" << endl << "5. Quick Sort" << endl;
    
    int input;
    cin >> input;

    switch (input)
    {
    case 1:
        bubbleSort(myArray,10);
        break;
    case 2:
        selectionSort(myArray);
        break;
    case 3:
        insertionSort(myArray);
        break;
    case 4:
        mergeSort(myArray, 0, 9);
        break;
    case 5:
        quicksort(myArray,0,9);
        break;
    default:
        break;
    }
    printOut(myArray);

    

}
