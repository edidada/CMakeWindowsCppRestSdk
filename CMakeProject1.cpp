// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"
#include "include/MyClass.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	MyClass myClass;
	int integer = myClass.get();
	cout << integer << endl;
	return 0;
}
