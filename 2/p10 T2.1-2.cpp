//p10 T2.1-2
#include <iostream>
#include <cstdio>
using namespace std;
void InsertSort(int a[], int n)
{
	for(int i = 1; i < n ; ++i)      //��1��ʼ��Ϊ�˺����j=i-1 
	{
		int key = a[i], j = i - 1;   //a[i]Ϊ��׼����a[j]Ϊa[i]ǰ������� 
		while(j >= 0 && a[j] < key)  //a[j]>key=a[i]ʱΪ�棬���Ǳ�a[i]��Ķ���Ҫ�˵����� 
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key;              //jͣס�ĵط�Ϊ����λ�õ�ǰһλ 
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
