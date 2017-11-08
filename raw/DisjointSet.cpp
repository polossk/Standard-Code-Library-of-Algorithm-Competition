/****
	*COPYRIGHT NOTICE
    *Copyright (c) 2014
    *All rights reserved

	*@author    Shen
	*@name		Disjoint Set
	*@file		G:\ACM\模板笔记\自用模板\代码\02 - 数据结构\DisjointSet.cpp
	*@date		2014/6/3 23:26
	*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct DisjointSet
{
	vector<int> father, rank;
	DisjointSet(int n) : father(n), rank(n)
	{
		for (int i = 0; i < n; i++)
			father[i] = i;
	}

	inline int find(int v)
	{
		return father[v] = (father[v] == v)? v: find(father[v]);
	}

	void merge(int x, int y)
	{
		int a = find(x), b = find(y);
		if (rank[a] < rank[b])
			father[a] = b;
		else
		{
			father[a] = b;
			if (rank[b] == rank[a])
				rank[a]++;
		}
	}
};

int main()
{
    return 0;
}
