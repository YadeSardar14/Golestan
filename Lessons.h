#pragma once

#include "Structs.h"
#include "Classes.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <vcclr.h>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;




class Lessons
{

	friend void SetStudent(vector<Student>&, Lessons);
	friend void ReadFileLessons(vector<Lessons>&, vector<Student>&, vector<string>&, string);

protected:

	vector<Student> Students;
	int ClassLocation = 0;
	string ID = "";
	string Name = "";
	string Teacher = "";
	gcroot <String^> name;
	gcroot <String^> teacher;
	Date StartDay;
	Date CoStartDay;
	Time Start;
	Time Duration;
	bool VideoProjector = 0;
	bool Foq = 0;
	

public:
	
	Lessons(string ID, string Name, string Teacher,
		vector<Student> students,
		int StartTime_h, int StartTime_m,
		int DurationTime_h, int DurationTime_m,
		int StartDay_wd,
		bool videoprojector = 0,
		int StartDay_y = 0, int StartDay_m = 0,
		int StartDay_d = 0)
	{


		Students = students;
		Start.Huor = StartTime_h;
		Start.Minute = StartTime_m;
		Duration.Huor = DurationTime_h;
		Duration.Minute = DurationTime_m;
		StartDay.WeekDay = StartDay_wd;
		VideoProjector = videoprojector;
		StartDay.Year = StartDay_y;
		StartDay.Month = StartDay_m;
		StartDay.Day = StartDay_d;
		CoStartDay = StartDay;
		this->ID = ID;
		this->Name = Name;
		this->Teacher = Teacher;


	}



	void setClassLocation(Classes cl)
	{
		ClassLocation = cl.getID();
		cl.Fill = true;
	}

	void setClassLocation(int cl_lo)
	{
		ClassLocation = cl_lo;
		
	}

	void setStartTime(int h, int m = 0) { Start.Huor = h; Start.Minute = m; }
	void setDurationTime(int h, int m = 0) { Duration.Huor = h; Duration.Minute = m; }
	void setData(int d, int m, int y) { StartDay.Day = d; StartDay.Month = m; StartDay.Year = y; CoStartDay.Year = y; CoStartDay.Month = m;	CoStartDay.Day = d; }
	void setFoq(bool foq) { Foq = foq; }
	void setString(String^ Na, String^ Tich) { name = Na; teacher = Tich; }
	
	string getName() { return Name; }
	string getID() { return ID; }
	string getTeacherName() { return Teacher; }
	String^ getTeacherName_S() { return teacher; }
	String^ getName_S() { return name; }
	int getClassLocation() { return ClassLocation; }
	bool getVideoProjector() { return VideoProjector; }
	bool getFoq() { return Foq; }
	Time getStartTime() { return Start; }
	Time getDurationTime() { return Duration; }
	Date getData() { return StartDay; }
	Date getConstData() { return CoStartDay; }
	vector<Student> getStudents() { return Students; }


	bool ClockInterference(Lessons less2)
	{
		int time1_start = Start.Huor * 60 + Start.Minute;
		int time2_start = less2.getStartTime().Huor * 60 + less2.getStartTime().Minute;
		int time1_finaly = time1_start + Duration.Huor * 60 + Duration.Minute;
		int time2_finaly = time2_start + less2.Duration.Huor * 60 + less2.Duration.Minute;

		if (time2_start >= time1_start && time2_start < time1_finaly)
			return true;
		else if (time2_finaly > time1_start && time2_finaly < time1_finaly)
			return true;
		else if (time1_start > time2_start && time1_start < time2_finaly)
			return true;
		else if (time1_finaly > time2_start && time1_finaly < time2_finaly)
			return true;
		else
			return false;
	}

	bool ClockInterference(int hs, int ms, int htool, int mtool)
	{
		int time1_start = Start.Huor * 60 + Start.Minute;
		int time2_start = hs * 60 + ms;
		int time1_finaly = time1_start + Duration.Huor * 60 + Duration.Minute;
		int time2_finaly = time2_start + htool * 60 + mtool;

		if (time2_start >= time1_start && time2_start < time1_finaly)
			return true;
		else if (time2_finaly > time1_start && time2_finaly < time1_finaly)
			return true;
		else if (time1_start > time2_start && time1_start < time2_finaly)
			return true;
		else if (time1_finaly > time2_start && time1_finaly < time2_finaly)
			return true;
		else
			return false;
	}



	bool PlaceInterference(Lessons less)
	{
		if (ClassLocation == less.ClassLocation)
			return true;
		else
			return false;
	}

	bool PlaceInterference(Classes cla)
	{
		if (ClassLocation == cla.getID())
			return true;
		else
			return false;
	}


