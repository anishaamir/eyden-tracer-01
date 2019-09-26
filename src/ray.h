// Basic ray structure
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "types.h"

/// Basic ray structure
struct Ray
{
	Vec3f org;
	Vec3f dir;
	float t; 
};
