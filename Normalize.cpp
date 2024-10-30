#include <bits/stdc++.h>
using namespace std;

void normalize(vector<int>& nums) {
	vector<int> cpy(nums.begin(),nums.end());
	sort(cpy.begin(),cpy.end());
	cpy.erase(unique(cpy.begin(),cpy.end()), cpy.end());
	for(int& num: nums) num = lower_bound(cpy.begin(),cpy.end(),num) - cpy.begin();
}
