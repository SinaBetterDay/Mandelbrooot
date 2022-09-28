#include <iostream>
#include <SFML/Graphics>

using namespace std;
using namespace sf;

const int width = 1920;
const int height = 1080;


void gen_mandelbrot(VertexArray& va, int shift_x, int shift_y, int max_iter, float zoom)
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      long double x = ((long double)j - shift_x) / zoom;
      long double y = ((long double)u - shift_y) / zoom;
      
      complex<long double> c(x,y);
      int n = 0; //number of iterations, we have to keep track of this variable
      
      complex<long double> z(0.0, 0.0);
      
      for (int k = 0; k < max_iter; k++)
      {
        complex<long double> z2(0.0, 0.0);
        z2.real(real(z) * real(z) - imag(z) * imag(z));
        z2.imag(2 * real(z) * imag(z));
        
        z2.real(real(z2) + real(c)); // add c to z
        z2.imag(imag(z2) + imag(c));
        
        n++;
        
        // to break of this loop, we either reach teh max_iter
        // or the absolute(z+z) > 2

int main() {
  String title = "Mandelbrot_Plotter";
  RenderWindow w(VideoMode (width, height), titles);
  
  
  
  return 0;
}
