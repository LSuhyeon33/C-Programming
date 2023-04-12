#pragma once
class Point{
    public:
        // constructors
        Point();
        Point(int coordX, int coordY);
        
        int getX() const;
        int getY() const;
        
        void setX(int x);
        void setY(int y);

        bool operator ==(const Point& point);
        
        Point& operator =(const Point& point);
    private:
        int x, y;
};
