
#include <random>
#include "randomization.h"

using namespace std;

// ������� ��������� ���������� ������������� ����� � ��������� �� min �� max
double GetRandRealNumb(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(min, max);
	return dist(gen);
}

// ������� ��������� ���������� ������ ����� � ��������� �� min �� max
int GetRandIntNumb(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

// ������� ����������� ������������� � �������������� ��������� u � ����������� ����������� o
double GetNormDistNumb(double u, double o)
{
	random_device rd;
	mt19937 gen(rd());
	normal_distribution<> dist(u, o);
	return dist(gen);
}