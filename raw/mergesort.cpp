#include <bits/stdc++.h>
using namespace std;

const int Max_Size = 1000005;

int __[Max_Size];

int inv(int n, int *a)
{
    int L = n >> 1, R = n - L;
    int ret = R > 1 ? (inv(L, a) + inv(R, a + L)) : 0;
    for (int i = 0, j = 0; i <= L; __[i + j] = a[i], i++)
        for (ret += j; j < R && (i == L || a[i] > a[L + j]); __[i + j] = a[L + j], j++);
    memcpy(a, __, sizeof(int) * n);
    cout << "L= " << L << ", r= " << R << ", => ret= " << ret << endl;
    return ret;
}

int main()
{
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    cout << inv(10, a) << endl; // => 45
    return 0;
}