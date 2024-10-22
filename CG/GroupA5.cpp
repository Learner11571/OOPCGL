#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;

struct Point {
    int x, y;
};

// Function to draw a concave polygon
void drawPolygon(Point points[], int n) {
    for (int i = 0; i < n - 1; i++) {
        line(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
    }
    line(points[n - 1].x, points[n - 1].y, points[0].x, points[0].y); // Closing the polygon
}

// Function to apply scan-line fill algorithm
void scanLineFill(Point points[], int n) {
    int minY = points[0].y, maxY = points[0].y;

    // Find the minimum and maximum y-coordinates
    for (int i = 1; i < n; i++) {
        if (points[i].y < minY) {
            minY = points[i].y;
        }
        if (points[i].y > maxY) {
            maxY = points[i].y;
        }
    }

    // Scan through each horizontal line from minY to maxY
    for (int y = minY; y <= maxY; y++) {
        int intersections[20], k = 0;
        
        // Find all intersections of the polygon edges with the scanline
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            if ((points[i].y <= y && points[next].y > y) || (points[i].y > y && points[next].y <= y)) {
                // Calculate the x-coordinate of the intersection point
                int x = points[i].x + (y - points[i].y) * (points[next].x - points[i].x) / (points[next].y - points[i].y);
                intersections[k++] = x;
            }
        }

        // Sort the intersection points (from left to right)
        for (int i = 0; i < k - 1; i++) {
            for (int j = i + 1; j < k; j++) {
                if (intersections[i] > intersections[j]) {
                    swap(intersections[i], intersections[j]);
                }
            }
        }

        // Fill the pixels between pairs of intersections
        for (int i = 0; i < k; i += 2) {
            for (int x = intersections[i]; x <= intersections[i + 1]; x++) {
                putpixel(x, y, YELLOW);  // Fill with yellow color
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Initialize the graphics system

    Point points[] = {{100, 100}, {200, 50}, {300, 100}, {250, 200}, {150, 200}};  // Vertices of a concave polygon
    int n = 5;  // Number of vertices

    drawPolygon(points, n);  // Draw the polygon
    scanLineFill(points, n);  // Fill the polygon

    getch();  // Wait for key press to close the program
    closegraph();  // Close the graphics mode

    return 0;
}
