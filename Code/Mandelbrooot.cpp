#include <iostream>
#include <vector>     
#include <complex> 
#include <iomanip>
#include <SFML/Graphics.hpp>
#include "ComplexPlane.h"



using namespace std;
using namespace sf;

int main()
{
    Defineset mandle(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);


    // Create a window with the same pixel depth as the desktop

    sf::RenderWindow window;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(mandle.returnxpixels(), mandle.returnypixels()), "SFML window");
    window.setFramerateLimit(60);
    // run the program as long as the window is open

    sf::Text textcalc;
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }


    auto &clock = sf::Clock();

    text = sf::Text("", font, 24);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    text.setPosition({ 10, 5 });
    textcalc = sf::Text("", font, 24);

    textcalc.setFillColor(sf::Color::White);
    textcalc.setOutlineThickness(2);
    textcalc.setOutlineColor(sf::Color::Black);
    textcalc.setPosition({ 500, 500 });

    

    

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mandle.leftkey();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                mandle.rightkey();
            }
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                mandle.akey();
            }
            if (Keyboard::isKeyPressed(Keyboard::W)) {
                mandle.wkey();
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                mandle.skey();
            }
            if (Keyboard::isKeyPressed(Keyboard::D)) {
                mandle.dkey();
            }
            if (Keyboard::isKeyPressed(Keyboard::Add)) {
                mandle.pluskey();

            }
            if (Keyboard::isKeyPressed(Keyboard::Subtract)) {
                mandle.minuskey();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            };

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
        window.clear();
        if (mandle.pullbool() == true) {
            window.draw(text);
            window.draw(mandle.recoverarray());
        }

        if (mandle.pullbool() == true) {
            auto text_builder = std::ostringstream();
            text_builder << setw(4) << "Calculating";
            textcalc.setString(text_builder.str());
            window.draw(textcalc);
            window.display();


        }


        if (mandle.pullbool() == true) {
           
            mandle.calcuatevetex();
            mandle.setboolfalse();
            window.display();
            
        }
       
        auto text_builder = std::ostringstream();        
        text_builder << setw(4) << int(1 / clock.restart().asSeconds()) << " fps\n";
        text_builder << setw(4) << mandle.pulliter() << " iters\n";
        text_builder << setprecision(1) << std::scientific << (complex<float>)mandle.pulliter() / mandle.pullcomplexvalue() << '\n';
        text_builder << "Right Click:zoom" << endl << "Left Click:Unzoom" << endl << " + - for Iteration" << endl << " A W S D Movement";
        
        text.setString(text_builder.str());
        window.draw(mandle.recoverarray());
        window.draw(text);


    }
}
