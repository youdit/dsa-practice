// https://cp-algorithms.com/data_structures/fenwick.html#finding-sum-in-one-dimensional-array

#include<bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for(int i=0; i< a.size(); ++i) {
            add(i, a[i]);
        }
    }

    int sum(int r) {
        int res = 0;
        for(; r>=0 ; r = (r&r+1) - 1) {
            res += bit[r];
        }
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void add(int idx, int delta) {
        for(; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += delta;
        }
    }
};

int main(){

}