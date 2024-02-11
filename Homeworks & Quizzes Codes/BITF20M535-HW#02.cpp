#include "iostream"
#include "cmath"
using namespace std;

class Cuboids
{
    float height;
    float width;
    float depth;

public:
    //Default constructor #03
    Cuboids()
    {
        height = 1;
        width = 1;
        depth = 1;
    }

    //Parametrize constructor #01
    Cuboids(float height, float width, float depth)
    {
        if (height > 0 && height < 35.00)
        {
            this->height = height;
        }
        else
        {
            this->height = 1;
        }

        if (width > 0 && width < 35.00)
        {
            this->width = width;
        }
        else
        {
            this->width = 1;
        }

        if (depth > 0 && depth < 35.00)
        {
            this->depth = depth;
        }
        else
        {
            this->depth = 1;
        }
    }

    //Parametrize constructor #02
    Cuboids(float height, float width)
    {
        if (height > 0 && height < 35.00)
        {
            this->height = height;
        }
        else
        {
            this->height = 1;
        }

        if (width > 0 && width < 35.00)
        {
            this->width = width;
        }
        else
        {
            this->width = 1;
        }

        depth = 1;
    }

    //Copy constructor #04
    Cuboids(Cuboids &rdx)
    {
        height = rdx.height;
        width = rdx.width;
        depth = rdx.depth;
    }

    //Destructor #05
    ~Cuboids()
    {
        cout << "\"Destructor executed...\"" << endl;
    }

    //Mutators
    void setHeight(float hgt)
    {
        if (hgt > 0 && hgt < 35.00)
        {
            height = hgt;
        }
    }

    void setWidth(float wdt)
    {
        if (wdt > 0 && wdt < 35.00)
        {
            width = wdt;
        }
    }

    void setDepth(float dpt)
    {
        if (dpt > 0 && dpt < 35.00)
        {
            depth = dpt;
        }
    }

    //Accessors
    float getHeight()
    {
        return height;
    }

    float getWidth()
    {
        return width;
    }

    float getDepth()
    {
        return depth;
    }

    //Member functions
    void setCuboids(float height, float width, float depth)
    {
        if (height > 0 && height < 35.00)
        {
            this->height = height;
        }
        if (width > 0 && width < 35.00)
        {
            this->width = width;
        }
        if (depth > 0 && depth < 35.00)
        {
            this->depth = depth;
        }
    }

    void getCuboids()
    {
        float hgt = 0, wdt = 0, dpt = 0;

        cout << "Enter height: ";
        cin >> hgt;
        cout << "Enter width: ";
        cin >> wdt;
        cout << "Enter depth: ";
        cin >> dpt;

        if (hgt > 0 && hgt < 35.00)
        {
            height = hgt;
        }

        if (wdt > 0 && wdt < 35.00)
        {
            width = wdt;
        }

        if (dpt > 0 && dpt < 35.00)
        {
            depth = dpt;
        }
    }

    void putCuboids()
    {
        cout << "Height of Cuboid = " << height << endl;
        cout << "Width of Cuboid = " << width << endl;
        cout << "Depth of Cuboid = " << depth << endl;
    }

    float getSurfaceArea()
    {
        float surfaceArea = 0;

        surfaceArea = 2 * (height * width) + 2 * (height * depth) + 2 * (width * depth);

        return surfaceArea;
    }

    float getVolume()
    {
        float volume = 0;

        volume = height * width * depth;

        return volume;
    }

    float getSpaceDiagonal()
    {
        float spaceDiagonal = 0;

        spaceDiagonal = sqrt(pow(height, 2) + pow(width, 2) + pow(depth, 2));

        return spaceDiagonal;
    }

    void putCuboidsInfo()
    {
        cout << "Surface Area = " << getSurfaceArea() << endl;
        cout << "Volume = " << getVolume() << endl;
        cout << "Space Diagonal = " << getSpaceDiagonal() << endl;
    }
};

int main()
{
    Cuboids rdx1, rdx2(5, -6, 27), rdx3(21, 7), rdx4(rdx2);

    //rdx1.setCuboids(-5, 28, -29);
    rdx1.getCuboids();

    /*rdx1.setHeight(14);
    rdx1.setWidth(27);
    rdx1.setDepth(-25);*/ 

    cout << rdx1.getSurfaceArea() << "\t" << rdx1.getVolume() << "\t" << rdx1.getSpaceDiagonal() << endl;
    //cout << rdx3.getHeight() << "\t" << rdx3.getWidth() << "\t" << rdx3.getDepth() << endl;

    rdx1.putCuboids();
    //rdx2.putCuboids();
    //rdx3.putCuboids();
    //rdx4.putCuboids();
    rdx1.putCuboidsInfo();
    return 0;
}