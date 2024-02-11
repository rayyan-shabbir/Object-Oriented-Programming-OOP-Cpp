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
        Point(int p = 0) {
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

        Circle(const Circle& obj) {
            this->st = obj.st;

            pt = new Point(*(obj.pt));
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

    Circle c(&s, p), c2(c);
    c2.display();
    return 0;
}