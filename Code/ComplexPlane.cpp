#include <iostream>
#include <vector>     
#include <complex> 
#include <iomanip>
#include <SFML/Graphics.hpp>
#include "ComplexPlane.h"




Defineset::Defineset(unsigned int _xpixels, unsigned int _ypixels)
{
    xpixels = _xpixels;
    ypixels = _ypixels;
    points.setPrimitiveType(sf::Points);
    points.resize(ypixels * xpixels);

}
void Defineset::calcuatevetex()
{
    ///sf::VertexArray points(sf::Points, xpixels + 1 + ypixels * xpixels);
        

    for (int j = 0; j < xpixels; j++)
    {
        for (int i = 0; i < ypixels; i++)
        {

            point.x = j;
            point.y = i;
            convertxytocomplex();
            FindIterationsFromC();
            ConvertIterToColor();
            points[j + (i * xpixels)].position = point;
            points[j + (i * xpixels)].color = color;

        }
    }
    vArray = points;
}



sf::VertexArray& Defineset::recoverarray() {
    return vArray;
}
void Defineset::ConvertIterToColor() {

    int t = iter;
    int r = 9 * (1 - t) * pow(t, 3);
    int g = 15 * pow((1 - t), 2) * pow(t, 3);
    int b = 8.5 * pow((1 - t), 3) * t;
    color.r = r;
    color.g = g;
    color.b = b;

}
void Defineset::FindIterationsFromC()
{
    std::complex<float> z;
    for (int i = 0; i < MAX_ITER; i++) {
        z = z * z + c;
        if (abs(z) >= 2) {
            iter = i;
            return;


        }
        iter = 0;
    }
}

void Defineset::convertxytocomplex() {
    c = { (point.x - xpixels / 2) * BASE_ZOOM + xset,
        (point.y - xpixels / 2) * BASE_ZOOM + yset };



}
std::complex<float> Defineset::pullcomplexvalue() {
    return c;
}
int Defineset::returnxpixels() {
    return xpixels;
}
int Defineset::returnypixels() {
    return ypixels;
}
void Defineset::wkey() {
    yset -= 40 * BASE_ZOOM;
    calculate = true;
}
void Defineset::akey() {
    xset -= 40 * BASE_ZOOM;
    calculate = true;
}
void Defineset::skey() {
    yset += 40 * BASE_ZOOM;
    calculate = true;
}
void Defineset::dkey() {
    xset += 40 * BASE_ZOOM;
    calculate = true;
}
void Defineset::leftkey() {
    BASE_ZOOM /= 0.9;
    calculate = true;
}
void Defineset::rightkey() {
    BASE_ZOOM *= 0.9;
    calculate = true;
}
void Defineset::pluskey() {
    MAX_ITER = MAX_ITER + 10;
    calculate = true;
}
void Defineset::minuskey() {
    MAX_ITER = MAX_ITER - 10;
    calculate = true;
}
bool Defineset::pullbool() {
    return calculate;
}
void Defineset::setboolfalse() {
    calculate = false;
    
}
int Defineset::pulliter() {
    return MAX_ITER;
}
