#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int c[4], d[4];
int r[1296][4];
int check()
{
	int b = 0, w = 0, i, j;
	int tc[4], td[4];
	for (i = 0; i < 4; i++)
	{
		tc[i] = c[i];
		td[i] = d[i];
	}
	for (i = 0; i < 4; i++)
		if (tc[i] == td[i])
		{
			b++;
			tc[i] *= 100;
			td[i] *= 10;
		}
	if (b < 3)
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				if (tc[i] == td[j])
				{
					w++;
					tc[i] *= 100;
					td[j] *= 10;
				}
	return (b * 10 + w);
}
int main()
{
	srand(time(0));
	int bw;
	int cc[4];
	while (1)
	{
		cout << "enter the C[] = ";
		cin >> c[0] >> c[1] >> c[2] >> c[3];
		cout << "\n---------\n";
		cout << "STEP(1)>>>>\n";
		cout << "D1 = ";
		for (int z = 0; z < 4; z++)
		{
			d[z] = (rand() % 6) + 1;
			cout << d[z] << " ";
		}
		cout << endl;
		bw = check();
		cout << "BW1 = " << bw;
		for (int i = 0; i < 4; i++)
			cc[i] = c[i];
		int count = 0;
		for (int i3 = 1; i3 < 7; i3++)
			for (int i2 = 1; i2 < 7; i2++)
				for (int i1 = 1; i1 < 7; i1++)
					for (int i0 = 1; i0 < 7; i0++)
					{
						c[3] = i3;	c[2] = i2;	c[1] = i1;	c[0] = i0;
						if (bw == check())
						{
							for (int k = 0; k < 4; k++)
								r[count][k] = c[k];
							count++;
						}
					}
		cout << "\nCOUNT = " << count;
		cout << "\n---------\n";
		getch();
		int s = 2;
		while (count > 1)
		{
			cout << "\nSTEP(" << s << ")>>>>\n";
			for (int i = 0; i < 1296; i++)
				if (r[i][0] != 0)
				{
					d[0] = r[i][0]; d[1] = r[i][1]; d[2] = r[i][2]; d[3] = r[i][3];
					break;
				}
			cout << "D" << s << " = " << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << endl;
			for (int i = 0; i < 4; i++)
				c[i] = cc[i];
			bw = check();
			cout << "BW" << s << " = " << bw;
			for (int i = 0; i < 4; i++)
				cc[i] = c[i];
			for (int k = 0; k < 1296; k++)
			{
				if (r[k][0] == 0)
					continue;
				for (int l = 0; l < 4; l++)
					c[l] = r[k][l];
				if (bw != check())
				{
					r[k][0] = r[k][1] = r[k][2] = r[k][3] = 0;
					count--;
				}
			}
			cout << "\nCOUNT" << s++ << " = " << count;
			cout << "\n---------\n";
			getch();
		}
		cout << "\nResult: ";
		for (int i = 0; i < 1296; i++)
			if (r[i][0] != 0)
			{
				cout << r[i][0] << " " << r[i][1] << " " << r[i][2] << " " << r[i][3];
				break;
			}
		cout << "\nCount STEP = " << s;
		cout << "\n.::FINISH::. HOOOORRRRAAAAAAA ^_________^\n";
		getch();
		getch();
        // clrscr();
        system("cls");
	}
	return 0;
}
