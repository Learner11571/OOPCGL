#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;

class dcircle {
private:
    int x0, y0;

public:
    dcircle() {
        x0 = 0;
        y0 = 0;
    }

    void setoff(int xx, int yy) {
        x0 = xx;
        y0 = yy;
    }

    void drawc(int x1, int y1, int r) {
        float d;
        int x, y;
        x = 0;
        y = r;
        d = 3 - 2 * r;

        do {
            putpixel(x1 + x0 + x, y0 + y - y1, 15);
            putpixel(x1 + x0 + y, y0 + x - y1, 15);
            putpixel(x1 + x0 + y, y0 - x - y1, 15);
            putpixel(x1 + x0 + x, y0 - y - y1, 15);
            putpixel(x1 + x0 - x, y0 - y - y1, 15);
            putpixel(x1 + x0 - y, y0 - x - y1, 15);
            putpixel(x1 + x0 - y, y0 + x - y1, 15);
            putpixel(x1 + x0 - x, y0 + y - y1, 15);

            if (d <= 0) {
                d = d + 4 * x + 6;
            } else {
                d = d + 4 * (x - y) + 10;
                y = y - 1;
            }
            x = x + 1;
        } while (x < y);
    }
};

class pt {
protected:
    int xco, yco, color;

public:
    pt() {
        xco = 0;
        yco = 0;
        color = 15;
    }

    void setco(int x, int y) {
        xco = x;
        yco = y;
    }

    void setcolor(int c) {
        color = c;
    }

    void draw() {
        putpixel(xco, yco, color);
    }
};

class dline : public pt {
private:
    int x2, y2;

public:
    dline() : pt() {
        x2 = 0;
        y2 = 0;
    }

    void setline(int x, int y, int xx, int yy) {
        pt::setco(x, y);
        x2 = xx;
        y2 = yy;
    }

    void drawl(int colour) {
        float x, y, dx, dy, length;
        int i;
        pt::setcolor(colour);
        dx = abs(x2 - xco);
        dy = abs(y2 - yco);

        if (dx >= dy) {
            length = dx;
        } else {
            length = dy;
        }

        dx = (x2 - xco) / length;
        dy = (y2 - yco) / length;
        x = xco + 0.5;
        y = yco + 0.5;
        i = 1;
        while (i <= length) {
            pt::setco(x, y);
            pt::draw();
            x = x + dx;
            y = y + dy;
            i = i + 1;
        }
        pt::setco(x, y);
        pt::draw();
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Default values
    int x = 100, y = 70, r = 30; // Circle center (100, 70), radius 30
    int x1 = 40, y1 = 40, x2 = 100, y2 = 124; // Line 1 coordinates
    int x3 = 40, y3 = 40, x4 = 160, y4 = 40; // Line 2 coordinates
    int x5 = 160, y5 = 40, x6 = 100, y6 = 124; // Line 3 coordinates

    int xmax = getmaxx();
    int ymax = getmaxy();
    int xmid = xmax / 2;
    int ymid = ymax / 2;

    dcircle c;
    setcolor(1);

    c.setoff(xmid, ymid);
    line(xmid, 0, xmid, ymax);
    line(0, ymid, xmax, ymid);
    setcolor(15);

    c.drawc(x, y, r); // Draw the circle

    // Draw lines
    pt p1;
    p1.setco(100, 100);
    p1.setcolor(14);

    dline l;
    l.setline(x1 + xmid, ymid - y1, x2 + xmid, ymid - y2); // Line 1
    l.drawl(15);

    l.setline(x3 + xmid, ymid - y3, x4 + xmid, ymid - y4); // Line 2
    l.drawl(15);

    l.setline(x5 + xmid, ymid - y5, x6 + xmid, ymid - y6); // Line 3
    l.drawl(15);

    // Draw second circle with default values
    x = 100;
    y = 62;
    r = 60; // Second circle
    setcolor(5);
    c.drawc(x, y, r);

    getch();
    delay(200);
    closegraph();
    return 0;
}
