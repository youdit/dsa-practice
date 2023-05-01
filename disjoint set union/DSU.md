# DISJOINT SET UNION

**Disjoint Set Union** provide us two main function of providing the ability to *find* the set in which the element is present and to *union* a two sets to create a new sets.

So in total the DSU provide us 2 function in its core:
* ```make_set(v)``` - create a new set consist of element v
* ```union_set(a,b)``` - to union 2 sets which contains the element $a$ and $b$ if they are in two different set
* ```find_set(v)``` - return the respective set to which the element $v$ belong to. Two sets are equal if ```find_set(a) == find_set(b)```

It provide a $O(1)$ time aromatized time complexity for all the above operation

I