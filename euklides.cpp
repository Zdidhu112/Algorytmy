#include <iostream>
using namespace std;

int NWD1 (int a, int b) {
	while(a != b) {
		if(a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
int NWD2 (int a, int b) {
	if (a == b) return a;
	if(a < b) {
		int c = a;
		a = b;
		b = c;
	}
	return NWD2(a - b, b);
}
int NWD3 (int a, int b) {
	int c;
	while(b > 0) {
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}
int NWD4 (int a, int b) {
	if(b == 0) return a;
	return NWD4(b, a % b);
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << NWD4(a, b) << '\n';
	return 0;
}