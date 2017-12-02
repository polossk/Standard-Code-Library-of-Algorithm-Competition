/// Begin as namespace SparseTable
template<typename Tp, int Max_Size = 100005> struct SparseTable {
    int preLog2[Max_Size]; Tp arr[Max_Size][32];

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
            arr[i][0] = src[i];
            for (int j = 1; (i + (1 << j ) - 1) < len; j++)
            {
                arr[i][j] = min(arr[i][j - 1], arr[i + (1 << j - 1)][j - 1]);
            }
        }
    }

    inline Tp query(int l, int r)
    {
        int len = r - l + 1, k = preLog2[len];
        return min(arr[l][k], arr[r - (1 << k) + 1][k]);
    }
};
/// End as namespace SparseTable
