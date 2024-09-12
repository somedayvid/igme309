// Part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>

using namespace std;

template<class T>
void bubbleSort(T toSort[]) {
    bool didSwap;

    for (int i = 0; i < toSort.size() - 1; ++i) {
        didSwap = false;
        for (int j = 0; j < toSort.size() - 1; ++j) {
            if (toSort[i] > toSort[i + 1]) {
                swap(toSort[i], toSort[i + 1]);
                didSwap = true;
            }
        }
        if (!didSwap) {
            break;
        }
    }

}
template<class T>
void selectionSort(T toSort[]){
    for (int i = 0; i < toSort.size()  - 1; ++i)
    {
        int minNum = i;
        for (int j = i + 1; j < toSort.size(); ++j)
        {
            if (toSort[j] < toSort[minNum])
                minNum = j;
        }
        if (minNum != i)
            swap(toSort[minNum], toSort[i]);
    }
}
template<class T>
void insertionSort(T toSort[]) {
    for (int i = 1; i < n; ++i) {
        int key = toSort[i];
        int j = i - 1;

        while (j >= 0 && toSort[j] > key) {
            toSort[j + 1] = toSort[j];
            j = j - 1;
        }
        toSort[j + 1] = key;
    }
}
template<class T>
void mergeSort(T toSort[]) {

}
template<class T>
void quickSort(T toSort[]) {

}
//
//void printOut() {
//    cout << "[";
//    for (T thing : toSort) {
//        cout << thing << ", ";
//    }
//    cout << "]" << endl;
//}

int main()
{
    std::cout << "Hello World!\n";
}
