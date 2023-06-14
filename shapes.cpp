
#define _USE_MATH_DEFINES
#include "shapes.h"
#include "randomization.h"
#include <string>
#include <cmath>

// ����������� ����������� � �������� ���-��� ����� (Count)
Plane::Plane(int Count, double offset_x, double offset_y, double offset_z)
{
	Point_Count = Count;
	k_x = offset_x;
	k_y = offset_y;
	k_z = offset_z;
}

// ��������� ����������� � ���� �����
vector <Point> Plane::GetAsPoints(double o)
{
	vector <Point> p;
	Point dot;
	double angle = GetRandRealNumb(0, 360);
	double a = cos(angle * M_PI / 180.0);
	double b = sin(angle * M_PI / 180.0);
	for (int i = 0; i < Point_Count; i++) 
	{
		dot.x = GetRandRealNumb(0, 100) + k_x;
		dot.y = GetRandRealNumb(0, 100) + k_y;
		dot.z = -(a * dot.x + b * dot.y) + k_z;
		p.push_back(dot);
	}
	return p;
}

// ���������� ����������� � ���� ������ ��� ������ .csv
string Plane::GetAsCSV(vector <vector <Point>> f)
{
	string str;
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < f[i].size(); j++)
		{
			str += to_string(i + 1) + ";" + "3" + ";" + to_string(f[i][j].x) + ";" + to_string(f[i][j].y) + ";" + to_string(f[i][j].z) + "\n";
		}
	}
	return str;
}

string Plane::GetAsCSV(vector <Point> p)
{
	string str;
	int num = NumberInCSV();
	for (int i = 0; i < p.size(); i++)
	{
		str += to_string(num) + ";" + "3" + ";" + to_string(p[i].x) + ";" + to_string(p[i].y) + ";" + to_string(p[i].z) + "\n";
	}
	return str;
}

// ���������� ����������� � ���� ������ ��� ������ .json
string Plane::GetAsJSON(vector <vector <Point>> f)
{
	string str;
	return str;
}
// ����������� ���������� ��������
//Cylinder::Cylinder()
//{
//	
//	h = GetRandRealNumb(5, 100);
//	r = GetRandRealNumb(5, 100);
//	// ��������� ��������� � ������� ��������
//	CreateFooting(r, h);
//
//	// ��������� ������ ��������
//	CreateWalls(r, h);
//	f.push_back(p);
//	++ID();
//}

// ����������� �������� � �������� �������� � �������
Cylinder::Cylinder(double radius, double height, double offset_x, double offset_y, double offset_z)
{
	r = radius;
	h = height;
	k_x = offset_x;
	k_y = offset_y;
	k_z = offset_z;
}

// ��������� �������� � ���� ����� � ���������� �������������� ��� ������ ����� � ������� ����������� o
vector <Point> Cylinder::GetAsPoints(double o)
{
	vector <Point> p;
	vector <Point> hlp;
	if (o == 0)
	{
		//hlp = CreateFooting(r, h);
		//p.insert(p.end(), hlp.begin(), hlp.end());
		hlp = CreateWalls();
		p.insert(p.end(), hlp.begin(), hlp.end());
	}
	else
	{
		//hlp = CreateFooting(r, h, o);
		//p.insert(p.end(), hlp.begin(), hlp.end());
		hlp = CreateWalls(o);
		p.insert(p.end(), hlp.begin(), hlp.end());
	}
	return p;
}

// ����������� ��������� �����
//Sphere::Sphere()
//{
	
	//r = GetRandRealNumb(5, 100);
	//// ��������� ���������� ���������� �����
	//CreateFooting(r);

	//// ��������� ������� ���������
	//CreateUpHemisphere(r);

	//// ��������� ������ ���������
	//CreateDownHemisphere(r);

	//f.push_back(p);
	//++ID();
//}

// ����������� ����� � �������� ��������
Sphere::Sphere(double radius, double offset_x, double offset_y, double offset_z)
{
	r = radius;
	k_x = offset_x;
	k_y = offset_y;
	k_z = offset_z;
}

// ���������� ������� � ���� ������ ��� ������ .csv
string Cylinder::GetAsCSV(vector <vector <Point>> f)
{
	string str;
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < f[i].size(); j++)
		{
			str += to_string(i+1) + ";" + "1" + ";" + to_string(f[i][j].x) + ";" + to_string(f[i][j].y) + ";" + to_string(f[i][j].z) + "\n";
		}	
	}
	return str;
}

string Cylinder::GetAsCSV(vector <Point> p)
{
	string str;
	int num = NumberInCSV();
	for (int i = 0; i < p.size(); i++)
	{
		str += to_string(num) + ";" + "1" + ";" + to_string(p[i].x) + ";" + to_string(p[i].y) + ";" + to_string(p[i].z) + "\n";
	}
	return str;
}

