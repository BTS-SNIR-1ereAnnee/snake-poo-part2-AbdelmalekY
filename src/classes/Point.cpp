#include "Point.h"
#include "Board.h"
#include <iostream>


using namespace std;

Point::Point()
{
    m_x = m_y = 10;
    m_caractere='*';//modif
}

Point::Point(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
    m_caractere='*';//modif
}

Point::Point(int x, int y,char unCar/*modif*/)
{
    this->m_x = x;
    this->m_y = y;
    m_caractere=unCar;//modif
}

Point::Point(char unCar/*modif*/)
{
    m_x = m_y = 10;
    m_caractere=unCar;//modif
}

Point::Point()
{
    m_x = m_y = 10;
}
void Point::setPoint(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

void Point::moveDown()
{
    m_y++;
}

void Point::moveUp()
{
    m_y--;
}

void Point::moveRight()
{
    m_x++;
}
void Point::moveLeft()
{
    m_x--;
}

int Point::getX() const
{
    return m_x;
}


void Point::setX(int val)
{
    m_x = val;
}

int Point::getY() const
{
    return m_y;
}

void Point::setY(int val)
{
    m_y = val;
}


void Point::drawPoint()
{
    Board *b;
    b = Board::getInstance(); // dessine les points
    b->dessinerPoint(*this);
}

void Point::erasePoint()
{
    Board *b;
    b = Board::getInstance(); //efface les points
    b->effacerPoint(*this);
}

void Point::debug()
{
    cout << "(" << this->m_x << "," << this->m_y << ")";
}

//MODIF
char Point::getChar()
{
    return m_caractere;

}

void Point::setChar(char val)
{
    m_caractere=val;

}

Point::~Point()
{
    //dtor
}

