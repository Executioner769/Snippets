#include <bits/stdc++.h>
using namespace std;

// 1 based indexing implementation
// Supports point query and range update
class FenwickTree {
private:
	// Binary Indexed Tree
	vector<int> bit;
	int n;
public:
	FenwickTree(int n) {
		this->n = n + 1;
		bit.assign(n+1,0);
	}

	FenwickTree(vector<int> a): FenwickTree(a.size()) {
		for(size_t i = 0; i < a.size(); i++) {
			update(i, a[i]);
		}
	}

	void update(int idx, int delta) {
		while(idx < n) {
			bit[idx] += delta;
			idx += (idx & -idx);
		}
	}
	
	void update(int l, int r, int delta) {
		update(l,delta);
		update(r + 1,-delta);
	}

	int query(int idx) {
		int sum = 0;
		while(idx > 0) {
			sum += bit[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
};
