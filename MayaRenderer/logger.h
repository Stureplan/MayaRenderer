#pragma once

#include <maya/MGlobal.h>
#include <string>

void log_info(std::string info)
{
	MGlobal::displayInfo(info.c_str());
}

void log_error(std::string error)
{
	MGlobal::displayError(error.c_str());
}

void log_warning(std::string warning)
{
	MGlobal::displayWarning(warning.c_str());
}
