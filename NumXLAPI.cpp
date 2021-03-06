/**
*  Copyright (c) 2007-2015 Spider Financial Corp. http://www.spiderfinancial.com
*  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

// NumXLAPI.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"

/*
* Function to be called from Python
*/
extern "C" static PyObject* py_myFunction(PyObject* self, PyObject* args)
{
  char *s = "Hello from C!";
  return Py_BuildValue("s", s);
}


/*
* Bind Python function names to our C functions
*/
static PyMethodDef myNumXLAPI_methods[] = {
    { "myFunction", py_myFunction, METH_VARARGS },
    { NULL, NULL }
};


/*
* Python calls this to let us initialize our module
*/
extern "C"  void initNumXLAPI()
{
  (void)Py_InitModule("NumXLAPI", myNumXLAPI_methods);
}

