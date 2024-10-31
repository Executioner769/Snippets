#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
	vector<int> parent, size;
public:
	DisjointSet(int N) {
		parent.resize(N+1);
		for (int i = 0; i < N+1; ++i) {
			parent[i] = i;
		}
		
		size.resize(N+1,1);
	}
	
	int findParent(int node) {
		if(parent[node] == node) return node;
		else return parent[node] = findParent(parent[node]);
	}
	
	void unionBySize(int n1, int n2) {
		int ult_pn1 = findParent(n1);
		int ult_pn2 = findParent(n2);
		
		if(ult_pn1 == ult_pn2) return;
		if(size[ult_pn1] < size[ult_pn2]) swap(ult_pn1,ult_pn2);
		if(size[ult_pn1] >= size[ult_pn2]) {
			parent[ult_pn2] = ult_pn1;
			size[ult_pn1] += size[ult_pn2];
		}
		return;
	}
	
};
