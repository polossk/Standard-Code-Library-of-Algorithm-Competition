/// Begin as namespace DisjointSet
template<int Max_Size = 100005> struct DisjointSet {
    int fa[Max_Size], rk[Max_Size];

    void init(int n) { fill(rk, rk + n, 0); while (n-- >= 0) fa[n] = n; }

    DisjointSet(int n = 0) { init(n); }

    inline int _(int x) { return fa[x] = (fa[x] == x) ? x: _(fa[x]); }

    inline int find(int x) { return _(x); }

    inline bool query(int x, int y) { return _(x) == _(y); }

    inline void merge(int x, int y)
    {
        x = _(x); y = _(y); 
        if (x == y) return;
        if (rk[x] < rk[y]) fa[x] = y;
        else { fa[y] = x; rk[x] += (rk[x] == rk[y]); }
    }
};
/// End as namespace DisjointSet