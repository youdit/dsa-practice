# DISJOINT SET UNION

**Disjoint Set Union** provide us two main function of providing the ability to *find* the set in which the element is present and to *union* a two sets to create a new sets.

So in total the DSU provide us 2 function in its core:
* ```make_set(v)``` - create a new set consist of element v
* ```union_set(a,b)``` - to union 2 sets which contains the element $a$ and $b$ if they are in two different set
* ```find_set(v)``` - return the respective set to which the element $v$ belong to. Two sets are equal if ```find_set(a) == find_set(b)```

It provide a $O(1)$ time aromatized time complexity for all the above operation

In this the the every Disjoint set can be considered as a set of elements with the fist element as the parent of the set or the base set

For the the function ```find_set(v)``` it will return this base set. for the union of the 2 sets the parent of the set.


### How the parent of a node is stored in DSU

Consider an array $parent$ in range $[0,N]$ where the the $parent[i]$ store the parent of value $i$.

So on the start the array is having the value $A = {0,1,2,3,4,5,6..N}$

when the two independent sets are combined we update the parent of one node to that of the value of second node

Ex: if union(3,4) the the parent Array becomes $A = {0,1,2,3,3,5,6...N}$

But the worst case time complexity of this algorithm to find the parent is $O(n)$ which will be left or right skewed tree.

This can be improved to $O(1)$ time complexity by doing a simple optimization of adding the node to the root node of $a$ instead of attaching it to the node $a$

So the implementation of finding the parent in optimized form

```cpp

int find_set(int v) {
    if( v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
```

This *find_set* function compress the path of the parent to the root node of the set for the future query which will make the time complexity of finding set of complexity $O(N)$


### Union of the set

The one of the important property of the DSU id the combination of two sets to create a single set

The most implementation of this will be with the use of the size.

```cpp
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if( a != b) {
        if( size[a] < size[b]) {
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}
```

we can also use rank instead of the size for this the code will be 

```cpp
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if( a != b) {
        if( rank[a] < rank[b]) {
            swap(a,b);
        }
        parent[b] = a;
        if(rank[a] == rank[b])
            rank[a]++;
    }
}
```

So the final Implementation of the DSU is 

```cpp
void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
```

So we have implemented all the operation provided to us by the DSU.


## Application Of DSU

### Connected Component in a graph

DSU can be used to find the connected component of the undirected Graph in online mode (i.e. we can find if two component are connected at any point in time).

Consider a graph $G$ consist of the $edges = {1,2,3,4,5,6,7}$ initially all the the edges are independent so the parent of each node is the value of the node itself

so we insert a bidirectional edge from $a -> b$ in the Graph $G$ it will be equivalent to the taking ```union_sets(a, b)``` which will connect the two different connected component into single componenet.

So to find if two edges $x$ and $y$ are in the same connected component at any given time is:

```cpp
bool isConnected = find_set(x) == find_set(y)
```

