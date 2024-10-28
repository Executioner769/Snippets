#include <bits/stdc++.h>
using namespace std;

// Iterative Solution
long long power(long long x, int n) {
	if(x == 1) return 1;
	int pw = 1;
	while( n != 0) {
		if(n & 1) pw *= x;
		x *= x;
		n /= 2;
	}
	return pw;
}
