#include <iostream>
#include "g2.h"
#include <cmath>
double findA(Point x1, Point x2) // вираховуємо коефіціент а прямої 
{
	double a;
	if ((x1.getX() - x2.getX()) == 0)
		a = x2.getY() - x1.getY();
	else
	a = (x2.getY() - x1.getY()) / (x1.getX() - x2.getX());
	return a;
}
bool Opusana(Point a1, Point a2, Point a3, Point a4)// перевіряє на описаність
{
	if ((sqrt(pow((a2.getX() - a1.getX()), 2) + pow((a2.getY() - a1.getY()), 2)) + sqrt(pow((a4.getX() - a3.getX()), 2) + pow((a4.getY() - a3.getY()), 2))) == (sqrt(pow((a3.getX() - a2.getX()), 2.0) + pow((a3.getY() - a2.getY()), 2)) + sqrt(pow((a1.getX() - a4.getX()), 2) + pow((a1.getY() - a4.getY()), 2))))
		return 1;
	else return 0;
}
bool DifferentPoints(Point a1, Point a2, Point a3, Point a4)// перевірка чи всі точки ламаної різні
{
	if ((a1.compare(a2) == 0) && (a1.compare(a3) == 0) && (a1.compare(a4) == 0) && (a2.compare(a4) == 0) && (a2.compare(a4) == 0) && (a3.compare(a4) == 0))
		return 1;
	else return 0;
}
double findB (Point x1,Point x2  )// знаходить коефіціент b прямої
{
	double b;
	if ((x1.getX() - x2.getX()) == 0)
		b = 0;
	else
		b = 1;
	return b;
 }
double findC(Point x1, Point x2) //знаходимо коефіціент с прямої
{
	double c;
	if ((x1.getX() - x2.getX()) == 0)
		c = x1.getX() * (x1.getY() - x2.getY());
	else
	c = x1.getX() * (x1.getY() - x2.getY()) / (x1.getX() - x2.getX()) - x1.getY();
	return c;
}
double pidstanovka(Line line, Point k)// виконує необхідні обчислення для перевірки опуклості
{
	double m;
    m = line.getA() * k.getX() + line.getB() * k.getY() + line.getC();
	return m;
}
bool poodunbik(Line line, Point k, Point l)// виконує необхідні обчислення для перевірки опуклості
{
	if (pidstanovka(line, k) * pidstanovka(line, l) > 0)
		return true;
	else return false;
}
bool Opukluy(Point a1, Point a2, Point a3, Point a4)//перевірка опуклості
{
	Line line12(findA(a1, a2), findB(a1,a2), findC(a1, a2));
	Line line23(findA(a2, a3), findB(a2, a3), findC(a2, a3));
	Line line34(findA(a3, a4), findB(a3, a4), findC(a3, a4));
	Line line41(findA(a4, a1), findB(a4, a1), findC(a4, a1));
	if ((poodunbik(line12, a3, a4) == 1) && (poodunbik(line23, a1, a4) == 1) && (poodunbik(line34, a1, a2) == 1) && (poodunbik(line41, a2, a3) == 1))
		return true;
	else return false;
}
bool colinear(Point a1, Point a2, Point a3, Point a4)//перевірка паралельності сторін( колінеарності відповідних векторів)
{
	if (((a4.getX() - a3.getX()) == 0) && ((a2.getX() - a1.getX()) == 0)) 
		return 1;
	else if  ((a4.getY() - a3.getY() == 0) && (a2.getY() - a1.getY() == 0))
		return true;
	else if ((a2.getX() - a1.getX()) / (a4.getX() - a3.getX()) == ((a2.getY() - a1.getY()) / (a4.getY() - a3.getY())))
		return 1;
	else return 0;
}
bool Trapetion(Point a1, Point a2, Point a3, Point a4)//перевірка чи є трапецією
{
	if (((colinear(a1, a2, a3, a4) == 1) && (colinear(a2, a3, a4, a1) == 0)) || ((colinear(a2, a3, a4, a1) == 1) && (colinear(a1, a2, a3, a4) == 0)))
		return 1;
	else return 0;



}
