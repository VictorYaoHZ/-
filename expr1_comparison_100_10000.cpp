#include<iostream>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
using namespace std;
void initialize(int** b, int* s, int* a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = i + j;
		}
	}
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}

}
void calc_100(int** b, int* s, int* a, int n) {
	for (int i = 0; i < n; i++) {
		s[i] = 0;
		for (int j = 0; j < n; j++) {
			s[i] += b[j][i] * a[j];
		}


	}
}
void calc2_100(int** b, int* s, int* a, int n) {
	for (int i = 0; i < n; i++) {
		s[i] = 0;
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			s[i] += b[j][i] * a[j];
		}
	}
}
void calc_10000(int** b, int* s, int* a, int n) {
	for (int i = 0; i < n; i++) {
		s[i] = 0;
		for (int j = 0; j < n; j++) {
			s[i] += b[j][i] * a[j];
		}


	}
}
void calc2_10000(int** b, int* s, int* a, int n) {
	for (int i = 0; i < n; i++) {
		s[i] = 0;
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			s[i] += b[j][i] * a[j];
		}
	}
}
int main()
{
	int n = 100, n2 = 10000;//手动在此修改参数
	int step = 100;

	static long long head1, tail1, freq1;
	static long long head2, tail2, freq2;
	static long long head11, tail11, freq11;
	static long long head22, tail22, freq22;
	//---------------------------
	int** b = new int* [n];
	for (int i = 0; i < n; i++) {
		b[i] = new int[n];
	}
	int* s = new int[n];
	int* a = new int[n];
	//-----------------------------
	cout << n;
	initialize(b, s, a, n);
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
	QueryPerformanceCounter((LARGE_INTEGER*)&head1);
	calc_100(b, s, a, n);

	QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
	cout << " 优化前：  " << (tail1 - head1) * 1000 / freq1;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq2);
	QueryPerformanceCounter((LARGE_INTEGER*)&head2);
	calc2_100(b, s, a, n);
	QueryPerformanceCounter((LARGE_INTEGER*)&tail2);
	cout << " 优化后：  " << (tail2 - head2) * 1000 / freq2 << endl;


	b = new int* [n2];
	for (int i = 0; i < n2; i++) {
		b[i] = new int[n2];
	}
	s = new int[n2];
	a = new int[n2];
	//-----------------------------
	cout << n2;
	initialize(b, s, a, n2);
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq1);
	QueryPerformanceCounter((LARGE_INTEGER*)&head1);
	calc_100(b, s, a, n2);

	QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
	cout << " 优化前：  " << (tail1 - head1) * 1000 / freq1;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq2);
	QueryPerformanceCounter((LARGE_INTEGER*)&head2);
	calc2_100(b, s, a, n2);
	QueryPerformanceCounter((LARGE_INTEGER*)&tail2);
	cout << " 优化后：  " << (tail2 - head2) * 1000 / freq2 << endl;

	return 0;

}
