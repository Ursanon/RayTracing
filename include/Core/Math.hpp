#ifndef MATH_HPP_
#define MATH_HPP_

#include <functional>
#include <random>
#include "Core/Vector3.hpp"

namespace bs
{
	const float PI = 3.14159265358979f;
	const float TAU = 6.28318530718f;

	template <typename T = float>
	inline float clamp(const float& value, const float& min, const float& max)
	{
		if (value > max)
		{
			return max;
		}
		else if(value < min)
		{
			return min;
		}

		return value;
	}

	template <typename T = float>
	inline float clamp01(const float& value)
	{
		const int minimum = 0;
		const int maximum = 1;

		return clamp(value, minimum, maximum);
	}

	template <typename T = double>
	inline T random_range(const T& minimum, const T& maximum)
	{
		static std::uniform_real_distribution<T> distribution(minimum, maximum);
		static std::mt19937 generator;
		static std::function<T()> random_generator = std::bind(distribution, generator);

		return random_generator();
	}

	inline float random()
	{
		return (float)random_range(0.0, 1.0);
	}

	inline Vector3f random_in_shpere()
	{
		Vector3f point;
		do
		{
			point = Vector3f((float)random_range(-1.0, 1.0), (float)random_range(-1.0, 1.0), (float)random_range(-1.0, 1.0));
		} while (point.squard_magnitude() >= 1.0);

		return point;
	}

	inline Vector3f reflect(const Vector3f& vector, const Vector3f& normal)
	{
		return vector - (normal * 2 * vector.dot(normal));
	}

	inline Vector3f random_in_disk() 
	{
		Vector3f p;
		do
		{
			p = 2.f * Vector3f(random(), random(), 0) - Vector3f(1, 1, 0);
		} while (p.dot(p) >= 1.0);

		return p;
	}
}

#endif // !MATH_HPP_