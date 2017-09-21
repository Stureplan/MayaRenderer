#include <iostream>
#include <maya/MSimple.h>
#include <maya/MIOStream.h>
#include <maya/MGlobal.h>

DeclareSimpleCommand(LoadRenderer, "Autodesk", "2016");

MStatus LoadRenderer::doIt(const MArgList&)
{
	MGlobal::displayInfo("Hello");
	return MS::kSuccess;
}