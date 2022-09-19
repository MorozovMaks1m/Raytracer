#include "vector3.h"

Vector3 RandomInUnitSphere()
{
    Vector3 p = Vector3::random(-1,1);
    while (p.length_squared() >= 1)
    {
        p = Vector3::random(-1,1);
    }
    return p;
}