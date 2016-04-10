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
	// 1. initialize the python interpreter and execution context
	Py_Initialize();
	object main_module = import("__main__");
	object main_namespace = main_module.attr("__dict__");

	// 2. set global variables
	main_namespace["a"] = 2;
	main_namespace["b"] = 3;

	// 3. run a python statement
	try {
		object ignored = exec("result = a ** b", main_namespace);
	} catch (error_already_set&) {
		PyErr_Print();
		return 1;
	}

	// 4. extract integer from "result" global variable
	int result = extract<int>(main_namespace["result"]);
	// , or even simpler:
	// int result = extract<int>(eval("a ** b", main_namespace));

	// 5. output result
	cout << result << endl;
	return 0;
}
