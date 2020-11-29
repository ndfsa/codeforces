#include <iostream>
#include <cmath>

const double pi = 4.0 * std::atan(1.0);

struct Vector2
{
	double x;
	double y;

	double size()
	{
		return std::sqrt(x * x + y * y);
	}

	double distance(Vector2& other)
	{
		return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
	}
	Vector2 operator-(Vector2& other)
	{
		return Vector2{ x - other.x, y - other.y };
	}
	double dot(Vector2& other)
	{
		return x * other.x + y * other.y;
	}
	double angle(Vector2& other)
	{
		return std::acos(dot(other) / (size() * other.size()));
	}
};

bool IsInt(double number)
{
	return (number - std::floor(number) > 0.9999 || number - std::floor(number) < 0.0001);
}

double GetN(double a, double b, double c)
{
	for (double i = 3; i < 101; i++)
	{
		double gamma = (2 * pi / i);
		if (IsInt(a / gamma) && IsInt(b / gamma) && IsInt(b / gamma))
		{
			return std::round(i);
		}
	}
}

int main()
{

	double n{};
	Vector2 p1{};
	std::cin >> p1.x >> p1.y;
	Vector2 p2{};
	std::cin >> p2.x >> p2.y;
	Vector2 p3{};
	std::cin >> p3.x >> p3.y;
	Vector2 C{};
	double cx1 = -(2 * (p1.x * p1.x + p1.y * p1.y - p2.x * p2.x - p2.y * p2.y) * (p2.y - p3.y)
		- 2 * (p1.y - p2.y) * (p2.x * p2.x + p2.y * p2.y - p3.x * p3.x - p3.y * p3.y));
	double cx2 = (4 * (p1.y * (p2.x - p3.x) + p2.y * p3.x - p2.x * p3.y + p1.x * (-p2.y + p3.y)));

	double cy1;
	double cy2;
	std::cout.precision(7);
	if (cx2 != 0)
	{
		cy1 = (-p2.x * p2.x * p3.x - p2.y * p2.y * p3.x +
			p2.x * p3.x * p3.x + p1.x * p1.x * (-p2.x + p3.x) + p1.y * p1.y * (-p2.x + p3.x) +
			p2.x * p3.y * p3.y + p1.x * (p2.x * p2.x + p2.y * p2.y - p3.x * p3.x - p3.y * p3.y));
		cy2 = (2 * (-p2.y * p3.x + p1.y * (-p2.x + p3.x) + p1.x * (p2.y - p3.y) +
			p2.x * p3.y));
		C.x = (cx1 / cx2);
		C.y = (cy1 / cy2);

		double circumrad = (C - p1).size();
		Vector2 Ax = p1 - C;
		Vector2 Bx = p2 - C;
		Vector2 Cx = p3 - C;
		n = GetN(Ax.angle(Bx), Bx.angle(Cx), Cx.angle(Ax));
		double area = 0.5 * n * circumrad * circumrad * std::sin(2 * pi / n);
		std::cout << std::fixed << area << std::endl;
	}
	return 0;
}