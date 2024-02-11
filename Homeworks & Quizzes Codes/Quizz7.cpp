#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point(const Point &obj)
    {
        x = obj.x;
        y = obj.y;
    }

    void print()
    {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }
};

class Style
{
    int color;
    bool isFilled;

public:
    Style() {
        
    }
    Style(int color, bool filled)
    {
        this->color = color;
        this->isFilled = filled;
    }

    void print()
    {
        cout << "color: " << color << endl;
        cout << "isFilled: " << isFilled << endl;
    }
};

class Circle
{
    Point *pt;
    Style *st;

public:
    Circle(const Circle &obj) :// st(obj.st)
    {
        // pt = new Point(*(obj.pt));
        // pt = new Point;
        // pt = obj.(*pt);

        st = new Style;
        st = obj.(*st);
    }

    Circle(Point p, Style *s)// :st(obj.st)
    {
        // pt = new Point(obj.pt);
        pt = new Point(p);
        st = s;
        // pt = &p;
    }

    ~Circle()
    {
        delete (pt);
        // st = NULL;
    }

    void display()
    {
        pt->print();
        st->print();
    }
};

int main()
{
    Point p(1, 2);
    Style s(35, 0);

    Circle c(p, &s);
    Circle c2(c);

    // c.display();
    c2.display();
    return 0;
}
