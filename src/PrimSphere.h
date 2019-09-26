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
		// --- PUT YOUR CODE HERE ---
		float x = ray.dir.dot(ray.dir);
		float y = 2 * ray.dir.dot(ray.org - m_center);
		float z = (ray.org - m_center).dot(ray.org - m_center) - m_radius * m_radius;
		float test = y * y - (4 * x * z);
		if (test < 0)
		{
			return false;
		}
		float t = ((-y) + sqrt(test)) / x;
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
