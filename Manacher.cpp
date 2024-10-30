#include <bits/stdc++.h>
using namespace std;


class Manacher {
private:
    string t;
    vector<int> p;

    void buildT(string s) {
        for(auto ch: s) {
            t += string("#") + ch;
        }
        t += "#";
    }

    void run() {
        int n = t.length();
        int l = 1, r = 1;
        p.resize(n,1); 
        for(int i = 1; i < n; i++) {
            if(i > r) {
                p[i] = max(1, min(r - i, p[l + r - i]));
            }
            while(i + p[i] < n and i - p[i] >= 0 and t[i + p[i]] == t[i - p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

public:
    Manacher(string s) {
        buildT(s);
        run();
    }

    int getLongest(int center, bool odd) {
        // For even case we consider the next idx;
        int pos = 2*center + 1 + (!odd); 
        // We sub 1 because of the #s we have added;
        return p[pos] - 1;
    }

    bool isPal(int l, int r) {
        // if current len between l and r is <= Longest at its center then true
        // if l and r have same parity then odd length else even
        if((r - l + 1) <= getLongest((l + (r-l)/2), l%2 == r%2))
            return 1;
        return 0;
    }

};