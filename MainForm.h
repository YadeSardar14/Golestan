#pragma once

#include "Functions.h"

namespace Golestan {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace std;
    
    
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

    private: OpenFileDialog^ XmlAdres;

	public:
		MainForm(void)
		{
			InitializeComponent();


            XmlAdres = gcnew OpenFileDialog();
            XmlAdres->Filter = "XML files (*.xml)|*.xml";
            XmlAdres->Title = "Select a File";
            XmlAdres->RestoreDirectory = true;


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

        }

        void HideImportPage() {

            BTImportFile->Hide();
            LAXmlFile->Hide();
            LAErorIm->Hide();
        }

        void ShowMeno() {

            BTBarnameDarsi->Show();
            BTTanzinBarname->Show();
            BTFoqBarname->Show();

        }

        void HideMeno() {

            BTBarnameDarsi->Hide();
            BTTanzinBarname->Hide();
            BTFoqBarname->Hide();

        }

        void ShowTable() {

            
            BTAuto->Show();
            BTSave->Show();
            BTBazgashtTable->Show();
            BTBishtarImTable->Show();
            Tabel->Show();
        }

        void HideTable() {

            Tabel->Hide();
            BTAuto->Hide();
            BTSave->Hide();
            BTBazgashtTable->Hide();
            BTBishtarImTable->Hide();
        }

        void ShowTanzimBarname() {

            BTTaiid->Show();
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

        }

        void ShowFoq2() {

            LADateFoq->Show();
            LATimeFoq->Show();
            LATimeToolFoq->Show();
            LAErorFoq->Show();
            BTTaiidFoq->Show();
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
            LAErorFoq->Hide();
            BTTaiidFoq->Hide();
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
            TXStNameFoq->Show();
            TXStNumFoq->Show();
            LAErorFoq->Show();
        }

