#include <iostream>

using namespace std;

void printSum(int a, int b)
{
	int s = a + b;
	cout << s << endl;
}

void printSum(int a, int b, int c)
{
	int s = a + b + c;
	cout << s << endl;
}

void printSum(double a, double b)
{
	float s = a + b;
	cout << s << endl;
}


int main()
{
	/*
	cout << "hello world" << "\n";  // endl
	cout << "Give your name" << endl;
	string name;
	cin >> name;
	cout << "Ok, your name is " << name << endl;
	
	int weight;
	cout << "give your weight" << endl;
	cin >> weight;
	cout << "your weight is " << weight << endl;
	
	int * p1 = new int(100); // pointer, malloc and calloc not needed
	cout << *p1 << endl;
	*/
	
	printSum(88,99);
	printSum(88,99, 100); // overloading
	printSum(2.5, 3.5);
	
	return 0;
}
