#include "Map.h"
#include "Screen.h"
#include "Player.h"
#include "Merchant.h"
#include <math.h>
#include "Enemy.h"
#include <SFML\Graphics.hpp>
class Play : public Screen
{
public:
	Play(sf::RenderWindow *window, GameState *state);
	void Update(sf::Time dt);
	void Draw(sf::RenderWindow *window);
	void HandleCollision();
	//Map demoMap;
	//sf::Texture mapTexture;
	Player player;
	Enemy enemy;
	sf::View view;
	sf::Keyboard keyboard;
	sf::Keyboard pastKeyboard;
	//Merchant merchant;
	sf::View playerView;
	sf::Texture blankTexture;
	sf::Sprite backgroundSprite;
	sf::Shader backgroundShader;
	float timeSinceStart;
	float distBetween(sf::Vector2f playerPos, sf::Vector2f OtherPos);
	void handleEvent(sf::Event e);
	std::vector<Enemy> smallSinWaveEnemies;
	std::vector<Enemy> largeSinWaveEnemies;
	std::vector<Enemy> goToCenterEnemies;
	std::vector<Enemy> leftToRightEnemies;
	std::vector<Enemy> rightToLeftEnemies;
};