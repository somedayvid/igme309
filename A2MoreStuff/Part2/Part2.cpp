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

void mergeSort(int toSort[]) {

}

void quickSort(int toSort[]) {

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
        //mergeSort();
        break;
    case 5:
        //quickSort();
        break;
    default:
        break;
    }
    printOut(myArray);

    

}
