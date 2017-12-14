#include <stdio.h>
#include <stdlib.h>
#include "cal.h"
/*
21 29 24 22 25 30 27 26
20 25 25 23 29 31 24 26 20 21
24 22 28 25 21 26
*/
int main()
{
	STAT stat;
	int i,j,n[10],r;
	double *data[10];
	double tmp[10][4];
	double result[3][4];
	char *colname[]={"方差来源","平方和","自由度","均方和","F值"};
	char *rowname[]={"因素A","误差","总和"};
	//输入数据
	printf("r=");
	scanf("%d",&r);
	for(i=0;i<r;i++){
		printf("n[%d]=",i+1);
		scanf("%d",n+i);
		puts("Please input data:");
		data[i]=(double*)malloc(n[i]*sizeof(double));
		for(j=0;j<n[i];j++){
			scanf("%lf",data[i]+j);
		}
	}
	//开始计算
	tmp[r][0]=0;
	tmp[r][1]=0;
	tmp[r][2]=0;
	tmp[r][3]=0;
	result[1][0]=0;
	for(i=0;i<r;i++){
		sd1var(data[i],n[i],&stat);
		tmp[i][0]=n[i];
		tmp[i][1]=stat.sumx;
		tmp[i][2]=stat.xbar;
		tmp[i][3]=stat.sumx2;
		tmp[r][0]+=n[i];
		tmp[r][1]+=stat.sumx;
		tmp[r][3]+=stat.sumx2;
		result[0][0]+=tmp[i][0]*tmp[i][2]*tmp[i][2];
	}
	tmp[r][2]=tmp[r][0]/tmp[r][1];
	for(i=0;i<=r;i++){
		for(j=0;j<4;j++){
			printf("%10.4lf ",tmp[i][j]);
		}
		putchar('\n');
	}
	result[2][0]=tmp[r][3]-tmp[r][1]*tmp[r][1]/tmp[r][0];
	result[0][0]=result[0][0]-tmp[r][1]*tmp[r][1]/tmp[r][0];
	result[1][0]=result[2][0]-result[0][0];
	result[0][1]=r-1;
	result[1][1]=tmp[r][0]-r;
	result[2][1]=tmp[r][0]-1;
	result[0][2]=result[0][0]/result[0][1];
	result[1][2]=result[1][0]/result[1][1];
	result[0][3]=result[0][2]/result[1][2];
	puts("方差分析表：");
	for(j=0;j<5;j++){
		printf("%10s ",colname[j]);
	}
	putchar('\n');
	for(i=0;i<3;i++){
		printf("%10s ",rowname[i]);
		for(j=0;j<4;j++){
			if(i+j<4)printf("%10.4f ",result[i][j]);
		}
		putchar('\n');
	}
    return 0;
}
