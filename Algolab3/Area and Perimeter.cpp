#include <iostream>
using namespace std;

int main() {
    int numTestcase;
    cin >> numTestcase;

    for (int i = 0; i < numTestcase; i++) {
        int ax, ay, bx, by, cx, cy, dx, dy;
        int area = 0, per = 0;
        int minx, miny, maxx, maxy;
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

        (ax < cx) ? minx = ax : minx = cx;  // x �� ũ���
        (bx < dx) ? maxx = dx : maxx = bx;  // x �� ũ���
        (ay < cy) ? miny = ay : miny = cy;  // y �� ũ���
        (by < dy) ? maxy = dy : maxy = by;  // y �� ũ���

        if (((maxx - minx) > ((bx - ax) + (dx - cx))) || ((maxy - miny) > ((by - ay) + (dy - cy)))) {  // ��ġġ �ʴ� ���
            area = ((bx - ax) * (by - ay)) + ((dx - cx) * (dy - cy));
            per = 2 * ((bx - ax) + (by - ay) + (dx - cx) + (dy - cy));
        }
        else if ((((maxx - minx) == (bx - ax)) && ((maxy - miny) == (by - ay))) || (((maxx - minx) == (dx - cx)) && ((maxy - miny) == (dy - cy)))) {  // ���ԵǴ� ���
            area = (maxx - minx) * (maxy - miny);
            per = 2 * ((maxx - minx) + (maxy - miny));
        }
        else {
            area = ((bx - ax) * (by - ay)) + ((dx - cx) * (dy - cy)) - ((((bx - ax) + (dx - cx)) - (maxx - minx)) * (((by - ay) + (dy - cy)) - (maxy - miny)));
            per = (2 * ((bx - ax) + (by - ay) + (dx - cx) + (dy - cy))) - (2 * ((((bx - ax) + (dx - cx)) - (maxx - minx)) + (((by - ay) + (dy - cy)) - (maxy - miny))));
        }
        cout << area << " " << per << endl;
    }
    return 0;
}