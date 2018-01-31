#include <iostream>
#include <maya/MSimple.h>
#include <maya/MIOStream.h>
#include <maya/MGlobal.h>
#include <maya/MSelectionList.h>

#include "logger.h"

DeclareSimpleCommand(LoadRenderer, "Autodesk", "2016");



void startup()
{
	log_info("Maya Plugin Started");

	MSelectionList selected;
	MGlobal::getActiveSelectionList(selected);

	for (unsigned int i = 0; i < selected.length(); i++)
	{
		MObject obj;

		selected.getDependNode(i, obj);


	}
}

MStatus LoadRenderer::doIt(const MArgList&)
{
	startup();
	return MS::kSuccess;
}