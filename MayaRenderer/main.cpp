#include <iostream>
#include <thread>
#include <Windows.h>
#include <maya/MSimple.h>
#include <maya/MIOStream.h>
#include <maya/MGlobal.h>

DeclareSimpleCommand(LoadRenderer, "Autodesk", "2016");

void startup()
{
	// additional information
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// start the program up
	CreateProcess("C:/Program Files/WinRAR/WinRAR.exe",   // the path
		"",        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	);
	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

MStatus LoadRenderer::doIt(const MArgList&)
{
	std::thread t(startup);
	t.join();
	
	
	MGlobal::displayInfo("Hello");



	return MS::kSuccess;
}