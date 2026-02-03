#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
void showData(double *ptr, int N, int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(ptr + i);
        if((i + 1) % M == 0) cout << endl;
        else cout << " ";
    }
}
void randData(double *ptr, int N, int M){
    for(int i = 0; i < N*M; i++){
        *(ptr + i) = (rand() % 101) / 100.0;
    }
}

void findRowSum(const double* matrix, double* result, int m, int n) {
    for (int i = 0; i < m; ++i) {
        double currentSum = 0;
        for (int j = 0; j < n; ++j) {
            currentSum += *(matrix + (i * n + j));
        }
        result[i] = currentSum;
    }
}

void findColSum(const double* matrix, double* result, int m, int n) {
    for (int j = 0; j < n; ++j) {
        result[j] = 0;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            result[j] += *(matrix + (i * n + j));
        }
    }
}