
typedef struct{
	int n;
	double xbar;
	double ybar;
	double sumx;
	double sumy;
	double ssx;
	double ssy;
	double sumx2;
	double sumy2;
	double sumxy;
	double sigmax;
	double sigmay;
}STAT;

double mean(double t[],int n);
int sd1var(double tx[],int n,STAT *result);
int sd2var(double tx[],double ty[],int n,STAT *result);
