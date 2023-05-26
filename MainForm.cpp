#pragma once

#include "Functions.h"
#include "MainForm.h"
#include "Structs.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace rapidxml;

[STAThread]

int main() {


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Golestan::MainForm Form;
	Application::Run(% Form);

}