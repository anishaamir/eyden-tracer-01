// Triangle Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once
#include "Prim.h"
/**
 * @brief Triangle Geaometrical Primitive class
 */
class CPrimTriangle : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param a Position of the first vertex
	 * @param b Position of the second vertex
	 * @param c Position of the third vertex
	 */
	CPrimTriangle(Vec3f color, Vec3f a, Vec3f b, Vec3f c)
		: CPrim(color), v_x(a), v_y(b), v_z(c)
	{
	}
	virtual ~CPrimTriangle(void) = default;
	virtual bool Intersect(Ray &ray) override
	{
		Vec3f nab = (v_y - ray.org).cross(v_x - ray.org);
		Vec3f nbc = (v_z - ray.org).cross(v_y - ray.org);
		Vec3f nca = (v_x - ray.org).cross(v_z - ray.org);
		float trea = nab.dot(ray.dir) + nbc.dot(ray.dir) + nca.dot(ray.dir);
		float l1 = nab.dot(ray.dir) / trea;
		float l2 = nbc.dot(ray.dir) / trea;
		float l3 = nca.dot(ray.dir) / trea;
		if (l1 < 0 || l2 < 0 || l3 < 0)
		{
			return false;
		}
		Vec3f p = l1 * v_x + l2 * v_y + l3 * v_z;
		float t = p[0] / ray.dir[0];
		if (t < Epsilon || t > ray.t)
		{
			return false;
		}
		ray.t = t;
		return true;
	}

private:
	Vec3f v_x;
	Vec3f v_y;
	Vec3f v_z;
};