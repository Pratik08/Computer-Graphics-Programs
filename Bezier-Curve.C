/**
*Bezier-Curve.c
*
*Pratik Dubal
*
*pratik.dubal08@gmail.com
*
**/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void bez(int [], int [], int n);
int fac(int a);

int fac(int a)
{
	int i, ret = 1;
	if (a == 1)
	{
		return 1;
	}
	else
	{
		for(i = a; i > 1; i--)
		{
			ret *= i;
		}
		return ret;
	}
}

int bezcoeff(int n, int i)
{
	int numer = fac(n);
	int denom1 = fac(n - i);
	int denom2 = fac(i);
	int result = (numer/(denom1 * denom2));
	return result;
}

void bez(int x[], int y[], int n)
{
	int i, coeff, deg = n - 1;
	float p[10], u, h, k;
	float temp1, temp2;
	for(i = 0; i < (n - 1); i++)
	{
		setcolor(GREEN);
		line(x[i], y[i], x[i+1], y[i+1]);
	}
	u = 0;
	while(u <= 1.0)
	{
		if(u == 0)
		{
			h = x[0];
			k = y[0];
		}
		else if(u == 1)
		{
			h = x[n - 1];
			k = y[n - 1];
		}
		else
		{
			for(i = 0; i <= deg; i++)
			{
				coeff = bezcoeff(deg, i);
				temp1 = pow(u, i);
				temp2 = pow((1 - u),(deg - i));
				p[i] = coeff * temp1 * temp2;
			}
			h = 0;
			k = 0;
			for(i = 0; i <= deg; i++)
			{
				h = h + (p[i] * x[i]);
				k = k + (p[i] * y[i]);
			}
		}
		putpixel((int) h, (int) k, RED);
		delay(100);
		u += 0.005;
	}
}

void main()
{
	int n, x[10], y[10], i, gdriver = DETECT, gmode;
	clrscr();
	printf("\nEnter the number of control point: ");
	scanf("%d", &n);
	printf("\nEnter coordinates of the control points\n");
	for(i = 0; i < n; i++)
	{
		printf("\nCoordinates of point %d: " , i + 1);
		scanf("%d %d", &x[i], &y[i]);
	}
	initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
	bez(x, y, n);
	getch();
	closegraph();
}
