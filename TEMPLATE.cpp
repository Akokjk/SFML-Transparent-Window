#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <random>


int main()
{
    // Create an SFML window with context settings
    sf::ContextSettings settings;
    settings.attributeFlags = sf::ContextSettings::Attribute::Default;
    settings.depthBits = 24; // Adjust as needed
    settings.stencilBits = 8; // Adjust as needed
    settings.antialiasingLevel = 0; // Adjust as needed 
    sf::RenderWindow window(
    	sf::VideoMode(1920, 1080), 
    	"TEMPLATE", 
    	sf::Style::None,
        settings );
    window.setFramerateLimit(0);

    //Create a transparent window for windows 
     // Set the window transparency using the window handle
    HWND hwnd = window.getSystemHandle(); // Get the native window handle
    // Set window to be layered
    SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    // Set the alpha value for transparency (0 = fully transparent, 255 = fully opaque)
    SetLayeredWindowAttributes(hwnd, RGB(255, 255, 255), 255, LWA_COLORKEY | LWA_ALPHA);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
        	switch (event.type){
        		case sf::Event::Closed:
                	window.close();
                	break;
                case sf::Event::MouseMoved: 
            		break; 
                case sf::Event::KeyPressed:
                	switch(event.key.code){
                		case sf::Keyboard::Escape: 
                			window.close();
                			break; 
                	}
                    break;  
        	    case sf::Event::MouseButtonPressed: 
                    switch(event.mouseButton.button){
                        case sf::Mouse::Left:
                            break; 
         
                    }
            }
        	
        }

        window.clear(sf::Color(255,255,255));



        // Display the window
        window.display();
    }

    return 0;
}