//answers are in the regions in comments
//some code examples need to be run
#include <iostream>

using namespace std;

//question 3
void callByValue(int variable) {
	variable++;
}
void callByReference(int& variable) {
	variable++;
}

//question 4
//function pointer
int add(int a, int b) {
	return a + b;
}

//function object
class AddThing {
public:
	int myNum = 10;
	int* myNumPtr = &myNum;
	int operator()(int a){
		return *myNumPtr += a;
	}
};

// A function that takes a function object or lambda and executes it
template <typename T>
void callingFunctionThing(T function, int a) {
	cout << "Result: " << function(a) << endl;
	
}

int main()
{
#pragma region QuestionOne
	//Explain the difference between a copy constructorand a copy - assignment operator. Give brief examples. (5)


	/*the copy constructor basically creates a copy of the stack and functions as it is named,
	*constructing a copy of the parameter using something like Stack<type>* myStack = new Stack<type>(*myOtherStack);
	*/

	//code segment: copy constructor
	//inline Stack<T>::Stack(const Stack& other) {
	//	size = other.size;
	//	capacity = other.capacity;
	//	heapArray = new T[capacity];

	//	//adding all the elements in the original array to the new one
	//	for (unsigned short i = 0; i < size; ++i) {
	//		heapArray[i] = other.heapArray[i];
	//	}
	//}

	/*The assignment operator utilizes the = sign like how you would normally set variables equal to other values
	* and does pretty much the same thing as variables do with the = sign by copying another class over one.
	* This differs from the copy constructor as this operator cannot be used to create a new class from and can only copy
	* over one that already exists.
	* 
	* the code between them are pretty much the same for copying the information from one to the other with the main
	* difference being in when they can be used as well as the code at the start of the assignment operator which has 
	* to manage memory when copy over the heaparray that already exists in the stack being copied over as well as 
	* making sure that you aren't trying to copy a stack over itself
	*/

	//you can see code-wise in my examples from my stack implementation that both populate themselves the same way with the difference being that
	//the assignment operator also has to manage memory it previously created with the only other big difference in code being the if statement
	//that just checks to see if the parameter being passed in is just itself in which case the rest of the code doesn't need to execute because
	//it already is itself

	//code segment: assignment operator
	//inline Stack<T> & Stack<T>::operator=(const Stack& other) {
	//	if (this == &other) {
	//		return *this;
	//	}

	//	if (heapArray != nullptr) {
	//		delete[] heapArray;
	//		heapArray = nullptr;
	//	}

	//	size = other.size;
	//	capacity = other.capacity;

	//	heapArray = new T[capacity];

	//	//adding all the elements in the original array to the new one
	//	for (unsigned short i = 0; i < size; ++i) {
	//		heapArray[i] = other.heapArray[i];
	//	}
	//	return *this;
	//}
#pragma endregion

#pragma region QuestionTwo
	//	What is const correctness, and when should you use it ? (5)

	/* Const correctness is I think kind of like ensuring that the variable in question will not under any circumstances be 
	* changed which from what I can find seems to come up a lot in if statements:
	* if(x = 100){ doThing(); }
	* as well as promising to the caller that the passed in variable will not be altered either 
	* in some of the other part I utilize const correctness in my class parameters such as the assignment operators such as:
	* Matrix& Matrix::operator*(const Matrix& other) 
	* using const in this situation ensures that we cant accidentally modify the parameter that is being passed in
	* and shouldnt even be modified in the first place
	*/
#pragma endregion

#pragma region QuestionThree
	cout << "QUESTION THREE CODE SHOWCASE" << endl;
//	Using functions, explain and demonstrate the difference between a call by value(pointer) and a call by reference. (10)
// 
// 	int a = 10;
//  void callByReference(int variable){
//		variable++;
//  }
//  cout << a;
// 
// 	will output only 10 because the a variable is not acutally modified in the function rather a copy
// 	of it is which only exists within the function thus when the function iterates a it would not be 
// 	reflected outside of the function
// 
// 	the call by reference would iterate the actual value even when adjusted inside of the function 
// 	because it knows the address of the variable and can adjust the variable in that way so when 
// 	we come out of the function b is iterated by 1
// 
// 	int b = 20;
// 	int bPtr = &b;
// 	void callByValue(int* variable){
//		variable++;	   
//	}
// 	cout << b;
// 	output: 21

	int a = 10;
	cout << "Before value function call: " << a << endl;
	callByValue(a);
	cout << "After value function call: " << a << endl;

	int b = 20;
	int* bPtr = &b;
	cout << "Before reference function call: " << b << std::endl;
	callByReference(*bPtr);
	cout << "After reference function call: " << b << std::endl;

#pragma endregion

#pragma region QuestionFour
	//	Explain and demonstrate the differences between function pointers and function objects in C++. (10)

	/* A function pointer is a pointer that stores the address of a function which can be used to call the functions that it points to
	* A function object is an object you can create inline that holds a function
	* I believe the major advantage to function objects is the fact that the classes can store data making them much more versatile
	* as operations can be performed using their functions which can then store changed data which can be utilized in a later call.
	*/

	//funcPtr should point to a function that has two int parameters and returns an int that function being "add"
	cout << endl << "QUESTION FOUR: " << endl;

	int (*funcPtr)(int, int) { add };
	cout << (*funcPtr)(20, 10) << endl;

	//function object
	AddThing add;

	callingFunctionThing(add, 5);
	callingFunctionThing(add, 10);

#pragma endregion

#pragma region QuestionFive
	//	How do you use lambda expressions in C++ ? (5)
	/* Lambda functions are good for creating inline functions for one specific purpose of the program that only 
	* needs to be used very few times or for one specific part. It operates sort of like a function object too but you still have to pass in variables
	* from the main program in order for it to be accessed
	* 
	* To use one you put in the variables from your program that you want it to have access to in the capture list ---> []
	* and then the parameters next --> (int x, int y) then declare the function like normal with {}
	*/
	cout << endl << "Question Five: " << endl;
	//lambda function
	int c = 10;
	auto yes = [c](int a, int b){
		cout << a + b + c;
	};
	yes(10, 10);

#pragma endregion
}

