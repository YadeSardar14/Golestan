#pragma once

#include "Functions.h"
//#include <chrono>
//#include <thread>

namespace Golestan {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace std;
    
    //List of student in foq temporarily
    vector <Student> StList;
	
    //List of extraLessons
    vector <Lessons> SplitEX;

    //List of All lessons
    vector <Lessons> SumLess;

    //Save Start Date
    vector <Date> SaveStartDate;
    
    /// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

    private: OpenFileDialog^ XmlAdres;
    private: System::Windows::Forms::Button^ BTBazgashtFog;
    private: System::Windows::Forms::Label^ LAErorFoq2;
    private: System::Windows::Forms::Button^ BTBazgasht2Foq;
    private: System::Windows::Forms::Label^ LAErorFoq3;
    private: System::Windows::Forms::Button^ BTBazgasht3Foq;
    private: System::Windows::Forms::Timer^ TimeEror;
    private: System::Windows::Forms::Label^ LAWeekCycle;

    private: System::Windows::Forms::Button^ BTNext;


    private: System::Windows::Forms::Button^ BTBack;
    private: System::Windows::Forms::Button^ BTDengerFill;
    private: System::Windows::Forms::Button^ BTBazgashtList;
    private: System::Windows::Forms::ListBox^ LITeacherList;
    private: System::Windows::Forms::Label^ LATeacherList;
    private: System::Windows::Forms::ListBox^ LIStudentList;
    private: System::Windows::Forms::Label^ LAStudentList;
    private: System::Windows::Forms::Label^ LAHeder;




    private: System::Windows::Forms::Timer^ TimeLogo;
    private: System::Windows::Forms::Button^ BTNewIm;

    private: System::Windows::Forms::Button^ BTExit;
    private: System::Windows::Forms::Panel^ PAFileErorr;
    private: System::Windows::Forms::Label^ LAErorrFile;
    private: System::Windows::Forms::Button^ BTNewFile2;
    private: System::Windows::Forms::Button^ BTDenger2;
    private: System::Windows::Forms::Panel^ PALogo;
    private: System::Windows::Forms::Panel^ LOGO;
    private: System::Windows::Forms::Label^ LALogoKaver;












    private: FolderBrowserDialog^ TxtSave;



	public:

