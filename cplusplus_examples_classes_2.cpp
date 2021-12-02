#include <iostream>

using namespace std;

class Person
{
	
	private: 
		string name;

	public:
		void setName(string n)
		{
			name = n;
		}
		
		string getName()
		{
			return name;	
		}	
};

class Car{
	private:
			string make;
			int year;
			Person owner;
	public:
		void addOwner(Person p)
		{
			owner = p;
		}
		void setMake(string m)
		{
			make = m;
		};
		void setYear(int y)
		{
			year = y;
		};
		string getMake()
		{
			return make;
		};
		int getYear()
		{
			return year;
		};
		void printCarInfo()
		{
			cout << "Car info" << endl;
			cout << "Make is " << make << endl;
			cout << "yearmodel is " << year << endl;
		};
		void printAllCarInfo()
		{
			cout << "Car info" << endl;
			cout << "Make is " << make << endl;
			cout << "yearmodel is " << year << endl;
			cout << "Owner is " << owner.getName() << endl;
		};
};



int main()
{
	Car car1;
	car1.setMake("Audi");
	car1.setYear(2020);
	car1.printCarInfo();

	Person p1;
	p1.setName("Staffan");
	cout << p1.getName() << endl;
	
	car1.addOwner(p1);
	car1.printAllCarInfo();
	
	
	return 0;
}
