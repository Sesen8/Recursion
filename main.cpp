#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::cerr;
using std::stringstream ;
using std::string;
using std::ostream;

unsigned long long int Fibonacci(unsigned int n);
void PrintReverseString(const string& str, ostream& output = cout);
// You may change the parameters of these functions
size_t MinimumPosition(const int array[], size_t size, size_t index=0, size_t min=0);
void SelectionSort(int array[], size_t size, size_t index=0);


int main() {
	const size_t ELEMENTS = 7;
	const size_t TESTS = 3;
	int data[][ELEMENTS] = {
			{7, 5, 4, 1, 3, 0, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{8, 5, 4, 1, 3, 4, 0}};

	int minimumSolutions[] = {5, 0, 6};
	int sortedArrays[][7] = {
			{0, 1, 3, 4, 5, 7, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{0, 1, 3, 4, 4, 5, 8}};

	unsigned long long int fibonacciSequence[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

	string strings[] = {"hello", "aardvark", "reviver"};
	string reverses[] = {"olleh", "kravdraa", "reviver"};
	size_t passed = 0;
	int minimumResponses[TESTS];
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = -1;
	}

	cout << "Testing Fibonacci" << endl;
	for (int i = 0; i < 10; ++i) {
		unsigned long long int fibonacci = Fibonacci(i);
		if (fibonacci == fibonacciSequence[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}


	cout << "Testing Minimum Position Finding" << endl;
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = MinimumPosition(data[i], ELEMENTS);
		if (minimumResponses[i] == minimumSolutions[i]){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Sorting" << endl;
	bool equal;
	for (int i = 0; i < TESTS; ++i) {
		SelectionSort(data[i], ELEMENTS);
		equal = true;
		for (int j = 0; j < ELEMENTS; ++j) {
			if (data[i][j] != sortedArrays[i][j]){
				equal = false;
				cerr << "Test " << i << " position " << j << " values: ";
				cerr << data[i][j] << " " << sortedArrays[i][j] << endl;
				break;
			}
		}
		if (equal){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Reverse Strings" << endl;
	stringstream out;
	for (int i = 0; i < TESTS; ++i) {
		out.clear();
		out.str("") ;
		PrintReverseString(strings[i], out);
		if (out.str() == reverses[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}

	return 0;
}

unsigned long long int Fibonacci(unsigned int n){
    if(n==0 || n==1){
        return n;
    }
    else{
        //calling on itself
        return Fibonacci(n-1) + Fibonacci(n-2);
    }

}
void PrintReverseString(const string& str, ostream& output){
    if(str.empty()){
        output << "";
    }
    else if(str.length()==1){
        output << str;
    }
    else{
        // calling on itself
        string newstr = str.substr(1,(str.length()-1));
        PrintReverseString(newstr,output);
        output << str.at(0);
    }
}
// You may change the parameters of these functions
//need to add index and minimum position
//initialize index and minimum position to 0 in definition
size_t MinimumPosition(const int array[], size_t size, size_t index, size_t min){
	if(index >= size){
        return min;
    }
    if(array[index] < array[min]){
        return MinimumPosition(array,size,index+1,index);
    }
    else{
        //calling on itself
        return MinimumPosition(array,size,index+1,min);
    }
}

//need to add index
//initialize index to 0 in definition
void SelectionSort(int array[], size_t size, size_t index){
    if(index >= size){
        return;
    }
    size_t min = MinimumPosition(array,size,index,index);
    if(index!=min){
        int tmpPos = array[index];
        array[index]=array[min];
        array[min]=tmpPos;
    }
    //calling on itself
    SelectionSort(array,size,index+1);

}
