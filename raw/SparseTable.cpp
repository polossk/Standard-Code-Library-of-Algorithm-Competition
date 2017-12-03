/// Begin as namespace SparseTable
template<typename Tp, int Max_Size = 100005> struct SparseTable {
    int preLog2[Max_Size]; Tp a[Max_Size][32];

    void init(int n)
    {
        preLog2[1] = 0;
        for (int i = 2; i <= Max_Size; i++)
        {
            preLog2[i] = preLog2[i - 1];
            preLog2[i] += ((1 << preLog2[i] + 1) == i);
        }
    }

    SparseTable(int n = Max_Size) { init(n); }

    template<class InputIt> void build(InputIt first, InputIt last)
    {
        return build(first, int(first - last));
    }

    template<class InputIt> void build(InputIt src, int len)
    {
        for (int i = len - 1; i >= 0; i--)
        {
            a[i][0] = src[i];
            for (int j = 1; (i + (1 << j ) - 1) < len; j++)
            {
                a[i][j] = min(a[i][j - 1], a[i + (1 << j - 1)][j - 1]);
            }
        }
    }

    inline Tp query(int l, int r)
    {
        int k = preLog2[r - l + 1];
        return min(a[l][k], a[r - (1 << k) + 1][k]);
    }
};
/// End as namespace SparseTable