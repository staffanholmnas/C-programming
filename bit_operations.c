#include <stdio.h>

// ***WILL NOT BE IN THE EXAM***

// bit operations
// bitwise and &, or |, xor ^ 
// shifting to the left << and to the right

int main()
{
	int a = 222; // 1101 1110
	int b = 157; // 1001 1101
	
	/*
	bitwise AND &
	
	11011110
	10011101
	--------
	10011100  => 156
	*/
	
	int c = a & b;
	printf("c is %d \n", c);
	
	/*
	bitwise OR |
	
	11011110
	10011101
	--------
	11011111 => 223
	*/
	
	c = a | b;
	printf("c is %d \n", c);
	
	/*
	bitwise XOR ^
	11011110
	10011101
	--------
	01000011 => 67
	
	*/
	
	c = a ^ b;
	printf("c is %d \n", c);
	
	// shifting
	/*
	shifting a two times to the left multiplies by 2 two times
	a is 11011110
	
	1101111000 2 zeroes are added to the right 
	1101111000 => 888 (2 * 2 * 222 = 888)
	*/
	
	c = a << 2; // shifting to the left multiplies by 2 the specified amount of times
	printf("c is %d \n", c);
	
	/*
	shift b 3 times to the right divides b with 2 three times
	b is 10011101
	00010011 remove 3 bits from the right, add 3 zeroes to the right
	00010011 => 19
	*/
	
	c = b >> 3; // shifting to the right divides by 2 the specified amount of times
	printf("c is %d \n", c);
	
	// check the state of state of some bit
	/*
	Principle:
	shift the bit queue to the right until the specific bit is the first bit (LSB, last significant bit)
	then take AND operation with value 1
	=> result of the operation is the state of the specific bit
	
	Example:
	11011110
	what is the state of the 6. bit?
	
	00000110 remove 5 from right, add zeroes to the left
	00000001
	--------
	00000000 => result is 0
	*/
	
	int position = 5;
	int state = (b >> position - 1) & 1;
	
	printf("State is %d \n", state);
	
	// Inverting a bit
	/*
	Principle:
	Create a mask that has value 1 in the right position,
	other bits are zeroes
	Take XOR with mask and original bit queue
	
	b is 10011101	invert the 6. bit
	mask is 1 << 5 => 00100000
	
	10011101
	00100000 XOR ^
	--------
	10111101 => result is 189
	*/
	
	position = 6;
	
	int mask = 1 << (position - 1);
	
	b = b ^ mask;
	
	printf("b is now %d \n", b);
	
	
	
	return 0;
}


