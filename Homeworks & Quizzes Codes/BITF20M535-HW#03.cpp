#include "iostream"
#include "cmath"

using namespace std;

class Circle
{
    int x;
    int y;
    float radius;
    const double PI;

public:
    //MUTATORS
    void setX(int x1)
    {
        if (x1 >= -50 && x1 <= 50)
            x = x1;
        else
            x = 0;
    }

    void setY(int y1)
    {
        if (y1 >= -50 && y1 <= 50)
            y = y1;
        else
            y = 0;
    }

    void setRad(float rad1)
    {
        if (rad1 >= 1 && rad1 <= 10)
            radius = rad1;
        else
            radius = 5;
    }

    //ACCESSORS
    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    float getRad() const
    {
        return radius;
    }

    double getPi() const
    {
        return PI;
    }

    //CONSTRUCTORS
    //#04
    Circle() : PI(3.14159)
    {
        x = y = 0;
        radius = 5;
    }

    //#01
    Circle(int x1, int y1, float rad1) : PI(3.14159)
    {
        setX(x1);
        setY(y1);
        setRad(rad1);
    }

    //#02
    Circle(int x1, int y1) : PI(3.14159)
    {
        setX(x1);
        setY(y1);
        radius = 5;
    }

    //#03
    Circle(int x1, float rad1) : PI(3.14159)
    {
        setX(x1);
        setRad(rad1);
        y = 0;
    }

    //#05
    Circle(const Circle &rdx) : PI(rdx.PI)
    {
        x = rdx.x;
        y = rdx.y;
        radius = rdx.radius;
    }

    //#06
    ~Circle()
    {
        cout << "\"Destructor Executed...\"" << endl;
    }

    //MEMBER FUNCTION
    void setCircle(int x, int y, float radius)
    {
        if (x >= -50 && x <= 50)
            this->x = x;

        if (y >= -50 && y <= 50)
            this->y = y;

        if (radius >= 1 && radius <= 10)
            this->radius = radius;
    }

    void getCircle()
    {
        int x1, y1;
        float rad1;

        cout << "Enter x coordinate: ";
        cin >> x1;
        cout << "Enter y coordinate: ";
        cin >> y1;
        cout << "Enter Radius: ";
        cin >> rad1;

        setX(x1);
        setY(y1);
        setRad(rad1);
    }

    void putCircle() const
    {
        cout << "x = " << x << "\ty = " << y << "\tradius = " << radius << "\tPI = " << PI << endl;
    }

    float getArea()
    {
        float area = PI * pow(radius, 2);
        return area;
    }

    float getDiameter()
    {
        float diameter = radius * 2;
        return diameter;
    }

    float getCircumference()
    {
        float circumFerence = 2 * PI * radius;
        return circumFerence;
    }

    Circle addCircle(const Circle &rdx) const
    {
        Circle temp;

        temp.x = x + rdx.x;
        temp.y = y + rdx.y;
        temp.radius = radius + rdx.radius;

        return temp;
    }

    bool isEqual(const Circle &rdx) const
    {
        if ((x == rdx.x) && (y == rdx.y) && (radius == rdx.radius))
            return true;

        return false;
    }

    int findCircle(const Circle arr[], int size) const
    {
        for (int i = 0; i < size; i++)
        {
            if ((x == arr[i].x) && (y == arr[i].y) && (radius == arr[i].radius))
                return i;
        }

        return -1;
    }

    void updateObjects(Circle arr[], int size) const
    {
        for (int i = 0; i < size; i++)
        {
            if ((x == arr[i].x) && (y == arr[i].y))
                arr[i].radius = radius;
        }
    }
};

int main()
{
    float f = 6.6;
    Circle rdx1, rdx2(5, f), rdx3(5, 6), rdx4(1, 43, 7.9);
    //Circle arr[4] = {Circle(5, 6), Circle(1, 2, 3.3), Circle(1, 2, 6.7), Circle()};

    /*rdx1.getCircle();
    rdx1.updateObjects(arr, 4);
    //Circle t = (rdx1.addCircle(rdx4));
    for (int i = 0; i < 4; i++) arr[i].putCircle();
    //cout << "Index = " << ind << endl;
    //rdx1.setCircle(91, 67, 19.9);

    /*rdx1.setX(79);
    rdx1.setY(-6);
    rdx1.setRad(10);*/
    //cout << rdx1.getX() << endl << rdx1.getY() << endl << rdx1.getRad() << endl << rdx1.getPi() << endl;

    //t.putCircle();
    //rdx1.putCircle();
    //rdx2.putCircle();*/

    return 0;
}