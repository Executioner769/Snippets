#include <bits/stdc++.h>
using namespace std;

// 1 based indexing implementation
// Supports point update and range query
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

	int query(int idx) {
		int sum = 0;
		while(idx > 0) {
			sum += bit[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}

	int query(int l, int r) {
		return query(r) - query(l-1);
	}

	int lower_bound(int value) {
		int sum = 0, int idx = 0;
		for(int i = log2(n); i >= 0; --i) {
			if(bit[idx + (1<<i)] + sum < value) {
				idx = idx + (1<<i);
				sum += bit[idx];
			}
		}
		return idx+1;
	}
};
