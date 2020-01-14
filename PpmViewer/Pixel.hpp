#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include <istream>
#include <exception>
using namespace std;

class Pixel
{
private:
    int red;
    int green;
    int blue;

public:
    Pixel(int r = 0, int g = 0, int b = 0)
    {
        red = r;
        green = g;
        blue = b;
    }

    int getRed()
    {
        return red;
    }

    void setRed(int r)
    {
        red = r;
    }

    int getGreen()
    {
        return green;
    }

    void setGreen(int g)
    {
        green = g;
    }

    int getBlue()
    {
        return blue;
    }

    void setBlue(int b)
    {
        blue = b;
    }

    string toString()
    {
        ostringstream output{};
        output << red << " " << green << " "
            << blue;
        return output.str();
    }
};

#endif // !PIXEL_H
