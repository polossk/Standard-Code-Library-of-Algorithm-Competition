#include <bits/stdc++.h>
using namespace std;

template<typename Tp> struct Block
{
	vector<Tp> arr; Tp maintain;
	Block() {}
	Block(Tp val): arr(1, val) {}
	Block(vector<Tp> vals): arr(vals) {}
	friend ostream& operator<<(ostream& os, const Block& b) 
	{
		os << "["; for (auto e : b.arr) os << " " << e;
		os << " ]"; return os;
	}
};

vector<int> b = {4, 5, 6};
vector<int> c = {0, 1, 2, 3, 4, 5};

void foo()
{
	int a = 0, b = 0;
	std::tie(a, b) = make_pair(5, 6);
	cout << "(" << a << ", " << b << ")" << endl;
	std::tie(std::ignore, b) = make_pair(7, 8);
	cout << "(" << a << ", " << b << ")" << endl;
	std::tie(a, std::ignore) = make_pair(3, 4);
	cout << "(" << a << ", " << b << ")" << endl;
}

void bar()
{
	vector<int> d;
	cout << "=================" << __func__ << endl;
	d.resize(b.size());
	transform(b.begin(), b.end(), d.begin(), [](int _)->int{return _;});
	for (auto e : d) cout << " " << e; cout << endl;
	b.pop_back(); b.pop_back();
	transform(b.begin(), b.end(), d.begin(), [](int _)->int{return _ * 2;});
	for (auto e : d) cout << " " << e; cout << endl;
	d.resize(c.size());
	transform(c.begin(), c.end(), d.begin(), [](int _)->int{return _;});
	for (auto e : d) cout << " " << e; cout << endl;
	cout << *(d.end() - 1) << endl;
	cout << d.back() << endl;
}

template<class InputIt> void init(InputIt first, InputIt last)
{
	cout << "=========init" << endl;
	vector<typename std::remove_reference<decltype(*first)>::type> hoge(first, last);
	for (auto e : hoge) cout << " " << e; cout << endl;
	cout << "=========" << endl;
}

template<class InputIt, class Tp> void init2(InputIt first, InputIt last)
{
	cout << "=========init2" << endl;
	vector<Tp> hoge(first, last);
	for (auto e : hoge) cout << " " << e; cout << endl;
	cout << "=========" << endl;
}

void bar2()
{
	init(b.begin(), b.end());
	init2<vector<int>::iterator, int>(b.begin(), b.end());
}

int main()
{
	list<Block<int> > a;
	a.emplace_front(1);
	for (auto e : a) cout << " " << e; cout << endl;
	a.emplace_front(vector<int>({1, 2, 3}));
	for (auto e : a) cout << " " << e; cout << endl;
	a.emplace_front(b);
	for (auto e : a) cout << " " << e; cout << endl;
	for (auto e : c) cout << " " << e; cout << endl;
	c.resize(c.size() + 1);

	for (auto e : c) cout << " " << e; cout << endl;
	copy(c.begin() + 3, c.end(), c.begin() + 4);
	c[3] = 13;

	for (auto e : c) cout << " " << e; cout << endl;
	vector<int> hoge(c.begin() + 4, c.end());
	for (auto e : hoge) cout << " " << e; cout << endl;
	c.erase(c.begin() + 1);
	for (auto e : c) cout << " " << e; cout << endl;
	bar2();
	return 0;
}