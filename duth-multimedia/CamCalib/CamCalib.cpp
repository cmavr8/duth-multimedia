// CamCalib.cpp : main project file.
// Copyright 2011 Apostolos KOUTSOKALIS, Chris MAVRAKIS
// 
// This file is part of CamCalib.
// 
// CamCalib is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// 
// CamCalib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License along with CamCalib. If not, see http://www.gnu.org/licenses/.
#include "stdafx.h"
#include "Form1.h"


using namespace CamCalib;


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
			
	// Create the main window and run it	
	Application::Run(gcnew Form1());
	return 0;
}