        void HideFoq3() {

            LADaneshjoFoq->Hide();
            LAStNameFoq->Hide();
            LAStNumFoq->Hide();
            PAStNameFoq->Hide();
            PAStNumFoq->Hide();
            BTTaiid3Foq->Hide();
            BTAfzodanFoq->Hide();
            TXStNameFoq->Hide();
            TXStNumFoq->Hide();
            LAErorFoq->Hide();
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
    private: System::Windows::Forms::Button^ BTTaiidFoq;
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
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;











	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
            this->BTTaiidFoq = (gcnew System::Windows::Forms::Button());
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
            this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAJalaseFoq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAM1Foq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAH1Foq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAMFoq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAHFoq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VARozFoq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAMahFoq))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabel))->BeginInit();
            this->SuspendLayout();
            // 
            // TXWeekDayFoq
            // 
            this->TXWeekDayFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->TXWeekDayFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXWeekDayFoq->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXWeekDayFoq->Location = System::Drawing::Point(251, 380);
            this->TXWeekDayFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->TXWeekDayFoq->Name = L"TXWeekDayFoq";
            this->TXWeekDayFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->TXWeekDayFoq->Size = System::Drawing::Size(120, 19);
            this->TXWeekDayFoq->TabIndex = 172;
            this->TXWeekDayFoq->Text = L"شنبه";
            this->TXWeekDayFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // LAWeekDayFoq
            // 
            this->LAWeekDayFoq->AutoSize = true;
            this->LAWeekDayFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAWeekDayFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAWeekDayFoq->Location = System::Drawing::Point(368, 337);
            this->LAWeekDayFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAWeekDayFoq->Name = L"LAWeekDayFoq";
            this->LAWeekDayFoq->Size = System::Drawing::Size(131, 85);
            this->LAWeekDayFoq->TabIndex = 171;
            this->LAWeekDayFoq->Text = L" :  روز شروع";
            // 
            // TXStNumFoq
            // 
            this->TXStNumFoq->BackColor = System::Drawing::Color::Aquamarine;
            this->TXStNumFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXStNumFoq->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXStNumFoq->Location = System::Drawing::Point(244, 345);
            this->TXStNumFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->TXStNumFoq->Name = L"TXStNumFoq";
            this->TXStNumFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->TXStNumFoq->Size = System::Drawing::Size(441, 22);
            this->TXStNumFoq->TabIndex = 170;
            this->TXStNumFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // TXStNameFoq
            // 
            this->TXStNameFoq->BackColor = System::Drawing::Color::Aquamarine;
            this->TXStNameFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXStNameFoq->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXStNameFoq->Location = System::Drawing::Point(244, 241);
            this->TXStNameFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->TXStNameFoq->Name = L"TXStNameFoq";
            this->TXStNameFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->TXStNameFoq->Size = System::Drawing::Size(441, 22);
            this->TXStNameFoq->TabIndex = 169;
            this->TXStNameFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // BTAfzodanFoq
            // 
            this->BTAfzodanFoq->AutoEllipsis = true;
            this->BTAfzodanFoq->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTAfzodanFoq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTAfzodanFoq->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTAfzodanFoq->ForeColor = System::Drawing::SystemColors::Info;
            this->BTAfzodanFoq->Location = System::Drawing::Point(472, 539);
            this->BTAfzodanFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->BTAfzodanFoq->Name = L"BTAfzodanFoq";
            this->BTAfzodanFoq->Size = System::Drawing::Size(213, 43);
            this->BTAfzodanFoq->TabIndex = 168;
            this->BTAfzodanFoq->Text = L"افزودن";
            this->BTAfzodanFoq->UseVisualStyleBackColor = false;
            // 
            // PAStNumFoq
            // 
            this->PAStNumFoq->BackColor = System::Drawing::Color::DarkGreen;
            this->PAStNumFoq->Location = System::Drawing::Point(244, 367);
            this->PAStNumFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->PAStNumFoq->Name = L"PAStNumFoq";
            this->PAStNumFoq->Size = System::Drawing::Size(441, 4);
            this->PAStNumFoq->TabIndex = 167;
            // 
            // PAStNameFoq
            // 
            this->PAStNameFoq->BackColor = System::Drawing::Color::DarkGreen;
            this->PAStNameFoq->Location = System::Drawing::Point(244, 263);
            this->PAStNameFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->PAStNameFoq->Name = L"PAStNameFoq";
            this->PAStNameFoq->Size = System::Drawing::Size(441, 4);
            this->PAStNameFoq->TabIndex = 166;
            // 
            // BTTaiid3Foq
            // 
            this->BTTaiid3Foq->AutoEllipsis = true;
            this->BTTaiid3Foq->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTTaiid3Foq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTTaiid3Foq->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTTaiid3Foq->ForeColor = System::Drawing::SystemColors::Info;
            this->BTTaiid3Foq->Location = System::Drawing::Point(244, 539);
            this->BTTaiid3Foq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->BTTaiid3Foq->Name = L"BTTaiid3Foq";
            this->BTTaiid3Foq->Size = System::Drawing::Size(213, 43);
            this->BTTaiid3Foq->TabIndex = 165;
            this->BTTaiid3Foq->Text = L"تایید";
            this->BTTaiid3Foq->UseVisualStyleBackColor = false;
            // 
            // LAStNumFoq
            // 
            this->LAStNumFoq->AutoSize = true;
            this->LAStNumFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 34, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAStNumFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAStNumFoq->Location = System::Drawing::Point(681, 306);
            this->LAStNumFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAStNumFoq->Name = L"LAStNumFoq";
            this->LAStNumFoq->Size = System::Drawing::Size(183, 109);
            this->LAStNumFoq->TabIndex = 164;
            this->LAStNumFoq->Text = L" : شماره دانشجویی ";
            // 
            // LAStNameFoq
            // 
            this->LAStNameFoq->AutoSize = true;
            this->LAStNameFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 34, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAStNameFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAStNameFoq->Location = System::Drawing::Point(681, 185);
            this->LAStNameFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAStNameFoq->Name = L"LAStNameFoq";
            this->LAStNameFoq->Size = System::Drawing::Size(228, 109);
            this->LAStNameFoq->TabIndex = 163;
            this->LAStNameFoq->Text = L" : نام و نام خانوادگی    ";
            // 
            // LADaneshjoFoq
            // 
            this->LADaneshjoFoq->AutoSize = true;
            this->LADaneshjoFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LADaneshjoFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LADaneshjoFoq->Location = System::Drawing::Point(680, 41);
            this->LADaneshjoFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LADaneshjoFoq->Name = L"LADaneshjoFoq";
            this->LADaneshjoFoq->Size = System::Drawing::Size(239, 116);
            this->LADaneshjoFoq->TabIndex = 162;
            this->LADaneshjoFoq->Text = L" :  افزودن دانشجویان   ";
            // 
            // BTTaiidFoq
            // 
            this->BTTaiidFoq->AutoEllipsis = true;
            this->BTTaiidFoq->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTTaiidFoq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTTaiidFoq->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTTaiidFoq->ForeColor = System::Drawing::SystemColors::Info;
            this->BTTaiidFoq->Location = System::Drawing::Point(251, 539);
            this->BTTaiidFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->BTTaiidFoq->Name = L"BTTaiidFoq";
            this->BTTaiidFoq->Size = System::Drawing::Size(213, 43);
            this->BTTaiidFoq->TabIndex = 161;
            this->BTTaiidFoq->Text = L"تایید";
            this->BTTaiidFoq->UseVisualStyleBackColor = false;
            // 
            // VAJalaseFoq
            // 
            this->VAJalaseFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAJalaseFoq->Location = System::Drawing::Point(535, 374);
            this->VAJalaseFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->VAJalaseFoq->Name = L"VAJalaseFoq";
            this->VAJalaseFoq->Size = System::Drawing::Size(120, 22);
            this->VAJalaseFoq->TabIndex = 160;
            // 
            // LAJalaseFoq
            // 
            this->LAJalaseFoq->AutoSize = true;
            this->LAJalaseFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 34, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAJalaseFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAJalaseFoq->Location = System::Drawing::Point(645, 322);
            this->LAJalaseFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAJalaseFoq->Name = L"LAJalaseFoq";
            this->LAJalaseFoq->Size = System::Drawing::Size(189, 109);
            this->LAJalaseFoq->TabIndex = 159;
            this->LAJalaseFoq->Text = L" : تعداد جلسات ";
            // 
            // VAM1Foq
            // 
            this->VAM1Foq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAM1Foq->Location = System::Drawing::Point(251, 277);
            this->VAM1Foq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->VAM1Foq->Name = L"VAM1Foq";
            this->VAM1Foq->Size = System::Drawing::Size(120, 22);
            this->VAM1Foq->TabIndex = 158;
            // 
            // VAH1Foq
            // 
            this->VAH1Foq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAH1Foq->Location = System::Drawing::Point(447, 276);
            this->VAH1Foq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->VAH1Foq->Name = L"VAH1Foq";
            this->VAH1Foq->Size = System::Drawing::Size(120, 22);
            this->VAH1Foq->TabIndex = 157;
            // 
            // LAM1Foq
            // 
            this->LAM1Foq->AutoSize = true;
            this->LAM1Foq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAM1Foq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAM1Foq->Location = System::Drawing::Point(368, 240);
            this->LAM1Foq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAM1Foq->Name = L"LAM1Foq";
            this->LAM1Foq->Size = System::Drawing::Size(82, 85);
            this->LAM1Foq->TabIndex = 156;
            this->LAM1Foq->Text = L" : دقیقه";
            // 
            // LAH1Foq
            // 
            this->LAH1Foq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAH1Foq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAH1Foq->Location = System::Drawing::Point(563, 240);
            this->LAH1Foq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAH1Foq->Name = L"LAH1Foq";
            this->LAH1Foq->Size = System::Drawing::Size(113, 82);
            this->LAH1Foq->TabIndex = 155;
            this->LAH1Foq->Text = L" : ساعت";
            // 
            // LATimeToolFoq
            // 
            this->LATimeToolFoq->AutoSize = true;
            this->LATimeToolFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 34, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LATimeToolFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LATimeToolFoq->Location = System::Drawing::Point(648, 226);
            this->LATimeToolFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LATimeToolFoq->Name = L"LATimeToolFoq";
            this->LATimeToolFoq->Size = System::Drawing::Size(192, 109);
            this->LATimeToolFoq->TabIndex = 154;
            this->LATimeToolFoq->Text = L" : مدت برگزاری";
            // 
            // VAMFoq
            // 
            this->VAMFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAMFoq->Location = System::Drawing::Point(251, 187);
            this->VAMFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->VAMFoq->Name = L"VAMFoq";
            this->VAMFoq->Size = System::Drawing::Size(120, 22);
            this->VAMFoq->TabIndex = 153;
            // 
            // VAHFoq
            // 
            this->VAHFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAHFoq->Location = System::Drawing::Point(447, 186);
            this->VAHFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->VAHFoq->Name = L"VAHFoq";
            this->VAHFoq->Size = System::Drawing::Size(120, 22);
            this->VAHFoq->TabIndex = 152;
            // 
            // VARozFoq
            // 
            this->VARozFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VARozFoq->Location = System::Drawing::Point(251, 97);
            this->VARozFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->VARozFoq->Name = L"VARozFoq";
            this->VARozFoq->Size = System::Drawing::Size(120, 22);
            this->VARozFoq->TabIndex = 151;
            // 
            // VAMahFoq
            // 
            this->VAMahFoq->BackColor = System::Drawing::Color::MediumAquamarine;
            this->VAMahFoq->Location = System::Drawing::Point(447, 97);
            this->VAMahFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->VAMahFoq->Name = L"VAMahFoq";
            this->VAMahFoq->Size = System::Drawing::Size(120, 22);
            this->VAMahFoq->TabIndex = 150;
            // 
            // LAMFoq
            // 
            this->LAMFoq->AutoSize = true;
            this->LAMFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAMFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAMFoq->Location = System::Drawing::Point(368, 150);
            this->LAMFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAMFoq->Name = L"LAMFoq";
            this->LAMFoq->Size = System::Drawing::Size(82, 85);
            this->LAMFoq->TabIndex = 149;
            this->LAMFoq->Text = L" : دقیقه";
            // 
            // LAHFoq
            // 
            this->LAHFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAHFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAHFoq->Location = System::Drawing::Point(563, 150);
            this->LAHFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAHFoq->Name = L"LAHFoq";
            this->LAHFoq->Size = System::Drawing::Size(113, 82);
            this->LAHFoq->TabIndex = 148;
            this->LAHFoq->Text = L" : ساعت";
            // 
            // LATimeFoq
            // 
            this->LATimeFoq->AutoSize = true;
            this->LATimeFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 34, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LATimeFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LATimeFoq->Location = System::Drawing::Point(648, 137);
            this->LATimeFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LATimeFoq->Name = L"LATimeFoq";
            this->LATimeFoq->Size = System::Drawing::Size(221, 109);
            this->LATimeFoq->TabIndex = 147;
            this->LATimeFoq->Text = L" : ساعت برگزاری    ";
            // 
            // LARozFoq
            // 
            this->LARozFoq->AutoSize = true;
            this->LARozFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LARozFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LARozFoq->Location = System::Drawing::Point(365, 64);
            this->LARozFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LARozFoq->Name = L"LARozFoq";
            this->LARozFoq->Size = System::Drawing::Size(78, 85);
            this->LARozFoq->TabIndex = 146;
            this->LARozFoq->Text = L" : روز";
            // 
            // LAMahFoq
            // 
            this->LAMahFoq->AutoSize = true;
            this->LAMahFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LAMahFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LAMahFoq->Location = System::Drawing::Point(571, 64);
            this->LAMahFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LAMahFoq->Name = L"LAMahFoq";
            this->LAMahFoq->Size = System::Drawing::Size(68, 85);
            this->LAMahFoq->TabIndex = 145;
            this->LAMahFoq->Text = L" : ماه";
            // 
            // LADateFoq
            // 
            this->LADateFoq->AutoSize = true;
            this->LADateFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LADateFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LADateFoq->Location = System::Drawing::Point(644, 41);
            this->LADateFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LADateFoq->Name = L"LADateFoq";
            this->LADateFoq->Size = System::Drawing::Size(195, 116);
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
            this->LAErorFoq->Location = System::Drawing::Point(-1, 416);
            this->LAErorFoq->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
            this->LAErorFoq->Name = L"LAErorFoq";
            this->LAErorFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LAErorFoq->Size = System::Drawing::Size(852, 108);
            this->LAErorFoq->TabIndex = 143;
            this->LAErorFoq->Text = L"این درس نیاز به ویدیو پرژکتور دارد!";
            this->LAErorFoq->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // BOVideoProjectorFoq
            // 
            this->BOVideoProjectorFoq->AutoSize = true;
            this->BOVideoProjectorFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->BOVideoProjectorFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->BOVideoProjectorFoq->Location = System::Drawing::Point(691, 370);
            this->BOVideoProjectorFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->BOVideoProjectorFoq->Name = L"BOVideoProjectorFoq";
            this->BOVideoProjectorFoq->Size = System::Drawing::Size(116, 76);
            this->BOVideoProjectorFoq->TabIndex = 142;
            this->BOVideoProjectorFoq->Text = L"ویدئوپرژکتور";
            this->BOVideoProjectorFoq->UseVisualStyleBackColor = true;
            // 
            // TXLessonNameFoq
            // 
            this->TXLessonNameFoq->BackColor = System::Drawing::Color::Aquamarine;
            this->TXLessonNameFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXLessonNameFoq->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXLessonNameFoq->Location = System::Drawing::Point(232, 201);
            this->TXLessonNameFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->TXLessonNameFoq->Name = L"TXLessonNameFoq";
            this->TXLessonNameFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->TXLessonNameFoq->Size = System::Drawing::Size(441, 22);
            this->TXLessonNameFoq->TabIndex = 140;
            this->TXLessonNameFoq->Text = L" ";
            this->TXLessonNameFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // TXLessonIDFoq
            // 
            this->TXLessonIDFoq->BackColor = System::Drawing::Color::Aquamarine;
            this->TXLessonIDFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXLessonIDFoq->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXLessonIDFoq->Location = System::Drawing::Point(232, 127);
            this->TXLessonIDFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->TXLessonIDFoq->Name = L"TXLessonIDFoq";
            this->TXLessonIDFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->TXLessonIDFoq->Size = System::Drawing::Size(441, 22);
            this->TXLessonIDFoq->TabIndex = 139;
            this->TXLessonIDFoq->Text = L" ";
            this->TXLessonIDFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // LALessonNameFoq
            // 
            this->LALessonNameFoq->AutoSize = true;
            this->LALessonNameFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LALessonNameFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LALessonNameFoq->Location = System::Drawing::Point(667, 159);
            this->LALessonNameFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LALessonNameFoq->Name = L"LALessonNameFoq";
            this->LALessonNameFoq->Size = System::Drawing::Size(155, 116);
            this->LALessonNameFoq->TabIndex = 141;
            this->LALessonNameFoq->Text = L" : نام درس";
            // 
            // PALessonNameFoq
            // 
            this->PALessonNameFoq->BackColor = System::Drawing::Color::DarkGreen;
            this->PALessonNameFoq->Location = System::Drawing::Point(232, 229);
            this->PALessonNameFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->PALessonNameFoq->Name = L"PALessonNameFoq";
            this->PALessonNameFoq->Size = System::Drawing::Size(441, 4);
            this->PALessonNameFoq->TabIndex = 138;
            // 
            // LALessonIDFoq
            // 
            this->LALessonIDFoq->AutoSize = true;
            this->LALessonIDFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LALessonIDFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LALessonIDFoq->Location = System::Drawing::Point(669, 71);
            this->LALessonIDFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LALessonIDFoq->Name = L"LALessonIDFoq";
            this->LALessonIDFoq->Size = System::Drawing::Size(169, 116);
            this->LALessonIDFoq->TabIndex = 137;
            this->LALessonIDFoq->Text = L" : نشانی درس";
            // 
            // PALessonIDFoq
            // 
            this->PALessonIDFoq->BackColor = System::Drawing::Color::DarkGreen;
            this->PALessonIDFoq->Location = System::Drawing::Point(232, 151);
            this->PALessonIDFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->PALessonIDFoq->Name = L"PALessonIDFoq";
            this->PALessonIDFoq->Size = System::Drawing::Size(441, 4);
            this->PALessonIDFoq->TabIndex = 136;
            // 
            // TXTeacherNameFoq
            // 
            this->TXTeacherNameFoq->BackColor = System::Drawing::Color::Aquamarine;
            this->TXTeacherNameFoq->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXTeacherNameFoq->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXTeacherNameFoq->Location = System::Drawing::Point(232, 298);
            this->TXTeacherNameFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->TXTeacherNameFoq->Name = L"TXTeacherNameFoq";
            this->TXTeacherNameFoq->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->TXTeacherNameFoq->Size = System::Drawing::Size(441, 22);
            this->TXTeacherNameFoq->TabIndex = 135;
            this->TXTeacherNameFoq->Text = L" ";
            this->TXTeacherNameFoq->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // BTTaiid1Foq
            // 
            this->BTTaiid1Foq->AutoEllipsis = true;
            this->BTTaiid1Foq->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BTTaiid1Foq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTTaiid1Foq->Font = (gcnew System::Drawing::Font(L"Impact", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTTaiid1Foq->ForeColor = System::Drawing::SystemColors::Info;
            this->BTTaiid1Foq->Location = System::Drawing::Point(251, 505);
            this->BTTaiid1Foq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->BTTaiid1Foq->Name = L"BTTaiid1Foq";
            this->BTTaiid1Foq->Size = System::Drawing::Size(213, 43);
            this->BTTaiid1Foq->TabIndex = 134;
            this->BTTaiid1Foq->Text = L"تایید";
            this->BTTaiid1Foq->UseVisualStyleBackColor = false;
            // 
            // LATeacherNameFoq
            // 
            this->LATeacherNameFoq->AutoSize = true;
            this->LATeacherNameFoq->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LATeacherNameFoq->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LATeacherNameFoq->Location = System::Drawing::Point(669, 242);
            this->LATeacherNameFoq->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LATeacherNameFoq->Name = L"LATeacherNameFoq";
            this->LATeacherNameFoq->Size = System::Drawing::Size(148, 116);
            this->LATeacherNameFoq->TabIndex = 133;
            this->LATeacherNameFoq->Text = L" : نام استاد";
            // 
            // PATeacherNameFoq
            // 
            this->PATeacherNameFoq->BackColor = System::Drawing::Color::DarkGreen;
            this->PATeacherNameFoq->Location = System::Drawing::Point(233, 322);
            this->PATeacherNameFoq->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->PATeacherNameFoq->Name = L"PATeacherNameFoq";
            this->PATeacherNameFoq->Size = System::Drawing::Size(441, 4);
            this->PATeacherNameFoq->TabIndex = 132;
            // 
            // TXClassID
            // 
            this->TXClassID->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->TXClassID->BackColor = System::Drawing::Color::Aquamarine;
            this->TXClassID->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->TXClassID->Font = (gcnew System::Drawing::Font(L"Eras Demi ITC", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->TXClassID->Location = System::Drawing::Point(257, 255);
            this->TXClassID->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->TXClassID->Name = L"TXClassID";
            this->TXClassID->Size = System::Drawing::Size(441, 22);
            this->TXClassID->TabIndex = 130;
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
            this->TXLessonID->Location = System::Drawing::Point(257, 127);
            this->TXLessonID->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->TXLessonID->Name = L"TXLessonID";
            this->TXLessonID->Size = System::Drawing::Size(441, 22);
            this->TXLessonID->TabIndex = 129;
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
            this->LAEror->Location = System::Drawing::Point(33, 325);
            this->LAEror->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
            this->LAEror->Name = L"LAEror";
            this->LAEror->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LAEror->Size = System::Drawing::Size(852, 113);
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
            this->BTTaiid->Location = System::Drawing::Point(232, 505);
            this->BTTaiid->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->BTTaiid->Name = L"BTTaiid";
            this->BTTaiid->Size = System::Drawing::Size(656, 43);
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
            this->LACassID->Location = System::Drawing::Point(707, 212);
            this->LACassID->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LACassID->Name = L"LACassID";
            this->LACassID->Size = System::Drawing::Size(171, 116);
            this->LACassID->TabIndex = 126;
            this->LACassID->Text = L" : شماره کلاس";
            // 
            // PAClassID
            // 
            this->PAClassID->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->PAClassID->BackColor = System::Drawing::Color::DarkGreen;
            this->PAClassID->Location = System::Drawing::Point(257, 283);
            this->PAClassID->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->PAClassID->Name = L"PAClassID";
            this->PAClassID->Size = System::Drawing::Size(441, 4);
            this->PAClassID->TabIndex = 125;
            // 
            // LALessonID
            // 
            this->LALessonID->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->LALessonID->AutoSize = true;
            this->LALessonID->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->LALessonID->ForeColor = System::Drawing::Color::DarkOliveGreen;
            this->LALessonID->Location = System::Drawing::Point(707, 85);
            this->LALessonID->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LALessonID->Name = L"LALessonID";
            this->LALessonID->Size = System::Drawing::Size(169, 116);
            this->LALessonID->TabIndex = 124;
            this->LALessonID->Text = L" : نشانی درس";
            // 
            // PALessonID
            // 
            this->PALessonID->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->PALessonID->BackColor = System::Drawing::Color::DarkGreen;
            this->PALessonID->Location = System::Drawing::Point(257, 156);
            this->PALessonID->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->PALessonID->Name = L"PALessonID";
            this->PALessonID->Size = System::Drawing::Size(441, 4);
            this->PALessonID->TabIndex = 123;
            // 
            // Tabel
            // 
            this->Tabel->Anchor = System::Windows::Forms::AnchorStyles::None;
            this->Tabel->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
            this->Tabel->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
            dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
            dataGridViewCellStyle1->BackColor = System::Drawing::Color::MediumAquamarine;
            dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle1->ForeColor = System::Drawing::Color::ForestGreen;
            dataGridViewCellStyle1->NullValue = nullptr;
            dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::Aquamarine;
            dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->Tabel->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this->Tabel->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->Tabel->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
                this->Column, this->R0,
                    this->R1, this->R2, this->R3, this->R4, this->R5
            });
            this->Tabel->Cursor = System::Windows::Forms::Cursors::Cross;
            dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            dataGridViewCellStyle2->BackColor = System::Drawing::Color::Beige;
            dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::Desktop;
            dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::DarkKhaki;
            dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->Tabel->DefaultCellStyle = dataGridViewCellStyle2;
            this->Tabel->GridColor = System::Drawing::Color::DarkKhaki;
            this->Tabel->Location = System::Drawing::Point(-8, 37);
            this->Tabel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->Tabel->Name = L"Tabel";
            this->Tabel->ReadOnly = true;
            this->Tabel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
            dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
            dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->Tabel->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
            this->Tabel->RowHeadersWidth = 51;
            this->Tabel->Size = System::Drawing::Size(1017, 594);
            this->Tabel->TabIndex = 122;
            // 
            // Column
            // 
            this->Column->HeaderText = L" ";
            this->Column->MinimumWidth = 6;
            this->Column->Name = L"Column";
            this->Column->ReadOnly = true;
            this->Column->Width = 86;
            // 
            // R0
            // 
            this->R0->HeaderText = L"شنبه";
            this->R0->MinimumWidth = 6;
            this->R0->Name = L"R0";
            this->R0->ReadOnly = true;
            this->R0->Width = 103;
            // 
            // R1
            // 
            this->R1->HeaderText = L"یکشنبه";
            this->R1->MinimumWidth = 6;
            this->R1->Name = L"R1";
            this->R1->ReadOnly = true;
            this->R1->Width = 103;
            // 
            // R2
            // 
            this->R2->HeaderText = L"دوشنبه";
            this->R2->MinimumWidth = 6;
            this->R2->Name = L"R2";
            this->R2->ReadOnly = true;
            this->R2->Width = 103;
            // 
            // R3
            // 
            this->R3->HeaderText = L"سه شنبه";
            this->R3->MinimumWidth = 6;
            this->R3->Name = L"R3";
            this->R3->ReadOnly = true;
            this->R3->Width = 103;
            // 
            // R4
            // 
            this->R4->HeaderText = L"چهارشنبه";
            this->R4->MinimumWidth = 6;
            this->R4->Name = L"R4";
            this->R4->ReadOnly = true;
            this->R4->Width = 103;
            // 
            // R5
            // 
            this->R5->HeaderText = L"پنجشنبه";
            this->R5->MinimumWidth = 6;
            this->R5->Name = L"R5";
            this->R5->ReadOnly = true;
            this->R5->Width = 103;
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
            this->BTFoqBarname->Location = System::Drawing::Point(296, 378);
            this->BTFoqBarname->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->BTFoqBarname->Name = L"BTFoqBarname";
            this->BTFoqBarname->Size = System::Drawing::Size(339, 107);
            this->BTFoqBarname->TabIndex = 121;
            this->BTFoqBarname->Text = L"ایجاد درس فوق برنامه";
            this->BTFoqBarname->UseVisualStyleBackColor = false;
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
            this->BTTanzinBarname->Location = System::Drawing::Point(296, 254);
            this->BTTanzinBarname->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->BTTanzinBarname->Name = L"BTTanzinBarname";
            this->BTTanzinBarname->Size = System::Drawing::Size(339, 107);
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
            this->BTBarnameDarsi->Location = System::Drawing::Point(296, 123);
            this->BTBarnameDarsi->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->BTBarnameDarsi->Name = L"BTBarnameDarsi";
            this->BTBarnameDarsi->Size = System::Drawing::Size(339, 107);
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
            this->LAXmlFile->Location = System::Drawing::Point(179, 383);
            this->LAXmlFile->Name = L"LAXmlFile";
            this->LAXmlFile->Size = System::Drawing::Size(114, 25);
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
            this->BTImportFile->Location = System::Drawing::Point(175, 244);
            this->BTImportFile->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->BTImportFile->Name = L"BTImportFile";
            this->BTImportFile->Size = System::Drawing::Size(553, 106);
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
            this->LAErorIm->Location = System::Drawing::Point(-108, 370);
            this->LAErorIm->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
            this->LAErorIm->Name = L"LAErorIm";
            this->LAErorIm->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LAErorIm->Size = System::Drawing::Size(852, 261);
            this->LAErorIm->TabIndex = 173;
            this->LAErorIm->Text = L"ارور";
            this->LAErorIm->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // BTAuto
            // 
            this->BTAuto->AutoEllipsis = true;
            this->BTAuto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->BTAuto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTAuto->Font = (gcnew System::Drawing::Font(L"B Nazanin", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTAuto->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->BTAuto->Location = System::Drawing::Point(447, -4);
            this->BTAuto->Margin = System::Windows::Forms::Padding(1);
            this->BTAuto->Name = L"BTAuto";
            this->BTAuto->Size = System::Drawing::Size(511, 41);
            this->BTAuto->TabIndex = 175;
            this->BTAuto->TabStop = false;
            this->BTAuto->Text = L"تنظیم خودکار";
            this->BTAuto->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
            this->BTAuto->UseVisualStyleBackColor = false;
            this->BTAuto->Click += gcnew System::EventHandler(this, &MainForm::BTAuto_Click);
            // 
            // BTSave
            // 
            this->BTSave->AutoEllipsis = true;
            this->BTSave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->BTSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTSave->Font = (gcnew System::Drawing::Font(L"B Nazanin", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTSave->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->BTSave->Location = System::Drawing::Point(-8, -4);
            this->BTSave->Margin = System::Windows::Forms::Padding(1);
            this->BTSave->Name = L"BTSave";
            this->BTSave->Size = System::Drawing::Size(472, 41);
            this->BTSave->TabIndex = 176;
            this->BTSave->TabStop = false;
            this->BTSave->Text = L"ذخیره اطلاعات";
            this->BTSave->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
            this->BTSave->UseVisualStyleBackColor = false;
            // 
            // BTBazgashtTable
            // 
            this->BTBazgashtTable->AutoEllipsis = true;
            this->BTBazgashtTable->BackColor = System::Drawing::Color::Gainsboro;
            this->BTBazgashtTable->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBazgashtTable->Font = (gcnew System::Drawing::Font(L"B Nazanin", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTBazgashtTable->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->BTBazgashtTable->Location = System::Drawing::Point(829, 42);
            this->BTBazgashtTable->Margin = System::Windows::Forms::Padding(1);
            this->BTBazgashtTable->Name = L"BTBazgashtTable";
            this->BTBazgashtTable->Size = System::Drawing::Size(108, 38);
            this->BTBazgashtTable->TabIndex = 177;
            this->BTBazgashtTable->TabStop = false;
            this->BTBazgashtTable->Text = L"بازگشت";
            this->BTBazgashtTable->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
            this->BTBazgashtTable->UseVisualStyleBackColor = false;
            this->BTBazgashtTable->Click += gcnew System::EventHandler(this, &MainForm::BTBazgashtTable_Click);
            // 
            // BTBishtarImTable
            // 
            this->BTBishtarImTable->AutoEllipsis = true;
            this->BTBishtarImTable->BackColor = System::Drawing::Color::Gainsboro;
            this->BTBishtarImTable->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BTBishtarImTable->Font = (gcnew System::Drawing::Font(L"B Nazanin", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->BTBishtarImTable->ForeColor = System::Drawing::Color::DarkGoldenrod;
            this->BTBishtarImTable->Location = System::Drawing::Point(829, 82);
            this->BTBishtarImTable->Margin = System::Windows::Forms::Padding(1);
            this->BTBishtarImTable->Name = L"BTBishtarImTable";
            this->BTBishtarImTable->Size = System::Drawing::Size(108, 38);
            this->BTBishtarImTable->TabIndex = 178;
            this->BTBishtarImTable->TabStop = false;
            this->BTBishtarImTable->Text = L"...بیشتر";
            this->BTBishtarImTable->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
            this->BTBishtarImTable->UseVisualStyleBackColor = false;
            // 
            // LATanzimLessonInfo
            // 
            this->LATanzimLessonInfo->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->LATanzimLessonInfo->Location = System::Drawing::Point(-1, 110);
            this->LATanzimLessonInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LATanzimLessonInfo->Name = L"LATanzimLessonInfo";
            this->LATanzimLessonInfo->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LATanzimLessonInfo->Size = System::Drawing::Size(231, 59);
            this->LATanzimLessonInfo->TabIndex = 179;
            this->LATanzimLessonInfo->Text = L" ";
            // 
            // LATanzimClassInfo
            // 
            this->LATanzimClassInfo->Font = (gcnew System::Drawing::Font(L"IranNastaliq", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(178)));
            this->LATanzimClassInfo->Location = System::Drawing::Point(-1, 244);
            this->LATanzimClassInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->LATanzimClassInfo->Name = L"LATanzimClassInfo";
            this->LATanzimClassInfo->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->LATanzimClassInfo->Size = System::Drawing::Size(231, 59);
            this->LATanzimClassInfo->TabIndex = 180;
            this->LATanzimClassInfo->Text = L" ";
            // 
            // flowLayoutPanel1
            // 
            this->flowLayoutPanel1->Location = System::Drawing::Point(255, 550);
            this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
            this->flowLayoutPanel1->Size = System::Drawing::Size(267, 123);
            this->flowLayoutPanel1->TabIndex = 181;
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Aquamarine;
            this->ClientSize = System::Drawing::Size(939, 630);
            this->Controls->Add(this->flowLayoutPanel1);
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
            this->Controls->Add(this->BTTaiidFoq);
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
            this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->MaximizeBox = false;
            this->Name = L"MainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"MainForm";
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAJalaseFoq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAM1Foq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAH1Foq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAMFoq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAHFoq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VARozFoq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VAMahFoq))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabel))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion


	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
    private: System::Void BTImportFile_Click(System::Object^ sender, System::EventArgs^ e) {
        
        LAErorIm->Hide();
        lessons.clear();
        classes.clear();

        if (XmlAdres->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

        	String^ FilePath = XmlAdres->FileName;

        	ReadFileLessons(lessons,students, teacher, StringConvert(FilePath));
        	ReadFileClasses(classes, StringConvert(FilePath));


        	if (classes.size() == 0 || lessons.size() == 0) 
            {
                LAErorIm->Text = L"فایل معتبر نیست،\n لطفا فایل با چهارچوب معتبر انتخاب کنید!"; LAErorIm->Show(); return;
            }
        	else
        	{   
                SortLessons(lessons);
                SortClases(classes);
        		HideImportPage();
        		ShowMeno();


                for (size_t n = 0;n < classes.size();n++) {
                    Tabel->Rows->Add();
                    Tabel->Rows[n]->Cells[0]->Value = L"کلاس " + NumPerConvert(classes.at(n).getID());
                    if (classes.at(n).getVideoProjector())
                        Tabel->Rows[n]->Cells[0]->Value += L"📽";
                   
                }



        	}

        }
    }
private: System::Void BTBarnameDarsi_Click(System::Object^ sender, System::EventArgs^ e) {

    HideMeno();
    ShowTable();

}
private: System::Void BTAuto_Click(System::Object^ sender, System::EventArgs^ e) {
   
    AutoSetLocation(lessons,classes);
 
    for (size_t n = 0;n < classes.size();n++) {
        for (size_t m = 0;m < lessons.size();m++) {

            if (lessons.at(m).getClassLocation() == classes.at(n).getID()) {
               
                switch (lessons.at(m).getData().WeekDay) {

                case 0:
                    if (Tabel->Rows[n]->Cells[1]->Value)
                        Tabel->Rows[n]->Cells[1]->Value += "\n";
                    Tabel->Rows[n]->Cells[1]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + "\n(" + NumPerConvert(lessons.at(m).getStartTime().Huor) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                    break;
                case 1:
                    if (Tabel->Rows[n]->Cells[2]->Value)
                        Tabel->Rows[n]->Cells[2]->Value += "\n";
                    Tabel->Rows[n]->Cells[2]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + "\n(" + NumPerConvert(lessons.at(m).getStartTime().Huor) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                    break;
                case 2:
                    if (Tabel->Rows[n]->Cells[3]->Value)
                        Tabel->Rows[n]->Cells[3]->Value += "\n";
                    Tabel->Rows[n]->Cells[3]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + "\n(" + NumPerConvert(lessons.at(m).getStartTime().Huor) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                    break;
                case 3:
                    if (Tabel->Rows[n]->Cells[4]->Value)
                        Tabel->Rows[n]->Cells[4]->Value += "\n";
                    Tabel->Rows[n]->Cells[4]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + "\n(" + NumPerConvert(lessons.at(m).getStartTime().Huor) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                    break;
                case 4:
                    if (Tabel->Rows[n]->Cells[5]->Value)
                        Tabel->Rows[n]->Cells[5]->Value += "\n";
                    Tabel->Rows[n]->Cells[5]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + "\n(" + NumPerConvert(lessons.at(m).getStartTime().Huor) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                    break;
                case 5:
                    if (Tabel->Rows[n]->Cells[6]->Value)
                        Tabel->Rows[n]->Cells[6]->Value += "\n";
                    Tabel->Rows[n]->Cells[6]->Value += UTF8Convert(lessons.at(m).getName()) + L"، " + UTF8Convert(lessons.at(m).getTeacherName()) + "\n(" + NumPerConvert(lessons.at(m).getStartTime().Huor) + " : " + NumPerConvert(lessons.at(m).getStartTime().Huor) + " )";
                    break;


                }
            }
        }
    }
   


}
private: System::Void BTBazgashtTable_Click(System::Object^ sender, System::EventArgs^ e) {

    HideTable();
    ShowMeno();
}
private: System::Void BTTanzinBarname_Click(System::Object^ sender, System::EventArgs^ e) {

    HideMeno();
    ShowTanzimBarname();
}
private: System::Void TXClassID_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    
    if (StringConvert(TXLessonID->Text).size() > 1 && StringConvert(TXClassID->Text).size() > 1) LAEror->Text = "";
    
    if (isInteger(StringConvert("hg"))) {
        MessageBox::Show("");
    }
    //}//LAEror->Text = L"لطفا در فیلد کلاس رقم شماره کلاس را وارد کنید."; return; }
    if (StringConvert(TXClassID->Text).size()>1) {


        for (size_t n = 0;n < classes.size();n++) {
            if (stoi(StringConvert(TXClassID->Text)) == classes.at(n).getID()) {
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

    if (StringConvert(TXLessonID->Text).size() > 1 && StringConvert(TXClassID->Text).size() > 1) LAEror->Text = "";

    if (StringConvert(TXLessonID->Text).size() > 1) {


        for (size_t n = 0;n < lessons.size();n++) {
            if (TXLessonID->Text == StringConvert( lessons.at(n).getID() )) {
                if (lessons.at(n).getVideoProjector())
                    LATanzimLessonInfo->Text = L"🎦  "+UTF8Convert(lessons.at(n).getName()) + L" (دانشجویان : " + NumPerConvert(lessons.at(n).getStudents().size()) + ")";
                else
                    LATanzimLessonInfo->Text = UTF8Convert(lessons.at(n).getName()) + L" (دانشجویان : " + NumPerConvert(lessons.at(n).getStudents().size()) + ")";

                break;
            }
            else
                LATanzimLessonInfo->Text = "";
        }
    }
    else
        LATanzimLessonInfo->Text = "";
}
private: System::Void BTTaiid_Click(System::Object^ sender, System::EventArgs^ e) {
    LAEror->Text = "";


    if (TXClassID->Text == "" || TXLessonID->Text == "") { LAEror->Text = L"لطفا فیلد ها را پر کنید !"; return; }



    //int z = 0;



    //for (size_t n = 0;n < classes.size();n++) {
    //    if (stoi(StringConvert(TXClassID->Text)) == classes.at(n).getID())
    //    {
    //         break;
    //    }
    //    LAEror->Text = L"کلاس مورد نظر یافت نشد !";
    //}

    //for (size_t n = 0;n < lessons.size();n++) {
    //    if (TXLessonID->Text == StringConvert(lessons.at(n).getID()))
    //    {
    //         break;
    //    }
    //    LAEror->Text = L"درس مورد نظر یافت نشد !";
    //}
}
};
}

