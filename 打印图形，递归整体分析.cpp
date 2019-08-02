#include<iostream>
using namespace std;
#define N 70

void f(char a[][N], int rank, int row, int col)
{
	if(rank==1){
		a[row][col] = '*';
		return;
	}

	int w = 1;
	int i;
	for(i=0; i<rank-1; i++) w *= 2;//w=16
	f(a, rank-1, row, col+w/2);//(a,5,0,16);//处理顶上的三角形，都是rank=5的从左上角开始
	f(a, rank-1, row+w/2, col);//看递归要整体性的看待问题  (a,5,16,0) //处理左下角
	f(a, rank-1, row+w/2, col+w);//(a,5,16,32)//处理右下角
}

int main()
{
	char a[N][N];//模块化思想
	int i,j;
	for(i=0;i<N;i++)
	for(j=0;j<N;j++) a[i][j] = ' ';//全部初始化为‘ ’

	f(a,6,0,0);

	for(i=0; i<N; i++){
		for(j=0; j<N; j++) printf("%c",a[i][j]);
		printf("\n");
	}

	return 0;
}