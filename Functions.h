#pragma once

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "Classes.h"
#include "Lessons.h"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
#include <conio.h>
#include <codecvt>
#include <cmath>



using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace rapidxml;


vector<Lessons> lessons;
vector<Classes> classes;
vector<ExtraLessons> extraclass;
vector<Lessons> Gextraclass;
vector<Student> students;
vector<string> teachers;


#ifndef FUNCTION_H
#define FUNCTION_H




string ToLower(string str) { transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });  return str; }



string StringConvert(String^ str) {
	string STR = string(reinterpret_cast<const char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str).ToPointer()));
	//string STR = STR0;
	//System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr(reinterpret_cast<void*>(const_cast<char*>(STR0.c_str()))));
	return STR;
}

String^ StringConvert(string str) {
	return gcnew String(str.c_str());
}


String^ UTF8Convert(string str) {
	System::String^ managedText = gcnew System::String(std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str).c_str());
	return managedText;
}


Classes FindClass(String^ id) {
	for (size_t n = 0;n < classes.size();n++) {
		if (id == StringConvert(to_string(classes.at(n).getID())))
			return classes.at(n);
	}
}


ExtraLessons FindLesson(String^ id, vector <ExtraLessons> lessons) {
	for (size_t n = 0;n < lessons.size();n++) {
		if (id == StringConvert(lessons.at(n).getID()))
			return lessons.at(n);
	}
}

Lessons FindLesson(String^ id, vector <Lessons> lessons) {
	for (size_t n = 0;n < lessons.size();n++) {
		if (id == StringConvert(lessons.at(n).getID()))
			return lessons.at(n);
	}
}


Lessons FindLesson(String^ id) {
	for (size_t n = 0;n < lessons.size();n++) {
		if (id == StringConvert(lessons.at(n).getID()))
			return lessons.at(n);
	}
}

int FindClassIndex(String^ id) {
	for (size_t n = 0;n < classes.size();n++) {
		if (id == StringConvert(to_string(classes.at(n).getID())))
			return n;
	}
}

int FindLessonIndex(String^ id) {
	for (size_t n = 0;n < lessons.size();n++) {
		if (id == StringConvert(lessons.at(n).getID()))
			return n;
	}
}


int FindLessonIndex(String^ id , vector <Lessons> lessons) {
	for (size_t n = 0;n < lessons.size();n++) {
		if (id == StringConvert(lessons.at(n).getID()))
			return n;
	}
}


String^ NumPerConvert(int Num) {

	int s = to_string(Num).size();
	String^ Pnum = "";
		file<> xmlFile("./PNumber.xml");
		xml_document<> PN;
		PN.parse<0>(xmlFile.data());
		

		for (size_t n = 0;n < s;n++) {
			int Ntest = int(int(Num % int(pow(10, s - n))) / pow(10, s - 1 - n));

				switch (Ntest)
			{
			case 0:
				Pnum +=StringConvert( PN.first_node("0")->value());
				break;
			case 1:
				Pnum += StringConvert(PN.first_node("1")->value());
				break;
			case 2:
				Pnum += StringConvert(PN.first_node("2")->value());
				break;
			case 3:
				Pnum += StringConvert(PN.first_node("3")->value());
				break;
			case 4:
				Pnum += StringConvert(PN.first_node("4")->value());
				break;
			case 5:
				Pnum += StringConvert(PN.first_node("5")->value());
				break;
			case 6:
				Pnum += StringConvert(PN.first_node("6")->value());
				break;
			case 7:
				Pnum += StringConvert(PN.first_node("7")->value());
				break;
			case 8:
				Pnum += StringConvert(PN.first_node("8")->value());
				break;
			case 9:
				Pnum += StringConvert(PN.first_node("9")->value());
				break;

			}
		}

		return UTF8Convert(StringConvert(Pnum));
}



bool isintiger_char(char ch)
{

		if ((ch < 58 && ch >= 48))
			return true;
		else 
			return false;
}


bool isintiger(string str)
{
	int count = 0;
	for (int n=0;n<str.size();n++)
	{
		int test = str[n];
		
		if ((test < 58 && test>=48))
			continue;

		return false;
		
	}

	return true;


}


