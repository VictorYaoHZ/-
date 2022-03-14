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
void calc(int** b, int* s, int* a, int n) {
	for (int i = 0; i < n; i++) {
		s[i] = 0;
		for (int j = 0; j < n; j++) {
			s[i] += b[j][i] * a[j];
		}


	}
}
void calc2(int** b, int* s, int* a, int n) {
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
	int n;//手动在此修改参数
	int step = 100;

	static long long head1, tail1, freq1;
	static long long head2, tail2, freq2;
	for (n = 100; n <= 1000; n += step) {
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
		for (int i = 0; i < 1000; i++) {
			calc(b, s, a, n);
		}
		
		QueryPerformanceCounter((LARGE_INTEGER*)&tail1);
		cout << " 优化前：  " << (tail1 - head1) * 1000 / freq1;
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq2);
		QueryPerformanceCounter((LARGE_INTEGER*)&head2);
		for (int i = 0; i < 1000; i++) {
			calc2(b, s, a, n);
		}
		QueryPerformanceCounter((LARGE_INTEGER*)&tail2);
		cout << " 优化后：  " << (tail2 - head2) * 1000 / freq2 << endl;


	}
	return 0;

}