// ���������� ������� � ���� ������ ��� ������ .json
string Cylinder::GetAsJSON(vector <vector <Point>> f)
{	
	string str;
	//++NumberInJSON();
	//if (NumberInJSON() == 1)
	//{
	//	str += "{ \n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 1,\n";
	//}
	//else
	//{
	//	str += "\n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 1,\n";
	//}
	//str += "\"X\": [\n";
	//for (int i = 0; i < p.size(); i++)
	//{
	//	if (i == p.size() - 1)
	//	{
	//		str += to_string(p[i].x) + "\n";
	//		break;
	//	}
	//	str += to_string(p[i].x) + ",\n";
	//	
	//}
	//str += "],\n";
	//str += "\"Y\": [\n";
	//for (int i = 0; i < p.size(); i++)
	//{
	//	if (i == p.size() - 1)
	//	{
	//		str += to_string(p[i].y) + "\n";
	//		break;
	//	}
	//	str += to_string(p[i].y) + ",\n";

	//}
	//str += "],\n";
	//str += "\"Z\": [\n";
	//for (int i = 0; i < p.size(); i++)
	//{
	//	if (i == p.size() - 1)
	//	{
	//		str += to_string(p[i].z) + "\n";
	//		break;
	//	}
	//	str += to_string(p[i].z) + ",\n";

	//}
	//str += "]\n";
	//str += "},\n";
	return str;
}

//// ���������� ����� � ���� ������ ��� ������ .csv
//string Sphere::GetAsCSV()
//
//{
//	string str;
//	++NumberInCSV();
//	for (int i = 0; i < p.size(); i++)
//	{
//		str += to_string(NumberInCSV()) + ";" + "2" + ";" + to_string(ID()) + ";" + to_string(p[i].x) + ";" + to_string(p[i].y) + ";" + to_string(p[i].z) + "\n";
//	}
//	return str;
//}

// ���������� ����� � ���� ������ ��� ������ .json
//string Sphere::GetAsJSON()
//{
//	string str;
//	++NumberInJSON();
//	if (NumberInJSON() == 1)
//	{
//		str += "{ \n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 2,\n";
//	}
//	else
//	{
//		str += "\n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 2,\n";
//	}
//	str += "\"X\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].x) + "\n";
//			break;
//		}
//		str += to_string(p[i].x) + ",\n";
//
//	}
//	str += "],\n";
//	str += "\"Y\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].y) + "\n";
//			break;
//		}
//		str += to_string(p[i].y) + ",\n";
//
//	}
//	str += "],\n";
//	str += "\"Z\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].z) + "\n";
//			break;
//		}
//		str += to_string(p[i].z) + ",\n";
//
//	}
//	str += "]\n";
//	str += "},\n";
//	return str;
//}

// ���������� ����������� � ���� ������ ��� ������ .json
//string Plane::GetAsJSON()
//{
//	string str;
//	++NumberInJSON();
//	if (NumberInJSON() == 1)
//	{
//		str += "{ \n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 3,\n";
//	}
//	else
//	{
//		str += "\n \"Figure " + to_string(NumberInJSON()) + "\": {\n \"Type\": 3,\n";
//	}
//	str += "\"X\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].x) + "\n";
//			break;
//		}
//		str += to_string(p[i].x) + ",\n";
//
//	}
//	str += "],\n";
//	str += "\"Y\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].y) + "\n";
//			break;
//		}
//		str += to_string(p[i].y) + ",\n";
//
//	}
//	str += "],\n";
//	str += "\"Z\": [\n";
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (i == p.size() - 1)
//		{
//			str += to_string(p[i].z) + "\n";
//			break;
//		}
//		str += to_string(p[i].z) + ",\n";
//
//	}
//	str += "]\n";
//	str += "},\n";
//	return str;
//}

// ������� ��������� ��������� � ������� ��������
vector <Point> Cylinder::CreateFooting(double r, double h)
{
	vector <Point> p;
	Point dot;
	// x = r*cos(fi), y = r * sin(fi)
	double hlp_r = r;
	for (r; r > 0; r -= 2)  // ��������� ������� ����� ��� ���������� ���������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = r * cos(i);
			dot.y = 0;
			dot.z = r * sin(i);
			p.push_back(dot);
		}
	}
	for (hlp_r; hlp_r > 0; hlp_r -= 2)  // ��������� ������� ����� ��� ���������� �������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = hlp_r * cos(i);
			dot.y = h;
			dot.z = hlp_r * sin(i);
			p.push_back(dot);

		}
	}
	return p;
}

