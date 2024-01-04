#include <iostream>
#include "Platforms.h"
//constructor for movingPlatform
movingPlatform::movingPlatform(const sf::Vector2f& xandy, const sf::Vector2f& position) : sf::RectangleShape(xandy){
    //moving platform    
    setPosition(position);
}

int movingPlatform::getX(){
    return xVel;
}

int movingPlatform::getY(){
    return yVel;
}

void movingPlatform::setX(int newVel){
    xVel = newVel;
}

void movingPlatform::setY(int newVel){
    yVel = newVel;
}

//function for moving platform to collide with stationary platform
void movingPlatform::collidePlatform(const int bounderies, const sf::FloatRect bounds){
    //physics of moving platform

        if(getPosition().x > bounderies || getGlobalBounds().intersects(bounds)){
            xVel *= -1 ;
        }
        float newXPos = getPosition().x + xVel ;
        float newYPos = getPosition().y + yVel  ;
        setPosition(newXPos, newYPos);

}

//function for moving platform to collide with stationary platform
void movingPlatform::collidePlatformVert(const int bounderies, const sf::FloatRect bounds){
    //physics of moving platform

        if(getPosition().y < (bounderies * -1) || getGlobalBounds().intersects(bounds)){
            yVel *= -1 ;
        }
        float newXPos = getPosition().x + xVel ;
        float newYPos = getPosition().y + yVel  ;
        setPosition(newXPos, newYPos);

}