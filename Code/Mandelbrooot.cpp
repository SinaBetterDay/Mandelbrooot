#include "ComplexPlane.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

using namespace sf;
using namespace std;

int main()
{
	Event event;
	VideoMode res(1920, 1080);
	VideoMode monitor = res.getDesktopMode();
	float monitorWidth = monitor.width;
	float monitorHeight = monitor.height;
	float aspectratio = monitorHeight / monitorWidth;
	ComplexPlane complex(aspectratio);
	RenderWindow window(res, "Mandlebroooooooot", Style::Default);

	Font font;
	font.loadFromFile("./fonts/Game Of Squids.ttf");
	Text textbox("test", font, 15);
	textbox.setFillColor(sf::Color::White);
	textbox.setOutlineColor(sf::Color::Black);
	textbox.setScale(1, 1);
	textbox.setStyle(sf::Text::Bold);
	textbox.setPosition(0, 0);

	VertexArray vertices(Points, monitorHeight * monitorWidth);
	enum CurrentState { CALCULATING, DISPLAYING };
	CurrentState state = CALCULATING;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
			}
			if (event.type == Event::Closed) { window.close(); }
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2f clicked;
				clicked = window.mapPixelToCoords(Mouse::getPosition(window), complex.getView());

				if (event.mouseButton.button == Mouse::Left) { complex.zoomIn(); }
				if (event.mouseButton.button == Mouse::Right) { complex.zoomOut(); }
				complex.setCenter(clicked);
				state = CALCULATING;
			}

			if (event.type == Event::MouseMoved)
			{
				complex.setMouseLocation(window.mapPixelToCoords(Mouse::getPosition(window), complex.getView()));
			}
		}
		if (state == CALCULATING)
		{
			const int NUM_OF_THREADS = 16;

			//multithreading
			int step = static_cast<int>(monitorWidth) / NUM_OF_THREADS;
			thread t[NUM_OF_THREADS];

			for (int j = 0; j < monitorWidth; j++)
			{
				for (int i = 0; i < monitorHeight; i++)
				{
					size_t counter = 0;
					Uint8 r, g, b = 255;
					vertices[j + i * monitorWidth].position = { (float)j,(float)i };
					Vector2i points{ j,i };
					Vector2f coords = window.mapPixelToCoords(points, complex.getView());
					counter = complex.countIterations(coords);
					complex.iterationsToRGB(counter, r, g, b);
					vertices[j + i * monitorWidth].color = { r,g,b };
				}
			}
			state = DISPLAYING;
			complex.loadText(textbox);

		}

		window.clear();
		window.draw(vertices);
		window.draw(textbox);
		window.display();
		
	}
	return 0;
}
