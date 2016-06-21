#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
	int i,  j, x1, y1, x2, y2, wl, wr, wt, wb, gdriver = DETECT, gmode = DETECT;
	int dx, dy, p[4], q[4];
	float r[4], u1, u2, max, min;
	float x1p, x2p, y1p, y2p;
	clrscr();
	printf("\nEnter the coordinates of the line: ");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	printf("\nEnter the coordinates of clipping window\n");
	printf("\nLeft: ");
	scanf("%d", &wl);
	printf("\nTop: ");
	scanf("%d", &wt);
	printf("\nRight: ");
	scanf("%d", &wr);
	printf("\nBottom: ");
	scanf("%d", &wb);
	dx = x2 - x1;
	dy = y2 - y1;
	p[0] = (-1 * dx);
	p[1] = dx;
	p[2] = (-1 * dy);
	p[3] = dy;
	q[0] = x1 - wl;
	q[1] = wr - x1;
	q[2] = y1 - wb;
	q[3] = wt - y1;
	initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
	printf("\nLine before clipping\n");
	line(x1, y1, x2, y2);
	getch();
	for(i = 0; i < 4; i++)
	{
		if((p[i] == 0) && (q[i] < 0))
		{
			printf("\nThe line lies completely outside the clipping window\n");
			getch();
			exit(0);
		}
	}
	for(i = 0; i < 4; i++)
	{
		r[i] = ((float) q[i] / (float) p[i]);
	}
	max = 0.0;
	min = 1.0;
	for(i = 0; i < 4; i++)
	{
		if(p[i] < 0)
		{
			if(r[i] > max)
			{
				max = r[i];
			}
		}
		else if(p[i] > 0)
		{
			if(r[i] < min)
			{
				min = r[i];
			}
		}
	}
	u1 = max;
	u2 = min;
	if (u1 > u2)
	{
		printf("\nThe line lies outside the clipping window\n");
		getch();
		exit(0);
	}
	x1p = x1 + (u1 * dx);
	y1p = y1 + (u1 * dy);
	x2p = x1 + (u2 * dx);
	y2p = x1 + (u2 * dy);
	cleardevice();
	printf("\nLine after clipping\n");
	rectangle(wl, wb, wr, wt);
	setcolor(RED);
	line((int) x1p, (int) y1p, (int) x2p, (int) y2p);
	getch();
	closegraph();
}
