#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
	vector<int> st;
	int n;
	
	void build_SegmentTree(vector<int>& a,int i, int tl, int tr) {
		if(tl == tr) {
			st[i] = a[tl];
		} else {
			int tm = tl + (tr - tl) / 2;
			build_SegmentTree(a, 2*i, tl, tm);
			build_SegmentTree(a, 2*i+1, tm+1, tr);
			st[i] = st[2*i] + st[2*i+1];
		}
	}
	
	void update(int i, int tl, int tr, int pos, int value) {
		if(tl == tr) {
			st[i] = value;
		} else {
			int tm = tl + (tr - tl) / 2;
			if(pos <= tm) {
				update(i*2, tl, tm, pos, value);
			} else {
				update(i*2+1, tm+1, tr, pos, value);
			}
			st[i] = st[2*i] + st[2*i+1];
		}
	}
	
	int query(int i, int tl, int tr, int l, int r) {
		if(l > r) {
			return 0;
		}
		
		if(l == tl && r == tr) {
			return st[i];
		}
		
		int tm = tl + (tr - tl) / 2;
		return query(2*i, tl, tm, l, max(r,tm)) + query(2*i+1, tm+1, tr, min(l,tm+1), r);
	}
	
public:
	SegmentTree(vector<int>& a) {
		int n = a.size();
		this->n = n;
		st.assign(4*n,0);
		build_SegmentTree(a,1,0,n-1);
	}
	
	void update(int pos, int value) {
		update(1,0,n-1,pos,value);
	}
	
	int query(int l, int r) {
		return query(1,0,n-1,l,r);
	}
};
