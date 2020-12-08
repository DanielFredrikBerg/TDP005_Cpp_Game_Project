

#include "textured_object.h"

Textured_Object::Textured_Object(sf::FloatRect & rect, sf::Sprite & sprite)
: Game_Object{rect}, sprite{sprite}
{}


Update_Result Textured_Object::update(sf::Time const& time, Level & level)
{
    return Update_Result::none;
}

void Textured_Object::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}