	bool DataInterference(Lessons less, bool YearCheck)
	{
		switch (YearCheck) {

		case 1:

			if ((StartDay.WeekDay == less.StartDay.WeekDay) && (StartDay.Day == less.StartDay.Day) && (StartDay.Month == less.StartDay.Month) && (StartDay.Year == less.StartDay.Year))
				return true;
			else
				return false;

			break;

		case 0:

			if ((StartDay.WeekDay == less.StartDay.WeekDay) && (StartDay.Day == less.StartDay.Day) && (StartDay.Month == less.StartDay.Month))
				return true;
			else
				return false;

			break;

		}
	}


	bool DataInterference_W_D(Lessons less)
	{
		
			if  ((!Foq && !less.Foq && (StartDay.WeekDay == less.StartDay.WeekDay))  
			||  ((!Foq && less.Foq) && (StartDay.WeekDay == less.StartDay.WeekDay) && (less.DayCount() >= DayCount()))
			||	((Foq && !less.Foq) && (StartDay.WeekDay == less.StartDay.WeekDay) && (DayCount() >= less.DayCount()))
			||  ((Foq && less.Foq) && (StartDay.WeekDay == less.StartDay.WeekDay) && (StartDay.Day == less.StartDay.Day) && (StartDay.Month == less.StartDay.Month)) )
				return true;
			else
				return false;

	}

	bool DataInterference_W_D(int WeekD, int M , int D, bool foq)
	{

		if ((!Foq && !foq && (StartDay.WeekDay == WeekD))
			|| ((!Foq && foq) && (StartDay.WeekDay == WeekD) && (DayCount(M,D) >= DayCount()))
			|| ((Foq && !foq) && (StartDay.WeekDay == WeekD) && (DayCount() <= DayCount(M, D)))
			|| ((Foq && foq) && (StartDay.WeekDay == WeekD) && (StartDay.Day == D) && (StartDay.Month == M)))
			return true;
		else
			return false;

	}

	 

	bool CheckVideoProjector(Classes cl) {
		if (VideoProjector == cl.getVideoProjector())
			return true;
		else
			return false;
	}


	bool OverCapacity(Classes cl) {

		if (Students.size() > cl.getCapacity())
			return true;
		else
			return false;

	}


	int DayCount() {


		if (StartDay.Month < 7)
			return ((StartDay.Month - 1) * 31 + StartDay.Day);
		else if (StartDay.Month > 6)
			return (6 * 31 + (StartDay.Month - 6 - 1) * 30 + StartDay.Day);

	}

	int DayCount(int M , int D) {


		if (M < 7)
			return ((M - 1) * 31 +D);
		else if (M > 6)
			return (6 * 31 + (M - 6 - 1) * 30 + D);

	}

	void operator ++() {

			StartDay.Day += 7;
			if (StartDay.Month < 7 && StartDay.Day>31) { StartDay.Month++; StartDay.Day -= 31; }
			else if (StartDay.Month > 6 && StartDay.Month < 12 && StartDay.Day > 30) { StartDay.Month++; StartDay.Day -= 30; }
			else if (StartDay.Month == 12 && StartDay.Day > 29) {  StartDay.Year++; StartDay.Month = 1; StartDay.Day -= 29; 	}
			
	}


	void operator --() {
		int w = false;
		
		StartDay.Day -= 7;
		if (StartDay.Day < 1) {
			StartDay.Month--;
			w = true;
		}
		if (StartDay.Month == 0) {
			StartDay.Year--;
			StartDay.Month = 12;
			w = true;
			
		}
		
		if (w) {

			if (StartDay.Month < 7) { StartDay.Day += 31; }
			else if (StartDay.Month > 6 && StartDay.Month != 12 ) { StartDay.Day += 30; }
			else if (StartDay.Month == 12) { StartDay.Day += 29; }
			
		}
	}

};



class ExtraLessons : public Lessons {

	friend vector <Lessons> ToSplitExtraClass(vector <ExtraLessons> extraclass);


private:

	int Meetings = 0;

public:

	bool Fill = false;
	ExtraLessons(int meetings, string ID, string Name, string Teacher,
		vector<Student> students,
		int StartTime_h, int StartTime_m,
		int DurationTime_h, int DurationTime_m,
		int StartDay_wd,
		bool videoprojector = 0,
		int StartDay_y = 0, int StartDay_m = 0,
		int StartDay_d = 0) :Lessons(ID, Name, Teacher, students, StartTime_h, StartTime_m, DurationTime_h, DurationTime_m, StartDay_wd, videoprojector, StartDay_y, StartDay_m, StartDay_d)

	{
		Meetings = meetings;
	}

	int getMeetingsNum() { return Meetings; }
};
