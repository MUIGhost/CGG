#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps,k;
    float xIncrement, yIncrement, x = x1, y = y1;

    if (abs(dx) > abs(dy)) {
	steps = abs(dx);
    } else {
	steps = abs(dy);
    }

    xIncrement = (float) dx / steps;
    yIncrement = (float) dy / steps;

    putpixel(x, y, WHITE);

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
    }
}

int main() {
     int x1, y1, x2, y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


    printf("Enter coordinates of first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawLineDDA(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}


//150 100
//100 150
