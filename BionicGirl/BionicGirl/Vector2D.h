#pragma once
#include<math.h>

class Vector2D
{
public:
	Vector2D(double x, double y) : m_x(x), m_y(y) {}
	double getX() { return m_x; }
	double getY() { return m_y; }
	void setX(double x) { m_x = x; }
	void setY(double y) { m_y = y; }

	double length() { return sqrt(m_x * m_x + m_y * m_y); }
private:
	double m_x;
	double m_y;
};

