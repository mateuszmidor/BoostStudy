/**
 * @file   PythonModule.cpp
 * @author Mateusz Midor, kontakt@mateuszmidor.com
 * @date   IV 2016
 * @brief  First demo of creating custom python module using Boost::Python
 * @remark Do: export LD_LIBRARY_PATH=/usr/local/lib/boost/installation/lib/

	This demo requires Boost::Python installed under:
	/user/local/lib/boost/installation/lib/
 */

#include <boost/python.hpp>

using namespace boost::python;

char const* greet()
{
   return "hello world from custom python module!";
}

// define module that can be imported into python interpreter
BOOST_PYTHON_MODULE(libPythonModule)
{
	// define exposed module functions
    def("greet", greet);
}
