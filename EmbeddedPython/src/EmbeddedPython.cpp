//============================================================================
// Name        : EmbeddedPython.cpp
// Author      : Mateusz Midor
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <boost/python/detail/wrap_python.hpp>
#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;
using namespace std;

// First export LD_LIBRARY_PATH=/usr/local/lib/boost/installation/lib/
int main() {
	Py_Initialize();

	object main_module = import("__main__");
	object main_namespace = main_module.attr("__dict__");

	object ignored = exec("hello = file('hello.txt', 'w')\n"
	                      "hello.write('Hello world!')\n"
	                      "hello.close()",
	                      main_namespace);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
