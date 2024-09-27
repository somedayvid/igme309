// Part2.cpp : inthis file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// Compares values and swaps lower values to the left as it goes down the array 
/// </summary>
/// <param name="toSort">The array to sort</param>
/// <param name="size">Size of array</param>
void bubbleSort(int toSort[], int size) {
    bool didSwap;

    do
    {
        didSwap = false;
        for (int i = 0; i < size - 1; ++i) {
            if (toSort[i] > toSort[i + 1]) {
                swap(toSort[i], toSort[i + 1]);
                didSwap = true; //if the loop did not swap any elements the array is in order
            }
        }
    } while (didSwap);
}

/// <summary>
/// Orders an by choosing the smallest value from the unsorted part of the list and moving it to the sorted part
/// </summary>
/// <param name="toSort">Array to Sort</param>
void selectionSort(int toSort[], int size){
    int minIndex;

    for (int j = 0; j < size; ++j) {
        minIndex = j;
        for (int i = j; i < size; ++i) {
            if (toSort[i] < toSort[minIndex]) {
                minIndex = i;
            }
        }
        swap(toSort[j], toSort[minIndex]);
    }
}

/// <summary>
/// Orders an array by comparing values to the ones they are next to in the unsorted part of the array and swapping
/// </summary>
/// <param name="toSort">Array to Sort</param>
/// <param name="size">Size of array</param>
void insertionSort(int toSort[], int size) {
    for (int i = 1; i < size; ++i) {
        int currentIndex = i;
        while (toSort[currentIndex - 1] > toSort[currentIndex]) {
            swap(toSort[currentIndex - 1], toSort[currentIndex]);
            currentIndex--;
        }
    }
}

/// <summary>
/// Merges all of the subarrays back by comparing them and merging them
/// </summary>
/// <param name="toSort">Array to Sort</param>
/// <param name="start">First element in array</param>
/// <param name="mid">Middle element in array</param>
/// <param name="end">Last element in array</param>
void merge(int toSort[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    
    //holds temporary information
    double *left = new double[n1];
    double *right = new double[n2];

    for (int i = 0; i < n1; ++i)
    {
        left[i] = toSort[start + i];
    }
    for (int j = 0; j < n2; ++j)
    {
        right[j] = toSort[mid + 1 + j];
    }

    int x = 0;
    int y = 0;
    int z = start;

    //comparing values and merging them
    while (x < n1 && y < n2) {
        if (left[x] <= right[y]) {
            toSort[z] = left[x];
            x++;
        }
        else {
            toSort[z] = right[y];
            y++;
        }
        z++;
    }

    //gets the rest of the elements
    while (x < n1) {
        toSort[z] = left[x];
        x++;
        z++;
    }

    while (y < n2) {
        toSort[z] = right[y];
        y++;
        z++;
    }
}

/// <summary>
/// Orders the array by splitting the main array all the way into 1 space subarrays and them ordering them
/// by comparing and remerging them
/// </summary>
/// <param name="toSort">Array to sort</param>
/// <param name="start">First element in the array to be sorted</param>
/// <param name="end">Last element in the array to be sorted</param>
void mergeSort(int toSort[], int start, int end) {
    if (start < end) {
        int midIndex = (start + end) / 2;

        //reucursively splitting the array into subarrays first from 
        //the two parts of the front half and back half and then
        //continuing from there
        mergeSort(toSort, start, midIndex);
        mergeSort(toSort, midIndex + 1, end);
        merge(toSort, start, midIndex, end);
    }
}

/// <summary>
/// Sorts the elements in the partition so that the all the smaller elements than the pivot are on the left
/// while the larger ones are on the right and then swaps the pivot with the middle element
/// </summary>
/// <param name="array"></param>
/// <param name="low"></param>
/// <param name="high"></param>
/// <returns></returns>
int partition(int toSort[], int start, int end) {
    int pivot = toSort[end];
    int i = start - 1;

    //checking and swapping elements
    for (int j = start; j < end; ++j) {
        if (toSort[j] <= pivot) {
            ++i;
            swap(toSort[i], toSort[j]);
        }
    }

    //swap pivot 
    swap(toSort[i + 1], toSort[end]);
    return i + 1;
}

/// <summary>
/// Calls quickSort algorithm which recursively sorts an array by comparing elements
/// to a pivot and sorting them accordingly by size
/// </summary>
/// <param name="array">Array to Sort</param>
/// <param name="low">First</param>
/// <param name="high"></param>
void quicksort(int array[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(array, start, end);
        quicksort(array, start, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, end);
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
    
    cout << "Array to be sorted: " << endl;

    for (int i = 0; i < 10; ++i) {
        cout << myArray[i] << " ";
    }

    cout << endl << endl;

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
        selectionSort(myArray, 10);
        break;
    case 3:
        insertionSort(myArray, 10);
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
