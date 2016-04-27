//p10T2.1-3
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[5] = {1,2,3,4,5}, n;
	while(~scanf("%d", &n))
	{
		int exist = 0;
		for(int i = 0; i < 5; ++i)
		{
			if(a[i] == n)
			{
				exist = i+1;
				break;
			}
		}
		if(exist)
		{
			cout << exist << endl;
		}
		else
		{
			cout << "NIL\n";
		}
	}
}
