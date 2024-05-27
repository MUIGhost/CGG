#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawCircleBresenham(int xc, int yc, int radius) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (x <= y) {
	putpixel(xc + x, yc + y, WHITE);
	putpixel(xc - x, yc + y, WHITE);
	putpixel(xc + x, yc - y, WHITE);
	putpixel(xc - x, yc - y, WHITE);
	putpixel(xc + y, yc + x, WHITE);
	putpixel(xc - y, yc + x, WHITE);
	putpixel(xc + y, yc - x, WHITE);
	putpixel(xc - y, yc - x, WHITE);

	if (d <= 0) {
	    d = d + 4 * x + 6;
	} else {
	    d = d + 4 * (x - y) + 10;
	    y--;
	}
	x++;
    }
}

int main() {
    int xc, yc, radius;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


    printf("Enter coordinates of center (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius of circle: ");
    scanf("%d", &radius);

    drawCircleBresenham(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}

//300 200
//50