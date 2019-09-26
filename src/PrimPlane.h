// Plane Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once
#include "Prim.h"
/**
 * @brief The Plane Geaometrical Primitive class
 */
class CPrimPlane : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param origin Point on the plane
	 * @param normal Normal to the plane
	 */
	CPrimPlane(Vec3f color, Vec3f origin, Vec3f normal)
		: CPrim(color), m_normal(normal), m_origin(origin)
	{
		normalize(m_normal);
	}
	virtual ~CPrimPlane(void) = default;
	virtual bool Intersect(Ray &ray) override
	{
		// --- PUT YOUR CODE HERE ---
		float num = m_normal.dot(ray.org - m_origin);
		float dem = m_normal.dot(ray.dir);
		float t;
		if (dem == 0)
		{
			return 0;
		}
		else
		{
			t = num / dem;
		}
		if (t < Epsilon || t > ray.t)
		{
			return false;
		}
		ray.t = t;
		return true;
	}

private:
	Vec3f m_normal;
	Vec3f m_origin;
};