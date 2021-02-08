#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
using namespace std;
int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;
	//system("dir");
	sf::RenderWindow window(sf::VideoMode(23 * 40, 23 * 40), "SUDOKU", sf::Style::Close, settings);
	sf::Texture back;
	if (!back.loadFromFile("cursor.png"))
	{
		cout << "Error loading file" << endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(back);
	sf::Font font;

	if (!font.loadFromFile("Sunday Morning.ttf"))
	{
		cout << "error" << endl;
	}
	/*sf::Music music;
	if (!music.openFromFile("file_example_OOG_1MG.ogg"))
	{
		cout << "Error loading file" << endl;
	}*/
	bool start = true;
	sf::CircleShape cursor(10);
	cursor.setFillColor(sf::Color(255, 255, 255, 128));
	cursor.setOutlineThickness(5);
	cursor.setOutlineColor(sf::Color(250, 150, 100, 128));
	cursor.setPosition(15, 15);
	cursor.setOrigin(15, 15);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D && start == false && cursor.getPosition().x < 865 && (cursor.getPosition().x < 625 || (cursor.getPosition().x >= 625 && (cursor.getPosition().y < 425 || cursor.getPosition().y > 505))))
			{
				cout << "D has been pressed.\n";
				if (cursor.getPosition().x != 385 || (cursor.getPosition().x == 385 && (cursor.getPosition().y > 265 && cursor.getPosition().y < 665)))
				{
					cursor.move(sf::Vector2f(40, 0));
					cout << cursor.getPosition().x << endl;
				}
				else
				{
					cursor.move(sf::Vector2f(40 * 4, 0));
					cout << cursor.getPosition().x << endl;
				}


			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W && start == false && cursor.getPosition().y > 65 && (cursor.getPosition().y > 305 || (cursor.getPosition().y <= 305 && (cursor.getPosition().x < 425 || cursor.getPosition().x > 505))))
			{
				cout << "W has been pressed.\n";
				if (cursor.getPosition().y != 545 || (cursor.getPosition().y == 545 && (cursor.getPosition().x > 265 && cursor.getPosition().x < 665)))
				{
					cursor.move(sf::Vector2f(0, -40));
					cout << cursor.getPosition().y << endl;

				}
				else
				{
					cursor.move(sf::Vector2f(0, -40 * 4));
					cout << cursor.getPosition().y << endl;
				}

			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A && start == false && cursor.getPosition().x > 65 && (cursor.getPosition().x > 305 || (cursor.getPosition().x <= 305 && (cursor.getPosition().y < 425 || cursor.getPosition().y > 505))))
			{
				cout << "A has been pressed.\n";
				if (cursor.getPosition().x != 545 || (cursor.getPosition().x == 545 && (cursor.getPosition().y > 265 && cursor.getPosition().y < 665)))
				{
					cursor.move(sf::Vector2f(-40, 0));
					cout << cursor.getPosition().x << endl;
				}
				else
				{
					cursor.move(sf::Vector2f(-40 * 4, 0));
					cout << cursor.getPosition().x << endl;
				}

			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S && start == false && cursor.getPosition().y < 865 && (cursor.getPosition().y < 625 || (cursor.getPosition().y >= 625 && (cursor.getPosition().x < 425 || cursor.getPosition().x > 505))))
			{
				cout << "S has been pressed.\n";
				if (cursor.getPosition().y != 385 || (cursor.getPosition().y == 385 && (cursor.getPosition().x > 265 && cursor.getPosition().x < 665)))
				{
					cursor.move(sf::Vector2f(0, 40));
					cout << cursor.getPosition().y << endl;
				}
				else
				{
					cursor.move(sf::Vector2f(0, 40 * 4));
					cout << cursor.getPosition().y << endl;
				}

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			cout << "Space has been pressed.\n";
			if (start == true)
			{
				cursor.move(sf::Vector2f(50, 50));
				start = false;
			}
		}

		window.clear();
		/* sf::Text txt;
		 txt.setFont()*/
		 //q1
		float x1 = 40, x2 = 400, y1 = 40, y2 = 40;
		for (int i = 0; i < 10; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Color(0,204,204)),
				sf::Vertex(sf::Vector2f(x2, y2),sf::Color::Color(0,204,204))
			};
			y1 += 40, y2 += 40;
			window.draw(line, 2, sf::Lines);
		}
		x1 = 40, x2 = 40, y1 = 40, y2 = 400;
		for (int i = 0; i < 10; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Color(0,204,204)),
				sf::Vertex(sf::Vector2f(x2, y2),sf::Color::Color(0,204,204))
			};
			x1 += 40, x2 += 40;
			window.draw(line, 2, sf::Lines);
		}
		//q2
		x1 = 520, x2 = 880, y1 = 40, y2 = 40;
		for (int i = 0; i < 10; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Color(0,204,204)),
				sf::Vertex(sf::Vector2f(x2, y2),sf::Color::Color(0,204,204))
			};
			y1 += 40, y2 += 40;
			window.draw(line, 2, sf::Lines);
		}
		x1 = 520, x2 = 520, y1 = 40, y2 = 400;
		for (int i = 0; i < 10; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Color(0,204,204)),
				sf::Vertex(sf::Vector2f(x2, y2),sf::Color::Color(0,204,204))
			};
			x1 += 40, x2 += 40;
			window.draw(line, 2, sf::Lines);
		}
		//q3
		x1 = 40, x2 = 400, y1 = 520, y2 = 520;
		for (int i = 0; i < 10; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Color(0,204,204)),
				sf::Vertex(sf::Vector2f(x2, y2),sf::Color::Color(0,204,204))
			};
			y1 += 40, y2 += 40;
			window.draw(line, 2, sf::Lines);
		}
		x1 = 40, x2 = 40, y1 = 520, y2 = 880;
		for (int i = 0; i < 10; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Color(0,204,204)),
				sf::Vertex(sf::Vector2f(x2, y2),sf::Color::Color(0,204,204))
			};
			x1 += 40, x2 += 40;
			window.draw(line, 2, sf::Lines);
		}
		//q4
		x1 = 520, x2 = 880, y1 = 520, y2 = 520;
		for (int i = 0; i < 10; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Color(0,204,204)),
				sf::Vertex(sf::Vector2f(x2, y2),sf::Color::Color(0,204,204))
			};
			y1 += 40, y2 += 40;
			window.draw(line, 2, sf::Lines);
		}
		x1 = 520, x2 = 520, y1 = 520, y2 = 880;
		for (int i = 0; i < 10; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Color(0,204,204)),
				sf::Vertex(sf::Vector2f(x2, y2),sf::Color::Color(0,204,204))
			};
			x1 += 40, x2 += 40;
			window.draw(line, 2, sf::Lines);
		}
		//q5
		x1 = 280, x2 = 640, y1 = 280, y2 = 280;
		for (int i = 0; i < 10; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Color(0,204,204)),
				sf::Vertex(sf::Vector2f(x2, y2),sf::Color::Color(0,204,204))
			};
			y1 += 40, y2 += 40;
			window.draw(line, 2, sf::Lines);
		}
		x1 = 280, x2 = 280, y1 = 280, y2 = 640;
		for (int i = 0; i < 10; i++)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Color(0,204,204)),
				sf::Vertex(sf::Vector2f(x2, y2),sf::Color::Color(0,204,204))
			};
			x1 += 40, x2 += 40;
			window.draw(line, 2, sf::Lines);
		}
		window.draw(cursor);
		window.display();
	}

	return 0;
}