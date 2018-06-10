#include <bits/stdc++.h>
using namespace std;

/// Begin as namespace Type EndFlag
#define STD_NUM_LIM std::numeric_limits // std::numeric_limits<Tp>
template<typename Tp, class Compare> class EndFlag {
public:
    Tp value = Compare()(STD_NUM_LIM<Tp>::min(), STD_NUM_LIM<Tp>::max()) ?
        STD_NUM_LIM<Tp>::min(): STD_NUM_LIM<Tp>::max();
};
template<class Compare> class EndFlag<string, Compare> {
public:
    string value = Compare()("", "~~~~~~~~") ? "": "~~~~~~~~";
};
// template<class Compare> class EndFlag<Path, Compare> {
// public:
//     int imin = STD_NUM_LIM<int>::min();
//     int imax = STD_NUM_LIM<int>::max();
//     Path pmin = Path(imin, imin);
//     Path pmax = Path(imax, imax);
//     Path value = Compare()(pmin, pmax) ? pmin: pmax;
// };
#undef STD_NUM_LIM
/// End as namespace Type EndFlag

/// Begin as namespace Heapq
template<typename Tp, class Compare = std::less<Tp>, int Max_Size = 10005>
struct Heapq {
    int id[Max_Size], pos[Max_Size], n, cnt;
    Tp heap[Max_Size], ENDFLAG = EndFlag<Tp, Compare>().value;
    Heapq() : n(0), cnt(0) {}
    Heapq(Tp arr[], int len, int offset = 0) : n(0), cnt(0)
    {
        for (int i = offset; i < len; i++)
        {
            heap[++n] = arr[i]; id[n] = pos[n] = n;
        }
        for (int i = n / 2; i >= 1; i--) down(i);
    }

    Tp top() { return heap[1]; }

    bool empty() { return n == 0; }

    void clear() { n = cnt = 0; }

    void push(Tp v) { heap[++n] = v; id[n] = ++cnt; pos[id[n]] = n; up(n); }

    int pop()
    {
        swap(heap[1], heap[n]); swap(id[1], id[n--]);
        pos[id[1]] = 1; down(1); return id[n + 1];
    }

    int get(int i) { return heap[pos[i]]; }

    void modify(int i, Tp v) { heap[pos[i]] = v; down(pos[i]); up(pos[i]); }

    void erase(int i) { heap[pos[i]] = ENDFLAG; up(pos[i]); pop(); }

    void up(int i)
    {
        Tp x = heap[i]; int y = id[i];
        for (int j = i / 2; j >= 1; j >>= 1)
        {
            if (!Compare()(heap[j], x))
            {
                heap[i] = heap[j]; id[i] = id[j];
                pos[id[i]] = i; i = j;
            } else break;
        }
        heap[i] = x; id[i] = y; pos[y] = i;
    }

    void down(int i)
    {
        Tp x = heap[i]; int y = id[i];
        for (int j = i * 2; j <= n; j <<= 1)
        {
            j += j < n && Compare()(heap[j + 1], heap[j]);
            if (Compare()(heap[j], x))
            {
                heap[i] = heap[j]; id[i] = id[j];
                pos[id[i]] = i; i = j;
            } else break;
        }
        heap[i] = x; id[i] = y; pos[y] = i;
    }

    void __dbg__()
    {
        puts("=============\ni\tpos\tid\theap");
        for (int i = 1; i < n; i++)
        {
            printf("%d\t%d\t%d:\t", i, pos[i], id[i]);
            cout << heap[i] << endl;
        } cout << "=============" << endl;
        cout << "cnt = " << cnt << endl;
        cout << "  n = " <<  n  << endl;
        cout << "=============\n" << endl;
    }
};
/// End as namespace Heapq

int main()
{
    {
        Heapq<int> hpq;
        for (int e : {45, 65, 78, 98, 32, 12, 46, 97, 23, 11})
        {
            hpq.push(e);
            cout << hpq.top() << ", ";
        } cout << endl; hpq.__dbg__();
        hpq.pop(); hpq.__dbg__();
        hpq.modify(1, 50); hpq.__dbg__();
        hpq.erase(2); hpq.__dbg__();
    }
    {
        Heapq<string, greater<string> > hpq2;
        for (string e : {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"})
        {
            hpq2.push(string(e));
            cout << hpq2.top() << ", ";
        } cout << endl; hpq2.__dbg__();
        hpq2.pop(); hpq2.__dbg__();
        hpq2.modify(1, string("zabc")); hpq2.__dbg__();
        hpq2.erase(2); hpq2.__dbg__();
    }
    return 0;
}