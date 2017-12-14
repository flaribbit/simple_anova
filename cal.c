#include <math.h>
#include "cal.h"

double mean(double t[],int n){
	double sum=0;
	int i;
	for(i=0;i<n;i++)sum+=t[i];
	return sum/n;
}
int sd1var(double tx[],int n,STAT *result){
	int i;
	result->sumx=0;
	result->sumx2=0;
	for(i=0;i<n;i++){
		result->sumx+=tx[i];
		result->sumx2+=tx[i]*tx[i];
	}
	result->xbar=result->sumx/n;
	result->ssx=0;
    for(i=0;i<n;i++){
		result->ssx+=(tx[i]-result->xbar)*(tx[i]-result->xbar);
    }
    result->sigmax=sqrt(result->ssx/n);
    return 1;
}
int sd2var(double tx[],double ty[],int n,STAT *result){
	int i;
	result->sumx=0;
	result->sumy=0;
	result->sumx2=0;
	result->sumy2=0;
	result->sumxy=0;
	for(i=0;i<n;i++){
		result->sumx+=tx[i];
		result->sumy+=ty[i];
		result->sumx2+=tx[i]*tx[i];
		result->sumy2+=ty[i]*ty[i];
		result->sumxy+=tx[i]*ty[i];
	}
	result->xbar=result->sumx/n;
	result->ybar=result->sumy/n;
	result->ssx=0;
	result->ssy=0;
    for(i=0;i<n;i++){
		result->ssx+=(tx[i]-result->xbar)*(tx[i]-result->xbar);
		result->ssy+=(ty[i]-result->ybar)*(ty[i]-result->ybar);
    }
    result->sigmax=sqrt(result->ssx/n);
    result->sigmay=sqrt(result->ssy/n);
    return 1;
}
