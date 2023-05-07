#pragma once

#include <iostream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;



class Classes
{

friend void ReadFileClasses(vector<Classes>& , string );

private:
	int ID = 0;
	int Capacity = 0;
	bool VideoProjector = 0;

public:
	Classes(int id, int capacity, bool videoprojector = 0)
	{
		ID = id;
		Capacity = capacity;
		VideoProjector = videoprojector;
	}

	void setCapacity(int cap) { Capacity = cap; }
	void setvideoprojector(bool videoprojector)
	{
		VideoProjector = videoprojector;
	}

	int getID() { return ID; }
	int getCapacity() { return Capacity; }
	bool getVideoProjector() { return VideoProjector; }

};