// ������� ��������� ��������� � ������� �������� � ���������� �������������� �����
vector <Point> Cylinder::CreateFooting(double r, double h, double o)
{
	vector <Point> p;
	Point dot;
	// x = r*cos(fi), y = r * sin(fi)
	double hlp_r = r;
	for (r; r > 0; r -= 2)  // ��������� ������� ����� ��� ���������� ���������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = GetNormDistNumb(r * cos(i),o);
			dot.y = GetNormDistNumb(0, o);;
			dot.z = GetNormDistNumb(r * sin(i), o);
			p.push_back(dot);
		}
	}
	for (hlp_r; hlp_r > 0; hlp_r -= 2)  // ��������� ������� ����� ��� ���������� �������
	{
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = GetNormDistNumb(hlp_r * cos(i),o);
			dot.y = GetNormDistNumb(h, o);
			dot.z = GetNormDistNumb(hlp_r * sin(i), o);
			p.push_back(dot);

		}
	}
	return p;
}

//Point rotatePoints(Point& point, double angle)
//{
//	double cosTheta = cos(angle);
//	double sinTheta = sin(angle);
//	Point rotatedPoint;
//	rotatedPoint.x = point.x * cosTheta + point.z * sinTheta;
//	rotatedPoint.y = point.y;
//	rotatedPoint.z = -point.x * sinTheta + point.z * cosTheta;
//	return rotatedPoint;
//}

// ������� ��������� ������ ��������
vector <Point> Cylinder::CreateWalls()
{
	vector <Point> p;
	Point dot;
	Point newp;
	double hlp_y = 0;
	double k = 0;
	double theta = GetRandIntNumb(0, 360) * M_PI / 180.0f;
	while (hlp_y < h)
	{
		k = GetRandRealNumb(2, 4);
		hlp_y += k;
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = r * cos(i) + k_x;
			dot.y = hlp_y + k_y;
			dot.z = r * sin(i) + k_z;
			newp.x = dot.x * cos(theta) - dot.y * sin(theta);
			newp.y = dot.x * sin(theta) + dot.y * cos(theta);
			newp.z = dot.z;
			p.push_back(newp);
		}
	}
	return p;
}

// ������� ��������� ������ �������� � ���������� �������������� �����
vector <Point> Cylinder::CreateWalls(double o)
{
	vector <Point> p;
	Point dot;
	double hlp_y = 0;
	double k = 0;
	while (hlp_y < h)
	{
		k = GetRandRealNumb(2, 4);
		hlp_y += k;
		for (int i = 0; i <= 360; i += 5)
		{
			dot.x = GetNormDistNumb(r * cos(i), o) + k_x;
			dot.y = GetNormDistNumb(hlp_y, o) + k_y;
			dot.z = GetNormDistNumb(r * sin(i), o) + k_z;
			p.push_back(dot);
		}
	}
	return p;
}

// ��������� ����� � ���� �����
vector <Point> Sphere::GetAsPoints(double o)
{
	vector <Point> p;
	vector <Point> hlp;
	if (o == 0)
	{
		hlp = CreateFooting();
		p.insert(p.end(), hlp.begin(), hlp.end());
		hlp = CreateUpHemisphere();
		p.insert(p.end(), hlp.begin(), hlp.end());
		hlp = CreateDownHemisphere();
		p.insert(p.end(), hlp.begin(), hlp.end());
	}
	else
	{
		hlp = CreateFooting(o);
		p.insert(p.end(), hlp.begin(), hlp.end());
		hlp = CreateUpHemisphere(o);
		p.insert(p.end(), hlp.begin(), hlp.end());
		hlp = CreateDownHemisphere(o);
		p.insert(p.end(), hlp.begin(), hlp.end());
	}
	return p;
}

// ������� ��������� ����������-������ �����
vector <Point> Sphere::CreateFooting()
{
	vector <Point> p;
	Point dot;
	for (int i = 0; i <= 360; i += 2)
	{
		dot.x = r * cos(i) + k_x;
		dot.y = 0 + k_y;
		dot.z = r * sin(i) + k_z;
		p.push_back(dot);
	}
	return p;
}

vector <Point> Sphere::CreateFooting(double o)
{
	vector <Point> p;
	Point dot;
	for (int i = 0; i <= 360; i += 2)
	{
		dot.x = GetNormDistNumb(r * cos(i), o) + k_x;
		dot.y = GetNormDistNumb(0, o) + k_y;
		dot.z = GetNormDistNumb(r * sin(i), o) + k_z;
		p.push_back(dot);
	}
	return p;
}

