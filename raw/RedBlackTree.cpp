/// Begin as namespace RedBlackTree
template<typename Tp> struct RBNode {
	Tp data;
	int s, c;
	bool color; // color ? Red : Black;
	RBNode *fa, *ch[2];
	void set(const T &_, bool _c, int _i, RBNode *p)
	{
		data = _; color = _c; s = c = _i;
		fa = ch[0] = ch[1] = *p;
	}
	void push_up() { s = ch[0]->s + ch[1]->s + c; }
	void push_down() { for (auto *x = this; x->s; x = x->fa) x->s--; }
	int cmp(const T v) const { return data == v ? -1 : v > data; }
};

template<typename Tp, int Max_Size = 100005> struct RedBlackTree {
	int stack_ptr;
	RBNode<Tp> *root, *nil, *tail;
	RBNode<Tp> __[Max_Size], *stack[Max_Size];

	void init()
	{
		tail = &__[0]; nil = tail++;
		nil->set(Tp(), 0, 0, nullptr);
		root = nil; stack_ptr = 0;
	}

	RedBlackTree() { init(); }

	RBNode<Tp> *newNode(const Tp &v)
	{
		RBNode<Tp> *_ = nil;
		if (!stack_ptr) p = tail++;
		else p = stack[--stack_ptr];
		p->set(v, 1, 1, nil);
		return p;
	}

	void rotate(RBNode<Tp>* &x, bool flag)
	{ // flag ? Right : Left;
		RBNode<Tp> *y = x->ch[!flag];
		x->ch[!flag] = y->ch[flag];
		if (y->ch[flag]->s) y->ch[flag]->fa = x;
		y->fa = x->fa;
		if (!x->fa->s) root = y;
		else x->fa->ch[x->fa->ch[0] != x] = y;
		y->ch[flag] = x;
		x->fa = y;
		y->s = x->s;
		x->push_up();
	}

	void insert_fix(RBNode<Tp>* &x)
	{
		while (x->fa->color)
		{
			RBNode<Tp> *par = x->fa, *gp = par->fa;
			bool flag = par == gp->ch[0]; // lson?
			RBNode<Tp> *uncle = gp->ch[flag];
			if (uncle->color) // lson & rson
			{
				par->color = uncle->color = 0;
				gp->color = 1; // fix color
				x = gp;
			}
			else if (x == par->ch[flag]) rotate(x = par, !flag);
			else
			{
				gp->color = 1; par->color = 0;  // fix color
				rotate(gp, flag);
			}
		}
		root->color = 0;
	}

	void insert(const Tp &x)
	{
		RBNode<Tp> *x = root, *y = nil;
		while (x->s)
		{
			x->s++; y = x;
			int _ = x->cmp(v);
			if (_ == -1) { x->c++; return; }
			x = x->ch[_];
		}
		x = newNode(v);
		if (y->s) y->ch[v > y->data] = x;
		else root = x;
		x->fa = y;
		insert_fix(x);
	}

	RBNode<Tp> *find(RBNode<Tp> *x, const Tp &_) const
	{
		while (x->s && x->data != _) x = x->ch[x->data < _];
		return x;
	}

	void erase_fix(RBNode<Tp>* &x)
	{
		while (x != root && !x->color)
		{
			bool flag = x == x->fa->ch[0]; // lson?
			RBNode<Tp> *par=x->fa, *sibling = par->ch[flag];
			if (sibling->color)
			{
				sibling->color = 0;
				par->color = 1;
				rotate(x->fa, !flag);
				sibling = par->ch[flag];
			}
			else if (!sibling->ch[0]->color && !sibling->ch[1]->color)
			{
				sibling->color = 1;
				x = par;
			}
			else
			{
				if (!sibling->ch[flag]->color)
				{
					sibling->ch[!flag]->color = 0;
					sibling->color = 1;
					rotate(sibling, flag);
					sibling = par->ch[flag];
				}
				sibling->color = par->color;
				sibling->ch[flag]->color = par->color = 0;
				rotate(par, !flag);
				break;
			}
		}
		x->color = 0;
	}

	void erase(const Tp data)
	{
		RedBlackNode<T> *z = find(root, data);
		if (!z->s) return;
		if (z->c > 1)
		{
			z->c--;
			z->push_down();
			return;
		}
		RedBlackNode<T> *y = z, *x = null;
		if (z->ch[0]->s && z->ch[1]->s)
		{
			y = z->ch[1];
			while (y->ch[0]->s) y = y->ch[0];
		}
		x = y->ch[!y->ch[0]->s];
		x->fa = y->fa;
		if (!y->fa->s) root = x;
		else y->fa->ch[y->fa->ch[1] == y] = x;
		if (z != y) z->data = y->data, z->c = y->c;
		y->fa->push_down();
		for (RedBlackNode<T> *k = y->fa; y->c > 1 && k->s && k != z; k = k->fa)
			k->s -= y->c - 1;
		if (!y->color) del_fix(x);
		stack[stack_ptr++] = y;
	}
};
/// End as namespace RedBlackTree