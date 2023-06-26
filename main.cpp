
#include "API.h"
#include "writefile.h"

using namespace std;

int main()
{
	string cyls, spheres, planes;
	cyls = CreateShapes({ ShapeType::Cylinder, 10, 0 });
	spheres = CreateShapes({ ShapeType::Sphere, 10, 0 });
	planes = CreateShapes({ ShapeType::Plane, 10, 0 });
	WriteFile("cyl.csv", cyls);
	WriteFile("sph.csv", spheres);
	WriteFile("planes.csv", planes);
	return 0;
}
