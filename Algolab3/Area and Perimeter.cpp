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

        (ax < cx) ? minx = ax : minx = cx;  // x 값 크기비교
        (bx < dx) ? maxx = dx : maxx = bx;  // x 값 크기비교
        (ay < cy) ? miny = ay : miny = cy;  // y 값 크기비교
        (by < dy) ? maxy = dy : maxy = by;  // y 값 크기비교

        if (((maxx - minx) > ((bx - ax) + (dx - cx))) || ((maxy - miny) > ((by - ay) + (dy - cy)))) {  // 겹치치 않는 경우
            area = ((bx - ax) * (by - ay)) + ((dx - cx) * (dy - cy));
            per = 2 * ((bx - ax) + (by - ay) + (dx - cx) + (dy - cy));
        }
        else if ((((maxx - minx) == (bx - ax)) && ((maxy - miny) == (by - ay))) || (((maxx - minx) == (dx - cx)) && ((maxy - miny) == (dy - cy)))) {  // 포함되는 경우
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