#include<iostream>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#include<cmath>
using namespace std;
int calc(int *a,int n){
	int sum=0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}
int calc2(int* a, int n) {
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i+=2) {
		sum1 += a[i];
		sum2 += a[i + 1];
	}
	return sum1+sum2;
}
int calc3(int* a, int n) {
	for (int m = n; m > 1; m /= 2) {
		for (int i = 0; i < m / 2; i++) {
			a[i] = a[i * 2] + a[i * 2 + 1];
		}
	}
	return a[0];
}
float calc_float(float* a, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}
float calc2_float(float* a, int n) {
	float sum1 = 0;
	float sum2 = 0;
	for (int i = 0; i < n; i += 2) {
		sum1 += a[i];
		sum2 += a[i + 1];
	}
	return sum1 + sum2;
}
float calc3_float(float* a, int n) {
	for (int m = n; m > 1; m /= 2) {
		for (int i = 0; i < m / 2; i++) {
			a[i] = a[i * 2] + a[i * 2 + 1];
		}
	}
	return a[0];
}
void init(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
}
void init_float(float* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i+i/100;
	}
}
int main() {
	int n = 2;
	static long long head1, tail1, freq1;
	for (n = 2; n <= pow(2,15); n *= 2) {
		int* a = new int[n];
		float* b = new float[n];
		cout << n;
		init(a, n);
		init_float(b, n);
		//--------------------------------------------------
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
		QueryPerformanceCounter((LARGE_INTEGER*)&head1);
		if (n <= 32) { for (int i = 0; i < 1000000; i++) { calc(a, n); } }
		else for (int i = 0; i < 10000; i++) { calc(a, n); }
		
		QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
		cout << " before:  " << (double)(tail1 - head1) * 1000 / freq1;
		//--------------------------------------------------
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
		QueryPerformanceCounter((LARGE_INTEGER*)&head1);
		if (n <= 32) { for (int i = 0; i < 1000000; i++) { calc2(a, n); } }
		else for (int i = 0; i < 10000; i++) { calc2(a, n); }
		QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
		cout << " after_2road:  " << (double)(tail1 - head1) * 1000 / freq1;
		//--------------------------------------------------
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
		QueryPerformanceCounter((LARGE_INTEGER*)&head1);
		if (n <= 32) { for (int i = 0; i < 1000000; i++) { calc3(a, n); } }
		else for (int i = 0; i < 10000; i++) { calc3(a, n); }
		QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
		cout << " after_recursion£º  " << (double)(tail1 - head1) * 1000 / freq1;
		//--------------------------------------------------
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
		QueryPerformanceCounter((LARGE_INTEGER*)&head1);
		if (n <= 32) { for (int i = 0; i < 1000000; i++) { calc_float(b, n); } }
		else for (int i = 0; i < 10000; i++) {
			calc_float(b, n);
		}		
		QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
		cout << " before_float:  " << (double)(tail1 - head1) * 1000 / freq1;
		//--------------------------------------------------
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
		QueryPerformanceCounter((LARGE_INTEGER*)&head1);
		if (n <= 32) { for (int i = 0; i < 1000000; i++) { calc_float(b, n); } }
		else for (int i = 0; i < 10000; i++) {
			calc2_float(b, n);
		}
		QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
		cout << " after_float_2roads  " << (double)(tail1 - head1) * 1000 / freq1 << endl;
		//--------------------------------------------------
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
		QueryPerformanceCounter((LARGE_INTEGER*)&head1);
		if (n <= 32) { for (int i = 0; i < 1000000; i++) { calc_float(b, n); } }
		else for (int i = 0; i < 10000; i++) {
			calc3_float(b, n);
		}
		QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
		cout << " after_float_recursion  " << (double)(tail1 - head1) * 1000 / freq1 << endl;
	}
}
