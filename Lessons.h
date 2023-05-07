#pragma once

#include "Structs.h"
#include "Classes.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


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
	Date StartDay;
	Time Start;
	Time Duration;
	bool VideoProjector = 0;


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


	}



	void setClassLocation(int classnum)
	{
		ClassLocation = classnum;
	}

	void setStartTime(int h, int m = 0) { Start.Huor = h; Start.Minute = m; }
	void setDurationTime(int h, int m = 0) { Duration.Huor = h; Duration.Minute = m; }
	void setData(int d, int m, int y) { StartDay.Day = d; StartDay.Month = m; StartDay.Year = y; }

	string getName() { return Name; }
	string getID() { return ID; }
	string getTeacherName() { return Teacher; }
	int getClassLocation() { return ClassLocation; }
	bool getVideoProjector() { return VideoProjector; }
	Time getStartTime() { return Start; }
	Time getDurationTime() { return Duration; }
	Date getData() { return StartDay; }
	vector<Student> getStudents() { return Students; }

	bool ClockInterference(Lessons less2)
	{
		int time1_start = Start.Huor * 60 + Start.Minute;
		int time2_start = less2.getStartTime().Huor * 60 + less2.getStartTime().Minute;
		int time1_finaly = time1_start + Duration.Huor * 60 + Duration.Minute;
		int time2_finaly = time2_start + less2.Duration.Huor * 60 + less2.Duration.Minute;

		if (time2_start > time1_start && time2_start < time1_finaly)
			return true;
		else if (time2_finaly > time1_start && time2_finaly < time1_finaly)
			return true;
		else if (time1_start > time2_start && time1_start < time2_finaly)
			return true;
		else if (time1_finaly > time2_start && time1_finaly < time2_finaly)
			return true;
		if (time2_start == time1_start && time1_finaly == time2_finaly)
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


	bool DataInterference(Lessons less)
	{
		
		if ((StartDay.WeekDay == less.StartDay.WeekDay) && (StartDay.Day == less.StartDay.Day) && (StartDay.Month == less.StartDay.Month) && (StartDay.Year == less.StartDay.Year))
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
};



class ExtraLessons :Lessons {

	friend void ToSplitExtraClass(vector <ExtraLessons> extraclass, vector <Lessons>& Gextraclass);

private:

	int Meetings = 0;

public:

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
