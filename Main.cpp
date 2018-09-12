//included library section
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
int main()
{
	//game setup-------------------------------------------------------------------

	// make a variable called a gamewindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick draw",
		sf::Style::Titlebar | sf::Style::Close);

	//timer functionality
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeTillSignal = sf::seconds(0.0f);
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

		//------------------------------------------------------------------------
		//update
		//------------------------------------------------------------------------
		//update the clock each frame
		sf::Time frameTime = gameClock.restart();
		//------------------------------------------------------------------------
		//end update
		//------------------------------------------------------------------------

		//Clear the window to a single color
		gameWindow.clear(sf::Color::Black);

		//Draw section
		gameWindow.draw(buttonSprite);
	}//END WINDOW OPEN WHILE LOOP
	return 0;
}// END MAIN FUNCTION
