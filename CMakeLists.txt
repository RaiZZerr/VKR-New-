
# �������� ������ CMake
cmake_minimum_required(VERSION 3.5)

# �������� ������� � �������� ����������� ����������� �++
project(API)

# �������� ���������, �� ������� ������� ������������ ����������
add_library(random randomization.h randomization.cpp)
add_library(writeinfile writefile.h writefile.cpp)
add_library(shapes shapes.h shapes.cpp)

# �������� ������������ ���������� � ������ API
add_library(API SHARED api.cpp)
add_library(Static_lib api.cpp)
add_executable(myAPI main.cpp)

target_link_libraries(shapes
	PRIVATE
		random
)

target_link_libraries(shapes
	PRIVATE
		random
)

target_link_libraries(API
	PRIVATE
		shapes
		writeinfile
)

target_link_libraries(Static_lib
	PRIVATE
		shapes
		writeinfile
)

target_link_libraries(myAPI
	PUBLIC
		Static_lib
)


#  add_library(API SHARED api.cpp randomization.cpp writefile.cpp shapes.cpp)
