#include<iostream>
#include<time.h>
#include<Windows.h>
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
	int n = 1000;
	int step = 100;

	clock_t start1, finish1, start2, finish2;
	for (n = 100; n < 3000; n += step) {
		//---------------------------
		int** b = new int* [n];
		for (int i = 0; i < n; i++) {
			b[i] = new int[n];
		}
		int* s = new int[n];
		int* a = new int[n];
		//-----------------------------

		initialize(b, s, a, n);
		start1 = clock();
		calc(b, s, a, n);
		finish1 = clock();
		initialize(b, s, a, n);
		start2 = clock();
		calc2(b, s, a, n);
		finish2 = clock();

		cout << n;
		cout << " 优化前：  " << (finish1 - start1) / float(CLOCKS_PER_SEC);
		cout << " 优化后：  " << (finish2 - start2) / float(CLOCKS_PER_SEC) << endl;
		if (n >= 2000) step = 1000;
	}



}
