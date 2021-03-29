#pragma once

#include <cmath>
#include <iostream>

constexpr double pi = 3.14159265358979323846;

class Vector2D
{
	double m_x = 0;
	double m_y = 0;
public:
	explicit Vector2D(double x = 0, double y = 0) : m_x(x), m_y(y) {} 
	~Vector2D() = default;
	Vector2D(const Vector2D&) = default;
	Vector2D& operator=(const Vector2D&) = default;
	Vector2D(Vector2D&&) = default;
	Vector2D& operator=(Vector2D&&) = default;

	double getX() const { return m_x; }
	void setX(const double &x) { m_x = x; }
	double getY() const { return m_y; }
	void setY(const double &y) { m_y = y; }

	const Vector2D& rotate(const int& angle)
	{
        double old_x = m_x, old_y = m_y;
		//x2=cosβx1−sinβy1
		m_x = old_x * std::cos((angle*pi)/180) - old_y * std::sin((angle*pi)/180);
		//y2=sinβx1+cosβy1
		m_y = old_x * std::sin((angle*pi)/180) + old_y * std::cos((angle*pi)/180);
        return *this;
	}

	Vector2D operator+(const Vector2D &other) const
	{
		// a + b = {ax + bx; ay + by}
		Vector2D vec;
		vec.setX(m_x + other.getX());
		vec.setY(m_y + other.getY());
		return vec;
	}
	Vector2D operator-(const Vector2D &other) const
	{
		// a - b = {ax - bx; ay - by}
		Vector2D vec;
		vec.setX(m_x - other.getX());
		vec.setY(m_y - other.getY());
		return vec;
	}

	friend std::ostream& operator<< (std::ostream &out, const Vector2D &vector);
};

std::ostream& operator<< (std::ostream &out, const Vector2D &vector)
{ 
	out << "{ " << vector.m_x << " , " << vector.m_y << " }" << std::endl;
	return out;
}

typedef Vector2D Vector;