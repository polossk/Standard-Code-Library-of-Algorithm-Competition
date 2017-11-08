#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 310;

int N;
int val[maxn][maxn];

//2D RMQ
//dp[row][col][i][j] 表示[row,row+2^i-1]x[col,col+2^j-1] 二维区间内的最小值.
//dp[row][col][i][j] = 
//	min( dp[row][col][i-1][j], dp[row + (1<<(i-1))][col][i-1][j] )
//    	min( dp[row][col][i][j-1], dp[row][col + (1<<(j-1))][i][j-1] )

int code(int i){
    return log(double(i)) / log(2.0);
}

int dp[maxn][maxn][9][9];
void initRMQ(int N,int M){
	for (int row=1;row<=N;row++){
	for (int col=1;col<=M;col++){
		dp[row][col][0][0]=val[row][col];
	}
	}
	int n = code(N);
	int m = code(M);
	for (int i=0;i<=n;i++){
	for (int j=0;j<=m;j++){
		if(i == 0 && j==0)continue;
		for (int row=1;row+(1<<i)-1<=N;row++){
		for (int col=1;col+(1<<j)-1<=M;col++){
			if (i==0){//水平划分
				dp[row][col][i][j] = min(dp[row][col][i][j-1] , dp[row][col+(1<<(j-1))][i][j-1]);
			}
			else {//竖直划分
				dp[row][col][i][j] = min(dp[row][col][i-1][j] , dp[row+(1<<(i-1))][col][i-1][j]);
			}
		}
		}
	}
	}
}

int RMQ(int x1,int x2,int y1,int y2){
	int kx = code(x2-x1+1);
	int ky = code(y2-y1+1);
	int m1 = dp[x1][y1][kx][ky];
	int m2 = dp[x2-(1<<kx)+1][y1][kx][ky];
	int m3 = dp[x1][y2-(1<<ky)+1][kx][ky];
	int m4 = dp[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky];
	return min( min(m1,m2), min(m3,m4) );
}


int main(){
	int T;
	int M;
	int x1,y1,x2,y2;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				scanf("%d",&val[i][j]);
			}
		}
		initRMQ(N,N);
		scanf("%d",&M);
		while(M--)	{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%d\n",RMQ(x1,x2,y1,y2));
		}
	}
	return 0;
