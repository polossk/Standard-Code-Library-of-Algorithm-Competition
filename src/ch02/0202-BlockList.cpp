/// Begin as namespace BlockList
template<typename Tp> struct Block {
    vector<Tp> arr; Tp maintain;
    Block() {}
    Block(Tp val): arr(1, val) {}
    Block(vector<Tp> vals): arr(vals) {}
    friend ostream& operator<<(ostream& os, const Block& b)
    {
        os << "["; for (auto e : b.arr) os << " " << e; os << " ]"; return os;
    }
};

template<typename Tp> struct BlockList {
    list<Block<Tp> > fat;
    vector<int> sum;
    int block_capacity;
    typedef typename list<Block<Tp> >::iterator iter;

    inline iter next(const iter &_) const { return _ + 1; }
    inline int blocksize(const iter &_) const { return _->arr.size(); }

    void maintain()
    {   // rewrite it to fit the problem
        sum = vector<int>(1, 0);
        for (iter it = fat.begin(); it != fat.end(); it++)
            sum.push_back(blocksize(it));
        std::partial_sum(sum.begin(), sum.end(), sum.begin(), std::plus<int>());
    }

    template<class InputIt> void init(int cap, InputIt first, InputIt last)
    {
        init(cap, first, int(last - first));
    }

    template<class InputIt> void init(int cap, InputIt src, int len)
    {
        block_capacity = cap;
        typedef typename std::remove_reference<decltype(*src)>::type Tp2;
        for (int i = 0; i < len; i += cap)
        {
            int j = (i + cap > len) ? len : i + cap;
            fat.emplace_back(vector<Tp2>(src + i, src + j));
        }
        maintain();
    }

    inline pair<iter, int> get_block(int pos)
    {
        iter now = fat.begin();
        while (pos >= blocksize(now) && next(now) != fat.end())
        {
            pos -= blocksize(now);
            now = next(now);
        }
        return make_pair(now, pos);
    }

    inline pair<iter, int> get_block_bs(int pos)
    {   // use it with the prefix sum
        if (pos == *sum.rbegin())
            return make_pair(fat.end() - 1, pos - *(sum.rbegin() + 1));
        int offset = upper_bound(sum.begin(), sum.end(), pos) - sum.begin();
        return make_pair(fat.begin() + offset - 1, pos - sum[offset - 1]);
    }

    void insert(int pos, Tp val)
    {
        if (fat.begin() == fat.end()) { fat.emplace_back(val); return; }
        pair<iter, int> res = get_block(pos);
        iter now = res.first; pos = res.second;
        now->arr.resize(blocksize(now) + 1);
        copy(now->arr.begin() + pos, now->arr.end(), now->arr.begin() + pos +1);
        now->arr[pos] = val;
        if (blocksize(now) == 2 * block_capacity)
        {
            vector<Tp> hoge(now->arr.begin() + block_capacity, now->arr.end());
            now->arr.erase(now->arr.begin() + block_capacity, now->arr.end());
            fat.insert(next(now), Block<Tp>(hoge));
        }
        maintain();
    }

    void remove(int pos)
    {
        pair<iter, int> res = get_block(pos);
        iter now = res.first; pos = res.second;
        now->arr.erase(now->arr.begin() + pos);
        maintain();
    }

    Tp at(int pos)
    {
        pair<iter, int> res = get_block(pos);
        iter now = res.first; pos = res.second;
        return now->arr[pos];
    }

    void __dbg__()
    {
        puts("=============DEBUG=BEGIN=============");
        cout << "block_capacity = " << block_capacity << endl;
        int i = 0; for (iter it = fat.begin(); it != fat.end(); it++, i++)
        {
            cout << " ->" << sum[i] << ": " << *it << endl;
        } puts("==============DEBUG=END==============\n");
    }
};
/// End as namespace BlockList