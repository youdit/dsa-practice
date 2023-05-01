// https://cp-algorithms.com/data_structures/fenwick.html#finding-sum-in-one-dimensional-array

#include<bits/stdc++.h>
using namespace std;

class FenwickTree {

private:
    int n;
    vector<int> T;

public:

    FenwickTree(int n){
        this -> n = n;
        T.assign(n, 0);
    }

    FenwickTree(vector<int> &a) : FenwickTree(a.size()) {
        for(int i = 0; i < n; ++i) {
            add(i, a[i]);
        }
    }

    void add(int idx, int delta) {
        for(; idx < n; idx = idx | (idx + 1)) {
            T[idx] += delta;
        }
    }

    int sum(int r) {
        int res = 0;
        for(; r >=0 ; r = (r&(r+1)) - 1) {
            res += T[r];
        }
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    vector<int> fenwickVector(){
        return T;
    }
};


int main(){
    vector<int> A = {1,2,3,4,5,6,7,8};
    
    FenwickTree tree = FenwickTree(A);
    for(int x: tree.fenwickVector()) cout<<x<<" ";
    cout<<"\n";
}