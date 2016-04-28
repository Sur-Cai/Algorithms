//p12 t2.1-4
#include <iostream>
#include <string>
using namespace std;
string a,b;
int JINZHI = 2;
int main()
{
	cin >> JINZHI;
	while(cin >> a >> b)
	{
		if(a.size() < b.size())
		{
			string temp;
			temp = b;
			b = a;
			a = temp;
		}
		int jin = 0;
		for(int i = b.size() - 1; i >= 0; --i)
		{
			int j = i+a.size() - b.size(),tt=a[j]+b[i]-2*'0'+jin;
			if(tt>=JINZHI)
			{
				a[j] = tt - JINZHI+'0';
				jin = tt/JINZHI;
			}
			else
			{
				a[j] = tt + '0';
				jin = 0;
			}
		}
		if(jin)
		{
			for(int i = a.size()-b.size()-1; i>=0;--i)
			{
				int tt = a[i]-'0'+jin;
				if(tt >= JINZHI)
				{
					a[i] = tt-JINZHI + '0';
					jin = tt/JINZHI;
				}
				else
				{
					a[i] = tt+'0';
					jin=0;
				}
			}
		}
		if(jin) cout << 1;
		for(int i = 0; i < a.size(); ++i) cout << a[i];
		cout << endl;
	}
}
