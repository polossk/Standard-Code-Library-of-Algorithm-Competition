#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

/// Begin as namespace BinaryIndexedTree v2 (range modification & query)
template<int Max_Size = 100005> struct BITree_v2 {
    int arr[Max_Size], brr[Max_Size];
    static inline int lowbit(int x) { return x & (-x); }

    BITree(int initial = 0)
    {
        fill(arr, arr + Max_Size, initial);
        fill(brr, brr + Max_Size, initial);
    }

    void _add(int x, int v)
    {
        for (int i = x; i <= Max_Size; i += lowbit(i))
        {
            arr[i] += v;
            brr[i] += (x - 1) * v;
        }
    }

    inline void modify(int x, int y, int v) { _add(x, v); _add(y + 1, -v); }

    int64 get(int x)
    {
        int64 hoge = 0, piyo = 0;
        for (int i = x; i; i -= lowbit(i))
        {
            hoge += arr[i];
            piyo += brr[i];
        }
        return 1LL * x * hoge - piyo;
    }

    inline int64 getxy(int x, int y) { return get(y) - get(x - 1); }
};
/// End as namespace BinaryIndexedTree