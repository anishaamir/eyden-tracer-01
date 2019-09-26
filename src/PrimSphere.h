// Sphere Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once
#include "Prim.h"
/**
 * @brief Sphere Geaometrical Primitive class
 */
class CPrimSphere : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param center Position of the center of the sphere
	 * @param radius Radius of the sphere
	 */
	CPrimSphere(Vec3f color, Vec3f center, float radius)
		: CPrim(color), m_center(center), m_radius(radius)
	{
	}
	virtual ~CPrimSphere(void) = default;
	virtual bool Intersect(Ray &ray) override
	{
		Vec3f v1 = ray.org - m_center;
		float i = ray.dir.dot(ray.dir);
		float j = 2 * ray.dir.dot(v1);
		float k = v1.dot(v1) - m_radius * m_radius;
		float l = j * j - 4 * i * k;
		if (l < 0)
		{
			return false;
		}
		float t = (-j - sqrt(l)) / i;
		if (t < Epsilon)
		{
			t = (-j + sqrt(l)) / i;
		}
		if (t < Epsilon || t > ray.t)
		{
			return false;
		}
		ray.t = t;
		return true;
	}

private:
	Vec3f m_center;
	float m_radius;
};
