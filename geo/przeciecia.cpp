#include<bits/stdc++.h>
using namespace std;

struct point{
	int x, y;
};

bool onSegment(double x1, double y1, double x2, double y2, double px, double py) {
    return min(x1, x2) <= px && px <= max(x1, x2) && min(y1, y2) <= py && py <= max(y1, y2);
}

void check_intersect(point a, point b, point c, point d) {

    double A1 = b.y - a.y, B1 = a.x - b.x, C1 = A1 * a.x + B1 * a.y;
    double A2 = d.y - c.y, B2 = c.x - d.x, C2 = A2 * c.x + B2 * c.y;

    double det = A1 * B2 - A2 * B1;

    if (det == 0) {
        cout << "NIE\n";
        return;
    }

    double px = (B2 * C1 - B1 * C2) / det;
    double py = (A1 * C2 - A2 * C1) / det;

    if (onSegment(a.x, a.y, b.x, b.y, px, py) && onSegment(c.x, c.y, d.x, d.y, px, py)) {
        cout << fixed << setprecision(2) << px << " " << py << "\n";
    } else {
        cout << "NIE\n";
    }
}
