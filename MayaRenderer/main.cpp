#include <iostream>
#include <maya/MSimple.h>
#include <maya/MIOStream.h>
#include <maya/MGlobal.h>
#include <maya/MSelectionList.h>
#include <maya/MObjectArray.h>
#include <maya/MFnTransform.h>
#include <maya/MMatrix.h>

#include <maya/MFloatMatrix.h>

#include "logger.h"

DeclareSimpleCommand(LoadRenderer, "Autodesk", "2016");

void get_selection(MFn::Type type)
{
	MObjectArray objects;
	MSelectionList selected;
	MGlobal::getActiveSelectionList(selected);

	for (unsigned int i = 0; i < selected.length(); i++)
	{
		MObject obj;

		selected.getDependNode(i, obj);
		if (obj.hasFn(type))
		{
			objects.append(obj);
		}
		
		if (obj.hasFn(MFn::kTransform))
		{
			MFnTransform fn(obj);
			MMatrix m = fn.transformationMatrix();
			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					// log the local-space transformation matrix (T*R*S)
					log_info(std::to_string(m.matrix[x][y]));
				}
			}



			for (unsigned int j = 0; j < fn.childCount(); j++)
			{
				MObject child = fn.child(j);
				if (child.hasFn(type))
				{
					objects.append(child);
				}
			}
		}
	}

	for (unsigned int i = 0; i < objects.length(); i++)
	{
		log_info(std::string("OBJECT TYPE: ").append(objects[i].apiTypeStr()));
	}
}

void startup()
{
	log_info("Maya Plugin Started");

	get_selection(MFn::kMesh);
}

MStatus LoadRenderer::doIt(const MArgList&)
{
	startup();
	return MS::kSuccess;
}