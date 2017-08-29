/****
	*COPYRIGHT NOTICE 
    *Copyright (c) 2014 
    *All rights reserved
    
	*@author    Shen
	*@name		Binary Index Tree
	*@file		G:\ACM\模板笔记\自用模板\代码\02 - 数据结构\BinaryIndexTree.cpp
	*@date		2014/6/3 23:08
	*/

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 100000;
int arr[maxN + 10];
inline  int lowbit(int x) { return (x & -x); }

//data[x] += v
inline void add(int x, int v)
{
	for (int i = x; i <= maxN; i += lowbit(i))
		arr[i] += v;
}

//return data[1] + ... + data[x];
inline int getSum(int x)
{
	int sum = 0;
	for (int i = x; i; i -= lowbit(i))
		sum += arr[i];
	return sum;
}

//return data[x] + ... + data[y];
inline int querySum(int x, int y)
{
	return getSum(y) - getSum(x - 1);
}

int main()
{
	int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 1; i <= 10; i++)
		add(i, data[i - 1]);
	for (int i = 1; i <= 10; i++)
		printf("%d %d\n", i - 1, getSum(i));
	return 0;
}
