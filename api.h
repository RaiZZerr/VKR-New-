
#include <fstream>

using namespace std;

/*! \file */

/// ����� ��������� ����� �����
enum class ShapeType {
    Cylinder, ///< ���������, ��� ��� ������ - �������
    Sphere, ///< ���������, ��� ��� ������ - �����
    Plane ///< ���������, ��� ��� ������ - ���������
}; 
/*!
    \brief ��������� ���������� ������� CreateShapes

    ��������� �������� ��� ��������, ���������� ���������� � ���������� ��� ������� CreateShapes
    type - ��� ������
    count - ��������� ���������� ��������������� �����
    partition - �������� ������������ ���������� ��� ����������� ������������� ����� (���� (= 0), ���������� ������������� �� ������������)
*/
struct ShapeProperties {
    ShapeType type;
    int count;
    double partition;
};

/*!
    \brief ��������� ���������� ������� CreateRandomShapes

    ��������� �������� ��� ��������, ���������� ���������� � ���������� ��� ������� CreateShapes
    count - ��������� ���������� ��������������� �����
    partition - �������� ������������ ���������� ��� ����������� ������������� ����� (���� (= 0), ���������� ������������� �� ������������)
*/
struct RandomShapeProperties {
    int count;
    double partition;
};

/*!
    ���������� ���� � ������ "fileName" � ����������� .csv ��� .json (� ����������� �� ����, ����� ���������� ������� � �����),���������� ������ ���� param.type � ���������� param.count
    � ��������� ������������ ���������� param.partition ��� ����������� ������������� �����
    \param fileName ��� �����
    \param param ��������� ���������� ������� CreateShapes (������ �������� funcParams)
    \return ����, ���������� ��������������� ������ ��������� �����
*/
void CreateShapes(const char fileName[], ShapeProperties param);

string CreateShapes(ShapeProperties param);

/*!
    ���������� ���� � ������ "fileName" � ����������� .csv ��� .json (� ����������� �� ����, ����� ���������� ������� � �����),���������� ������ ���������� ���� � ���������� param.count
    � ��������� ������������ ���������� param.partition ��� ����������� ������������� �����
    \param fileName ��� �����
    \param param ��������� ���������� ������� CreateRandomShapes (������ �������� funcParams1)
    \return ����, ���������� ��������������� ������ ��������� �����
*/
void CreateRandomShapes(const char fileName[], RandomShapeProperties param);

string CreateRandomShapes(RandomShapeProperties param);

