/**
 * @file   EmbeddedPython.cpp
 * @author Mateusz Midor, kontakt@mateuszmidor.com
 * @date   IV 2016
 * @brief  First demo of embedding python in c++ using Boost::Python
 * @remark Do: export LD_LIBRARY_PATH=/usr/local/lib/boost/installation/lib/

	This demo requires Boost::Python installed under:
	/user/local/lib/boost/installation/lib/
 */

#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;
using namespace std;

int main() {
	Py_Initialize();

	object main_module = import("__main__");
	object main_namespace = main_module.attr("__dict__");

	const char PYTHON[] = "print '--- hello from python! ---'";
	object ignored = exec(PYTHON, main_namespace);
}
