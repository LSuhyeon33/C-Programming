#ifndef _MY_POINT_H_
#define _MY_POINT_H_
class MyPoint
{
    public:
        // constructors
        MyPoint();
        MyPoint(int coordX, int coordY);
        MyPoint(const MyPoint& p);
        // accessor functions
        int getX() const;
        int getY() const;
        // mutator function
        void setX(int x);
        void setY(int y);
        // comparison operators
        bool operator== (const MyPoint& p) const;
        bool operator!= (const MyPoint& p) const;
        // utility functions
        int dist2sqr(const MyPoint& p) const; // �����Ÿ�(Euclidean distance)�� ������ ���
        int dist1(const MyPoint& p) const;    // �����Ÿ�(rectilinear distance)�� ���
    private:
        int x = 0; int y = 0;
};
#endif // _MY_POINT_H_ 