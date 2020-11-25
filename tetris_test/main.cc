#include <SFML/Graphics.hpp>

void update(sf::RenderWindow& window)
{
   window.clear();
}

int main() 
{
   sf::RenderWindow window{sf::VideoMode(1024, 768), "Hello World"};
   sf::CircleShape circle{40};
   circle.setPosition(sf::Vector2f{300, 300});

   sf::Event event;
   while (window.isOpen())
   {
      window.draw(circle);
      window.display();
      update(window);
      while (window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
         {
            window.close();
         }
         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
         {
            circle.move(sf::Vector2f{-1,0});
         }
         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
         {
            circle.move(sf::Vector2f{0,-1});
         }
         
      }
      
   }

   return 0;
}
