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
vector<string> teacher;


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


bool isInteger(string str)
{
	int count = 0;
	for (int n=0;n<str.size();n++)
	{
		int test = str[n];
		
		if ((test < 58 && test>48))
		{
			count++;
		}
	}

	if (count == str.size())
		return true;
	else
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

bool ClockInterference(Lessons less1, Lessons less2)
{
	int time1_start = less1.getStartTime().Huor * 60 + less1.getStartTime().Minute;
	int time2_start = less2.getStartTime().Huor * 60 + less2.getStartTime().Minute;
	int time1_finaly = FinalTime(less1).Huor * 60 + FinalTime(less1).Minute;
	int time2_finaly = FinalTime(less2).Huor * 60 + FinalTime(less2).Minute;

	if (time2_start > time1_start && time2_start < time1_finaly)
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

void AutoSetLocation(vector<Lessons>& lessons, vector<Classes> classes) {




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
					if (lessons.at(f).DataInterference(lessons.at(n))) {
						if (lessons.at(f).ClockInterference(lessons.at(n)))
						{
							Interference = true; break;
						}
					}
				}
			}


			if (Interference)
				continue;

			lessons.at(n).setClassLocation(classes.at(m).getID());


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
					if (lessons.at(f).DataInterference(lessons.at(n))) {
						if (lessons.at(f).ClockInterference(lessons.at(n)))
						{
							Interference = true; break;
						}
					}
				}
			}


			if (Interference)
				continue;

			lessons.at(n).setClassLocation(classes.at(m).getID());


		}
	}


}


void ToSplitExtraClass(vector <ExtraLessons> extraclass, vector <Lessons>& Gextraclass) {

	for (int n = 0;n < extraclass.size();n++) {


		for (int m = 0; m < extraclass.at(n).getMeetingsNum();m++) {
			int D = extraclass.at(n).StartDay.Day;
			int M = extraclass.at(n).StartDay.Month;
			int Y = extraclass.at(n).StartDay.Year;

			D += 7 * m;
			if (M < 7 && D>31) { M++; D -= 31; }
			else if (M > 6 && M != 12 && D > 30) { M++; D -= 30; }
			else if (M == 12 && D > 29) { Y++; M = 1; D -= 29; }

			Lessons less(extraclass.at(n).ID, extraclass.at(n).Name, extraclass.at(n).Teacher, extraclass.at(n).Students, extraclass.at(n).Start.Huor, extraclass.at(n).Start.Minute, extraclass.at(n).Duration.Huor, extraclass.at(n).Duration.Minute, extraclass.at(n).StartDay.WeekDay, extraclass.at(n).VideoProjector, Y, M, D);

			Gextraclass.push_back(less);

		}
	}



}



  

#endif