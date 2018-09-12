//included library section
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>
int main()
{
	//game setup-------------------------------------------------------------------

	// make a variable called a gamewindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick draw",
		sf::Style::Titlebar | sf::Style::Close);

	//seed our random number generator
	srand(time(NULL));

	//timer functionality
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeTillSignal = sf::seconds(5.0f);
	sf::Time timeSinceSignal = sf::seconds(0.0f);
	sf::Clock gameClock;

	//create button sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");
	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(
	gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
	gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2);


	//end game set up--------------------------------------------------------------




	//game loop-------------------------------------------------------------------
	//runs every frame untill the game window is closed
	while (gameWindow.isOpen())
	{
		//------------------------------------------------------------------------
		//input
		//------------------------------------------------------------------------
		// Check for input
		sf::Event gameEvent;

		while (gameWindow.pollEvent(gameEvent))
		{
			if (gameEvent.type == sf::Event::Closed)
			{
				//close game window
				gameWindow.close();

			}//END CLOSE EVENT

		}//END POLLING WHILE LOOP
		//------------------------------------------------------------------------
		//end input
		//------------------------------------------------------------------------
		//TOD:process events
		if (gameEvent.type == sf::Event::MouseButtonPressed)
		{
			//check if we hit the button
			if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
			{
				//we did!
				int range = (int)signalTimeUpperLimit - signalTimeLowerLimit;
				float signalSeconds = rand() % range + signalTimeLowerLimit;
				timeTillSignal = sf::seconds(signalSeconds);
			}
		}
		// check if the event is the close event
		if (gameEvent.type == sf::Event::Closed)
		{
			//close the game window
			gameWindow.close();
		}
	

		//------------------------------------------------------------------------
		//update
		//------------------------------------------------------------------------
		//update the clock each frame
		sf::Time frameTime = gameClock.restart();
		timeTillSignal = timeTillSignal - frameTime;

		if (timeTillSignal.asSeconds() <= 0.0f)
		{
			buttonSprite.setColor(sf::Color::Red);

		}
		//------------------------------------------------------------------------
		//end update
		//------------------------------------------------------------------------

		//Clear the window to a single color
		gameWindow.clear(sf::Color::Black);

		//Draw section
		gameWindow.draw(buttonSprite);

		gameWindow.display();
	}//END WINDOW OPEN WHILE LOOP
	return 0;
}// END MAIN FUNCTION
