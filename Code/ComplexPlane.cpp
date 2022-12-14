#include "ComplexPlane.h"


ComplexPlane::ComplexPlane(float aspectRatio) {

    m_aspectratio = aspectRatio;
    m_view.setSize(BASE_WIDTH, -BASE_HEIGHT * m_aspectratio);
    m_view.setCenter(0.0, 0.0);
    m_zoomcount = 0;

}

void ComplexPlane::zoomIn() {

    m_zoomcount++;

    float x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomcount));
    float y = BASE_HEIGHT * m_aspectratio * (pow(BASE_ZOOM, m_zoomcount));

    m_view.setSize(x, y);

}

void ComplexPlane::zoomOut() {

    m_zoomcount--;

    float x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomcount));
    float y = BASE_HEIGHT * m_aspectratio * (pow(BASE_ZOOM, m_zoomcount));

    m_view.setSize(x, y);

}

void ComplexPlane::setCenter(Vector2f coord) 
{
    m_view.setCenter(coord);
}

View ComplexPlane::getView()
{
    return m_view;
}

void ComplexPlane::setMouseLocation(Vector2f coord) 
{
    m_mouselocation = coord;
}

void ComplexPlane::loadText(Text& text) {

    text.setCharacterSize(25);
    text.setFillColor(Color::Black);
    text.setPosition(0, 0);

    Vector2f centerCoord;
    centerCoord = m_view.getCenter();

    
    stringstream ss;
    ss << "Mandelbroooooot" << endl;
    ss << "Center: (" << centerCoord.x << ", " << centerCoord.y << ")" << endl;
    ss << "Cursor: (" << m_mouselocation.x << ", " << m_mouselocation.y << ")" << endl;
    ss << "Left click to Zoom in" << endl;
    ss << "Right click to Zoom out" << endl;
    text.setString(ss.str());

}

size_t ComplexPlane::countIterations(Vector2f coord) {

	complex<double> c(coord.x, coord.y);
	complex<double> z(0, 0);
	size_t iter = 0;

	while (abs(z) < 2 && iter < MAX_ITER)
	{
		z = z * z + c;
		iter++;
	}
	return iter;

}


void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b) {

	
    if (count == MAX_ITER)
    {
        r = 0;
        g = 0;
        b = 0;
    }

    else if (count > 57) {
        r = 0;
        g = 100;
        b = 0;
    }

    else if (count > 49) {
        r = 34;
        g = 139;
        b = 34;
    }

    else if (count > 41)
    {
        r = 13;
        g = 152;
        b = 186;
    }

    else if (count > 33)
    {
        r = 13;
        g = 124;
        b = 184;
    }

    else if (count > 25)
    {
        r = 13;
        g = 53;
        b = 184;
    }

    else if (count > 17)
    {
        r = 56;
        g = 13;
        b = 184;
    }

    else if (count > 9)
    {
        r = 98;
        g = 0;
        b = 255;
    }

    else
    {
        r = 255;
        g = 255;
        b = 255;
    }


}
