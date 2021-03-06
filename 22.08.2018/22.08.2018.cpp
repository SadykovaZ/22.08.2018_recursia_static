// 22.08.2018.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int sum = 0;
const int n = 6;
const int m = 7;
int arr[n][m] = { {1,0,0,1,0,1,0}, { 0,1,1,0,0,1,0 },{ 1,0,1,0,0,1,0 },{ 0,0,0,1,0,1,0 },{ 0,0,0,1,0,1,0 },{ 1,0,0,1,0,1,0 } };
bool fs[n][m] = { 0 };

int position(int arr[], int pos, int size, int &max, int &imax)
{
	if (pos == size - 3) return max;
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		sum += arr[pos + i];
	}
	if (sum > max)
	{
		max = sum;
		imax = pos;
	}
	pos++;
	return position(arr, pos, size, max, imax);
}

void print(int n)
{
	if (n == 0)return;
	char c;
	cin >> c;
	cout << c << endl;
	print(n - 1);
	//cout << c;
}

void func(int &x)
{
	static int y;
	y = 10;
	x = y * 2;
	//cout << y << endl;
}

void figure(int n)
{
	static int k = 1;
	if (n == 0) return;
	for (int i = 1; i < n; i++)
		cout << ' ';
	for (int i = 1; i <= k; i++)
		cout << '*';
	for (int i = 1; i < n; i++)
		cout << ' ';
	cout << endl;
	k += 2;
	figure(n - 1);
}

void func1(int a)
{
	static int y = 10;
	y += a;
	cout << y << endl;
}

int fib(int n)
{
	if (n == 1 || n == 0) return 1;
	else return fib(n - 1) + fib(n - 2);
}

int fib1(int n)
{
	int o = 0, v = 1, h;
	for (int i = 0; i < n; i++)
	{
		h = v;
		v += o;
		o = h;
	}
	return v;
}

void inf(int i, int j)
{
	if ((j >= 0 && j < m) && (i >= 0 && i < n))
	{
		sum++;
		fs[i][j] = true;
		if (arr[i][j - 1] != 0 && fs[i][j - 1] == false) inf(i, j - 1);
		if (arr[i][j + 1] != 0 && fs[i][j + 1] == false) inf(i, j + 1);
		if (arr[i - 1][j] != 0 && fs[i - 1][j] == false) inf(i - 1, j);
		if (arr[i + 1][j] != 0 && fs[i + 1][j] == false) inf(i + 1, j);
		if (arr[i - 1][j - 1] != 0 && fs[i - 1][j - 1] == false) inf(i - 1, j - 1);
		if (arr[i - 1][j + 1] != 0 && fs[i - 1][j + 1] == false) inf(i - 1, j + 1);
		if (arr[i + 1][j - 1] != 0 && fs[i + 1][j - 1] == false) inf(i + 1, j - 1);
		if (arr[i + 1][j + 1] != 0 && fs[i + 1][j + 1] == false) inf(i + 1, j + 1);
		cout << i << " "<<j << endl;
	}

}

int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	inf(1, 2);
	cout << sum << endl;
	
	/*int a[10] = { 22,1,2,3,4,55,6,0,8,300 };
	int m, i;
	cout << position(a, 0, 10, m, i)<<endl;
	cout << i << endl;
	*/
	/*int a=5;
	print(a);*/

	/*int a = 5;
	func(a);
	cout << a << endl;
	func(a);
	cout << a << endl;*/

	/*int a = 5;
	figure(a);
*/
/*int a = 5;
func1(a);*/

/*int n;
cin >> n;
cout << fib1(n) << endl;*/

//cout << fib(7) << endl;
//cout << endl;
	system("pause");
	return 0;
}

