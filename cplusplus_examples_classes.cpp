#include <iostream>

using namespace std;

class Dot
{
	// attributes, properties
	private:
	int x;
	int y;
	
	// constructors
	public:
	Dot()
	{
		cout << "A dot is created!" << endl;
		x = 0;
		x = 0;
	}
	
	Dot(int xx, int yy) // constructor with initialization
	{
		x = xx;
		y = yy;
	}
	
	// methods, operations, functions, subroutines
	public:
	void setXY(int xx, int yy) // in-line methods
	{
		x = xx;
		y = yy;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	
	// declaration
	void printDot();	
};

// print (x, y)
void Dot::printDot()
{
	cout << "(" << x << "," << y << ")" << endl;
}

int main()
{
	Dot dot1; // default constructor is called
	dot1.setXY(5,6);
	
	cout << dot1.getX() << ", " << dot1.getY() << endl;
	
	dot1.printDot();
	
	Dot dot2(88,99);
	dot2.printDot();
	
	return 0;
}
