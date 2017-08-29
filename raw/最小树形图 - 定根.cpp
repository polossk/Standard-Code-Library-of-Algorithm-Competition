struct node { double x, y; };
struct edg { int u, v; double cost; };

const int MaxN = 110;
const int MaxM = 10010;
const double eps = 1e-6;
const double inf = ~0u>>1;

node point[MaxN];
edg  E[MaxM];
double In[MaxN];
int ID[MaxN], vis[MaxN], pre[MaxN];
int NV, NE;

double SQ(int u, int v) {
    return sqrt((point[u].x - point[v].x)*(point[u].x - point[v].x) +
                (point[u].y - point[v].y)*(point[u].y - point[v].y));
}

double Directed_MST(int root) {
    double ret = 0;
    int i, u, v;
    while (true) {
        for (int i = 0; i < NV; i++) In[i] = inf;
        for (int i = 0; i < NE; i++)
		{// 找最小入边
            u = E[i].u;
            v = E[i].v;
            if (E[i].cost < In[v] && u != v)
			{
                In[v] = E[i].cost;
                pre[v] = u;
            }
        }
        for (int i = 0; i < NV; i++)
		{// 如果存在除root以外的孤立点，则不存在最小树形图
            if (i == root) continue;
            if (In[i] == inf) return -1;
        }

        int cnt = 0;
		fill(ID, ID + MaxN, -1);
		fill(vis, vis + MaxN, -1);
        In[root] = 0;

        for (int i = 0; i < NV; i++)
		{// 找环
            ret += In[i];
            int v = i;
            while (vis[v] != i && ID[v] == -1 && v != root)
			{
                vis[v] = i;
                v = pre[v];
            }
            if (v != root && ID[v] == -1)
			{// 缩点并且重新标号
                for (u = pre[v]; u != v; u = pre[u]) ID[u] = cnt;
                ID[v] = cnt++;
            }
        }
        if (cnt == 0) break;
        for (int i = 0; i < NV; i++) // 重新标号
            if (ID[i] == -1) ID[i] = cnt++;
        for (int i = 0; i < NE; i++)
		{// 更新其他点到环的距离
            v = E[i].v;
            E[i].u = ID[E[i].u];
            E[i].v = ID[E[i].v];
            if (E[i].u != E[i].v) E[i].cost -= In[v];
        }
        NV = cnt;
        root = ID[root];
    }
    return ret;
}
