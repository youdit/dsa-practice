# FENWICK TREE

## Introduction

Fenwick tree is a data structure which:
* calculate the value of function $f$ int the given range $[l, r]$ in $O(long N)$ time.
* updates the value of an element of A in $O(log N)$ time.
* requires $O(N)$ memory for the operation and storage.
* Easily extensible to multidimensional arrays.

*It is generally used for performing the Sum queries on the array*

The Mathematical represenatation of the fenwick tree for sum 

Let there be an array $A[0...N-1]$ , fenwick three is an arrya $T[0..N-1]$, where each element of the array $T$ is sum of element of of $A$ in range $[g(i), i]$

## $T_{i} = \sum_{j=g(i)}^i A_{j}$

where $g$ is some function satisfying $0\leq g(i) \leq i$

The function $g(i)$ can be define as the the function replacing all tailing $1s$ with $0s$ in binary representation.
### $g(i) = i \& (i+1)$

### So the implementation for finding the sum of the in range $[0,l]$ is as follow

```cpp
int g(int l) {
    return l&(l+1);
}

int sum(int l) {
    int res = 0;
    while( l >= 0) {
        res += T[l];
        l = g(l) - 1;
    }
}
```
It can be simplified to 

```cpp
int sum(int l) {
    int res = 0;
    while( l >= 0) {
        res += T[l];
        l = (l&(l+1)) - 1;
    }
}
```

### Working of the update query in the Fenwick tree

For increasing the the value of some index in the fenwick tree we have to add the

for a given $i$ we have to find all the $j$ such that $g(j) \leq i \leq j$ which will give us the list of all the $T[j]$ such that it will have $A[i]$ in its sum so we have to add the $delta$ to all the $T[j]$

how to find all the $j$ such that $g(j) \leq i \leq j$

we will start by $i$ and flip the last unset bit, call that operation $h(i)$ and use this $j=h(i)$ to find the next value till $n \leq j$ 

so since we have to flip the last unset bit it can be done by using the formula

### $ h(i) = i || (i+1)$

so the sudo code to updating the index $i$ by adding the value $delta$

```cpp
void add (int index, int delta) {
    while(index < n) {
        T[index] += delta;
        index = index | (index + 1);
    }
}
```


### Code For Implementing the Fenwick Tree For the Sum Query $[l,r]$

```cpp
vector<int> T;
int n;

void initialize(vector<int> A) {
    n = A.size();
    T.assign(n,0);
    for(int i=0; i<n; ++i ) {
        add(i, A[i]);
    }
}

int sum(int r) {
    int res = 0;
    while( r >=0 ){
        res += T[r];
        r = (r&(r + 1)) -1;
    }
    return res;
}

int sum(int l, int r) {
    return sum(r) - sum(l-1);
}

void add(int index, int delta) {
    while( index < n) {
        T[index] += delta;
        index = index | (index + 1);
    }
}
```

The Time Complexity of finding the sum id $O(log N)$.

The Time Complexity of updating the index value is $O(log N)$.

The Time Complexity of Initializing the FenwickTree is $O(Nlog N)$.

### lets generalize this code for any function ```function(int a, int b)``` instead of just Sum

Since not all function we can't find the query of $[l,r]$, so we will generalize it for $[0,l]$ only

```cpp
vector<int> T;
int n;

int function(int a, int b){
    // Some function like min, max
}

void initialize(vector<int> A) {
    n = A.size();
    T.assign(n,0);
    for(int i=0; i<n; ++i ) {
        update(i, A[i]);
    }
}

int query(int r) {
    int res = 0;
    while( r >=0 ){
        res = function(res, T[r]);
        r = (r&(r + 1)) -1;
    }
    return res;
}

void update(int index, int delta) {
    while( index < n) {
        T[index] = function(T[index], delta);
        index = index | (index + 1);
    }
}
```

## Finding Sum in 2-D array

```cpp
vector<vector<int>> bit;
int n, m;

// init(...) { ... }

int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += bit[i][j];
    return ret;
}

void add(int x, int y, int delta) {
    for (int i = x; i < n; i = i | (i + 1))
        for (int j = y; j < m; j = j | (j + 1))
            bit[i][j] += delta;
}
```

## Range Operations 
Fenwick Tree Support 3 type of range operation:
* Point Update and Range Query
* Range Update and Point Query
* Range Update and Range Query

### Point Update and Range Query
Have discussed it in the above discussion

### Range Update and Point Query 

For the range update $[l,r]$ it can be optimised as adding the add(l,x) and add (r+1, -x). This is due to 