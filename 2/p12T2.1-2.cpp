//p10 T2.1-2
#include <iostream>
#include <cstdio>
using namespace std;
void InsertSort(int a[], int n)
{
	for(int i = 1; i < n ; ++i)      //从1开始是为了后面的j=i-1 
	{
		int key = a[i], j = i - 1;   //a[i]为基准数，a[j]为a[i]前面的数。 
		while(j >= 0 && a[j] < key)  //a[j]>key=a[i]时为真，就是比a[i]大的都需要退到后面 
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key;              //j停住的地方为所需位置的前一位 
	}
}
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int a[n];
		for(int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		InsertSort(a, n);
		for(int i = 0; i < n; ++i)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
