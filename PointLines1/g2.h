#pragma once
class Point {
public:
	Point();
	Point(double x, double y);
	double getX();
	double getY();
	bool compare(Point a1);
private:
	double X;
	double Y;
};
class Line { 
public: 
	Line();
	Line(double a, double b, double c);
	double getA();
	double getB();
	double getC();
private:
	double A;
	double B;
	double C;
};
