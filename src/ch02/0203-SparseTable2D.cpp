/// Begin as namespace SparseTable2D
template<typename Tp, int Max_Size = 305> struct SparseTable2D {
    int preLog2[Max_Size]; Tp a[Max_Size][Max_Size][9][9];

    void init(int n)
    {
        preLog2[1] = 0;
        for (int i = 2; i <= Max_Size; i++)
        {
            preLog2[i] = preLog2[i - 1];
            preLog2[i] += ((1 << preLog2[i] + 1) == i);
        }
    }

    SparseTable2D(int n = Max_Size) { init(n); }

    template<class InputIt> void build(InputIt src, int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                a[i][j][0][0] = src[i][j];
        for (int ki = 0, x = preLog2[rows]; ki <= x; ki++)
            for (int kj = 0, y = preLog2[cols]; kj <= y; kj++)
        {
            if (ki == 0 && kj == 0) continue;
            for (int i = 0; i + (1 << ki) - 1 < rows; i++)
                for (int j = 0; j + (1 << kj) - 1 < cols; j++)
            {
                if (ki == 0) // rows
                    a[i][j][ki][kj] = max(a[i][j][ki][kj - 1],
                        a[i][j + (1 << (kj - 1))][ki][kj - 1]);
                else // cols
                    a[i][j][ki][kj] = max(a[i][j][ki - 1][kj],
                        a[i + (1 << (ki - 1))][j][ki - 1][kj]);
            }
        }
    }

    inline Tp query(int r1, int r2, int c1, int c2)
    {
        int kr = preLog2[r2 - r1 + 1], kc = preLog2[c2 - c1 + 1];
        r2 = r2 - (1 << kr) + 1; c2 = c2 - (1 << kc) + 1;
        Tp _1 = a[r1][c1][kr][kc], _2 = a[r2][c1][kr][kc];
        Tp _3 = a[r1][c2][kr][kc], _4 = a[r2][c2][kr][kc];
        return std::min({_1, _2, _3, _4});
    }
};
/// End as namespace SparseTable2D