bool isnot_ABC_or_123(String^ str){



	string Str = StringConvert(str);
	
	for (auto ch : Str) {

		if ((ch < 58 && ch >= 48) || (ch > 96 && ch < 123))
			continue;
			return true;
	}
	return false;


}


Time FinalTime(Lessons less)
{
	Time fainaly;
	int time = 0;
	time = (less.getStartTime().Huor + less.getDurationTime().Huor) * 60 + less.getStartTime().Minute + less.getDurationTime().Minute;

	fainaly.Minute = time % 60;
	if (time / 60 > 24)
		fainaly.Huor = time / 60 - 24;
	else
		fainaly.Huor = time / 60;

	return fainaly;
}


Time FinalTime(int hs,int ms, int htool , int mtool)
{
	Time fainaly;
	int time = 0;
	time = (hs + htool) * 60 + ms + mtool;

	fainaly.Minute = time % 60;
	if (time / 60 > 24)
		fainaly.Huor = time / 60 - 24;
	else
		fainaly.Huor = time / 60;

	return fainaly;
}


bool ClockInterference(Lessons less1, Lessons less2)
{
	int time1_start = less1.getStartTime().Huor * 60 + less1.getStartTime().Minute;
	int time2_start = less2.getStartTime().Huor * 60 + less2.getStartTime().Minute;
	int time1_finaly = FinalTime(less1).Huor * 60 + FinalTime(less1).Minute;
	int time2_finaly = FinalTime(less2).Huor * 60 + FinalTime(less2).Minute;

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


bool ClockInterference(int hs, int ms, int htool, int mtool, Lessons less2)
{
	int time1_start = hs * 60 + ms;
	int time2_start = less2.getStartTime().Huor * 60 + less2.getStartTime().Minute;
	int time1_finaly = FinalTime(hs,ms,htool,mtool).Huor * 60 + FinalTime(hs, ms, htool, mtool).Minute;
	int time2_finaly = FinalTime(less2).Huor * 60 + FinalTime(less2).Minute;

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
void SetStudent(vector<Student>& students, Lessons less)
{
	bool repet = false;
	if (students.size() == 0)
		students.push_back(less.Students.at(0));

	for (int n = 0;n < less.Students.size();n++) {
		for (int m = 0;m < students.size();m++)
		{
			if (less.Students.at(n).ID == students.at(m).ID) { repet = true; break; }
		}
		if (repet) { repet = false; continue; }

		students.push_back(less.Students.at(n));

	}
}

void SetTeacher(vector<string>& teacher, Lessons less) {

	bool repet = false;
	if (teacher.size() == 0)
		teacher.push_back(less.getTeacherName());

	for (int m = 0;m < teacher.size();m++)
	{
		if (ToLower(teacher.at(m)) == ToLower(less.getTeacherName())) { repet = true; break; }
	}
	if (repet) return;

	teacher.push_back(less.getTeacherName());

}

//
//string StrToAdres(string str) {
//	
//	size_t N = 0;
//	while ((N = str.find('\\', N)) != std::string::npos)
//	{
//		str.replace(N, 1, "\\\\");
//		N += 2;
//	}
//
//	
//	return str;
//
//}

void ReadFileLessons(vector<Lessons>& lessons, vector<Student>& students, vector<string>& teacher, string FilePath) {

		

		file<> xmlFile(FilePath.c_str());
		xml_document<> info;
		info.parse<0>(xmlFile.data());

		

		if (info.first_node()->name() != string("Lessons") || info.first_node()->next_sibling()->name() != string("Classes"))
			return;

	

		xml_node<>* LessCount = info.first_node("Lessons");
		xml_node<>* less = info.first_node("Lessons")->first_node("Lesson");

		
		int RapidCount = 0;
		for (int n = 0;n < count_children(LessCount);n++) {



			bool rapid = false;
			for (int e = 0;e < lessons.size();e++) {
				if (less->first_node("id")->value() == lessons.at(e).ID)
				{
					rapid = true; break;
				}
			}
			if (rapid)
			{
				if (n != count_children(LessCount) - 1)
					less = less->next_sibling();
				RapidCount++;
				continue;
			}

			xml_node<>* st = less->first_node("StudentList")->first_node("Student");
			vector<Student> stu;
			for (int m = 0;m < count_children(less->first_node("StudentList"));m++) {
				Student test;
				test.ID = st->first_node("id")->value();
				test.Name = st->first_node("name")->value();
				stu.push_back(test);
				st = st->next_sibling();
			}

			
				Lessons Ltest("", "", "", stu, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				lessons.push_back(Ltest);
				lessons.at(n-RapidCount).ID = less->first_node("id")->value();
				lessons.at(n - RapidCount).Name = less->first_node("Name")->value();
				lessons.at(n - RapidCount).Start.Huor = stoi(less->first_node("Time")->first_node("start")->first_node("hour")->value());
				lessons.at(n - RapidCount).Start.Minute = stoi(less->first_node("Time")->first_node("start")->first_node("minute")->value());
				lessons.at(n - RapidCount).Duration.Huor = stoi(less->first_node("Time")->first_node("duration")->first_node("hour")->value());
				lessons.at(n - RapidCount).Duration.Minute = stoi(less->first_node("Time")->first_node("duration")->first_node("minute")->value());
				lessons.at(n - RapidCount).StartDay.WeekDay = stoi(less->first_node("Date")->first_node("WeekDay")->value());
				lessons.at(n - RapidCount).StartDay.Year = stoi(less->first_node("Date")->first_node("Yeare")->value());
				lessons.at(n - RapidCount).StartDay.Month = stoi(less->first_node("Date")->first_node("Month")->value());
				lessons.at(n - RapidCount).StartDay.Day = stoi(less->first_node("Date")->first_node("Day")->value());
				lessons.at(n - RapidCount).VideoProjector = stoi(less->first_node("VideoProjector")->value());
				lessons.at(n - RapidCount).Teacher = less->first_node("Teacher")->value();
				lessons.at(n - RapidCount).CoStartDay = lessons.at(n - RapidCount).StartDay;

				SetStudent(students, lessons.at(n - RapidCount));
				SetTeacher(teacher, lessons.at(n - RapidCount));
			
		

			less = less->next_sibling();

		}

	
}

void ReadFileClasses(vector<Classes>& classes, string FilePath) {


	file<> xmlFile(FilePath.c_str());
	xml_document<> info;
	info.parse<0>(xmlFile.data());

	if (info.first_node()->name() != string("Lessons") || info.first_node()->next_sibling()->name() != string("Classes"))
		return;

	xml_node<>* StCount = info.first_node("Classes");
	xml_node<>* Stdu = info.first_node("Classes")->first_node("Class");

	int RapidCount = 0;
	for (int n = 0;n < count_children(StCount);n++) {


		bool rapid = false;
		for (int e = 0;e < classes.size();e++) {
			if (stoi(Stdu->first_node("id")->value()) == classes.at(e).getID())
			{
				rapid = true; break;
			}
		}
		if (rapid)
		{	if(n!= count_children(StCount)-1)
			Stdu = Stdu->next_sibling();
			RapidCount++;
			continue;
		}

		Classes Ctest(0, 0, 0);
		classes.push_back(Ctest);

		classes.at(n-RapidCount).ID = stoi(Stdu->first_node("id")->value());
		classes.at(n - RapidCount).setCapacity(stoi(Stdu->first_node("Capacity")->value()));
		classes.at(n - RapidCount).setvideoprojector(stoi(Stdu->first_node("VideoProjector")->value()));

		Stdu = Stdu->next_sibling();
	}

}


bool PlaceInterference(vector<Lessons> lessons, Classes cl)
{
	for (int n = 0; n < lessons.size(); n++)
	{
		if (lessons.at(n).getClassLocation() == cl.getID())
			return true;
	}

	return false;
}


void SortLessons(vector <Lessons>& lessons) {

	for (int n = 0;n < lessons.size();n++) {
		int Maxindex = n;
		for (int m = n + 1;m < lessons.size();m++) {
			if (lessons.at(Maxindex).getStudents().size() < lessons.at(m).getStudents().size())
				Maxindex = m;
		}
		if (Maxindex != n)
			swap(lessons.at(Maxindex), lessons.at(n));
	}
}


void SortClases(vector<Classes>& classes) {

	for (int n = 0;n < classes.size();n++) {
		int Maxindex = n;
		for (int m = n + 1;m < classes.size();m++) {
			if (classes.at(Maxindex).getCapacity() < classes.at(m).getCapacity())
				Maxindex = m;
		}
		if (Maxindex != n)
			swap(classes.at(Maxindex), classes.at(n));
	}
}

void AutoSetLocation_ByData(vector<Lessons>& lessons, vector<Classes> classes) {




	for (size_t n = 0; n < lessons.size(); n++)
	{

		for (size_t m = 0; m < classes.size(); m++)
		{

			if (!(lessons.at(n).CheckVideoProjector(classes.at(m))))
				continue;
			if (lessons.at(n).OverCapacity(classes.at(m)))
				continue;

			bool Interference = false;
			for (int f = 0;f < lessons.size();f++) {

				if (f == n)
					continue;

				if (lessons.at(f).PlaceInterference(classes.at(m))) {
					if (lessons.at(f).DataInterference(lessons.at(n),false)) {
						if (lessons.at(f).ClockInterference(lessons.at(n)))
						{
							Interference = true; break;
						}
					}
				}
			}


			if (Interference)
				continue;

			lessons.at(n).setClassLocation(classes.at(m));


		}
	}

	for (size_t n = 0; n < lessons.size(); n++) {

		if (lessons.at(n).getClassLocation() != 0)
			continue;

		for (size_t m = 0; m < classes.size(); m++)
		{

			if (lessons.at(n).getVideoProjector() && !classes.at(m).getVideoProjector())
				continue;
			if (lessons.at(n).OverCapacity(classes.at(m)))
				continue;

			bool Interference = false;
			for (int f = 0;f < lessons.size();f++) {

				if (f == n)
					continue;

				if (lessons.at(f).PlaceInterference(classes.at(m))) {
					if (lessons.at(f).DataInterference(lessons.at(n), false)) {
						if (lessons.at(f).ClockInterference(lessons.at(n)))
						{
							Interference = true; break;
						}
					}
				}
			}


			if (Interference)
				continue;

			lessons.at(n).setClassLocation(classes.at(m));


		}
	}


}




void AutoSetLocation_ByWDay(vector<Lessons>& lessons, vector<Classes> classes) {




	for (size_t n = 0; n < lessons.size(); n++)
	{

		for (size_t m = 0; m < classes.size(); m++)
		{

			if (!(lessons.at(n).CheckVideoProjector(classes.at(m))))
				continue;
			if (lessons.at(n).OverCapacity(classes.at(m)))
				continue;

			bool Interference = false;
			for (int f = 0;f < lessons.size();f++) {

				if (f == n)
					continue;

				if (lessons.at(f).PlaceInterference(classes.at(m))) {
					if (lessons.at(f).getData().WeekDay==lessons.at(n).getData().WeekDay) {
						if (lessons.at(f).ClockInterference(lessons.at(n)))
						{
							Interference = true; break;
						}
					}
				}
			}


			if (Interference)
				continue;

			lessons.at(n).setClassLocation(classes.at(m));


		}
	}

	for (size_t n = 0; n < lessons.size(); n++) {

		if (lessons.at(n).getClassLocation() != 0)
			continue;

		for (size_t m = 0; m < classes.size(); m++)
		{

			if (lessons.at(n).getVideoProjector() && !classes.at(m).getVideoProjector())
				continue;
			if (lessons.at(n).OverCapacity(classes.at(m)))
				continue;

			bool Interference = false;
			for (int f = 0;f < lessons.size();f++) {

				if (f == n)
					continue;

				if (lessons.at(f).PlaceInterference(classes.at(m))) {
					if (lessons.at(f).getData().WeekDay == lessons.at(n).getData().WeekDay) {
						if (lessons.at(f).ClockInterference(lessons.at(n)))
						{
							Interference = true; break;
						}
					}
				}
			}


			if (Interference)
				continue;

			lessons.at(n).setClassLocation(classes.at(m));


		}
	}


}



void AutoSetLocation_ByData_WDay(vector<Lessons>& lessons, vector<Classes> classes) {




	for (size_t n = 0; n < lessons.size(); n++)
	{

		for (size_t m = 0; m < classes.size(); m++)
		{

			if (!(lessons.at(n).CheckVideoProjector(classes.at(m))))
				continue;
			if (lessons.at(n).OverCapacity(classes.at(m)))
				continue;

			bool Interference = false;
			for (int f = 0;f < lessons.size();f++) {

				if (f == n)
					continue;
				//MessageBox::Show(StringConvert(lessons.at(f).getID()+" vs "+ lessons.at(n).getID()));
				if (lessons.at(f).PlaceInterference(classes.at(m))) {
					//MessageBox::Show("1");
					if (lessons.at(f).DataInterference_W_D(lessons.at(n))) {
					//	MessageBox::Show("2");
						if (lessons.at(f).ClockInterference(lessons.at(n)))
						{
							//MessageBox::Show("3");
							Interference = true; break;
						}
					}
				}
			} 

			if (Interference)
				continue;

			lessons.at(n).setClassLocation(classes.at(m));


		}
	}

	for (size_t n = 0; n < lessons.size(); n++) {

		if (lessons.at(n).getClassLocation() != 0)
			continue;

		for (size_t m = 0; m < classes.size(); m++)
		{

			if (lessons.at(n).getVideoProjector() && !classes.at(m).getVideoProjector())
				continue;
			if (lessons.at(n).OverCapacity(classes.at(m)))
				continue;

			bool Interference = false;
			for (int f = 0;f < lessons.size();f++) {

				if (f == n)
					continue;

				if (lessons.at(f).PlaceInterference(classes.at(m))) {
					if (lessons.at(f).DataInterference_W_D(lessons.at(n))) {
						if (lessons.at(f).ClockInterference(lessons.at(n)))
						{
							Interference = true; break;
						}
					}
				}
			}


			if (Interference)
				continue;

			lessons.at(n).setClassLocation(classes.at(m));


		}
	}


}




bool CheckTimeInterference(Lessons less, Classes cla,vector <Lessons> lessons = ::lessons) {
	
	for (size_t n = 0; n < lessons.size(); n++)
	{
		if (lessons.at(n).getID() == less.getID())
			continue;
		//MessageBox::Show(UTF8Convert(lessons.at(n).getName()) +" vs "+ UTF8Convert(less.getName()) + "  in  "+ StringConvert(to_string(cla.getID()))+"        place inm :  " + StringConvert(to_string(lessons.at(n).PlaceInterference(cla)) + " data in : " + to_string(lessons.at(n).DataInterference_W_D(less)) + " clack   in ; " + to_string(lessons.at(n).ClockInterference(less))));
		if (lessons.at(n).PlaceInterference(cla) && lessons.at(n).DataInterference_W_D(less) && lessons.at(n).ClockInterference(less)) 
			return true;
	
			}

	return false;

		}


vector <Lessons> EmptyClassLocation(vector <Lessons>& lessons) {

	for (size_t n = 0; n < lessons.size(); n++)
		lessons.at(n).setClassLocation(0);

	return lessons;

}

int DayCount(Lessons less) {


	if (less.getData().Month < 7)
		return ((less.getData().Month - 1) * 31 + less.getData().Day);
	else if (less.getData().Month > 6)
		return (6 * 31 + (less.getData().Month - 6 - 1) * 30 + less.getData().Day);

}


int DayCount(Date date) {


	if (date.Month < 7)
		return ((date.Month - 1) * 31 + date.Day);
	else if (date.Month > 6)
		return (6 * 31 + (date.Month - 6 - 1) * 30 + date.Day);

}

Lessons StartDayLesson(vector <Lessons> lessons , bool manual=false) {

	Lessons LSmall = lessons.at(0);

	for (size_t n = 1; n < lessons.size(); n++)
	{
		//if(lessons.at(n).getData().Year<LSmall.getData().Year) 
		//{
		//	LSmall = lessons.at(n); continue;
		//}
		//MessageBox::Show(StringConvert(to_string(lessons.at(n).getClassLocation())));

		//if (lessons.at(n).getClassLocation() == 0 && manual)
			//continue;

		
		 if ((lessons.at(n).getData().Month < LSmall.getData().Month) ||((lessons.at(n).getData().Month == LSmall.getData().Month) &&(lessons.at(n).getData().Day < LSmall.getData().Day)))
		{
			LSmall = lessons.at(n);
		}
	}

	return LSmall;

}

vector <Lessons> ToSplitExtraClass(vector <ExtraLessons> extraclass) {

	vector <Lessons> Gextraclass;

	for (size_t n = 0;n < extraclass.size();n++) {

		int D = extraclass.at(n).StartDay.Day;
		int M = extraclass.at(n).StartDay.Month;
		int Y = extraclass.at(n).StartDay.Year;

		for (size_t m = 0; m < extraclass.at(n).getMeetingsNum();m++) {
			
		
			
			if (M < 7 && D>31) { M++; D -= 31; }
			else if (M > 6 && M < 12 && D > 30) { M++; D -= 30; }
			else if (M == 12 && D > 29) { Y++; M = 1; D -= 29; }
			
	
			Lessons less(extraclass.at(n).ID, extraclass.at(n).Name, extraclass.at(n).Teacher, extraclass.at(n).Students, extraclass.at(n).Start.Huor, extraclass.at(n).Start.Minute, extraclass.at(n).Duration.Huor, extraclass.at(n).Duration.Minute, extraclass.at(n).StartDay.WeekDay, extraclass.at(n).VideoProjector, Y, M, D);
			less.setString(extraclass.at(n).getName_S(), extraclass.at(n).getTeacherName_S());
			less.setFoq(true);
			Gextraclass.push_back(less);
			D += 7;
		}
	}

	return Gextraclass;

}


vector <Lessons> ToSplitExtraClass(ExtraLessons ex) {


	vector <Lessons> Gextraclass;

	int D = ex.getData().Day;
	int M = ex.getData().Month;
	int Y = ex.getData().Year;


		for (int m = 0; m <ex.getMeetingsNum();m++) {
			

		
			if (M < 7 && D>31) { M++; D -= 31; }
			if (M > 6 && M != 12 && D > 30) { M++; D -= 30; }
			if (M == 12 && D > 29) { Y++; M = 1; D -= 29; }

			Lessons less(ex.getID(),ex.getName(), ex.getTeacherName(), ex.getStudents(), ex.getStartTime().Huor, ex.getStartTime().Minute, ex.getDurationTime().Huor, ex.getDurationTime().Minute, ex.getData().WeekDay, ex.getVideoProjector(), Y, M, D);
			less.setString(ex.getName_S(),ex.getTeacherName_S());
			less.setFoq(true);
			Gextraclass.push_back(less);

			D += 7;

		}

		return Gextraclass;
	}


bool isEnglishchar(String^ str) {

	string Str = ToLower(StringConvert(str));

	for (auto ch : Str) {

		if (ch > 96 && ch < 123)
			return true;
	}

	return false;
}
	
void TextSave(String^ FilePatch , vector <Lessons> SumLess) {

	ofstream File(StringConvert(FilePatch) + "//Golestan.txt", ios::out);

	File << "Students List :\n\n\n";
	File << "ID" << "               " << "Name\n\n";
	for (auto st : students) {

		if(st.Name.at(0)>= 97 && st.Name.at(0) <= 122)
			File  << st.ID << "          " << st.Name << endl;
		else
		{
			File << st.ID << "            " << st.Name << endl;
		}
	}

	File << left;
	File << "\n\n\n\n\n\nTeachers List :\n\n\n";
	
	for (auto te : teachers)
		File << te << endl;


	File << "\n\n\n\n\n\nLessons List :\n\n\n";


	File << setw(25)<< "ID" << setw(25) << "WeekDay" << setw(25) << "Time" << setw(25) << "Class" << setw(25) << "StudentNumber" << setw(25) << "VideoProjector" << setw(25) << "Teacher" << setw(25) << "Name"<<"\n\n\n";
	
	
	for (auto less : lessons)
	{
		string WeekDay = "";

		switch (less.getData().WeekDay) {

		case 0:
			WeekDay = "Saturday";
			break;
		case 1:
			WeekDay = "Sunday";
			break;
		case 2:
			WeekDay = "Monday";
			break;
		case 3:
			WeekDay = "Tuesday";
			break;
		case 4:
			WeekDay = "Wednesday";
			break;
		case 5:
			WeekDay = "Thursday";
			break;

		}
		string VideoProjector = "NO";
		if (less.getVideoProjector())
			VideoProjector = "YES";

		File <<endl<< setw(25) << less.getID() << setw(25) << WeekDay << setw(25) << to_string(less.getStartTime().Huor)+":"+ to_string(less.getStartTime().Minute)+"|"+ to_string(FinalTime(less).Huor)+":"+ to_string(FinalTime(less).Minute) << setw(25) << less.getClassLocation() << setw(25) << less.getStudents().size() << setw(25) << VideoProjector << setw(25+ less.getName().size()) << less.getName() << setw(25 + less.getTeacherName().size()) << less.getTeacherName() + "\n";
		

	}






	if (extraclass.size() == 0)
		return;


	File << "\n\n\n\n\n\nExtra Lessons List :\n\n\n";


	File << setw(25) << "ID" << setw(25) << "WeekDay" << setw(25) << "Time" << setw(25) << "Meetings" << setw(25) << "Class" << setw(25) << "StudentNumber" << setw(25) << "VideoProjector" << setw(25) << "Teacher" << setw(25) << "Name" << "\n\n\n";


	for (auto less : extraclass)
	{
		string WeekDay = "";

		switch (less.getData().WeekDay) {

		case 0:
			WeekDay = "Saturday";
			break;
		case 1:
			WeekDay = "Sunday";
			break;
		case 2:
			WeekDay = "Monday";
			break;
		case 3:
			WeekDay = "Tuesday";
			break;
		case 4:
			WeekDay = "Wednesday";
			break;
		case 5:
			WeekDay = "Thursday";
			break;

		}
		string VideoProjector = "NO";
		if (less.getVideoProjector())
			VideoProjector = "YES";

		File << "\n\n" << endl << setw(25) << less.getID() << setw(25) << WeekDay << setw(25) << to_string(less.getStartTime().Huor) + ":" + to_string(less.getStartTime().Minute) + "|" + to_string(FinalTime(less).Huor) + ":" + to_string(FinalTime(less).Minute) << setw(25) << less.getMeetingsNum() << setw(25) << less.getClassLocation() << setw(25) << less.getStudents().size() << setw(25) << VideoProjector << setw(25 + less.getName().size()) << less.getName() << setw(25 + less.getTeacherName().size()) << less.getTeacherName() + "\n";

		File << "\n{ \n";

		int meet = 0;
		for (auto less : ToSplitExtraClass(less)) {
			meet++;

			for each (auto sum in SumLess)
			{
				if (sum.getID() == less.getID() && DayCount(sum) == DayCount(less))
					less.setClassLocation(sum.getClassLocation());
			}

			File << endl << setw(25) << less.getID() << setw(25) << WeekDay << setw(25) << to_string(less.getStartTime().Huor) + ":" + to_string(less.getStartTime().Minute) + "|" + to_string(FinalTime(less).Huor) + ":" + to_string(FinalTime(less).Minute) << setw(25) << meet << setw(25) << less.getClassLocation() << setw(25) << less.getStudents().size() << setw(25) << VideoProjector << setw(25 + less.getName().size()) << less.getName() << setw(25 + less.getTeacherName().size()) << less.getTeacherName() + "\n";
		}

		File << "\n} \n";
	}


}
 

#endif