#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <cmath>

using std::cout;
using std::endl;

int multiply0(int, int);
int multiply1(int, int);
bool odd(int);
int half(int);

int main(void){
	int val1 {10};
	int val2 {3};
	std::string temp {""};

	cout << "n = " << val1 << " a = " << val2 << endl;
	cout << val1 << " * " << val2 << " = " << multiply0(val1,val2) << endl;
	cout << "Number of adds: " << val1 << " -> O(n)" << endl;
	cout << val1 << " * " << val2 << " = " << multiply1(val1,val2) << endl;
	temp = std::bitset<64>(val1).to_string();
	cout << "Number of adds: " << log2(val1) + std::count(temp.begin(), temp.end(), '1') - 1 << " -> O(log(n))" << endl;

	return 0;
}

int multiply0(int n, int a){
	if(n == 1) return a;
	return multiply0(n - 1, a) + a;
}

int multiply1(int n, int a){
	if(n == 1) return a;
	int result = multiply1(half(n), a + a);
	if(odd(n)) result = result + a;
	return result;
}

bool odd(int n){ return n & 0x1; }

int half(int n){ return n >> 1; }