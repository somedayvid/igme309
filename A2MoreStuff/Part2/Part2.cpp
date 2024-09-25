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

void mergeSort(int toSort[]) {
    //left = tosort.size/2
    //right = tosort.size/2

    //if size > 1
    //    split

    //    compare(left,right)

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