//������� ��������� ������� ���������
vector <Point> Sphere::CreateUpHemisphere()
{
	vector <Point> p;
	Point dot;
	float hlp_y = 0;
	float hlp_r = 0;
	while (hlp_y < r)
	{
		if (hlp_y + 2 > r)
		{
			break;
		}
		hlp_y += GetRandRealNumb(2, 3);
		hlp_r = sqrt(abs(r * r - hlp_y * hlp_y));
		for (int i = 0; i <= 360; i += GetRandRealNumb(1, 10))
		{
			dot.x = hlp_r * cos(i) + k_x;
			dot.y = hlp_y + k_y;
			dot.z = hlp_r * sin(i) + k_z;
			p.push_back(dot);
		}
	}
	return p;
}

vector <Point> Sphere::CreateUpHemisphere(double o)
{
	vector <Point> p;
	Point dot;
	float hlp_y = 0;
	float hlp_r = 0;
	while (hlp_y < r)
	{
		if (hlp_y + 2 > r)
		{
			break;
		}
		hlp_y += GetRandRealNumb(2, 3);
		hlp_r = sqrt(abs(r * r - hlp_y * hlp_y));
		for (int i = 0; i <= 360; i += GetRandRealNumb(1, 10))
		{
			dot.x = GetNormDistNumb(hlp_r * cos(i), o) + k_x;
			dot.y = GetNormDistNumb(hlp_y, o) + k_y;
			dot.z = GetNormDistNumb(hlp_r * sin(i), o) + k_z;
			p.push_back(dot);
		}
	}
	return p;
}

// ������� ��������� ������ ���������
vector <Point> Sphere::CreateDownHemisphere()
{
	vector <Point> p;
	Point dot;
	float hlp_y = 0;
	float hlp_r = 0;
	while ((-hlp_y) < r)
	{
		if (-(hlp_y - 2) > r)
		{
			break;
		}
		hlp_y -= GetRandRealNumb(2, 3);
		hlp_r = sqrt(abs(r * r - ((-hlp_y) * (-hlp_y))));
		for (int i = 0; i <= 360; i += GetRandRealNumb(1, 10))
		{
			dot.x = hlp_r * cos(i) + k_x;
			dot.y = hlp_y + k_y;
			dot.z = hlp_r * sin(i) + k_z;
			p.push_back(dot);
		}
	}
	return p;
}

vector <Point> Sphere::CreateDownHemisphere(double o)
{
	vector <Point> p;
	Point dot;
	float hlp_y = 0;
	float hlp_r = 0;
	while ((-hlp_y) < r)
	{
		if (-(hlp_y - 2) > r)
		{
			break;
		}
		hlp_y -= GetRandRealNumb(2, 3);
		hlp_r = sqrt(abs(r * r - ((-hlp_y) * (-hlp_y))));
		for (int i = 0; i <= 360; i += GetRandRealNumb(1, 10))
		{
			dot.x = GetNormDistNumb(hlp_r * cos(i), o) + k_x;
			dot.y = GetNormDistNumb(hlp_y, o) + k_y;
			dot.z = GetNormDistNumb(hlp_r * sin(i), o) + k_z;
			p.push_back(dot);
		}
	}
	return p;
}

string Sphere::GetAsCSV(vector <vector <Point>> f)
{
	string str;
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < f[i].size(); j++)
		{
			str += to_string(i + 1) + ";" + "2" + ";" + to_string(f[i][j].x) + ";" + to_string(f[i][j].y) + ";" + to_string(f[i][j].z) + "\n";
		}
	}
	return str;
}

string Sphere::GetAsCSV(vector <Point> p)
{
	string str;
	int num = NumberInCSV();
	for (int i = 0; i < p.size(); i++)
	{
		str += to_string(num) + ";" + "2" + ";" + to_string(p[i].x) + ";" + to_string(p[i].y) + ";" + to_string(p[i].z) + "\n";
	}
	return str;
}

string Sphere::GetAsJSON(vector <vector <Point>> f)
{
	string str;
	return str;
}

string Figure::GetAsCSV(vector <Point> p)
{
	string str;
	return str;
}

string Figure::GetAsCSV(vector <vector <Point>> f)
{
	//ofstream CSV;
	//ifstream check("CSV.csv");
	//if (!check.is_open())
	//{
	//	CSV.open("CSV.csv");
	//	CSV << "Number;Type;ID;X;Y;Z" << endl;
	//	CSV.close();
	//}
	//CSV.open("CSV.csv", ios_base::app);
	//for (int i = 0; i < f.size(); i++)
	//{
	//	for (int g = 0; g < p.size(); g++)
	//	{
	//		CSV << NumberInCSV() << ';' << '1' << ';' << ID() << ';' << f[i][g].x << ';' << f[i][g].y << ';' << f[i][g].z << endl;
	//	}
	//}
	//CSV.close();
	string str;
	return str;
}

string Figure::GetAsJSON(vector <vector <Point>> f)
{
	string str;
	return str;
}

vector <Point> Figure::GetAsPoints(double o)
{
	vector <Point> p;
	return p;
}