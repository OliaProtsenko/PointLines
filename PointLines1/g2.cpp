#include <iostream>
#include "g2.h"
double stnd = 0;
Point::Point() :X(stnd), Y(stnd) {}
Point::Point(double x, double y) : X(x), Y(y) {}
double Point::getX() {
	return X;
}
double Point::getY() {
	return Y;
}
bool Point::compare(Point a1) {
	if ((X == a1.getX()) && (Y == a1.getY()))
		return 1;
	else return 0;
}
Line::Line() : A(stnd), B(stnd), C(stnd) {}
Line::Line(double a, double b, double c) : A(a), B(b), C(c) {}
double Line::getA() {
	return A;
}
double Line::getB() { return B; }
double Line::getC() { return C; }
using namespace std;