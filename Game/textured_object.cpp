

#include "textured_object.h"

Textured_Object::Textured_Object(sf::FloatRect & rect, sf::Sprite & sprite)
: Game_Object{rect}, sprite{sprite}
{}


void Textured_Object::update(sf::Time const& time, Level & level) {}

void Textured_Object::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}