#include <iostream>
using namespace std;

class Style {
    private:
        int st;
    public:
        Style(int s) {
            this->st = s;
        }

        void display() {
            cout << "Style st = " << st << endl;
        }
};

class Point {
    private:
        int pt;
    public:
        Point(int p) {
            this->pt = p;
        }

        void display() {
            cout << "Point pt = " << pt << endl;
        }
};

class Circle {
    private:
        Style *st;
        Point *pt;
    public:
        Circle (Style *s, Point p) {
            this->st = s;

            pt = new Point(p);
            //this->pt = pt;
        }
        ~Circle () {
            delete pt;
            cout << "Destructor Executed" << endl;
        }
        void display() {
            st->display();
            pt->display();

            cout << "Point Display()" << endl;
        }
};
int main() {
    Style s(2);
    Point p(3);

    Circle c(&s, p);
    c.display();
    return 0;
}