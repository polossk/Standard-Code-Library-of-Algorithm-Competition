#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
using namespace std;

/// Begin as namespace BinaryIndexedTree
template<int Max_Size = 100005> struct BITree {
	int arr[Max_Size];
	static inline int lowbit(int x) { return x & (-x); }

	BITree(int initial = 0) { fill(arr, arr + Max_Size, initial); }

	inline void add(int x, int v) {
		for (int i = x; i <= Max_Size; i += lowbit(i)) arr[i] += v;
	}
	
	inline int get(int x)
	{
		int sum = 0;
		for (int i = x; i; i -= lowbit(i)) sum += arr[i];
		return sum;
	}

	inline int getxy(int x, int y) { return get(y) - get(x - 1); }
};
/// End as namespace BinaryIndexedTree

int n, tmp, ans[32768 >> 1];

int main()
{
	n = nextInt();
	BITree<32768> tree;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%*d", &tmp); tmp++;
		tree.add(tmp, 1); ans[tree.get(tmp) - 1]++;
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
