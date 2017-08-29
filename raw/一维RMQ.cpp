namespace RMQ_st
{
    const int Maxn = 100005;
    int dpmax[Maxn][32];
    int dpmin[Maxn][32];
    int mm[Maxn];
    int val[Maxn];

    void prev_mm(){
        mm[1] = 0;
        for (int i = 2; i < Maxn; i++){
            mm[i] = mm[i-1];
            if ((1 << mm[i] + 1) == i)
                mm[i]++;
        }
        return;
    }

    void prev_STmin(int n, int* array){
        for (int i = n - 1; i >= 0; i--){
            dpmin[i][0] = array[i];
            for (int j = 1; (i+(1<<j)-1)<n; j++){
                dpmin[i][j] = min(dpmin[i][j-1], dpmin[i+(1<<j-1)][j-1]);
            }
        }
    }

    void prev_STmax(int n, int* array){
        for (int i = n - 1; i >= 0; i--){
            dpmax[i][0] = array[i];
            for (int j = 1; (i+(1<<j)-1)<n; j++){
                dpmax[i][j]=max(dpmax[i][j-1], dpmax[i+(1<<j-1)][j-1]);
            }
        }
    }

    int query_min_with_array_index(int l, int r){
        int len = r - l + 1;
        int k = mm[len];
        return min(dpmin[l][k], dpmin[r-(1<<k)+1][k]);
    }

    int query_max_with_array_index(int l, int r){
        int len = r - l + 1;
        int k = mm[len];
        return max(dpmax[l][k], dpmax[r-(1<<k)+1][k]);
    }

    int query_min_with_natural_index(int l, int r){
        return query_min_with_array_index(l-1, r-1);
    }

    int query_max_with_natural_index(int l, int r){
        return query_max_with_array_index(l-1, r-1);
    }

};

void solve(int t){
    printf("Case %d:\n", t);
    int N, Q;
    scanf(" %d %d", &N, &Q);
    for (int i=0;i<N;i++){
        scanf(" %d", &RMQ_st::val[i]);
    }
    RMQ_st::prev_STmin(N, RMQ_st::val);
    //RMQ_st::prev_STmax(N, RMQ_st::val);
    while (Q--){
        int l, r;
        scanf(" %d %d", &l, &r);
        printf("%d\n", RMQ_st::query_min_with_natural_index(l, r));
        //printf("%d\n", RMQ_st::query_max_with_natural_index(l, r));
    }
    return;
}