		MainForm(void)
		{
			InitializeComponent();

            PALogo->Show();
            TimeLogo->Enabled = true;
           
            XmlAdres = gcnew OpenFileDialog();
            XmlAdres->Filter = "XML files (*.xml)|*.xml";
            XmlAdres->Title = "Select a File";
            XmlAdres->RestoreDirectory = true;

            TxtSave = gcnew FolderBrowserDialog();
            TxtSave->Description = "Select A Folder";
            TxtSave->ShowNewFolderButton = false;
            //TxtSave->RootFolder = Environment::SpecialFolder::MyComputer;
          
             
			//
			//TODO: Add the constructor code here
			//
           // Classes r(0,0,0);
            
            HideFoq1();
            HideFoq2();
            HideFoq3();
            HideMeno();
            HideTable();
            HideTanzimBarname();
            HideInfo();
            ShowImportPage();
          
           
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

    private:



        void ShowImportPage() {

            BTImportFile->Show();
            LAXmlFile->Show();
            LAErorIm->Hide();
            PAFileErorr->Hide();

        }

        void HideImportPage() {

            BTImportFile->Hide();
            LAXmlFile->Hide();
            LAErorIm->Hide();  
            PAFileErorr->Hide();
        }

        void ShowMeno() {

            BTBarnameDarsi->Show();
            BTTanzinBarname->Show();
            BTFoqBarname->Show();
            BTExit->Show();
            BTNewIm->Show();

        }

        void HideMeno() {

            BTBarnameDarsi->Hide();
            BTTanzinBarname->Hide();
            BTFoqBarname->Hide();
            BTExit->Hide();
            BTNewIm->Hide();
        }

        bool Showtable = false;

        void ShowTable() {

            this->MaximizeBox = true;
            Showtable = true;
            BTBack->BringToFront();
            BTNext->BringToFront();
            LAWeekCycle->BringToFront();

            
            BTAuto->Show();
            BTSave->Show();
            BTBazgashtTable->Show();
            BTBishtarImTable->Show();
            if(Week_Cycle)
            BTBack->Show();
            BTNext->Show();
            LAWeekCycle->Show();
            Tabel->Show();
            
        }

        void HideTable() {

            this->MaximizeBox = false;
            Showtable = false;
            LAHeder->Hide();
            Tabel->Hide();
            BTAuto->Hide();
            BTSave->Hide();
            BTBazgashtTable->Hide();
            BTBishtarImTable->Hide();
            BTBack->Hide();
            BTNext->Hide();
            LAWeekCycle->Hide();
        }

        void ShowTanzimBarname() {

            BTTaiid->Show();
            BTBazgasht->Show();
            PAClassID->Show();
            TXClassID->Show();
            LACassID->Show();
            LALessonID->Show();
            PALessonID->Show();
            TXLessonID->Show();
            LAEror->Show();
            LATanzimClassInfo->Show();
            LATanzimLessonInfo->Show();
        }

        void HideTanzimBarname() {

            BTTaiid->Hide();
            BTBazgasht->Hide();
            PAClassID->Hide();
            TXClassID->Hide();
            LACassID->Hide();
            LALessonID->Hide();
            PALessonID->Hide();
            TXLessonID->Hide();
            LAEror->Hide();
            LATanzimLessonInfo->Hide();
            LATanzimClassInfo->Hide();

        }

        void ShowFoq1() {

            BTTaiid1Foq->Show();
            BTBazgashtFog->Show();
            LALessonIDFoq->Show();
            LALessonNameFoq->Show();
            LATeacherNameFoq->Show();
            PALessonIDFoq->Show();
            PALessonNameFoq->Show();
            PATeacherNameFoq->Show();
            TXLessonIDFoq->Show();
            TXLessonNameFoq->Show();
            TXTeacherNameFoq->Show();
            BOVideoProjectorFoq->Show();
           LAErorFoq->Show();

        }

        void HideFoq1() {

            BTTaiid1Foq->Hide();
            LALessonIDFoq->Hide();
            LALessonNameFoq->Hide();
            LATeacherNameFoq->Hide();
            PALessonIDFoq->Hide();
            PALessonNameFoq->Hide();
            PATeacherNameFoq->Hide();
            TXLessonIDFoq->Hide();
            TXLessonNameFoq->Hide();
            TXTeacherNameFoq->Hide();
            BOVideoProjectorFoq->Hide();
            LAErorFoq->Hide();
            BTBazgashtFog->Hide();

        }

        void ShowFoq2() {

            LADateFoq->Show();
            LATimeFoq->Show();
            LATimeToolFoq->Show();
            LAErorFoq2->Show();
            BTTaiid2Foq->Show();
            BTBazgasht2Foq->Show();
            LAHFoq->Show();
            LAH1Foq->Show();
            LAMFoq->Show();
            LAM1Foq->Show();
            LAMahFoq->Show();
            LARozFoq->Show();
            LAJalaseFoq->Show();
            LAWeekDayFoq->Show();
            TXWeekDayFoq->Show();
            VAHFoq->Show();
            VAH1Foq->Show();
            VAMFoq->Show();
            VAM1Foq->Show();
            VAMahFoq->Show();
            VARozFoq->Show();
            VAJalaseFoq->Show();


        }

        void HideFoq2() {

            LADateFoq->Hide();
            LATimeFoq->Hide();
            LATimeToolFoq->Hide();
            LAErorFoq2->Hide();
            BTTaiid2Foq->Hide();
            BTBazgasht2Foq->Hide();
            LAHFoq->Hide();
            LAH1Foq->Hide();
            LAMFoq->Hide();
            LAM1Foq->Hide();
            LAMahFoq->Hide();
            LARozFoq->Hide();
            LAJalaseFoq->Hide();
            LAWeekDayFoq->Hide();
            TXWeekDayFoq->Hide();
            VAHFoq->Hide();
            VAH1Foq->Hide();
            VAMFoq->Hide();
            VAM1Foq->Hide();
            VAMahFoq->Hide();
            VARozFoq->Hide();
            VAJalaseFoq->Hide();


        }

        void ShowFoq3() {

            LADaneshjoFoq->Show();
            LAStNameFoq->Show();
            LAStNumFoq->Show();
            PAStNameFoq->Show();
            PAStNumFoq->Show();
            BTTaiid3Foq->Show();
            BTAfzodanFoq->Show();
            BTBazgasht3Foq->Show();
            TXStNameFoq->Show();
            TXStNumFoq->Show();
            LAErorFoq3->Show();
        }

        void HideFoq3() {

            LADaneshjoFoq->Hide();
            LAStNameFoq->Hide();
            LAStNumFoq->Hide();
            PAStNameFoq->Hide();
            PAStNumFoq->Hide();
            BTTaiid3Foq->Hide();
            BTAfzodanFoq->Hide();
            BTBazgasht3Foq->Hide();
            TXStNameFoq->Hide();
            TXStNumFoq->Hide();
            LAErorFoq3->Hide();
            BTDengerFill->Hide();
        }


        void ShowInfo() {

            LAStudentList->Show();
            LATeacherList->Show();
            LITeacherList->Show();
            LIStudentList->Show();
            BTBazgashtList->Show();
        }

        void HideInfo() {

            LAStudentList->Hide();
            LATeacherList->Hide();
            LITeacherList->Hide();
            LIStudentList->Hide();
            BTBazgashtList->Hide();
        }


        void EmptyTable() {

            for (size_t n = 0;n < classes.size();n++) {
                for (size_t m = 1;m < 7;m++)
                    Tabel->Rows[n]->Cells[m]->Value = "";
            }
        }


        private: int Week_Cycle = 0;

        void SetTable(vector <Lessons> lessons, vector <Classes> classes, int WeekCycle , bool Manual) {

            EmptyTable();
            //MessageBox::Show(StringConvert(to_string(StartDayLesson(lessons).getData().WeekDay) + " :  "+ to_string(StartDayLesson(lessons).getData().Month) + " / " + to_string(StartDayLesson(lessons).getData().Day)));
           
            int ScoopStart = DayCount(StartDayLesson(lessons, Manual));

            int ScoopEnd = ScoopStart + 7;

            if (StartDayLesson(lessons, Manual).getData().WeekDay != 0 && StartDayLesson(lessons, Manual).getData().WeekDay != 6) {

                if (WeekCycle == 0) {
                    ScoopStart = DayCount(StartDayLesson(lessons, Manual));
                    ScoopEnd = ScoopStart + (7 - (StartDayLesson(lessons, Manual).getData().WeekDay));

                }

                else
                {
                   
                   ScoopStart = DayCount(StartDayLesson(lessons, Manual)) + (7 - (StartDayLesson(lessons, Manual).getData().WeekDay)) + (WeekCycle - 1) * 7- 7 * WeekCycle;
                    
                   ScoopEnd = ScoopStart + 7;
                   
                }
               
           }

            

            //Start Set :

            //MessageBox::Show( StringConvert(to_string(ScoopStart) + " >>>> " + to_string(ScoopEnd) ));


            for (size_t n = 0;n < classes.size();n++) {
                for (size_t m = 0;m < lessons.size();m++) {
                    //MessageBox::Show(StringConvert(to_string(ScoopStart)+" < "+ to_string(DayCount(lessons.at(m)))));
                    if (!(DayCount(lessons.at(m)) >= ScoopStart && DayCount(lessons.at(m)) < ScoopEnd))
                        continue;

                    if (lessons.at(m).getClassLocation() == classes.at(n).getID()) {


                        switch (lessons.at(m).getData().WeekDay) {

                        case 0:


                            if (!(Tabel->Rows[n]->Cells[1]->Value == ""))
                                Tabel->Rows[n]->Cells[1]->Value += " \n";
                            if (lessons.at(m).getFoq())                        
                                Tabel->Rows[n]->Cells[1]->Value +=lessons.at(m).getName_S() + L"، " + lessons.at(m).getTeacherName_S() + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[1]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            break;


                        case 1:


                            if (!(Tabel->Rows[n]->Cells[2]->Value == ""))
                                Tabel->Rows[n]->Cells[2]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[2]->Value += lessons.at(m).getName_S() + L"، " + lessons.at(m).getTeacherName_S() + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[2]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            break;


                        case 2:


                            if (!(Tabel->Rows[n]->Cells[3]->Value == ""))
                                Tabel->Rows[n]->Cells[3]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[3]->Value += (lessons.at(m).getName_S()) + L"، " + (lessons.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[3]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            break;


                        case 3:


                            if (!(Tabel->Rows[n]->Cells[4]->Value == ""))
                                Tabel->Rows[n]->Cells[4]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[4]->Value += (lessons.at(m).getName_S()) + L"، " + (lessons.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[4]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            break;


                        case 4:


                            if (!(Tabel->Rows[n]->Cells[5]->Value == ""))
                                Tabel->Rows[n]->Cells[5]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[5]->Value += (lessons.at(m).getName_S()) + L"، " + (lessons.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[5]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            
                            break;


                        case 5:


                            if (!(Tabel->Rows[n]->Cells[6]->Value == ""))
                                Tabel->Rows[n]->Cells[6]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[6]->Value += (lessons.at(m).getName_S()) + L"، " + (lessons.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[6]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            break;


                        }

                       
                    }
                }
            }
        }

        void SetTable(vector <Lessons> lessons, vector <Lessons> lessons2, vector <Classes> classes, int WeekCycle, bool Manual) {

         

            EmptyTable();


            int ScoopStart = DayCount(StartDayLesson(lessons, Manual));
            int ScoopEnd = ScoopStart + 7;

            if (StartDayLesson(lessons, Manual).getData().WeekDay != 0 && StartDayLesson(lessons, Manual).getData().WeekDay != 6) {

                if (WeekCycle == 0) {
                    ScoopStart = DayCount(StartDayLesson(lessons, Manual));
                    ScoopEnd = ScoopStart + (7 - (StartDayLesson(lessons, Manual).getData().WeekDay));

                }

                else
                {
                    
                    ScoopStart = DayCount(StartDayLesson(lessons, Manual)) + (7 - (StartDayLesson(lessons, Manual).getData().WeekDay)) + (WeekCycle - 1) * 7 - 7 * WeekCycle;
                    ScoopEnd = ScoopStart + 7;
                }


            }


            //Start Set :



            for (size_t n = 0;n < classes.size();n++) {
                for (size_t m = 0;m < lessons.size();m++) {

                    if (!(DayCount(lessons.at(m)) >= ScoopStart && DayCount(lessons.at(m)) < ScoopEnd))
                        continue;

                    if (lessons.at(m).getClassLocation() == classes.at(n).getID()) {


                        switch (lessons.at(m).getData().WeekDay) {

                        case 0:


                            if (!(Tabel->Rows[n]->Cells[1]->Value == ""))
                                Tabel->Rows[n]->Cells[1]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[1]->Value += lessons.at(m).getName_S() + L"، " + lessons.at(m).getTeacherName_S() + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[1]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            break;


                        case 1:


                            if (!(Tabel->Rows[n]->Cells[2]->Value == ""))
                                Tabel->Rows[n]->Cells[2]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[2]->Value += lessons.at(m).getName_S() + L"، " + lessons.at(m).getTeacherName_S() + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[2]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            break;


                        case 2:


                            if (!(Tabel->Rows[n]->Cells[3]->Value == ""))
                                Tabel->Rows[n]->Cells[3]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[3]->Value += (lessons.at(m).getName_S()) + L"، " + (lessons.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[3]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            break;


                        case 3:


                            if (!(Tabel->Rows[n]->Cells[4]->Value == ""))
                                Tabel->Rows[n]->Cells[4]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[4]->Value += (lessons.at(m).getName_S()) + L"، " + (lessons.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[4]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            break;


                        case 4:


                            if (!(Tabel->Rows[n]->Cells[5]->Value == ""))
                                Tabel->Rows[n]->Cells[5]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[5]->Value += (lessons.at(m).getName_S()) + L"، " + (lessons.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[5]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";

                            break;


                        case 5:


                            if (!(Tabel->Rows[n]->Cells[6]->Value == ""))
                                Tabel->Rows[n]->Cells[6]->Value += " \n";
                            if (lessons.at(m).getFoq())
                                Tabel->Rows[n]->Cells[6]->Value += (lessons.at(m).getName_S()) + L"، " + (lessons.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[6]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                            break;


                        }


                    }
                }



                for (size_t m = 0;m < lessons2.size();m++) {

                    if (!(DayCount(lessons2.at(m)) >= ScoopStart && DayCount(lessons2.at(m)) < ScoopEnd))
                        continue;
                   
                    if (lessons2.at(m).getClassLocation() == classes.at(n).getID()) {

                       
                        switch (lessons2.at(m).getData().WeekDay) {

                        case 0:


                            if (!(Tabel->Rows[n]->Cells[1]->Value == ""))
                                Tabel->Rows[n]->Cells[1]->Value += " \n";
                            if (lessons2.at(m).getFoq())
                                Tabel->Rows[n]->Cells[1]->Value += lessons2.at(m).getName_S() + L"، " + lessons2.at(m).getTeacherName_S() + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[1]->Value += UTF8Convert(lessons2.at(m).getName()) + L"، " + UTF8Convert(lessons2.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            break;


                        case 1:


                            if (!(Tabel->Rows[n]->Cells[2]->Value == ""))
                                Tabel->Rows[n]->Cells[2]->Value += " \n";
                            if (lessons2.at(m).getFoq())
                                Tabel->Rows[n]->Cells[2]->Value += lessons2.at(m).getName_S() + L"، " + lessons2.at(m).getTeacherName_S() + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[2]->Value += UTF8Convert(lessons2.at(m).getName()) + L"، " + UTF8Convert(lessons2.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            break;


                        case 2:


                            if (!(Tabel->Rows[n]->Cells[3]->Value == ""))
                                Tabel->Rows[n]->Cells[3]->Value += " \n";
                            if (lessons2.at(m).getFoq())
                                Tabel->Rows[n]->Cells[3]->Value += (lessons2.at(m).getName_S()) + L"، " + (lessons2.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[3]->Value += UTF8Convert(lessons2.at(m).getName()) + L"، " + UTF8Convert(lessons2.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            break;


                        case 3:


                            if (!(Tabel->Rows[n]->Cells[4]->Value == ""))
                                Tabel->Rows[n]->Cells[4]->Value += " \n";
                            if (lessons2.at(m).getFoq())
                                Tabel->Rows[n]->Cells[4]->Value += (lessons2.at(m).getName_S()) + L"، " + (lessons2.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[4]->Value += UTF8Convert(lessons2.at(m).getName()) + L"، " + UTF8Convert(lessons2.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            break;


                        case 4:


                            if (!(Tabel->Rows[n]->Cells[5]->Value == ""))
                                Tabel->Rows[n]->Cells[5]->Value += " \n";
                            if (lessons2.at(m).getFoq())
                                Tabel->Rows[n]->Cells[5]->Value += (lessons2.at(m).getName_S()) + L"، " + (lessons2.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[5]->Value += UTF8Convert(lessons2.at(m).getName()) + L"، " + UTF8Convert(lessons2.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";

                            break;


                        case 5:


                            if (!(Tabel->Rows[n]->Cells[6]->Value == ""))
                                Tabel->Rows[n]->Cells[6]->Value += " \n";
                            if (lessons2.at(m).getFoq())
                                Tabel->Rows[n]->Cells[6]->Value += (lessons2.at(m).getName_S()) + L"، " + (lessons2.at(m).getTeacherName_S()) + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[6]->Value += UTF8Convert(lessons2.at(m).getName()) + L"، " + UTF8Convert(lessons2.at(m).getTeacherName()) + " \n(" + NumPerConvert(lessons2.at(m).getStartTime().Minute) + " : " + NumPerConvert(lessons2.at(m).getStartTime().Huor) + " )";
                            break;


                        }


                    }
                }




            }
        }

       


        void SetTable(Lessons less, vector <Classes> classes, int WeekCycle, bool Manual) {

            EmptyTable();
            //MessageBox::Show(StringConvert(to_string(StartDayLesson(lessons).getData().WeekDay) + " :  "+ to_string(StartDayLesson(lessons).getData().Month) + " / " + to_string(StartDayLesson(lessons).getData().Day)));

            int ScoopStart = DayCount(StartDayLesson(lessons, Manual));

            int ScoopEnd = ScoopStart + 7;

            if (StartDayLesson(lessons, Manual).getData().WeekDay != 0 && StartDayLesson(lessons, Manual).getData().WeekDay != 6) {

                if (WeekCycle == 0) {
                    ScoopStart = DayCount(StartDayLesson(lessons, Manual));
                    ScoopEnd = ScoopStart + (7 - (StartDayLesson(lessons, Manual).getData().WeekDay));

                }

                else
                {

                    ScoopStart = DayCount(StartDayLesson(lessons, Manual)) + (7 - (StartDayLesson(lessons, Manual).getData().WeekDay)) + (WeekCycle - 1) * 7 - 7 * WeekCycle;

                    ScoopEnd = ScoopStart + 7;

                }

            }



            //Start Set :



            for (size_t n = 0;n < classes.size();n++) {
               
                if (!(DayCount(less) >= ScoopStart && DayCount(less) < ScoopEnd))
                        continue;

                    if (less.getClassLocation() == classes.at(n).getID()) {


                        switch (less.getData().WeekDay) {

                        case 0:


                            if (!(Tabel->Rows[n]->Cells[1]->Value == ""))
                                Tabel->Rows[n]->Cells[1]->Value += " \n";
                            if (less.getFoq())
                                Tabel->Rows[n]->Cells[1]->Value += less.getName_S() + L"، " + less.getTeacherName_S() + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[1]->Value += UTF8Convert(less.getName()) + L"، " + UTF8Convert(less.getTeacherName()) + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            break;


                        case 1:


                            if (!(Tabel->Rows[n]->Cells[2]->Value == ""))
                                Tabel->Rows[n]->Cells[2]->Value += " \n";
                            if (less.getFoq())
                                Tabel->Rows[n]->Cells[2]->Value += less.getName_S() + L"، " + less.getTeacherName_S() + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[2]->Value += UTF8Convert(less.getName()) + L"، " + UTF8Convert(less.getTeacherName()) + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            break;


                        case 2:


                            if (!(Tabel->Rows[n]->Cells[3]->Value == ""))
                                Tabel->Rows[n]->Cells[3]->Value += " \n";
                            if (less.getFoq())
                                Tabel->Rows[n]->Cells[3]->Value += less.getName_S() + L"، " + less.getTeacherName_S() + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[3]->Value += UTF8Convert(less.getName()) + L"، " + UTF8Convert(less.getTeacherName()) + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            break;


                        case 3:


                            if (!(Tabel->Rows[n]->Cells[4]->Value == ""))
                                Tabel->Rows[n]->Cells[4]->Value += " \n";
                            if (less.getFoq())
                                Tabel->Rows[n]->Cells[4]->Value += less.getName_S() + L"، " + less.getTeacherName_S() + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[4]->Value += UTF8Convert(less.getName()) + L"، " + UTF8Convert(less.getTeacherName()) + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            break;


                        case 4:


                            if (!(Tabel->Rows[n]->Cells[5]->Value == ""))
                                Tabel->Rows[n]->Cells[5]->Value += " \n";
                            if (less.getFoq())
                                Tabel->Rows[n]->Cells[5]->Value += less.getName_S() + L"، " + less.getTeacherName_S() + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[5]->Value += UTF8Convert(less.getName()) + L"، " + UTF8Convert(less.getTeacherName()) + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            break;


                        case 5:


                            if (!(Tabel->Rows[n]->Cells[6]->Value == ""))
                                Tabel->Rows[n]->Cells[6]->Value += " \n";
                            if (less.getFoq())
                                Tabel->Rows[n]->Cells[6]->Value += less.getName_S() + L"، " + less.getTeacherName_S() + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            else
                                Tabel->Rows[n]->Cells[6]->Value += UTF8Convert(less.getName()) + L"، " + UTF8Convert(less.getTeacherName()) + " \n(" + NumPerConvert(less.getStartTime().Minute) + " : " + NumPerConvert(less.getStartTime().Huor) + " )";
                            break;


                        }


                    
                }
            }
        }


        void SetTable_ClassName() { 

            for (size_t n = 0;n < classes.size();n++) {
                Tabel->Rows->Add();
                Tabel->Rows[n]->Cells[0]->Value = L"کلاس " + NumPerConvert(classes.at(n).getID());
                if (classes.at(n).getVideoProjector())
                    Tabel->Rows[n]->Cells[0]->Value += L"📽";

            }
        }




        String^ WeekDayConvert(int Week) {



            switch (Week)
            {
            case 0:
                return L"شنبه";
                break;
            case 1:
                return L"یکشنبه";
                break;
            case 2:
                return L"دوشنبه";
                break;
            case 3:
                return L"سه شنبه";
                break;
            case 4:
                return L"چهارشنبه";
                break;
            case 5:
                return L"پنجشنبه";
                break;
            case 6:
                return L"جمعه";
                break;

            default:

               
                return  L"شنبه";

                break;
            }

    }
     

    private: System::Windows::Forms::TextBox^ TXWeekDayFoq;
    protected:
    private: System::Windows::Forms::Label^ LAWeekDayFoq;
    private: System::Windows::Forms::TextBox^ TXStNumFoq;
    private: System::Windows::Forms::TextBox^ TXStNameFoq;
    private: System::Windows::Forms::Button^ BTAfzodanFoq;
    private: System::Windows::Forms::Panel^ PAStNumFoq;
    private: System::Windows::Forms::Panel^ PAStNameFoq;
    private: System::Windows::Forms::Button^ BTTaiid3Foq;
    private: System::Windows::Forms::Label^ LAStNumFoq;
    private: System::Windows::Forms::Label^ LAStNameFoq;
    private: System::Windows::Forms::Label^ LADaneshjoFoq;
private: System::Windows::Forms::Button^ BTTaiid2Foq;


    private: System::Windows::Forms::NumericUpDown^ VAJalaseFoq;
    private: System::Windows::Forms::Label^ LAJalaseFoq;
    private: System::Windows::Forms::NumericUpDown^ VAM1Foq;
    private: System::Windows::Forms::NumericUpDown^ VAH1Foq;
    private: System::Windows::Forms::Label^ LAM1Foq;
    private: System::Windows::Forms::Label^ LAH1Foq;
    private: System::Windows::Forms::Label^ LATimeToolFoq;
    private: System::Windows::Forms::NumericUpDown^ VAMFoq;
    private: System::Windows::Forms::NumericUpDown^ VAHFoq;
    private: System::Windows::Forms::NumericUpDown^ VARozFoq;
    private: System::Windows::Forms::NumericUpDown^ VAMahFoq;
    private: System::Windows::Forms::Label^ LAMFoq;
    private: System::Windows::Forms::Label^ LAHFoq;
    private: System::Windows::Forms::Label^ LATimeFoq;
    private: System::Windows::Forms::Label^ LARozFoq;
    private: System::Windows::Forms::Label^ LAMahFoq;
    private: System::Windows::Forms::Label^ LADateFoq;
    private: System::Windows::Forms::Label^ LAErorFoq;
    private: System::Windows::Forms::CheckBox^ BOVideoProjectorFoq;
    private: System::Windows::Forms::TextBox^ TXLessonNameFoq;
    private: System::Windows::Forms::TextBox^ TXLessonIDFoq;
    private: System::Windows::Forms::Label^ LALessonNameFoq;
    private: System::Windows::Forms::Panel^ PALessonNameFoq;
    private: System::Windows::Forms::Label^ LALessonIDFoq;
    private: System::Windows::Forms::Panel^ PALessonIDFoq;
    private: System::Windows::Forms::TextBox^ TXTeacherNameFoq;
    private: System::Windows::Forms::Button^ BTTaiid1Foq;
    private: System::Windows::Forms::Label^ LATeacherNameFoq;
    private: System::Windows::Forms::Panel^ PATeacherNameFoq;

    private: System::Windows::Forms::TextBox^ TXClassID;
    private: System::Windows::Forms::TextBox^ TXLessonID;
    private: System::Windows::Forms::Label^ LAEror;
    private: System::Windows::Forms::Button^ BTTaiid;
    private: System::Windows::Forms::Label^ LACassID;
    private: System::Windows::Forms::Panel^ PAClassID;
    private: System::Windows::Forms::Label^ LALessonID;
    private: System::Windows::Forms::Panel^ PALessonID;
    private: System::Windows::Forms::DataGridView^ Tabel;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ R0;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ R1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ R2;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ R3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ R4;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ R5;
    private: System::Windows::Forms::Button^ BTFoqBarname;
    private: System::Windows::Forms::Button^ BTTanzinBarname;
    private: System::Windows::Forms::Button^ BTBarnameDarsi;
    private: System::Windows::Forms::Label^ LAXmlFile;
    private: System::Windows::Forms::Button^ BTImportFile;
private: System::Windows::Forms::Label^ LAErorIm;


private: System::Windows::Forms::Button^ BTAuto;
private: System::Windows::Forms::Button^ BTSave;
private: System::Windows::Forms::Button^ BTBazgashtTable;
private: System::Windows::Forms::Button^ BTBishtarImTable;
private: System::Windows::Forms::Label^ LATanzimLessonInfo;
private: System::Windows::Forms::Label^ LATanzimClassInfo;
private: System::Windows::Forms::Button^ BTBazgasht;
private: System::ComponentModel::IContainer^ components;














	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->components = (gcnew System::ComponentModel::Container());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
            this->TXWeekDayFoq = (gcnew System::Windows::Forms::TextBox());
            this->LAWeekDayFoq = (gcnew System::Windows::Forms::Label());
            this->TXStNumFoq = (gcnew System::Windows::Forms::TextBox());
            this->TXStNameFoq = (gcnew System::Windows::Forms::TextBox());
            this->BTAfzodanFoq = (gcnew System::Windows::Forms::Button());
            this->PAStNumFoq = (gcnew System::Windows::Forms::Panel());
            this->PAStNameFoq = (gcnew System::Windows::Forms::Panel());
            this->BTTaiid3Foq = (gcnew System::Windows::Forms::Button());
            this->LAStNumFoq = (gcnew System::Windows::Forms::Label());
            this->LAStNameFoq = (gcnew System::Windows::Forms::Label());
            this->LADaneshjoFoq = (gcnew System::Windows::Forms::Label());
            this->BTTaiid2Foq = (gcnew System::Windows::Forms::Button());
            this->VAJalaseFoq = (gcnew System::Windows::Forms::NumericUpDown());
            this->LAJalaseFoq = (gcnew System::Windows::Forms::Label());
            this->VAM1Foq = (gcnew System::Windows::Forms::NumericUpDown());
            this->VAH1Foq = (gcnew System::Windows::Forms::NumericUpDown());
            this->LAM1Foq = (gcnew System::Windows::Forms::Label());
            this->LAH1Foq = (gcnew System::Windows::Forms::Label());
            this->LATimeToolFoq = (gcnew System::Windows::Forms::Label());
            this->VAMFoq = (gcnew System::Windows::Forms::NumericUpDown());
            this->VAHFoq = (gcnew System::Windows::Forms::NumericUpDown());
            this->VARozFoq = (gcnew System::Windows::Forms::NumericUpDown());
            this->VAMahFoq = (gcnew System::Windows::Forms::NumericUpDown());
            this->LAMFoq = (gcnew System::Windows::Forms::Label());
            this->LAHFoq = (gcnew System::Windows::Forms::Label());
            this->LATimeFoq = (gcnew System::Windows::Forms::Label());
            this->LARozFoq = (gcnew System::Windows::Forms::Label());
            this->LAMahFoq = (gcnew System::Windows::Forms::Label());
            this->LADateFoq = (gcnew System::Windows::Forms::Label());
            this->LAErorFoq = (gcnew System::Windows::Forms::Label());
            this->BOVideoProjectorFoq = (gcnew System::Windows::Forms::CheckBox());
            this->TXLessonNameFoq = (gcnew System::Windows::Forms::TextBox());
            this->TXLessonIDFoq = (gcnew System::Windows::Forms::TextBox());
            this->LALessonNameFoq = (gcnew System::Windows::Forms::Label());
            this->PALessonNameFoq = (gcnew System::Windows::Forms::Panel());
            this->LALessonIDFoq = (gcnew System::Windows::Forms::Label());
            this->PALessonIDFoq = (gcnew System::Windows::Forms::Panel());
            this->TXTeacherNameFoq = (gcnew System::Windows::Forms::TextBox());
            this->BTTaiid1Foq = (gcnew System::Windows::Forms::Button());
            this->LATeacherNameFoq = (gcnew System::Windows::Forms::Label());
            this->PATeacherNameFoq = (gcnew System::Windows::Forms::Panel());
            this->TXClassID = (gcnew System::Windows::Forms::TextBox());
            this->TXLessonID = (gcnew System::Windows::Forms::TextBox());
            this->LAEror = (gcnew System::Windows::Forms::Label());
            this->BTTaiid = (gcnew System::Windows::Forms::Button());
            this->LACassID = (gcnew System::Windows::Forms::Label());
            this->PAClassID = (gcnew System::Windows::Forms::Panel());
            this->LALessonID = (gcnew System::Windows::Forms::Label());
            this->PALessonID = (gcnew System::Windows::Forms::Panel());
            this->Tabel = (gcnew System::Windows::Forms::DataGridView());
            this->Column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->R0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->R1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->R2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->R3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->R4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->R5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->BTFoqBarname = (gcnew System::Windows::Forms::Button());
            this->BTTanzinBarname = (gcnew System::Windows::Forms::Button());
            this->BTBarnameDarsi = (gcnew System::Windows::Forms::Button());
            this->LAXmlFile = (gcnew System::Windows::Forms::Label());
            this->BTImportFile = (gcnew System::Windows::Forms::Button());
            this->LAErorIm = (gcnew System::Windows::Forms::Label());
            this->BTAuto = (gcnew System::Windows::Forms::Button());
            this->BTSave = (gcnew System::Windows::Forms::Button());
            this->BTBazgashtTable = (gcnew System::Windows::Forms::Button());
            this->BTBishtarImTable = (gcnew System::Windows::Forms::Button());
            this->LATanzimLessonInfo = (gcnew System::Windows::Forms::Label());
            this->LATanzimClassInfo = (gcnew System::Windows::Forms::Label());
            this->BTBazgasht = (gcnew System::Windows::Forms::Button());
            this->BTBazgashtFog = (gcnew System::Windows::Forms::Button());
            this->LAErorFoq2 = (gcnew System::Windows::Forms::Label());
            this->BTBazgasht2Foq = (gcnew System::Windows::Forms::Button());
            this->LAErorFoq3 = (gcnew System::Windows::Forms::Label());
            this->BTBazgasht3Foq = (gcnew System::Windows::Forms::Button());
            this->TimeEror = (gcnew System::Windows::Forms::Timer(this->components));
            this->LAWeekCycle = (gcnew System::Windows::Forms::Label());
            this->BTNext = (gcnew System::Windows::Forms::Button());
            this->BTBack = (gcnew System::Windows::Forms::Button());
            this->BTDengerFill = (gcnew System::Windows::Forms::Button());
            this->BTBazgashtList = (gcnew System::Windows::Forms::Button());
            this->LITeacherList = (gcnew System::Windows::Forms::ListBox());
            this->LATeacherList = (gcnew System::Windows::Forms::Label());
            this->LIStudentList = (gcnew System::Windows::Forms::ListBox());
            this->LAStudentList = (gcnew System::Windows::Forms::Label());
            this->LAHeder = (gcnew System::Windows::Forms::Label());
            this->BTExit = (gcnew System::Windows::Forms::Button());
            this->BTNewIm = (gcnew System::Windows::Forms::Button());
            this->TimeLogo = (gcnew System::Windows::Forms::Timer(this->components));
            this->PAFileErorr = (gcnew System::Windows::Forms::Panel());
            this->LAErorrFile = (gcnew System::Windows::Forms::Label());
            this->BTNewFile2 = (gcnew System::Windows::Forms::Button());
            this->BTDenger2 = (gcnew System::Windows::Forms::Button());
            this->PALogo = (gcnew System::Windows::Forms::Panel());
            this->LOGO = (gcnew System::Windows::Forms::Panel());
            this->LALogoKaver = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAJalaseFoq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAM1Foq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAH1Foq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAMFoq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAHFoq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VARozFoq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAMahFoq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabel))->BeginInit();
            this->PAFileErorr->SuspendLayout();
            this->PALogo->SuspendLayout();
            this->LOGO->SuspendLayout();
            this->SuspendLayout();
            // 
            // TXWeekDayFoq
            // 
            this->TXWeekDayFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->TXWeekDayFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->TXWeekDayFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXWeekDayFoq->Font = (gcnew System::Drawing::Font(L"B Nazanin", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->TXWeekDayFoq->Location = System::Drawing::Point(188, 302);
            this->TXWeekDayFoq->Name = L"TXWeekDayFoq";
            this->TXWeekDayFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->TXWeekDayFoq->Size = System::Drawing::Size(90, 26);
            this->TXWeekDayFoq->TabIndex = 161;
            this->TXWeekDayFoq->Text = L"شنبه";
            this->TXWeekDayFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // LAWeekDayFoq
            // 
            this->LAWeekDayFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAWeekDayFoq->AutoSize = true;
            this->LAWeekDayFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAWeekDayFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAWeekDayFoq->Location = System::Drawing::Point(276, 274);
            this->LAWeekDayFoq->Name = L"LAWeekDayFoq";
            this->LAWeekDayFoq->Size = System::Drawing::Size(102, 67);
            this->LAWeekDayFoq->TabIndex = 171;
            this->LAWeekDayFoq->Text = L" :  روز شروع";
            // 
            // TXStNumFoq
            // 
            this->TXStNumFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->TXStNumFoq->BackColor = System::Drawing::Color::Aquamarine;
            this->TXStNumFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXStNumFoq->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXStNumFoq->Location = System::Drawing::Point(183, 278);
            this->TXStNumFoq->Name = L"TXStNumFoq";
            this->TXStNumFoq->Size = System::Drawing::Size(331, 18);
            this->TXStNumFoq->TabIndex = 170;
            this->TXStNumFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // TXStNameFoq
            // 
            this->TXStNameFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->TXStNameFoq->BackColor = System::Drawing::Color::Aquamarine;
            this->TXStNameFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXStNameFoq->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXStNameFoq->Location = System::Drawing::Point(183, 194);
            this->TXStNameFoq->Name = L"TXStNameFoq";
            this->TXStNameFoq->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->TXStNameFoq->Size = System::Drawing::Size(331, 18);
            this->TXStNameFoq->TabIndex = 169;
            this->TXStNameFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // BTAfzodanFoq
            // 
            this->BTAfzodanFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTAfzodanFoq->AutoEllipsis = true;
            this->BTAfzodanFoq->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTAfzodanFoq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTAfzodanFoq->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTAfzodanFoq->ForeColor = System::Drawing::SystemColors::Info;
            this->BTAfzodanFoq->Location = System::Drawing::Point(354, 438);
            this->BTAfzodanFoq->Name = L"BTAfzodanFoq";
            this->BTAfzodanFoq->Size = System::Drawing::Size(160, 35);
            this->BTAfzodanFoq->TabIndex = 168;
            this->BTAfzodanFoq->Text = L"افزودن";
            this->BTAfzodanFoq->UseVisualStyleBackColor = false;
            this->BTAfzodanFoq->Click += gcnew System::EventHandler(this, &MainForm::BTAfzodanFoq_Click);
            // 
            // PAStNumFoq
            // 
            this->PAStNumFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->PAStNumFoq->BackColor = System::Drawing::Color::DarkGreen;
            this->PAStNumFoq->Location = System::Drawing::Point(183, 298);
            this->PAStNumFoq->Name = L"PAStNumFoq";
            this->PAStNumFoq->Size = System::Drawing::Size(331, 3);
            this->PAStNumFoq->TabIndex = 167;
            // 
            // PAStNameFoq
            // 
            this->PAStNameFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->PAStNameFoq->BackColor = System::Drawing::Color::DarkGreen;
            this->PAStNameFoq->Location = System::Drawing::Point(183, 214);
            this->PAStNameFoq->Name = L"PAStNameFoq";
            this->PAStNameFoq->Size = System::Drawing::Size(331, 3);
            this->PAStNameFoq->TabIndex = 166;
            // 
            // BTTaiid3Foq
            // 
            this->BTTaiid3Foq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTTaiid3Foq->AutoEllipsis = true;
            this->BTTaiid3Foq->BackColor = System::Drawing::Color::ForestGreen;
            this->BTTaiid3Foq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTTaiid3Foq->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTTaiid3Foq->ForeColor = System::Drawing::SystemColors::Info;
            this->BTTaiid3Foq->Location = System::Drawing::Point(525, 438);
            this->BTTaiid3Foq->Name = L"BTTaiid3Foq";
            this->BTTaiid3Foq->Size = System::Drawing::Size(160, 35);
            this->BTTaiid3Foq->TabIndex = 165;
            this->BTTaiid3Foq->Text = L"ثبت درس";
            this->BTTaiid3Foq->UseVisualStyleBackColor = false;
            this->BTTaiid3Foq->Click += gcnew System::EventHandler(this, &MainForm::BTTaiid3Foq_Click);
            // 
            // LAStNumFoq
            // 
            this->LAStNumFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAStNumFoq->AutoSize = true;
            this->LAStNumFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 34, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAStNumFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAStNumFoq->Location = System::Drawing::Point(511, 249);
            this->LAStNumFoq->Name = L"LAStNumFoq";
            this->LAStNumFoq->Size = System::Drawing::Size(150, 89);
            this->LAStNumFoq->TabIndex = 164;
            this->LAStNumFoq->Text = L" : شماره دانشجویی ";
            // 
            // LAStNameFoq
            // 
            this->LAStNameFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAStNameFoq->AutoSize = true;
            this->LAStNameFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 34, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAStNameFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAStNameFoq->Location = System::Drawing::Point(511, 150);
            this->LAStNameFoq->Name = L"LAStNameFoq";
            this->LAStNameFoq->Size = System::Drawing::Size(189, 89);
            this->LAStNameFoq->TabIndex = 163;
            this->LAStNameFoq->Text = L" : نام و نام خانوادگی    ";
            // 
            // LADaneshjoFoq
            // 
            this->LADaneshjoFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LADaneshjoFoq->AutoSize = true;
            this->LADaneshjoFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 38, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LADaneshjoFoq->ForeColor = System::Drawing::Color::OliveDrab;
            this->LADaneshjoFoq->Location = System::Drawing::Point(506, 39);
            this->LADaneshjoFoq->Name = L"LADaneshjoFoq";
            this->LADaneshjoFoq->Size = System::Drawing::Size(194, 98);
            this->LADaneshjoFoq->TabIndex = 162;
            this->LADaneshjoFoq->Text = L"  افزودن دانشجویان   ";
            // 
            // BTTaiid2Foq
            // 
            this->BTTaiid2Foq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTTaiid2Foq->AutoEllipsis = true;
            this->BTTaiid2Foq->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTTaiid2Foq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTTaiid2Foq->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTTaiid2Foq->ForeColor = System::Drawing::SystemColors::Info;
            this->BTTaiid2Foq->Location = System::Drawing::Point(405, 438);
            this->BTTaiid2Foq->Name = L"BTTaiid2Foq";
            this->BTTaiid2Foq->Size = System::Drawing::Size(217, 35);
            this->BTTaiid2Foq->TabIndex = 161;
            this->BTTaiid2Foq->Text = L"تایید";
            this->BTTaiid2Foq->UseVisualStyleBackColor = false;
            this->BTTaiid2Foq->Click += gcnew System::EventHandler(this, &MainForm::BTTaiid2Foq_Click);
            // 
            // VAJalaseFoq
            // 
            this->VAJalaseFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->VAJalaseFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAJalaseFoq->Location = System::Drawing::Point(401, 304);
            this->VAJalaseFoq->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
            this->VAJalaseFoq->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->VAJalaseFoq->Name = L"VAJalaseFoq";
            this->VAJalaseFoq->Size = System::Drawing::Size(90, 20);
            this->VAJalaseFoq->TabIndex = 160;
            this->VAJalaseFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->VAJalaseFoq->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // LAJalaseFoq
            // 
            this->LAJalaseFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAJalaseFoq->AutoSize = true;
            this->LAJalaseFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 34, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAJalaseFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAJalaseFoq->Location = System::Drawing::Point(484, 262);
            this->LAJalaseFoq->Name = L"LAJalaseFoq";
            this->LAJalaseFoq->Size = System::Drawing::Size(154, 89);
            this->LAJalaseFoq->TabIndex = 159;
            this->LAJalaseFoq->Text = L" : تعداد جلسات ";
            // 
            // VAM1Foq
            // 
            this->VAM1Foq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->VAM1Foq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAM1Foq->Location = System::Drawing::Point(188, 225);
            this->VAM1Foq->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
            this->VAM1Foq->Name = L"VAM1Foq";
            this->VAM1Foq->Size = System::Drawing::Size(90, 20);
            this->VAM1Foq->TabIndex = 158;
            this->VAM1Foq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // VAH1Foq
            // 
            this->VAH1Foq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->VAH1Foq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAH1Foq->Location = System::Drawing::Point(335, 224);
            this->VAH1Foq->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->VAH1Foq->Name = L"VAH1Foq";
            this->VAH1Foq->Size = System::Drawing::Size(90, 20);
            this->VAH1Foq->TabIndex = 157;
            this->VAH1Foq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // LAM1Foq
            // 
            this->LAM1Foq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAM1Foq->AutoSize = true;
            this->LAM1Foq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAM1Foq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAM1Foq->Location = System::Drawing::Point(276, 195);
            this->LAM1Foq->Name = L"LAM1Foq";
            this->LAM1Foq->Size = System::Drawing::Size(64, 67);
            this->LAM1Foq->TabIndex = 156;
            this->LAM1Foq->Text = L" : دقیقه";
            // 
            // LAH1Foq
            // 
            this->LAH1Foq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAH1Foq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAH1Foq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAH1Foq->Location = System::Drawing::Point(422, 195);
            this->LAH1Foq->Name = L"LAH1Foq";
            this->LAH1Foq->Size = System::Drawing::Size(85, 67);
            this->LAH1Foq->TabIndex = 155;
            this->LAH1Foq->Text = L" : ساعت";
            // 
            // LATimeToolFoq
            // 
            this->LATimeToolFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LATimeToolFoq->AutoSize = true;
            this->LATimeToolFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 34, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LATimeToolFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LATimeToolFoq->Location = System::Drawing::Point(486, 184);
            this->LATimeToolFoq->Name = L"LATimeToolFoq";
            this->LATimeToolFoq->Size = System::Drawing::Size(157, 89);
            this->LATimeToolFoq->TabIndex = 154;
            this->LATimeToolFoq->Text = L" : مدت برگزاری";
            // 
            // VAMFoq
            // 
            this->VAMFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->VAMFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAMFoq->Location = System::Drawing::Point(188, 152);
            this->VAMFoq->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
            this->VAMFoq->Name = L"VAMFoq";
            this->VAMFoq->Size = System::Drawing::Size(90, 20);
            this->VAMFoq->TabIndex = 153;
            this->VAMFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // VAHFoq
            // 
            this->VAHFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->VAHFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAHFoq->Location = System::Drawing::Point(335, 151);
            this->VAHFoq->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 23, 0, 0, 0 });
            this->VAHFoq->Name = L"VAHFoq";
            this->VAHFoq->Size = System::Drawing::Size(90, 20);
            this->VAHFoq->TabIndex = 152;
            this->VAHFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // VARozFoq
            // 
            this->VARozFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->VARozFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VARozFoq->Location = System::Drawing::Point(188, 79);
            this->VARozFoq->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
            this->VARozFoq->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->VARozFoq->Name = L"VARozFoq";
            this->VARozFoq->Size = System::Drawing::Size(90, 20);
            this->VARozFoq->TabIndex = 151;
            this->VARozFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->VARozFoq->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->VARozFoq->ValueChanged += gcnew System::EventHandler(this, &MainForm::VARozFoq_ValueChanged);
            // 
            // VAMahFoq
            // 
            this->VAMahFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->VAMahFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAMahFoq->Location = System::Drawing::Point(335, 79);
            this->VAMahFoq->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
            this->VAMahFoq->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->VAMahFoq->Name = L"VAMahFoq";
            this->VAMahFoq->Size = System::Drawing::Size(90, 20);
            this->VAMahFoq->TabIndex = 150;
            this->VAMahFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->VAMahFoq->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->VAMahFoq->ValueChanged += gcnew System::EventHandler(this, &MainForm::VAMahFoq_ValueChanged);
            // 
            // LAMFoq
            // 
            this->LAMFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAMFoq->AutoSize = true;
            this->LAMFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAMFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAMFoq->Location = System::Drawing::Point(276, 122);
            this->LAMFoq->Name = L"LAMFoq";
            this->LAMFoq->Size = System::Drawing::Size(64, 67);
            this->LAMFoq->TabIndex = 149;
            this->LAMFoq->Text = L" : دقیقه";
            // 
            // LAHFoq
            // 
            this->LAHFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAHFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAHFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAHFoq->Location = System::Drawing::Point(422, 122);
            this->LAHFoq->Name = L"LAHFoq";
            this->LAHFoq->Size = System::Drawing::Size(85, 67);
            this->LAHFoq->TabIndex = 149;
            this->LAHFoq->Text = L" : ساعت";
            // 
            // LATimeFoq
            // 
            this->LATimeFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LATimeFoq->AutoSize = true;
            this->LATimeFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 34, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LATimeFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LATimeFoq->Location = System::Drawing::Point(486, 111);
            this->LATimeFoq->Name = L"LATimeFoq";
            this->LATimeFoq->Size = System::Drawing::Size(181, 89);
            this->LATimeFoq->TabIndex = 147;
            this->LATimeFoq->Text = L" : ساعت برگزاری    ";
            // 
            // LARozFoq
            // 
            this->LARozFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LARozFoq->AutoSize = true;
            this->LARozFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LARozFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LARozFoq->Location = System::Drawing::Point(274, 52);
            this->LARozFoq->Name = L"LARozFoq";
            this->LARozFoq->Size = System::Drawing::Size(60, 67);
            this->LARozFoq->TabIndex = 146;
            this->LARozFoq->Text = L" : روز";
            // 
            // LAMahFoq
            // 
            this->LAMahFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAMahFoq->AutoSize = true;
            this->LAMahFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAMahFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAMahFoq->Location = System::Drawing::Point(428, 52);
            this->LAMahFoq->Name = L"LAMahFoq";
            this->LAMahFoq->Size = System::Drawing::Size(53, 67);
            this->LAMahFoq->TabIndex = 145;
            this->LAMahFoq->Text = L" : ماه";
            // 
            // LADateFoq
            // 
            this->LADateFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LADateFoq->AutoSize = true;
            this->LADateFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LADateFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LADateFoq->Location = System::Drawing::Point(483, 33);
            this->LADateFoq->Name = L"LADateFoq";
            this->LADateFoq->Size = System::Drawing::Size(157, 92);
            this->LADateFoq->TabIndex = 144;
            this->LADateFoq->Text = L" : تاریخ شروع  ";
            // 
            // LAErorFoq
            // 
            this->LAErorFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAErorFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAErorFoq->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->LAErorFoq->ImeMode = System::Windows::Forms::ImeMode::NoControl;
            this->LAErorFoq->Location = System::Drawing::Point(-1, 296);
            this->LAErorFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAErorFoq->Name = L"LAErorFoq";
            this->LAErorFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LAErorFoq->Size = System::Drawing::Size(482, 77);
            this->LAErorFoq->TabIndex = 143;
            this->LAErorFoq->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // BOVideoProjectorFoq
            // 
            this->BOVideoProjectorFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BOVideoProjectorFoq->AutoSize = true;
            this->BOVideoProjectorFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->BOVideoProjectorFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->BOVideoProjectorFoq->Location = System::Drawing::Point(518, 301);
            this->BOVideoProjectorFoq->Name = L"BOVideoProjectorFoq";
            this->BOVideoProjectorFoq->Size = System::Drawing::Size(95, 60);
            this->BOVideoProjectorFoq->TabIndex = 4;
            this->BOVideoProjectorFoq->Text = L"ویدئوپرژکتور";
            this->BOVideoProjectorFoq->UseVisualStyleBackColor = true;
            // 
            // TXLessonNameFoq
            // 
            this->TXLessonNameFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->TXLessonNameFoq->BackColor = System::Drawing::Color::Aquamarine;
            this->TXLessonNameFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXLessonNameFoq->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXLessonNameFoq->Location = System::Drawing::Point(174, 163);
            this->TXLessonNameFoq->Name = L"TXLessonNameFoq";
            this->TXLessonNameFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->TXLessonNameFoq->Size = System::Drawing::Size(331, 18);
            this->TXLessonNameFoq->TabIndex = 140;
            this->TXLessonNameFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->TXLessonNameFoq->TextChanged += gcnew System::EventHandler(this, &MainForm::TXLessonNameFoq_TextChanged);
            // 
            // TXLessonIDFoq
            // 
            this->TXLessonIDFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->TXLessonIDFoq->BackColor = System::Drawing::Color::Aquamarine;
            this->TXLessonIDFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXLessonIDFoq->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXLessonIDFoq->Location = System::Drawing::Point(174, 103);
            this->TXLessonIDFoq->Name = L"TXLessonIDFoq";
            this->TXLessonIDFoq->Size = System::Drawing::Size(331, 18);
            this->TXLessonIDFoq->TabIndex = 139;
            this->TXLessonIDFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->TXLessonIDFoq->TextChanged += gcnew System::EventHandler(this, &MainForm::TXLessonIDFoq_TextChanged);
            // 
            // LALessonNameFoq
            // 
            this->LALessonNameFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LALessonNameFoq->AutoSize = true;
            this->LALessonNameFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LALessonNameFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LALessonNameFoq->Location = System::Drawing::Point(500, 129);
            this->LALessonNameFoq->Name = L"LALessonNameFoq";
            this->LALessonNameFoq->Size = System::Drawing::Size(126, 92);
            this->LALessonNameFoq->TabIndex = 141;
            this->LALessonNameFoq->Text = L" : نام درس";
            // 
            // PALessonNameFoq
            // 
            this->PALessonNameFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->PALessonNameFoq->BackColor = System::Drawing::Color::DarkGreen;
            this->PALessonNameFoq->Location = System::Drawing::Point(174, 186);
            this->PALessonNameFoq->Name = L"PALessonNameFoq";
            this->PALessonNameFoq->Size = System::Drawing::Size(331, 3);
            this->PALessonNameFoq->TabIndex = 138;
            // 
            // LALessonIDFoq
            // 
            this->LALessonIDFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LALessonIDFoq->AutoSize = true;
            this->LALessonIDFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LALessonIDFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LALessonIDFoq->Location = System::Drawing::Point(502, 58);
            this->LALessonIDFoq->Name = L"LALessonIDFoq";
            this->LALessonIDFoq->Size = System::Drawing::Size(136, 92);
            this->LALessonIDFoq->TabIndex = 137;
            this->LALessonIDFoq->Text = L" : نشانی درس";
            // 
            // PALessonIDFoq
            // 
            this->PALessonIDFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->PALessonIDFoq->BackColor = System::Drawing::Color::DarkGreen;
            this->PALessonIDFoq->Location = System::Drawing::Point(174, 123);
            this->PALessonIDFoq->Name = L"PALessonIDFoq";
            this->PALessonIDFoq->Size = System::Drawing::Size(331, 3);
            this->PALessonIDFoq->TabIndex = 136;
            // 
            // TXTeacherNameFoq
            // 
            this->TXTeacherNameFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->TXTeacherNameFoq->BackColor = System::Drawing::Color::Aquamarine;
            this->TXTeacherNameFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXTeacherNameFoq->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXTeacherNameFoq->Location = System::Drawing::Point(174, 235);
            this->TXTeacherNameFoq->Name = L"TXTeacherNameFoq";
            this->TXTeacherNameFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->TXTeacherNameFoq->Size = System::Drawing::Size(331, 18);
            this->TXTeacherNameFoq->TabIndex = 3;
            this->TXTeacherNameFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->TXTeacherNameFoq->TextChanged += gcnew System::EventHandler(this, &MainForm::TXTeacherNameFoq_TextChanged);
            // 
            // BTTaiid1Foq
            // 
            this->BTTaiid1Foq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTTaiid1Foq->AutoEllipsis = true;
            this->BTTaiid1Foq->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTTaiid1Foq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTTaiid1Foq->Font = (gcnew System::Drawing::Font(L"B Nazanin", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTTaiid1Foq->ForeColor = System::Drawing::SystemColors::Info;
            this->BTTaiid1Foq->Location = System::Drawing::Point(390, 410);
            this->BTTaiid1Foq->Name = L"BTTaiid1Foq";
            this->BTTaiid1Foq->Size = System::Drawing::Size(204, 35);
            this->BTTaiid1Foq->TabIndex = 134;
            this->BTTaiid1Foq->Text = L"تایید";
            this->BTTaiid1Foq->UseVisualStyleBackColor = false;
            this->BTTaiid1Foq->Click += gcnew System::EventHandler(this, &MainForm::BTTaiid1Foq_Click);
            // 
            // LATeacherNameFoq
            // 
            this->LATeacherNameFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LATeacherNameFoq->AutoSize = true;
            this->LATeacherNameFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LATeacherNameFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LATeacherNameFoq->Location = System::Drawing::Point(502, 197);
            this->LATeacherNameFoq->Name = L"LATeacherNameFoq";
            this->LATeacherNameFoq->Size = System::Drawing::Size(120, 92);
            this->LATeacherNameFoq->TabIndex = 133;
            this->LATeacherNameFoq->Text = L" : نام استاد";
            // 
            // PATeacherNameFoq
            // 
            this->PATeacherNameFoq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->PATeacherNameFoq->BackColor = System::Drawing::Color::DarkGreen;
            this->PATeacherNameFoq->Location = System::Drawing::Point(175, 255);
            this->PATeacherNameFoq->Name = L"PATeacherNameFoq";
            this->PATeacherNameFoq->Size = System::Drawing::Size(331, 3);
            this->PATeacherNameFoq->TabIndex = 132;
            // 
            // TXClassID
            // 
            this->TXClassID->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->TXClassID->BackColor = System::Drawing::Color::Aquamarine;
            this->TXClassID->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXClassID->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXClassID->Location = System::Drawing::Point(193, 207);
            this->TXClassID->Name = L"TXClassID";
            this->TXClassID->Size = System::Drawing::Size(331, 18);
            this->TXClassID->TabIndex = 2;
            this->TXClassID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->TXClassID->TextChanged += gcnew System::EventHandler(this, &MainForm::TXClassID_TextChanged);
            // 
            // TXLessonID
            // 
            this->TXLessonID->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->TXLessonID->BackColor = System::Drawing::Color::Aquamarine;
            this->TXLessonID->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXLessonID->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXLessonID->Location = System::Drawing::Point(193, 103);
            this->TXLessonID->Name = L"TXLessonID";
            this->TXLessonID->Size = System::Drawing::Size(331, 18);
            this->TXLessonID->TabIndex = 1;
            this->TXLessonID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->TXLessonID->TextChanged += gcnew System::EventHandler(this, &MainForm::TXLessonID_TextChanged);
            // 
            // LAEror
            // 
            this->LAEror->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAEror->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAEror->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->LAEror->ImeMode = System::Windows::Forms::ImeMode::NoControl;
            this->LAEror->Location = System::Drawing::Point(25, 264);
            this->LAEror->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAEror->Name = L"LAEror";
            this->LAEror->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LAEror->Size = System::Drawing::Size(639, 92);
            this->LAEror->TabIndex = 128;
            this->LAEror->Text = L" ";
            this->LAEror->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // BTTaiid
            // 
            this->BTTaiid->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTTaiid->AutoEllipsis = true;
            this->BTTaiid->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTTaiid->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTTaiid->Font = (gcnew System::Drawing::Font(L"B Nazanin", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTTaiid->ForeColor = System::Drawing::SystemColors::Info;
            this->BTTaiid->Location = System::Drawing::Point(415, 410);
            this->BTTaiid->Name = L"BTTaiid";
            this->BTTaiid->Size = System::Drawing::Size(206, 35);
            this->BTTaiid->TabIndex = 127;
            this->BTTaiid->Text = L"تایید";
            this->BTTaiid->UseVisualStyleBackColor = false;
            this->BTTaiid->Click += gcnew System::EventHandler(this, &MainForm::BTTaiid_Click);
            // 
            // LACassID
            // 
            this->LACassID->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LACassID->AutoSize = true;
            this->LACassID->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LACassID->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LACassID->Location = System::Drawing::Point(530, 172);
            this->LACassID->Name = L"LACassID";
            this->LACassID->Size = System::Drawing::Size(138, 92);
            this->LACassID->TabIndex = 126;
            this->LACassID->Text = L" : شماره کلاس";
            // 
            // PAClassID
            // 
            this->PAClassID->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->PAClassID->BackColor = System::Drawing::Color::DarkGreen;
            this->PAClassID->Location = System::Drawing::Point(193, 230);
            this->PAClassID->Name = L"PAClassID";
            this->PAClassID->Size = System::Drawing::Size(331, 3);
            this->PAClassID->TabIndex = 125;
            // 
            // LALessonID
            // 
            this->LALessonID->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LALessonID->AutoSize = true;
            this->LALessonID->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LALessonID->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LALessonID->Location = System::Drawing::Point(530, 69);
            this->LALessonID->Name = L"LALessonID";
            this->LALessonID->Size = System::Drawing::Size(136, 92);
            this->LALessonID->TabIndex = 124;
            this->LALessonID->Text = L" : نشانی درس";
            // 
            // PALessonID
            // 
            this->PALessonID->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->PALessonID->BackColor = System::Drawing::Color::DarkGreen;
            this->PALessonID->Location = System::Drawing::Point(193, 127);
            this->PALessonID->Name = L"PALessonID";
            this->PALessonID->Size = System::Drawing::Size(331, 3);
            this->PALessonID->TabIndex = 123;
            // 
            // Tabel
            // 
            this->Tabel->AllowUserToAddRows = false;
            this->Tabel->AllowUserToDeleteRows = false;
            this->Tabel->AllowUserToResizeColumns = false;
            this->Tabel->AllowUserToResizeRows = false;
            this->Tabel->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->Tabel->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
            this->Tabel->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
            dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle7->BackColor = System::Drawing::Color::MediumAquamarine;
            dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle7->ForeColor = System::Drawing::Color::ForestGreen;
            dataGridViewCellStyle7->NullValue = nullptr;
            dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::Aquamarine;
            dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->Tabel->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle7;
            this->Tabel->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->Tabel->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
                this->Column, this->R0,
                    this->R1, this->R2, this->R3, this->R4, this->R5
            });
            this->Tabel->Cursor = System::Windows::Forms::Cursors::Cross;
            dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle8->BackColor = System::Drawing::Color::Beige;
            dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::DarkKhaki;
            dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->Tabel->DefaultCellStyle = dataGridViewCellStyle8;
            this->Tabel->GridColor = System::Drawing::Color::DarkKhaki;
            this->Tabel->Location = System::Drawing::Point(-6, 30);
            this->Tabel->Name = L"Tabel";
            this->Tabel->ReadOnly = true;
            this->Tabel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle9->BackColor = System::Drawing::SystemColors::Control;
            dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle9->SelectionBackColor = System::Drawing::SystemColors::Highlight;
            dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->Tabel->RowHeadersDefaultCellStyle = dataGridViewCellStyle9;
            this->Tabel->RowHeadersWidth = 51;
            this->Tabel->Size = System::Drawing::Size(763, 483);
            this->Tabel->TabIndex = 122;
            // 
            // Column
            // 
            this->Column->HeaderText = L" ";
            this->Column->MinimumWidth = 6;
            this->Column->Name = L"Column";
            this->Column->ReadOnly = true;
            // 
            // R0
            // 
            this->R0->HeaderText = L"شنبه";
            this->R0->MinimumWidth = 6;
            this->R0->Name = L"R0";
            this->R0->ReadOnly = true;
            // 
            // R1
            // 
            this->R1->HeaderText = L"یکشنبه";
            this->R1->MinimumWidth = 6;
            this->R1->Name = L"R1";
            this->R1->ReadOnly = true;
            // 
            // R2
            // 
            this->R2->HeaderText = L"دوشنبه";
            this->R2->MinimumWidth = 6;
            this->R2->Name = L"R2";
            this->R2->ReadOnly = true;
            // 
            // R3
            // 
            this->R3->HeaderText = L"سه شنبه";
            this->R3->MinimumWidth = 6;
            this->R3->Name = L"R3";
            this->R3->ReadOnly = true;
            // 
            // R4
            // 
            this->R4->HeaderText = L"چهارشنبه";
            this->R4->MinimumWidth = 6;
            this->R4->Name = L"R4";
            this->R4->ReadOnly = true;
            // 
            // R5
            // 
            this->R5->HeaderText = L"پنجشنبه";
            this->R5->MinimumWidth = 6;
            this->R5->Name = L"R5";
            this->R5->ReadOnly = true;
            // 
            // BTFoqBarname
            // 
            this->BTFoqBarname->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTFoqBarname->AutoEllipsis = true;
            this->BTFoqBarname->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTFoqBarname->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTFoqBarname->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->BTFoqBarname->ForeColor = System::Drawing::SystemColors::Info;
            this->BTFoqBarname->Location = System::Drawing::Point(222, 307);
            this->BTFoqBarname->Name = L"BTFoqBarname";
            this->BTFoqBarname->Size = System::Drawing::Size(254, 87);
            this->BTFoqBarname->TabIndex = 121;
            this->BTFoqBarname->Text = L"ایجاد درس فوق برنامه";
            this->BTFoqBarname->UseVisualStyleBackColor = false;
            this->BTFoqBarname->Click += gcnew System::EventHandler(this, &MainForm::BTFoqBarname_Click);
            // 
            // BTTanzinBarname
            // 
            this->BTTanzinBarname->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTTanzinBarname->AutoEllipsis = true;
            this->BTTanzinBarname->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTTanzinBarname->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTTanzinBarname->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->BTTanzinBarname->ForeColor = System::Drawing::SystemColors::Info;
            this->BTTanzinBarname->Location = System::Drawing::Point(222, 206);
            this->BTTanzinBarname->Name = L"BTTanzinBarname";
            this->BTTanzinBarname->Size = System::Drawing::Size(254, 87);
            this->BTTanzinBarname->TabIndex = 120;
            this->BTTanzinBarname->Text = L"تنظیم دستی   برنامه";
            this->BTTanzinBarname->UseVisualStyleBackColor = false;
            this->BTTanzinBarname->Click += gcnew System::EventHandler(this, &MainForm::BTTanzinBarname_Click);
            // 
            // BTBarnameDarsi
            // 
            this->BTBarnameDarsi->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTBarnameDarsi->AutoEllipsis = true;
            this->BTBarnameDarsi->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTBarnameDarsi->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBarnameDarsi->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->BTBarnameDarsi->ForeColor = System::Drawing::SystemColors::Info;
            this->BTBarnameDarsi->Location = System::Drawing::Point(222, 100);
            this->BTBarnameDarsi->Name = L"BTBarnameDarsi";
            this->BTBarnameDarsi->Size = System::Drawing::Size(254, 87);
            this->BTBarnameDarsi->TabIndex = 119;
            this->BTBarnameDarsi->Text = L"برنامه  درسی";
            this->BTBarnameDarsi->UseVisualStyleBackColor = false;
            this->BTBarnameDarsi->Click += gcnew System::EventHandler(this, &MainForm::BTBarnameDarsi_Click);
            // 
            // LAXmlFile
            // 
            this->LAXmlFile->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAXmlFile->AutoSize = true;
            this->LAXmlFile->BackColor = System::Drawing::Color::Aquamarine;
            this->LAXmlFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAXmlFile->ForeColor = System::Drawing::Color::DarkCyan;
            this->LAXmlFile->Location = System::Drawing::Point(134, 320);
            this->LAXmlFile->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->LAXmlFile->Name = L"LAXmlFile";
            this->LAXmlFile->Size = System::Drawing::Size(91, 20);
            this->LAXmlFile->TabIndex = 118;
            this->LAXmlFile->Text = L"(XML FILE)";
            // 
            // BTImportFile
            // 
            this->BTImportFile->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTImportFile->AutoEllipsis = true;
            this->BTImportFile->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTImportFile->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->BTImportFile->ForeColor = System::Drawing::Color::DarkCyan;
            this->BTImportFile->Location = System::Drawing::Point(131, 198);
            this->BTImportFile->Name = L"BTImportFile";
            this->BTImportFile->Size = System::Drawing::Size(415, 86);
            this->BTImportFile->TabIndex = 117;
            this->BTImportFile->Text = L"برای وارد کردن فایل اطلاعات کلیک کنید";
            this->BTImportFile->UseVisualStyleBackColor = false;
            this->BTImportFile->Click += gcnew System::EventHandler(this, &MainForm::BTImportFile_Click);
            // 
            // LAErorIm
            // 
            this->LAErorIm->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAErorIm->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAErorIm->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->LAErorIm->ImeMode = System::Windows::Forms::ImeMode::NoControl;
            this->LAErorIm->Location = System::Drawing::Point(-81, 296);
            this->LAErorIm->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAErorIm->Name = L"LAErorIm";
            this->LAErorIm->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LAErorIm->Size = System::Drawing::Size(639, 98);
            this->LAErorIm->TabIndex = 173;
            this->LAErorIm->Text = L"ارور";
            this->LAErorIm->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // BTAuto
            // 
            this->BTAuto->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->BTAuto->AutoEllipsis = true;
            this->BTAuto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->BTAuto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTAuto->Font = (gcnew System::Drawing::Font(L"B Nazanin", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTAuto->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->BTAuto->Location = System::Drawing::Point(335, -3);
            this->BTAuto->Margin = System::Windows::Forms::Padding(1);
            this->BTAuto->Name = L"BTAuto";
            this->BTAuto->Size = System::Drawing::Size(383, 33);
            this->BTAuto->TabIndex = 1;
            this->BTAuto->TabStop = false;
            this->BTAuto->Text = L"تنظیم خودکار";
            this->BTAuto->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
            this->BTAuto->UseVisualStyleBackColor = false;
            this->BTAuto->Click += gcnew System::EventHandler(this, &MainForm::BTAuto_Click);
            // 
            // BTSave
            // 
            this->BTSave->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->BTSave->AutoEllipsis = true;
            this->BTSave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->BTSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTSave->Font = (gcnew System::Drawing::Font(L"B Nazanin", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTSave->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->BTSave->Location = System::Drawing::Point(-6, -3);
            this->BTSave->Margin = System::Windows::Forms::Padding(1);
            this->BTSave->Name = L"BTSave";
            this->BTSave->Size = System::Drawing::Size(354, 33);
            this->BTSave->TabIndex = 2;
            this->BTSave->TabStop = false;
            this->BTSave->Text = L"ذخیره اطلاعات";
            this->BTSave->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
            this->BTSave->UseVisualStyleBackColor = false;
            this->BTSave->Click += gcnew System::EventHandler(this, &MainForm::BTSave_Click);
            // 
            // BTBazgashtTable
            // 
            this->BTBazgashtTable->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->BTBazgashtTable->AutoEllipsis = true;
            this->BTBazgashtTable->BackColor = System::Drawing::Color::Gainsboro;
            this->BTBazgashtTable->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBazgashtTable->Font = (gcnew System::Drawing::Font(L"B Nazanin", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTBazgashtTable->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->BTBazgashtTable->Location = System::Drawing::Point(606, 34);
            this->BTBazgashtTable->Margin = System::Windows::Forms::Padding(1);
            this->BTBazgashtTable->Name = L"BTBazgashtTable";
            this->BTBazgashtTable->Size = System::Drawing::Size(97, 31);
            this->BTBazgashtTable->TabIndex = 3;
            this->BTBazgashtTable->TabStop = false;
            this->BTBazgashtTable->Text = L"بازگشت";
            this->BTBazgashtTable->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
            this->BTBazgashtTable->UseVisualStyleBackColor = false;
            this->BTBazgashtTable->Click += gcnew System::EventHandler(this, &MainForm::BTBazgashtTable_Click);
            // 
            // BTBishtarImTable
            // 
            this->BTBishtarImTable->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->BTBishtarImTable->AutoEllipsis = true;
            this->BTBishtarImTable->BackColor = System::Drawing::Color::Gainsboro;
            this->BTBishtarImTable->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBishtarImTable->Font = (gcnew System::Drawing::Font(L"B Nazanin", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTBishtarImTable->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->BTBishtarImTable->Location = System::Drawing::Point(606, 67);
            this->BTBishtarImTable->Margin = System::Windows::Forms::Padding(1);
            this->BTBishtarImTable->Name = L"BTBishtarImTable";
            this->BTBishtarImTable->Size = System::Drawing::Size(97, 31);
            this->BTBishtarImTable->TabIndex = 4;
            this->BTBishtarImTable->TabStop = false;
            this->BTBishtarImTable->Text = L"...بیشتر";
            this->BTBishtarImTable->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
            this->BTBishtarImTable->UseVisualStyleBackColor = false;
            this->BTBishtarImTable->Click += gcnew System::EventHandler(this, &MainForm::BTBishtarImTable_Click);
            // 
            // LATanzimLessonInfo
            // 
            this->LATanzimLessonInfo->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LATanzimLessonInfo->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->LATanzimLessonInfo->Location = System::Drawing::Point(-1, 89);
            this->LATanzimLessonInfo->Name = L"LATanzimLessonInfo";
            this->LATanzimLessonInfo->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LATanzimLessonInfo->Size = System::Drawing::Size(173, 48);
            this->LATanzimLessonInfo->TabIndex = 179;
            this->LATanzimLessonInfo->Text = L" ";
            // 
            // LATanzimClassInfo
            // 
            this->LATanzimClassInfo->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LATanzimClassInfo->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->LATanzimClassInfo->Location = System::Drawing::Point(-1, 198);
            this->LATanzimClassInfo->Name = L"LATanzimClassInfo";
            this->LATanzimClassInfo->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LATanzimClassInfo->Size = System::Drawing::Size(173, 48);
            this->LATanzimClassInfo->TabIndex = 180;
            this->LATanzimClassInfo->Text = L" ";
            // 
            // BTBazgasht
            // 
            this->BTBazgasht->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTBazgasht->AutoEllipsis = true;
            this->BTBazgasht->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTBazgasht->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBazgasht->Font = (gcnew System::Drawing::Font(L"B Nazanin", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTBazgasht->ForeColor = System::Drawing::SystemColors::Info;
            this->BTBazgasht->Location = System::Drawing::Point(193, 410);
            this->BTBazgasht->Name = L"BTBazgasht";
            this->BTBazgasht->Size = System::Drawing::Size(206, 35);
            this->BTBazgasht->TabIndex = 181;
            this->BTBazgasht->Text = L"بازگشت";
            this->BTBazgasht->UseVisualStyleBackColor = false;
            this->BTBazgasht->Click += gcnew System::EventHandler(this, &MainForm::BTBazgasht_Click);
            // 
            // BTBazgashtFog
            // 
            this->BTBazgashtFog->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTBazgashtFog->AutoEllipsis = true;
            this->BTBazgashtFog->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTBazgashtFog->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBazgashtFog->Font = (gcnew System::Drawing::Font(L"B Nazanin", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTBazgashtFog->ForeColor = System::Drawing::SystemColors::Info;
            this->BTBazgashtFog->Location = System::Drawing::Point(174, 410);
            this->BTBazgashtFog->Name = L"BTBazgashtFog";
            this->BTBazgashtFog->Size = System::Drawing::Size(204, 35);
            this->BTBazgashtFog->TabIndex = 5;
            this->BTBazgashtFog->Text = L"بازگشت";
            this->BTBazgashtFog->UseVisualStyleBackColor = false;
            this->BTBazgashtFog->Click += gcnew System::EventHandler(this, &MainForm::BTBazgashtFog_Click);
            // 
            // LAErorFoq2
            // 
            this->LAErorFoq2->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAErorFoq2->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAErorFoq2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->LAErorFoq2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
            this->LAErorFoq2->Location = System::Drawing::Point(-1, 341);
            this->LAErorFoq2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAErorFoq2->Name = L"LAErorFoq2";
            this->LAErorFoq2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LAErorFoq2->Size = System::Drawing::Size(639, 79);
            this->LAErorFoq2->TabIndex = 183;
            this->LAErorFoq2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // BTBazgasht2Foq
            // 
            this->BTBazgasht2Foq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTBazgasht2Foq->AutoEllipsis = true;
            this->BTBazgasht2Foq->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTBazgasht2Foq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBazgasht2Foq->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTBazgasht2Foq->ForeColor = System::Drawing::SystemColors::Info;
            this->BTBazgasht2Foq->Location = System::Drawing::Point(175, 438);
            this->BTBazgasht2Foq->Name = L"BTBazgasht2Foq";
            this->BTBazgasht2Foq->Size = System::Drawing::Size(217, 35);
            this->BTBazgasht2Foq->TabIndex = 184;
            this->BTBazgasht2Foq->Text = L"بازگشت";
            this->BTBazgasht2Foq->UseVisualStyleBackColor = false;
            this->BTBazgasht2Foq->Click += gcnew System::EventHandler(this, &MainForm::BTBazgasht2Foq_Click);
            // 
            // LAErorFoq3
            // 
            this->LAErorFoq3->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAErorFoq3->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAErorFoq3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->LAErorFoq3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
            this->LAErorFoq3->Location = System::Drawing::Point(-1, 341);
            this->LAErorFoq3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAErorFoq3->Name = L"LAErorFoq3";
            this->LAErorFoq3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LAErorFoq3->Size = System::Drawing::Size(662, 79);
            this->LAErorFoq3->TabIndex = 185;
            this->LAErorFoq3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // BTBazgasht3Foq
            // 
            this->BTBazgasht3Foq->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTBazgasht3Foq->AutoEllipsis = true;
            this->BTBazgasht3Foq->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTBazgasht3Foq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBazgasht3Foq->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTBazgasht3Foq->ForeColor = System::Drawing::SystemColors::Info;
            this->BTBazgasht3Foq->Location = System::Drawing::Point(183, 438);
            this->BTBazgasht3Foq->Name = L"BTBazgasht3Foq";
            this->BTBazgasht3Foq->Size = System::Drawing::Size(160, 35);
            this->BTBazgasht3Foq->TabIndex = 186;
            this->BTBazgasht3Foq->Text = L"بازگشت";
            this->BTBazgasht3Foq->UseVisualStyleBackColor = false;
            this->BTBazgasht3Foq->Click += gcnew System::EventHandler(this, &MainForm::BTBazgasht3Foq_Click);
            // 
            // TimeEror
            // 
            this->TimeEror->Tick += gcnew System::EventHandler(this, &MainForm::TimeEror_Tick);
            // 
            // LAWeekCycle
            // 
            this->LAWeekCycle->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->LAWeekCycle->BackColor = System::Drawing::Color::Goldenrod;
            this->LAWeekCycle->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->LAWeekCycle->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAWeekCycle->ForeColor = System::Drawing::Color::LightGoldenrodYellow;
            this->LAWeekCycle->Location = System::Drawing::Point(319, -17);
            this->LAWeekCycle->Name = L"LAWeekCycle";
            this->LAWeekCycle->Size = System::Drawing::Size(48, 46);
            this->LAWeekCycle->TabIndex = 187;
            this->LAWeekCycle->Text = L"۱";
            this->LAWeekCycle->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // BTNext
            // 
            this->BTNext->AutoEllipsis = true;
            this->BTNext->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->BTNext->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTNext->Font = (gcnew System::Drawing::Font(L"B Nazanin", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTNext->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->BTNext->Location = System::Drawing::Point(-1, -3);
            this->BTNext->Margin = System::Windows::Forms::Padding(1);
            this->BTNext->Name = L"BTNext";
            this->BTNext->Size = System::Drawing::Size(29, 33);
            this->BTNext->TabIndex = 6;
            this->BTNext->TabStop = false;
            this->BTNext->Text = L"◀";
            this->BTNext->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
            this->BTNext->UseVisualStyleBackColor = false;
            this->BTNext->Click += gcnew System::EventHandler(this, &MainForm::BTNext_Click);
            // 
            // BTBack
            // 
            this->BTBack->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->BTBack->AutoEllipsis = true;
            this->BTBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->BTBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBack->Font = (gcnew System::Drawing::Font(L"B Nazanin", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTBack->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->BTBack->Location = System::Drawing::Point(674, -3);
            this->BTBack->Margin = System::Windows::Forms::Padding(1);
            this->BTBack->Name = L"BTBack";
            this->BTBack->Size = System::Drawing::Size(29, 33);
            this->BTBack->TabIndex = 5;
            this->BTBack->TabStop = false;
            this->BTBack->Text = L"▶";
            this->BTBack->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
            this->BTBack->UseVisualStyleBackColor = false;
            this->BTBack->Click += gcnew System::EventHandler(this, &MainForm::BTBack_Click);
            // 
            // BTDengerFill
            // 
            this->BTDengerFill->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTDengerFill->AutoEllipsis = true;
            this->BTDengerFill->BackColor = System::Drawing::Color::OrangeRed;
            this->BTDengerFill->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTDengerFill->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTDengerFill->ForeColor = System::Drawing::SystemColors::Info;
            this->BTDengerFill->Location = System::Drawing::Point(526, 438);
            this->BTDengerFill->Name = L"BTDengerFill";
            this->BTDengerFill->Size = System::Drawing::Size(160, 35);
            this->BTDengerFill->TabIndex = 188;
            this->BTDengerFill->Text = L"در هر صورت ادامه  بده";
            this->BTDengerFill->UseVisualStyleBackColor = false;
            this->BTDengerFill->Click += gcnew System::EventHandler(this, &MainForm::BTDengerFill_Click_1);
            // 
            // BTBazgashtList
            // 
            this->BTBazgashtList->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTBazgashtList->AutoEllipsis = true;
            this->BTBazgashtList->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTBazgashtList->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBazgashtList->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTBazgashtList->ForeColor = System::Drawing::SystemColors::Info;
            this->BTBazgashtList->Location = System::Drawing::Point(116, 415);
            this->BTBazgashtList->Margin = System::Windows::Forms::Padding(4);
            this->BTBazgashtList->Name = L"BTBazgashtList";
            this->BTBazgashtList->Size = System::Drawing::Size(96, 43);
            this->BTBazgashtList->TabIndex = 193;
            this->BTBazgashtList->Text = L"بازگشت";
            this->BTBazgashtList->UseVisualStyleBackColor = false;
            this->BTBazgashtList->Click += gcnew System::EventHandler(this, &MainForm::BTBazgashtList_Click);
            // 
            // LITeacherList
            // 
            this->LITeacherList->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LITeacherList->BackColor = System::Drawing::Color::Aquamarine;
            this->LITeacherList->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->LITeacherList->Font = (gcnew System::Drawing::Font(L"B Nazanin", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->LITeacherList->FormattingEnabled = true;
            this->LITeacherList->ItemHeight = 35;
            this->LITeacherList->Location = System::Drawing::Point(116, 132);
            this->LITeacherList->Name = L"LITeacherList";
            this->LITeacherList->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LITeacherList->Size = System::Drawing::Size(197, 210);
            this->LITeacherList->TabIndex = 192;
            // 
            // LATeacherList
            // 
            this->LATeacherList->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LATeacherList->AutoSize = true;
            this->LATeacherList->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LATeacherList->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LATeacherList->Location = System::Drawing::Point(228, 27);
            this->LATeacherList->Name = L"LATeacherList";
            this->LATeacherList->Size = System::Drawing::Size(103, 92);
            this->LATeacherList->TabIndex = 191;
            this->LATeacherList->Text = L" :  اساتید";
            // 
            // LIStudentList
            // 
            this->LIStudentList->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LIStudentList->BackColor = System::Drawing::Color::Aquamarine;
            this->LIStudentList->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->LIStudentList->Font = (gcnew System::Drawing::Font(L"B Nazanin", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->LIStudentList->FormattingEnabled = true;
            this->LIStudentList->ItemHeight = 35;
            this->LIStudentList->Location = System::Drawing::Point(372, 132);
            this->LIStudentList->Name = L"LIStudentList";
            this->LIStudentList->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LIStudentList->Size = System::Drawing::Size(277, 210);
            this->LIStudentList->TabIndex = 190;
            // 
            // LAStudentList
            // 
            this->LAStudentList->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAStudentList->AutoSize = true;
            this->LAStudentList->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAStudentList->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAStudentList->Location = System::Drawing::Point(530, 27);
            this->LAStudentList->Name = L"LAStudentList";
            this->LAStudentList->Size = System::Drawing::Size(136, 92);
            this->LAStudentList->TabIndex = 189;
            this->LAStudentList->Text = L" :   دانشجویان   ";
            // 
            // LAHeder
            // 
            this->LAHeder->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->LAHeder->Dock = System::Windows::Forms::DockStyle::Top;
            this->LAHeder->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAHeder->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->LAHeder->Location = System::Drawing::Point(0, 0);
            this->LAHeder->Name = L"LAHeder";
            this->LAHeder->Size = System::Drawing::Size(704, 39);
            this->LAHeder->TabIndex = 194;
            this->LAHeder->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // BTExit
            // 
            this->BTExit->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTExit->AutoEllipsis = true;
            this->BTExit->BackColor = System::Drawing::Color::Aquamarine;
            this->BTExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTExit->Font = (gcnew System::Drawing::Font(L"Impact", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTExit->ForeColor = System::Drawing::SystemColors::Info;
            this->BTExit->Location = System::Drawing::Point(354, 480);
            this->BTExit->Margin = System::Windows::Forms::Padding(4);
            this->BTExit->Name = L"BTExit";
            this->BTExit->Size = System::Drawing::Size(122, 25);
            this->BTExit->TabIndex = 198;
            this->BTExit->Text = L"خروج";
            this->BTExit->UseVisualStyleBackColor = false;
            this->BTExit->Click += gcnew System::EventHandler(this, &MainForm::BTExit_Click);
            // 
            // BTNewIm
            // 
            this->BTNewIm->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTNewIm->AutoEllipsis = true;
            this->BTNewIm->BackColor = System::Drawing::Color::Aquamarine;
            this->BTNewIm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTNewIm->Font = (gcnew System::Drawing::Font(L"Impact", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTNewIm->ForeColor = System::Drawing::SystemColors::Info;
            this->BTNewIm->Location = System::Drawing::Point(222, 480);
            this->BTNewIm->Margin = System::Windows::Forms::Padding(4);
            this->BTNewIm->Name = L"BTNewIm";
            this->BTNewIm->Size = System::Drawing::Size(118, 25);
            this->BTNewIm->TabIndex = 197;
            this->BTNewIm->Text = L"فایل جدید";
            this->BTNewIm->UseVisualStyleBackColor = false;
            this->BTNewIm->Click += gcnew System::EventHandler(this, &MainForm::BTNewIm_Click);
            // 
            // TimeLogo
            // 
            this->TimeLogo->Interval = 20;
            this->TimeLogo->Tick += gcnew System::EventHandler(this, &MainForm::TimeLogo_Tick);
            // 
            // PAFileErorr
            // 
            this->PAFileErorr->Controls->Add(this->LAErorrFile);
            this->PAFileErorr->Controls->Add(this->BTNewFile2);
            this->PAFileErorr->Controls->Add(this->BTDenger2);
            this->PAFileErorr->Location = System::Drawing::Point(-6, 89);
            this->PAFileErorr->Name = L"PAFileErorr";
            this->PAFileErorr->Size = System::Drawing::Size(710, 319);
            this->PAFileErorr->TabIndex = 199;
            // 
            // LAErorrFile
            // 
            this->LAErorrFile->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LAErorrFile->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAErorrFile->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->LAErorrFile->ImeMode = System::Windows::Forms::ImeMode::NoControl;
            this->LAErorrFile->Location = System::Drawing::Point(72, 55);
            this->LAErorrFile->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAErorrFile->Name = L"LAErorrFile";
            this->LAErorrFile->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LAErorrFile->Size = System::Drawing::Size(553, 89);
            this->LAErorrFile->TabIndex = 195;
            this->LAErorrFile->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // BTNewFile2
            // 
            this->BTNewFile2->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTNewFile2->AutoEllipsis = true;
            this->BTNewFile2->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTNewFile2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTNewFile2->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTNewFile2->ForeColor = System::Drawing::SystemColors::Info;
            this->BTNewFile2->Location = System::Drawing::Point(144, 192);
            this->BTNewFile2->Margin = System::Windows::Forms::Padding(4);
            this->BTNewFile2->Name = L"BTNewFile2";
            this->BTNewFile2->Size = System::Drawing::Size(219, 35);
            this->BTNewFile2->TabIndex = 194;
            this->BTNewFile2->Text = L"فایل جدید";
            this->BTNewFile2->UseVisualStyleBackColor = false;
            this->BTNewFile2->Click += gcnew System::EventHandler(this, &MainForm::BTNewFile2_Click);
            // 
            // BTDenger2
            // 
            this->BTDenger2->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->BTDenger2->AutoEllipsis = true;
            this->BTDenger2->BackColor = System::Drawing::Color::OrangeRed;
            this->BTDenger2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTDenger2->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTDenger2->ForeColor = System::Drawing::SystemColors::Info;
            this->BTDenger2->Location = System::Drawing::Point(378, 192);
            this->BTDenger2->Name = L"BTDenger2";
            this->BTDenger2->Size = System::Drawing::Size(222, 35);
            this->BTDenger2->TabIndex = 189;
            this->BTDenger2->Text = L"در هر صورت ادامه  بده";
            this->BTDenger2->UseVisualStyleBackColor = false;
            this->BTDenger2->Click += gcnew System::EventHandler(this, &MainForm::BTDenger2_Click);
            // 
            // PALogo
            // 
            this->PALogo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(192)));
            this->PALogo->Controls->Add(this->LOGO);
            this->PALogo->Location = System::Drawing::Point(-1, 0);
            this->PALogo->Name = L"PALogo";
            this->PALogo->Size = System::Drawing::Size(705, 513);
            this->PALogo->TabIndex = 197;
            // 
            // LOGO
            // 
            this->LOGO->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LOGO.BackgroundImage")));
            this->LOGO->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->LOGO->Controls->Add(this->LALogoKaver);
            this->LOGO->Location = System::Drawing::Point(143, 50);
            this->LOGO->Name = L"LOGO";
            this->LOGO->Size = System::Drawing::Size(382, 423);
            this->LOGO->TabIndex = 0;
            // 
            // LALogoKaver
            // 
            this->LALogoKaver->Location = System::Drawing::Point(-14, 8);
            this->LALogoKaver->Name = L"LALogoKaver";
            this->LALogoKaver->Size = System::Drawing::Size(438, 394);
            this->LALogoKaver->TabIndex = 0;
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Aquamarine;
            this->ClientSize = System::Drawing::Size(704, 512);
            this->Controls->Add(this->PALogo);
            this->Controls->Add(this->PAFileErorr);
            this->Controls->Add(this->BTNewIm);
            this->Controls->Add(this->BTExit);
            this->Controls->Add(this->LAHeder);
            this->Controls->Add(this->BTBazgashtList);
            this->Controls->Add(this->LITeacherList);
            this->Controls->Add(this->LATeacherList);
            this->Controls->Add(this->LIStudentList);
            this->Controls->Add(this->LAStudentList);
            this->Controls->Add(this->BTDengerFill);
            this->Controls->Add(this->BTBack);
            this->Controls->Add(this->BTNext);
            this->Controls->Add(this->LAWeekCycle);
            this->Controls->Add(this->BTBazgasht3Foq);
            this->Controls->Add(this->LAErorFoq3);
            this->Controls->Add(this->BTBazgasht2Foq);
            this->Controls->Add(this->LAErorFoq2);
            this->Controls->Add(this->BTBazgashtFog);
            this->Controls->Add(this->BTBazgasht);
            this->Controls->Add(this->LATanzimClassInfo);
            this->Controls->Add(this->LATanzimLessonInfo);
            this->Controls->Add(this->BTBishtarImTable);
            this->Controls->Add(this->BTBazgashtTable);
            this->Controls->Add(this->BTSave);
            this->Controls->Add(this->BTAuto);
            this->Controls->Add(this->LAErorIm);
            this->Controls->Add(this->TXWeekDayFoq);
            this->Controls->Add(this->LAWeekDayFoq);
            this->Controls->Add(this->TXStNumFoq);
            this->Controls->Add(this->TXStNameFoq);
            this->Controls->Add(this->BTAfzodanFoq);
            this->Controls->Add(this->PAStNumFoq);
            this->Controls->Add(this->PAStNameFoq);
            this->Controls->Add(this->BTTaiid3Foq);
            this->Controls->Add(this->LAStNumFoq);
            this->Controls->Add(this->LAStNameFoq);
            this->Controls->Add(this->LADaneshjoFoq);
            this->Controls->Add(this->BTTaiid2Foq);
            this->Controls->Add(this->VAJalaseFoq);
            this->Controls->Add(this->LAJalaseFoq);
            this->Controls->Add(this->VAM1Foq);
            this->Controls->Add(this->VAH1Foq);
            this->Controls->Add(this->LAM1Foq);
            this->Controls->Add(this->LAH1Foq);
            this->Controls->Add(this->LATimeToolFoq);
            this->Controls->Add(this->VAMFoq);
            this->Controls->Add(this->VAHFoq);
            this->Controls->Add(this->VARozFoq);
            this->Controls->Add(this->VAMahFoq);
            this->Controls->Add(this->LAMFoq);
            this->Controls->Add(this->LAHFoq);
            this->Controls->Add(this->LATimeFoq);
            this->Controls->Add(this->LARozFoq);
            this->Controls->Add(this->LAMahFoq);
            this->Controls->Add(this->LADateFoq);
            this->Controls->Add(this->LAErorFoq);
            this->Controls->Add(this->BOVideoProjectorFoq);
            this->Controls->Add(this->TXLessonNameFoq);
            this->Controls->Add(this->TXLessonIDFoq);
            this->Controls->Add(this->LALessonNameFoq);
            this->Controls->Add(this->PALessonNameFoq);
            this->Controls->Add(this->LALessonIDFoq);
            this->Controls->Add(this->PALessonIDFoq);
            this->Controls->Add(this->TXTeacherNameFoq);
            this->Controls->Add(this->BTTaiid1Foq);
            this->Controls->Add(this->LATeacherNameFoq);
            this->Controls->Add(this->PATeacherNameFoq);
            this->Controls->Add(this->TXClassID);
            this->Controls->Add(this->TXLessonID);
            this->Controls->Add(this->LAEror);
            this->Controls->Add(this->BTTaiid);
            this->Controls->Add(this->LACassID);
            this->Controls->Add(this->PAClassID);
            this->Controls->Add(this->LALessonID);
            this->Controls->Add(this->PALessonID);
            this->Controls->Add(this->Tabel);
            this->Controls->Add(this->BTFoqBarname);
            this->Controls->Add(this->BTTanzinBarname);
            this->Controls->Add(this->BTBarnameDarsi);
            this->Controls->Add(this->LAXmlFile);
            this->Controls->Add(this->BTImportFile);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"MainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"MainForm";
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAJalaseFoq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAM1Foq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAH1Foq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAMFoq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAHFoq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VARozFoq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAMahFoq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabel))->EndInit();
            this->PAFileErorr->ResumeLayout(false);
            this->PALogo->ResumeLayout(false);
            this->LOGO->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion


	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
    private: System::Void BTImportFile_Click(System::Object^ sender, System::EventArgs^ e) {

        //MessageBox::Show(StringConvert(to_string(isintiger("55123"))));

        
        LAErorIm->Hide();
        lessons.clear();
        classes.clear();
        SumLess.clear();

        LAErorIm->Text = "";

        if (XmlAdres->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

        	String^ FilePath = XmlAdres->FileName;

        	ReadFileLessons(lessons,students, teachers, StringConvert(FilePath));
        	ReadFileClasses(classes, StringConvert(FilePath));


        	if (classes.size() == 0 || lessons.size() == 0) 
            {
                LAErorIm->Text = L"فایل معتبر نیست، لطفا فایل با چهارچوب معتبر انتخاب کنید!"; LAErorIm->Show(); return;
            }
        	else
        	{   
                vector <Lessons> lesstest = lessons;
                vector <Classes> clatest = classes;
                SortClases(clatest);
                SortLessons(lesstest);
                AutoSetLocation_ByWDay(lesstest, clatest);

                for (auto less : lesstest) {
                    
                    if (less.getClassLocation() == 0) {
                        
                        PAFileErorr->Show();
                       
                        LAErorrFile->Text = L" طبق داده های شما کلاس  کافی برای برگزاری همه دورس وجود ندارد! ";
                        return;
                    }
                }


                SortLessons(lessons);
                SortClases(classes);
        		HideImportPage();
        		ShowMeno();


                SetTable_ClassName();


                for (size_t n = 0; n < lessons.size(); n++)
                    SaveStartDate.push_back(lessons.at(n).getData());
                


        	}

        }
    }
private: System::Void BTBarnameDarsi_Click(System::Object^ sender, System::EventArgs^ e) {
    
   
    HideMeno();
    ShowTable();

}



private: int Auto_Set = 0;
private: bool AutoSet = false;


private: System::Void BTAuto_Click(System::Object^ sender, System::EventArgs^ e) {
   
    Auto_Set++;

    if (Auto_Set % 2)
        AutoSet = true;
    else
        AutoSet = false;

    if (!AutoSet) { EmptyTable(); EmptyClassLocation(lessons); return; }
    //MessageBox::Show(StringConvert(to_string(lessons.at(0).getData().WeekDay) + " :  " + to_string(lessons.at(0).getData().Month) + " / " + to_string(lessons.at(0).getData().Day)));

    if (extraclass.size() == 0) {
        AutoSetLocation_ByWDay(lessons, classes);
        SetTable(lessons, classes, Week_Cycle, false);
      
    }
    else {

            vector <Lessons> SplitEX = ToSplitExtraClass(extraclass);
            vector <Lessons> SumLess = lessons;

            for (Lessons Sp : SplitEX)
                SumLess.push_back(Sp);


            SortLessons(SumLess);
            AutoSetLocation_ByData_WDay(SumLess,classes);
//
//for each (auto var in SumLess)
//            {
//                MessageBox::Show(StringConvert(to_string(var.getClassLocation()) + " :  " + to_string(var.getData().Month) + " / " + to_string(var.getData().Day)));
//
//            }
            vector <Lessons> SplitEX2;

            for (Lessons sum : SumLess) {
                if (sum.getFoq())
                    SplitEX2.push_back(sum);
            }

            
            for (Lessons sum : SumLess) {
                for (size_t n = 0; n< lessons.size(); n++) {
                    if (sum.getID() == lessons.at(n).getID()) 
                        lessons.at(n).setClassLocation(sum.getClassLocation());
                       
                }
            }

            Golestan::SplitEX = SplitEX2;
            Golestan::SumLess = SumLess;

            EmptyTable();
           
            SetTable(lessons,SplitEX2, classes, Week_Cycle, false);
           
        }

}





private: System::Void BTBazgashtTable_Click(System::Object^ sender, System::EventArgs^ e) {
    LAErorFoq->Text = "";
    LAErorFoq2->Text = "";
    LAErorFoq3->Text = "";
    LAEror->Text = "";
    LAErorIm->Text = "";
    HideTable();
    ShowMeno();
}
private: System::Void BTTanzinBarname_Click(System::Object^ sender, System::EventArgs^ e) {

    HideMeno();
    ShowTanzimBarname();
}

       private: bool Bles = false, Bcla = false;


private: System::Void TXClassID_TextChanged(System::Object^ sender, System::EventArgs^ e) {

    
    if (StringConvert(TXLessonID->Text).size() > 1 && StringConvert(TXClassID->Text).size() > 1) LAEror->Text = "";
   
    if(!isintiger(StringConvert(TXClassID->Text))) { LAEror->Text = L"لطفا در فیلد کلاس تنها رقم شماره کلاس را وارد کنید."; return; }
    else
        LAEror->Text = "";

    if (StringConvert(TXClassID->Text).size()>1) {

        Bcla = false;

        for (size_t n = 0;n < classes.size();n++) {
            if (stoi(StringConvert(TXClassID->Text)) == classes.at(n).getID()) {
                Bcla = true;
                if (classes.at(n).getVideoProjector())
                    LATanzimClassInfo->Text = L"🎦  (ظرفیت : " + NumPerConvert(classes.at(n).getCapacity()) + " )";
                else
                    LATanzimClassInfo->Text = L" (ظرفیت : " + NumPerConvert(classes.at(n).getCapacity()) + " )";

                break;
            }
            else
                LATanzimClassInfo->Text = "";
        }
    }
    else
        LATanzimClassInfo->Text = "";
}




private: System::Void TXLessonID_TextChanged(System::Object^ sender, System::EventArgs^ e) {

    if (TXLessonID->Text != "" && TXClassID->Text != "") LAEror->Text = "";

    if (StringConvert(TXLessonID->Text).size() > 1) {

        Bles = false;

        if (extraclass.size()) {


            for(auto less : SumLess) {
                if (TXLessonID->Text == StringConvert(less.getID())) {

                    Bles = true;

                    String^ Name = "";

                    if (less.getFoq())
                        Name = less.getName_S();
                    else
                        Name = UTF8Convert(less.getName());

                    if (less.getVideoProjector())
                        LATanzimLessonInfo->Text = L"🎦  " + Name + L" (دانشجویان : " + NumPerConvert(less.getStudents().size()) + ")";

                    else
                        LATanzimLessonInfo->Text = Name + L" (دانشجویان : " + NumPerConvert(less.getStudents().size()) + ")";


                    break;
                }
                else
                    LATanzimLessonInfo->Text = "";
            }


        }


        else {

            for each (auto less in lessons) {
                if (TXLessonID->Text == StringConvert(less.getID())) {

                    Bles = true;

                    if (less.getVideoProjector())
                        LATanzimLessonInfo->Text = L"🎦  " + UTF8Convert(less.getName()) + L" (دانشجویان : " + NumPerConvert(less.getStudents().size()) + ")";

                    else
                        LATanzimLessonInfo->Text = UTF8Convert(less.getName()) + L" (دانشجویان : " + NumPerConvert(less.getStudents().size()) + ")";


                    break;
                }
                else
                    LATanzimLessonInfo->Text = "";
            }
        }
    }
    else
        LATanzimLessonInfo->Text = "";
    
}








private: System::Void BTTaiid_Click(System::Object^ sender, System::EventArgs^ e) {
    LAEror->Text = "";


    if (TXClassID->Text == "" || TXLessonID->Text == "") { LAEror->Text = L"لطفا فیلد ها را پر کنید !"; return; }

    if (!Bles)
    {
        LAEror->Text = L"درس مورد نظر یافت نشد !"; return;
    }
    else if (!Bcla)
    {
        LAEror->Text = L"کلاس مورد نظر یافت نشد !"; return;
    }


    if (extraclass.size()) {


        if (FindLesson(TXLessonID->Text,SumLess).OverCapacity(FindClass(TXClassID->Text)))
        {
            LAEror->Text = L"ظرفیت کلاس کافی نیست !"; return;
        }

        if (FindLesson(TXLessonID->Text,SumLess).getVideoProjector() && !FindClass(TXClassID->Text).getVideoProjector())
        {
            LAEror->Text = L"این درس نیاز به ویدیوپرژکتور دارد !"; return;
        }


        if (FindLesson(TXLessonID->Text, SumLess).getFoq()) {

            for (auto sp : ToSplitExtraClass(FindLesson(TXLessonID->Text, extraclass))) {
                if (CheckTimeInterference(sp, FindClass(TXClassID->Text),SumLess))
                {
                    LAEror->Text = L"تداخل ساعات دروس در کلاس وجود دارد  !"; return;

                }
            }
        }
        else
        {
            if (CheckTimeInterference(FindLesson(TXLessonID->Text, SumLess), FindClass(TXClassID->Text)) )
            {
                LAEror->Text = L"تداخل ساعات دروس در کلاس وجود دارد  !"; return;

            }
        }


        SumLess.at(FindLessonIndex(TXLessonID->Text, SumLess)).setClassLocation(FindClass(TXClassID->Text));


        if (FindLesson(TXLessonID->Text, SumLess).getFoq()) {
            for (size_t n = 0; n < SumLess.size(); n++) {

                if(SumLess.at(n).getID() == StringConvert(TXLessonID->Text))
                    SumLess.at(n).setClassLocation(FindClass(TXClassID->Text));
            }
        }



        { vector <Lessons> SplitEX2;

        for (Lessons sum : SumLess) {
            if (sum.getFoq())
                SplitEX2.push_back(sum);
        }


        for (Lessons sum : SumLess) {
            for (size_t n = 0; n < lessons.size(); n++) {
                if (sum.getID() == lessons.at(n).getID())
                    lessons.at(n).setClassLocation(sum.getClassLocation());

            }
        }
        Golestan::SplitEX = SplitEX2;
        EmptyTable();

        SetTable(lessons, SplitEX2, classes, Week_Cycle, false); }
       
    }


    else {



    if(FindLesson(TXLessonID->Text).OverCapacity( FindClass(TXClassID->Text)))
    {
        LAEror->Text = L"ظرفیت کلاس کافی نیست !"; return;
    }

    if(FindLesson(TXLessonID->Text).getVideoProjector()&&!FindClass(TXClassID->Text).getVideoProjector())
    {
        LAEror->Text = L"این درس نیاز به ویدیوپرژکتور دارد !"; return;
    }

    if(CheckTimeInterference(FindLesson(TXLessonID->Text), FindClass(TXClassID->Text)))
    {
        LAEror->Text = L"تداخل ساعات دروس در کلاس وجود دارد  !"; return;

    }

  
        lessons.at(FindLessonIndex(TXLessonID->Text)).setClassLocation(FindClass(TXClassID->Text));
        SetTable(lessons, classes, Week_Cycle, true);
    }

    HideTanzimBarname();
    ShowMeno();

}




private: System::Void BTBazgasht_Click(System::Object^ sender, System::EventArgs^ e) {

    LAErorFoq->Text = "";
    LAErorFoq2->Text = "";
    LAErorFoq3->Text = "";
    LAEror->Text = "";
    LAErorIm->Text = "";
    //for (auto x : lessons)
    //    MessageBox::Show(UTF8Convert(x.getName())+" : "+StringConvert(to_string(x.getClassLocation())));

    HideTanzimBarname();
    ShowMeno();
}
private: System::Void BTSave_Click(System::Object^ sender, System::EventArgs^ e) {

    if (TxtSave->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        String^ FilePatch= TxtSave->SelectedPath;
        
        TextSave(FilePatch,SumLess);
    }

}
private: System::Void BTFoqBarname_Click(System::Object^ sender, System::EventArgs^ e) {

    HideMeno();
    ShowFoq1();
}
private: System::Void BTBazgashtFog_Click(System::Object^ sender, System::EventArgs^ e) {
    LAErorFoq->Text = "";
    LAErorFoq2->Text = "";
    LAErorFoq3->Text = "";
    LAEror->Text = "";
    LAErorIm->Text = "";
    HideFoq1();
    ShowMeno();
}


       

private: System::Void BTTaiid1Foq_Click(System::Object^ sender, System::EventArgs^ e) {

    //MessageBox::Show(UTF8Convert(StringConvert(TXLessonNameFoq->Text)));
    //if (!(TXLessonIDFoq->Text == "" || TXLessonNameFoq->Text == "" || TXTeacherNameFoq->Text == "")) LAEror->Text = "";

    LAErorFoq->Text = "";

    if (TXLessonIDFoq->Text == "" || TXLessonNameFoq->Text == "" || TXTeacherNameFoq->Text == "") { LAErorFoq->Text = L"لطفا همه فیلد ها را پر کنید !"; return; }

    else
        LAErorFoq->Text = "";

    if(isnot_ABC_or_123(TXLessonIDFoq->Text)) { LAErorFoq->Text = L"آدرس درس تنها میتواند شامل اعداد و حروف لاتین باشد ."; return; }


    if (extraclass.size()) {
        for (auto id : SumLess) {
            if (id.getID() == StringConvert(TXLessonIDFoq->Text))
            {
                LAErorFoq->Text = L"نشانی وارد شده از قبل وجود دارد لطفا نشانی دیگری وارد کنید !"; return;
            }
        }
    }
    else
    {
        for (auto id : lessons) {
            if (id.getID() == StringConvert(TXLessonIDFoq->Text))
            {
                LAErorFoq->Text = L"نشانی وارد شده از قبل وجود دارد لطفا نشانی دیگری وارد کنید !"; return;
            }
        }
    }


    if (isintiger(StringConvert(TXTeacherNameFoq->Text))) { LAErorFoq->Text = L"لطفا نام استاد را به درستی وارد کنید ."; return; }

    if (isEnglishchar(TXLessonNameFoq->Text)) { LAErorFoq->Text = L"لطفا نام درس را فارسی وارد کنید ."; return; }

    if(isEnglishchar(TXTeacherNameFoq->Text)) { LAErorFoq->Text = L"لطفا نام استاد را فارسی وارد کنید ."; return; }

   


    VARozFoq->BringToFront();
    LATimeToolFoq->SendToBack();
    LATimeFoq->SendToBack();
    VAHFoq->BringToFront();
    VAH1Foq->BringToFront();
    LAJalaseFoq->SendToBack();
    LAErorFoq2->SendToBack();
    LATimeFoq->SendToBack();
    LADateFoq->SendToBack();


    LAErorFoq2->Text = "";
    HideFoq1();
    ShowFoq2();


}
private: System::Void TXLessonIDFoq_TextChanged(System::Object^ sender, System::EventArgs^ e) {

    if (!(TXLessonIDFoq->Text == "" || TXLessonNameFoq->Text == "" || TXTeacherNameFoq->Text == "")) LAErorFoq->Text = "";
}
private: System::Void TXLessonNameFoq_TextChanged(System::Object^ sender, System::EventArgs^ e) {

    if (!(TXLessonIDFoq->Text == "" || TXLessonNameFoq->Text == "" || TXTeacherNameFoq->Text == "")) LAErorFoq->Text = "";if (!(TXLessonIDFoq->Text == "" || TXLessonNameFoq->Text == "" || TXTeacherNameFoq->Text == "")) LAEror->Text = "";

   
        //MessageBox::Show(TXLessonNameFoq->Text[TXLessonNameFoq->Text->Length - 1] + "");
       
    if (isEnglishchar(TXLessonNameFoq->Text)) { LAErorFoq->Text = L"لطفا نام درس را فارسی وارد کنید ."; TXLessonNameFoq->Text=""; return; }
    


    
}
private: System::Void TXTeacherNameFoq_TextChanged(System::Object^ sender, System::EventArgs^ e) {
  //  MessageBox::Show(StringConvert(to_string(         (TXTeacherNameFoq->Text) == UTF8Convert(lessons.at(0).getTeacherName())         )));
    if (!(TXLessonIDFoq->Text == "" || TXLessonNameFoq->Text == "" || TXTeacherNameFoq->Text == "")) LAErorFoq->Text = "";


    if (isEnglishchar(TXTeacherNameFoq->Text)) { LAErorFoq->Text = L"لطفا نام استاد را فارسی وارد کنید ."; TXTeacherNameFoq->Text = ""; return; }
    

}




      
private: System::Void BTBazgasht2Foq_Click(System::Object^ sender, System::EventArgs^ e) {
    LAErorFoq->Text = "";
    LAErorFoq2->Text = "";
    LAErorFoq3->Text = "";
    LAEror->Text = "";
    LAErorIm->Text = "";

    WeekErorr = 0;

    HideFoq2();
    ShowFoq1();

}

private: int WeekDay = 7;
private: int WeekErorr = 0;

private: System::Void BTTaiid2Foq_Click(System::Object^ sender, System::EventArgs^ e) {

    LAErorFoq2->Text = "";
    LAErorFoq2->ForeColor = Color::FromArgb(255, 128, 128);
    // if (VAMahFoq->Value == 0 || VARozFoq->Value == 0 || VAMahFoq->Value >12 || VARozFoq->Value > 31) { LAErorFoq2->Text = L"لطفا تاریخ شروع کلاس را به درستی وارد کنید."; return; }

    if (VAMahFoq->Value > 6 && VARozFoq->Value == 31) { LAErorFoq2->Text = L" این ماه کمتر از ۳۱ روز دارد!"; return; }

    if (VAMahFoq->Value < StartDayLesson(lessons).getData().Month || (VAMahFoq->Value == StartDayLesson(lessons).getData().Month && VARozFoq->Value < StartDayLesson(lessons).getData().Day))
    {
        LAErorFoq2->Text = L"    اولین کلاس اصلی در مرکز در تاریخ  " + NumPerConvert(StartDayLesson(lessons).getData().Day) + " / " + NumPerConvert(StartDayLesson(lessons).getData().Month) + L" برگزار میشود، لطفا تاریخ شروع را پس از این تاریخ وارد کنید    .";  return;
    }

    if (VAH1Foq->Value == 0 && VAM1Foq->Value == 0) { LAErorFoq2->Text = L"مدت زمان کلاس نمی تواند صفر باشد!"; return; }

    if (VAH1Foq->Value == 0 && VAM1Foq->Value < 15) { LAErorFoq2->Text = L"مدت زمان کلاس باید بیشتر از ۱۵ دقیقه باشد."; return; }

    if (TXWeekDayFoq->Text == "") { LAErorFoq2->Text = L"لطفا روز شروع را وارد کنید."; return; }

    if (TXWeekDayFoq->Text == L"جمعه") { LAErorFoq2->Text = L"کلاس نمیتواند در روز تعطیل برگزار شود!"; return; }



    switch (TXWeekDayFoq->Text[0])
    {
    case L'ش':
        WeekDay = 0;
        break;
    case L'ی':
        WeekDay = 1;
        break;
    case L'د':
        WeekDay = 2;
        break;
    case L'س':
        WeekDay = 3;
        break;
    case L'چ':
        WeekDay = 4;
        break;
    case L'پ':
        WeekDay = 5;
        break;

    default:

        LAErorFoq2->Text = L"لطفا روز هفته را با حروف فارسی بدون حرف یا فاصله اضافی، وارد کنید.";
        return;

        break;
    }

    Date test;
    test.Day = int(VARozFoq->Value);
    test.Month = int(VAMahFoq->Value);
    if (WeekDay != (FindDayWeek(StartDayLesson(lessons), test))) {

        if(WeekErorr < 3) {
            WeekErorr++;
            LAErorFoq2->Text = L"لطفا روز هفته را متناسب با تاریخ وارد کنید.";
            return;
        }
    
    }


    if (extraclass.size()) {

       
        for (auto less : SumLess) {

            if (TXTeacherNameFoq->Text == UTF8Convert(less.getTeacherName()) || TXTeacherNameFoq->Text == (less.getTeacherName_S())) {
              
             //   if (less.getData().WeekDay == WeekDay)

                ExtraLessons test((int)VAJalaseFoq->Value, StringConvert(TXLessonIDFoq->Text), StringConvert(TXLessonNameFoq->Text), StringConvert(TXTeacherNameFoq->Text), StList, (int)VAHFoq->Value, (int)VAMFoq->Value, (int)VAH1Foq->Value, (int)VAM1Foq->Value, WeekDay, BOVideoProjectorFoq->Checked, 1402, (int)VAMahFoq->Value, (int)VARozFoq->Value);
                test.setString(TXLessonNameFoq->Text, TXTeacherNameFoq->Text);
                
                
                for (auto Ex : ToSplitExtraClass(test)) {
                    if (less.DataInterference_W_D(Ex) && less.ClockInterference((int)VAHFoq->Value, (int)VAMFoq->Value, (int)VAH1Foq->Value, (int)VAM1Foq->Value))
                    {
                       
                        LAErorFoq2->Text = L"استاد مورد نظر در این بازه زمانی، کلاس دیگری دارد!";
                        return;
                    }
                }
            }

        }

    }

    else{


    for (auto less : lessons) {

        if ((TXTeacherNameFoq->Text) == UTF8Convert(less.getTeacherName())) {

         //   if (less.getData().WeekDay == WeekDay)

                if (less.getData().WeekDay == WeekDay && less.ClockInterference((int)VAHFoq->Value, (int)VAMFoq->Value, (int)VAH1Foq->Value, (int)VAM1Foq->Value))
                {

                    LAErorFoq2->Text = L"استاد مورد نظر در این بازه زمانی، کلاس دیگری دارد!";
                    return;
                }
        }

    }
}
   

    HideFoq2();
    ShowFoq3();

}




private: System::Void BTTaiid3Foq_Click(System::Object^ sender, System::EventArgs^ e) {

    LAErorFoq3->ForeColor = Color::FromArgb(255, 128, 128);
    LAErorFoq3->Text = "";
    if (StList.size() < 2) { LAErorFoq3->Text = L"کلاس باید حداقل ۲ دانشجو داشته باشد !"; return; }
    else
        LAErorFoq3->Text = "";

    
    {
        ExtraLessons test((int)VAJalaseFoq->Value, StringConvert(TXLessonIDFoq->Text), StringConvert(TXLessonNameFoq->Text), StringConvert(TXTeacherNameFoq->Text), StList, (int)VAHFoq->Value, (int)VAMFoq->Value, (int)VAH1Foq->Value, (int)VAM1Foq->Value, WeekDay, BOVideoProjectorFoq->Checked, 1402, (int)VAMahFoq->Value, (int)VARozFoq->Value);
        test.setString(TXLessonNameFoq->Text, TXTeacherNameFoq->Text);
       
        vector <ExtraLessons> EXtest = extraclass;
        EXtest.push_back(test);

        vector <Lessons> SplitEX = ToSplitExtraClass(EXtest);
        vector <Lessons> SumLess = lessons;

    for (Lessons Sp : SplitEX)
        SumLess.push_back(Sp);


    SortLessons(SumLess);
    AutoSetLocation_ByData_WDay(SumLess, classes);
    for (auto less : SumLess) {
      
        if (less.getClassLocation() == 0) {

            LAErorFoq3->Text =  L"کلاسی متناسب با درس شما برای همه جلسات یافت نشد، ممکن است برخی یا همه جلسات نادیده گر فته شوند."; 
            BTTaiid3Foq->Hide();
            BTDengerFill->Show();
            return; 
        }
    }
    }





    ExtraLessons test((int)VAJalaseFoq->Value, StringConvert(TXLessonIDFoq->Text), StringConvert(TXLessonNameFoq->Text), StringConvert(TXTeacherNameFoq->Text), StList, (int)VAHFoq->Value, (int)VAMFoq->Value, (int)VAH1Foq->Value, (int)VAM1Foq->Value, WeekDay, BOVideoProjectorFoq->Checked, 1402, (int)VAMahFoq->Value, (int)VARozFoq->Value);
    test.setString(TXLessonNameFoq->Text, TXTeacherNameFoq->Text);
    extraclass.push_back(test);
    SetStudent(students, test);
    SetTeacher(teachers, test);

    {  vector <Lessons> SplitEX = ToSplitExtraClass(extraclass);
    vector <Lessons> SumLess = lessons;

    for (Lessons Sp : SplitEX)
        SumLess.push_back(Sp);

    Golestan::SumLess = SumLess; }

    
    StList.clear(); 


    HideFoq3();
    ShowMeno(); 

}





private: System::Void BTAfzodanFoq_Click(System::Object^ sender, System::EventArgs^ e) {

    LAErorFoq3->ForeColor = Color::FromArgb(255, 128, 128);
    LAErorFoq3->Text = "";

    if (StList.size() == 40) { LAErorFoq3->Text = L"اضافه کردن بیش از چهل دانشجو امکان پذیر نیست !"; return; }

    if (TXStNameFoq->Text == "" || TXStNumFoq->Text == "") { LAErorFoq3->Text = L"لطفا فیلد ها را پر کنید !"; return; }

    else if (!isintiger(StringConvert(TXStNumFoq->Text))) { LAErorFoq3->Text = L"لطفا شماره دانشجویی را به درستی وارد کنید."; return; }
    else
        LAErorFoq3->Text = "";


    for (auto st : StList) {
        if (StringConvert(TXStNumFoq->Text) == st.ID)
        {
            LAErorFoq3->Text = L"دانشجو قبلا افزوده شده است !"; return;
        }
    }


    if (extraclass.size()) {

        for (auto less : SumLess) {

            for (auto st : less.getStudents()) {

                if ((st.ID == StringConvert(TXStNumFoq->Text)) && less.getData().WeekDay == WeekDay && less.ClockInterference((int)VAHFoq->Value, (int)VAMFoq->Value, (int)VAH1Foq->Value, (int)VAM1Foq->Value)) {

                    LAErorFoq3->Text = L"دانشجو مدنظر در این بازه زمانی کلاس دیگری دارد!"; return;

                }
                else
                    LAErorFoq3->Text = "";
            }

        }

    }

    else {

        for (auto less : lessons) {

            for (auto st : less.getStudents()) {

                if ((st.ID == StringConvert(TXStNumFoq->Text)) && less.getData().WeekDay == WeekDay && less.ClockInterference((int)VAHFoq->Value, (int)VAMFoq->Value, (int)VAH1Foq->Value, (int)VAM1Foq->Value)) {

                    LAErorFoq3->Text = L"دانشجو مدنظر در این بازه زمانی کلاس دیگری دارد!"; return;

                }
                else
                    LAErorFoq3->Text = "";
            }

        }
    }

    
    
    Student test;
    test.Name = StringConvert(TXStNameFoq->Text);
    test.ID = StringConvert(TXStNumFoq->Text);
    StList.push_back(test);

    
    LAErorFoq3->ForeColor = Color::Green;
    LAErorFoq3->Text = L" ✅ " + NumPerConvert(StList.size()) + L" دانشجو افزوده شد ";
    TimeEror->Enabled = true;
    
   

}




private: System::Void BTBazgasht3Foq_Click(System::Object^ sender, System::EventArgs^ e) {
    LAErorFoq->Text = "";
    LAErorFoq2->Text = "";
    LAErorFoq3->Text = "";
    LAEror->Text = "";
    LAErorIm->Text = "";

    WeekErorr = 0;
    HideFoq3();
    ShowFoq2();
}






private: int timesikl = 0;

private: System::Void TimeEror_Tick(System::Object^ sender, System::EventArgs^ e) {

    timesikl++;

    if (timesikl > 15) {
        LAErorFoq3->ForeColor = Color::FromArgb(255, 128, 128);
        LAErorFoq3->Text = "";
        TimeEror->Enabled = false;
        timesikl = 0;
    }
}


private: System::Void BTNext_Click(System::Object^ sender, System::EventArgs^ e) {

    if (Week_Cycle == 49)
        return;
   

    Week_Cycle++;


    
    int ScoopStart = 0;
  
  
        ScoopStart = DayCount(StartDayLesson(lessons)) + 7;

        if (StartDayLesson(lessons).getData().WeekDay != 0 && StartDayLesson(lessons).getData().WeekDay != 6)

            ScoopStart = DayCount(StartDayLesson(lessons)) + (7 - (StartDayLesson(lessons).getData().WeekDay));

       
    for (size_t n = 0; n < lessons.size(); n++) {
      
        if (lessons.at(n).getData().Month == 12 && lessons.at(n).getData().Day > 21)
        {
            Week_Cycle--; return;
        }


        if (ScoopStart > DayCount(lessons.at(n)) && !lessons.at(n).getFoq())
            ++lessons.at(n);
        else if(lessons.at(n).getData().Month == 12 && lessons.at(n).getData().Day > 22 )
            ++lessons.at(n);

    }

    LAWeekCycle->Text = NumPerConvert(Week_Cycle + 1);
   

    BTBack->Show();

    if (AutoSet && extraclass.size() == 0)
        SetTable(lessons, classes, Week_Cycle, false);
    else if (AutoSet && extraclass.size() > 0)
       SetTable(lessons, SplitEX, classes, Week_Cycle, false);

   // MessageBox::Show(UTF8Convert(lessons.at(0).getName()) + "  in  :" + StringConvert(to_string(lessons.at(0).getData().WeekDay) + " : " + to_string(lessons.at(0).getData().Day) + " vs " + to_string(lessons.at(0).getConstData().Day)));


  
}



private: System::Void BTBack_Click(System::Object^ sender, System::EventArgs^ e) {

    if (Week_Cycle == 1)
        BTBack->Hide();

    Week_Cycle--;


    int ScoopEnd = 0;


    ScoopEnd = DayCount(StartDayLesson(lessons)) + 7;

    if (StartDayLesson(lessons).getData().WeekDay != 0 && StartDayLesson(lessons).getData().WeekDay != 6)

        ScoopEnd = DayCount(StartDayLesson(lessons)) - (StartDayLesson(lessons).getData().WeekDay) + 7;



    for (size_t n = 0; n < lessons.size(); n++) {


         if (ScoopEnd > DayCount(lessons.at(n)) && DayCount(SaveStartDate.at(n)) < DayCount(lessons.at(n)) && !lessons.at(n).getFoq())
            --lessons.at(n);
       
    
    }

    LAWeekCycle->Text = NumPerConvert(Week_Cycle + 1);

    if (AutoSet && extraclass.size() == 0)
        SetTable(lessons, classes, Week_Cycle, false);
    else if (AutoSet && extraclass.size() > 0)
      SetTable(lessons, SplitEX, classes, Week_Cycle, false);


}


private: System::Void BTDengerFill_Click_1(System::Object^ sender, System::EventArgs^ e) {



    ExtraLessons test((int)VAJalaseFoq->Value, StringConvert(TXLessonIDFoq->Text), StringConvert(TXLessonNameFoq->Text), StringConvert(TXTeacherNameFoq->Text), StList, (int)VAHFoq->Value, (int)VAMFoq->Value, (int)VAH1Foq->Value, (int)VAM1Foq->Value, WeekDay, BOVideoProjectorFoq->Checked, 1402, (int)VAMahFoq->Value, (int)VARozFoq->Value);
    test.setString(TXLessonNameFoq->Text, TXTeacherNameFoq->Text);
    extraclass.push_back(test);
    SetStudent(students, test);
    SetTeacher(teachers, test);

    {  vector <Lessons> SplitEX = ToSplitExtraClass(extraclass);
    vector <Lessons> SumLess = lessons;

    for (Lessons Sp : SplitEX)
        SumLess.push_back(Sp);

    Golestan::SumLess = SumLess; }


    StList.clear();

    BTDengerFill->Hide();
    HideFoq3();
    ShowMeno();
}
private: System::Void BTBishtarImTable_Click(System::Object^ sender, System::EventArgs^ e) {

    LITeacherList->BringToFront();
    LIStudentList->BringToFront();

    LITeacherList->Items->Clear();
    LIStudentList->Items->Clear();

    for(auto Te : teachers)
    LITeacherList->Items->Add(UTF8Convert(Te));

    for (auto St : students) {
        if (St.Name.at(0) >= 97 && St.Name.at(0) <= 122)
            LIStudentList->Items->Add(StringConvert(St.Name) + " (" + StringConvert(St.ID) + ") ");
        else
            LIStudentList->Items->Add(UTF8Convert(St.Name) + " (" + StringConvert(St.ID) + ") ");
    }
   
   
    Color scrollBarBackColor = Color::Gray;
    Color scrollBarForeColor = Color::White;

    LIStudentList->IntegralHeight = false;
   

    HideTable();
    ShowInfo();

}
private: System::Void BTBazgashtList_Click(System::Object^ sender, System::EventArgs^ e) {

    HideInfo();
    ShowTable();

}



private: System::Void MainForm_Resize(System::Object^ sender, System::EventArgs^ e) {
    //Tabel->Dock = DockStyle::Fill;
    Tabel->Size = System::Drawing::Size(this->Size.Width + 46, this->Size.Height);

    if (this->Size.Width > 720) {

        LAHeder->Show();
        BTBazgashtTable->Hide();
        BTBishtarImTable->Hide();


    }
    else {
        
        if (Showtable) {

            BTBazgashtTable->Show();
            BTBishtarImTable->Show();
        }
    }
}


private: int opacity = 255;
private: System::Void TimeLogo_Tick(System::Object^ sender, System::EventArgs^ e) {

    if (opacity > 200)
        opacity--;
    else if (opacity > 150)
        opacity -= 3;
    else
        opacity -= 5;

    if (opacity > 0)
        LALogoKaver->BackColor = Color::FromArgb(opacity, 192, 255, 192);


    if (opacity < -100) {
        TimeEror->Enabled = false;
        timesikl = 0;
        PALogo->Hide();
    }
}
private: System::Void BTNewIm_Click(System::Object^ sender, System::EventArgs^ e) {

    Application::Restart();
    HideMeno();
    ShowImportPage();

  
}
private: System::Void BTExit_Click(System::Object^ sender, System::EventArgs^ e) {

    this->Close();
}

private: System::Void BTDenger2_Click(System::Object^ sender, System::EventArgs^ e) {

    PAFileErorr->Hide();

    SortLessons(lessons);
    SortClases(classes);
    HideImportPage();
    ShowMeno();


    SetTable_ClassName();


    for (size_t n = 0; n < lessons.size(); n++)
        SaveStartDate.push_back(lessons.at(n).getData());

}
private: System::Void BTNewFile2_Click(System::Object^ sender, System::EventArgs^ e) {

    Application::Restart();

}
private: System::Void VAMahFoq_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

    Date test;
    test.Day = int(VARozFoq->Value);
    test.Month = int(VAMahFoq->Value);
    TXWeekDayFoq->Text = WeekDayConvert(FindDayWeek(StartDayLesson(lessons),test));
}
private: System::Void VARozFoq_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

    Date test;
    test.Day = int(VARozFoq->Value);
    test.Month = int(VAMahFoq->Value);
    TXWeekDayFoq->Text = WeekDayConvert(FindDayWeek(StartDayLesson(lessons), test));
}
};
}

    