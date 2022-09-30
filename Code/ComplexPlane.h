#include <complex.h>
#include <SFML/Graphics.hpp>

const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;

class Defineset {
public:

   

    Defineset(unsigned int _xpixels, unsigned int _ypixels);
    void calcuatevetex();
    void convertxytocomplex();
    std::complex<float> pullcomplexvalue();
    void FindIterationsFromC();
    void ConvertIterToColor();
    sf::VertexArray& recoverarray();
    int returnxpixels();
    int returnypixels();
    void wkey();
    void akey();
    void skey();
    void dkey();
    void leftkey();
    void rightkey();
    void pluskey();
    void minuskey();
    bool pullbool();
    void setboolfalse();
    int pulliter();
    

private:
    sf::VertexArray vArray1;
    sf::VertexArray vArray;
    sf::Vector2f point;
    std::complex<float> c;
    int iter = 0;
    sf::Color color;
    sf::VertexArray points;
    unsigned int xpixels, ypixels;
    bool calculate = true;
    float xset = -0.5;
    float yset = 2.0;
    int MAX_ITER = 100;
    float BASE_ZOOM = 0.004;
    
    
};
