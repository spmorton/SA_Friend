#pragma once
#include <iostream>
#include <fstream>
#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <cstring>
#include <time.h>
#include <process.h>
#include <vcclr.h>

#using <system.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>
#using <mscorlib.dll>




namespace SA_Friend {

	using namespace std;
	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Specialized;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace System::Text;
	using namespace System::IO;




	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			
			// Initialize recognition 
			set_params();

			// Disable the Cancel button.
			Cancel_Async->Enabled = false;

			// Set initial logging parameters
			log_File = "";
			log = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	
	// User private data

	private:	
				System::String ^ ipAddr;
				char loginPrompt;
				char passwordPrompt;
				char commandPrompt;
				System::String ^ loginFailed1;
				System::String ^ loginFailed2;

	
	// This delegate enables asynchronous calls for setting 
    // the text property on a TextBox control. 
    delegate void SetTextDelegate(String^ text);

	
	
	// End user private data

	private: System::Windows::Forms::Button^  Select_List;
	private: System::Windows::Forms::CheckBox^  Verbose;
	protected: 


	private: System::Windows::Forms::TextBox^  Pass_Word;

	private: System::Windows::Forms::TextBox^  User_ID;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  Telnet;


	private: System::Windows::Forms::TextBox^  Command_Line;

	private: System::Windows::Forms::TextBox^  OutPutWindow;
	private: System::Windows::Forms::TabPage^  Info;


	private: System::Windows::Forms::Label^  systemCount;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  Command;
	private: System::Windows::Forms::Label^  Password;
	private: System::Windows::Forms::Label^  UserID;
	private: System::Windows::Forms::Button^  Run;
	private: System::Windows::Forms::ListBox^  ServerList;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  FailedServers;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Button^  Clear_Output;
	private: System::Windows::Forms::Button^  Add_Failed;
	private: System::Windows::Forms::Button^  Log_Output;
	
	private: String^ log_File;
			 bool log;

	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  Open_Log;

	private: System::Windows::Forms::Button^  Show_Failed;
	private: System::Windows::Forms::Button^  Exit_Bttn;
	private: System::Windows::Forms::TabPage^  Configure;
	private: System::Windows::Forms::TextBox^  flogin2;




	private: System::Windows::Forms::TextBox^  flogin1;
	private: System::Windows::Forms::TextBox^  commandPromptT;


	private: System::Windows::Forms::TextBox^  passwordPromptT;


	private: System::Windows::Forms::TextBox^  loginPromptT;


	private: System::Windows::Forms::Button^  Set_Params;



	private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  lFail1;

private: System::Windows::Forms::Label^  cPrompt;


	private: System::Windows::Forms::Label^  pPrompt;
	private: System::Windows::Forms::Label^  lPrompt;
	private: System::Windows::Forms::Label^  Config_Descript;
private: System::Windows::Forms::Label^  Config_Explain;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
private: System::Windows::Forms::Button^  Cancel_Async;









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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->Select_List = (gcnew System::Windows::Forms::Button());
			this->Verbose = (gcnew System::Windows::Forms::CheckBox());
			this->Pass_Word = (gcnew System::Windows::Forms::TextBox());
			this->User_ID = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->Telnet = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->Cancel_Async = (gcnew System::Windows::Forms::Button());
			this->Show_Failed = (gcnew System::Windows::Forms::Button());
			this->Exit_Bttn = (gcnew System::Windows::Forms::Button());
			this->Open_Log = (gcnew System::Windows::Forms::Button());
			this->Log_Output = (gcnew System::Windows::Forms::Button());
			this->Add_Failed = (gcnew System::Windows::Forms::Button());
			this->Clear_Output = (gcnew System::Windows::Forms::Button());
			this->ServerList = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->FailedServers = (gcnew System::Windows::Forms::ListBox());
			this->Command_Line = (gcnew System::Windows::Forms::TextBox());
			this->Run = (gcnew System::Windows::Forms::Button());
			this->systemCount = (gcnew System::Windows::Forms::Label());
			this->UserID = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Password = (gcnew System::Windows::Forms::Label());
			this->Command = (gcnew System::Windows::Forms::Label());
			this->OutPutWindow = (gcnew System::Windows::Forms::TextBox());
			this->Configure = (gcnew System::Windows::Forms::TabPage());
			this->Config_Explain = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lFail1 = (gcnew System::Windows::Forms::Label());
			this->cPrompt = (gcnew System::Windows::Forms::Label());
			this->pPrompt = (gcnew System::Windows::Forms::Label());
			this->lPrompt = (gcnew System::Windows::Forms::Label());
			this->Config_Descript = (gcnew System::Windows::Forms::Label());
			this->flogin2 = (gcnew System::Windows::Forms::TextBox());
			this->flogin1 = (gcnew System::Windows::Forms::TextBox());
			this->commandPromptT = (gcnew System::Windows::Forms::TextBox());
			this->passwordPromptT = (gcnew System::Windows::Forms::TextBox());
			this->loginPromptT = (gcnew System::Windows::Forms::TextBox());
			this->Set_Params = (gcnew System::Windows::Forms::Button());
			this->Info = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->tabControl1->SuspendLayout();
			this->Telnet->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->Configure->SuspendLayout();
			this->Info->SuspendLayout();
			this->SuspendLayout();
			// 
			// Select_List
			// 
			this->Select_List->Location = System::Drawing::Point(13, 49);
			this->Select_List->Name = L"Select_List";
			this->Select_List->Size = System::Drawing::Size(75, 23);
			this->Select_List->TabIndex = 1;
			this->Select_List->Text = L"Select List";
			this->Select_List->UseVisualStyleBackColor = true;
			this->Select_List->Click += gcnew System::EventHandler(this, &Form1::Select_List_Click);
			// 
			// Verbose
			// 
			this->Verbose->AutoSize = true;
			this->Verbose->Location = System::Drawing::Point(358, 10);
			this->Verbose->Name = L"Verbose";
			this->Verbose->Size = System::Drawing::Size(100, 17);
			this->Verbose->TabIndex = 7;
			this->Verbose->Text = L"Verbose Output";
			this->Verbose->UseVisualStyleBackColor = true;
			// 
			// Pass_Word
			// 
			this->Pass_Word->Location = System::Drawing::Point(12, 224);
			this->Pass_Word->Name = L"Pass_Word";
			this->Pass_Word->PasswordChar = '*';
			this->Pass_Word->Size = System::Drawing::Size(183, 20);
			this->Pass_Word->TabIndex = 3;
			// 
			// User_ID
			// 
			this->User_ID->Location = System::Drawing::Point(12, 139);
			this->User_ID->Name = L"User_ID";
			this->User_ID->Size = System::Drawing::Size(183, 20);
			this->User_ID->TabIndex = 2;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"Select a File";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->Telnet);
			this->tabControl1->Controls->Add(this->Configure);
			this->tabControl1->Controls->Add(this->Info);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(5, 5);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(942, 582);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::FillToRight;
			this->tabControl1->TabIndex = 5;
			// 
			// Telnet
			// 
			this->Telnet->BackColor = System::Drawing::Color::LightGray;
			this->Telnet->Controls->Add(this->splitContainer1);
			this->Telnet->Location = System::Drawing::Point(4, 22);
			this->Telnet->Name = L"Telnet";
			this->Telnet->Padding = System::Windows::Forms::Padding(10);
			this->Telnet->Size = System::Drawing::Size(934, 556);
			this->Telnet->TabIndex = 0;
			this->Telnet->Text = L"Telnet";
			// 
			// splitContainer1
			// 
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer1->IsSplitterFixed = true;
			this->splitContainer1->Location = System::Drawing::Point(10, 10);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->splitContainer1->Panel1->Controls->Add(this->Cancel_Async);
			this->splitContainer1->Panel1->Controls->Add(this->Show_Failed);
			this->splitContainer1->Panel1->Controls->Add(this->Exit_Bttn);
			this->splitContainer1->Panel1->Controls->Add(this->Open_Log);
			this->splitContainer1->Panel1->Controls->Add(this->Log_Output);
			this->splitContainer1->Panel1->Controls->Add(this->Add_Failed);
			this->splitContainer1->Panel1->Controls->Add(this->Clear_Output);
			this->splitContainer1->Panel1->Controls->Add(this->ServerList);
			this->splitContainer1->Panel1->Controls->Add(this->label2);
			this->splitContainer1->Panel1->Controls->Add(this->FailedServers);
			this->splitContainer1->Panel1->Controls->Add(this->Command_Line);
			this->splitContainer1->Panel1->Controls->Add(this->Select_List);
			this->splitContainer1->Panel1->Controls->Add(this->Verbose);
			this->splitContainer1->Panel1->Controls->Add(this->Pass_Word);
			this->splitContainer1->Panel1->Controls->Add(this->Run);
			this->splitContainer1->Panel1->Controls->Add(this->User_ID);
			this->splitContainer1->Panel1->Controls->Add(this->systemCount);
			this->splitContainer1->Panel1->Controls->Add(this->UserID);
			this->splitContainer1->Panel1->Controls->Add(this->label4);
			this->splitContainer1->Panel1->Controls->Add(this->Password);
			this->splitContainer1->Panel1->Controls->Add(this->Command);
			this->splitContainer1->Panel1->Margin = System::Windows::Forms::Padding(10);
			this->splitContainer1->Panel1->Padding = System::Windows::Forms::Padding(10);
			this->splitContainer1->Panel1MinSize = 200;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->splitContainer1->Panel2->Controls->Add(this->OutPutWindow);
			this->splitContainer1->Panel2->Margin = System::Windows::Forms::Padding(10);
			this->splitContainer1->Panel2->Padding = System::Windows::Forms::Padding(10);
			this->splitContainer1->Size = System::Drawing::Size(914, 536);
			this->splitContainer1->SplitterDistance = 470;
			this->splitContainer1->TabIndex = 17;
			// 
			// Cancel_Async
			// 
			this->Cancel_Async->Location = System::Drawing::Point(12, 473);
			this->Cancel_Async->Name = L"Cancel_Async";
			this->Cancel_Async->Size = System::Drawing::Size(75, 23);
			this->Cancel_Async->TabIndex = 23;
			this->Cancel_Async->Text = L"Cancel";
			this->Cancel_Async->UseVisualStyleBackColor = true;
			this->Cancel_Async->Click += gcnew System::EventHandler(this, &Form1::Cancel_Async_Click);
			// 
			// Show_Failed
			// 
			this->Show_Failed->Location = System::Drawing::Point(268, 473);
			this->Show_Failed->Name = L"Show_Failed";
			this->Show_Failed->Size = System::Drawing::Size(75, 23);
			this->Show_Failed->TabIndex = 22;
			this->Show_Failed->Text = L"Show Failed";
			this->Show_Failed->UseVisualStyleBackColor = true;
			this->Show_Failed->Click += gcnew System::EventHandler(this, &Form1::Show_Failed_Servers);
			// 
			// Exit_Bttn
			// 
			this->Exit_Bttn->Location = System::Drawing::Point(12, 502);
			this->Exit_Bttn->Name = L"Exit_Bttn";
			this->Exit_Bttn->Size = System::Drawing::Size(75, 23);
			this->Exit_Bttn->TabIndex = 21;
			this->Exit_Bttn->Text = L"Exit";
			this->Exit_Bttn->UseVisualStyleBackColor = true;
			this->Exit_Bttn->Click += gcnew System::EventHandler(this, &Form1::Exit_Bttn_Click);
			// 
			// Open_Log
			// 
			this->Open_Log->Location = System::Drawing::Point(358, 502);
			this->Open_Log->Name = L"Open_Log";
			this->Open_Log->Size = System::Drawing::Size(75, 23);
			this->Open_Log->TabIndex = 20;
			this->Open_Log->Text = L"Open Log";
			this->Open_Log->UseVisualStyleBackColor = true;
			this->Open_Log->Click += gcnew System::EventHandler(this, &Form1::Open_Log_Click);
			// 
			// Log_Output
			// 
			this->Log_Output->Location = System::Drawing::Point(358, 473);
			this->Log_Output->Name = L"Log_Output";
			this->Log_Output->Size = System::Drawing::Size(75, 23);
			this->Log_Output->TabIndex = 19;
			this->Log_Output->Text = L"Log Output";
			this->Log_Output->UseVisualStyleBackColor = true;
			this->Log_Output->Click += gcnew System::EventHandler(this, &Form1::Log_Output_Click);
			// 
			// Add_Failed
			// 
			this->Add_Failed->Location = System::Drawing::Point(268, 502);
			this->Add_Failed->Name = L"Add_Failed";
			this->Add_Failed->Size = System::Drawing::Size(75, 23);
			this->Add_Failed->TabIndex = 18;
			this->Add_Failed->Text = L"Add Failed";
			this->Add_Failed->UseVisualStyleBackColor = true;
			this->Add_Failed->Click += gcnew System::EventHandler(this, &Form1::Add_Failed_Click);
			// 
			// Clear_Output
			// 
			this->Clear_Output->Location = System::Drawing::Point(358, 444);
			this->Clear_Output->Name = L"Clear_Output";
			this->Clear_Output->Size = System::Drawing::Size(75, 23);
			this->Clear_Output->TabIndex = 17;
			this->Clear_Output->Text = L"Clear Output";
			this->Clear_Output->UseVisualStyleBackColor = true;
			this->Clear_Output->Click += gcnew System::EventHandler(this, &Form1::Clear_Output_Click);
			// 
			// ServerList
			// 
			this->ServerList->AllowDrop = true;
			this->ServerList->FormattingEnabled = true;
			this->ServerList->Location = System::Drawing::Point(268, 84);
			this->ServerList->Name = L"ServerList";
			this->ServerList->ScrollAlwaysVisible = true;
			this->ServerList->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->ServerList->Size = System::Drawing::Size(190, 199);
			this->ServerList->TabIndex = 14;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(9, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 20);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Telnet Batch Processor";
			// 
			// FailedServers
			// 
			this->FailedServers->FormattingEnabled = true;
			this->FailedServers->Location = System::Drawing::Point(308, 132);
			this->FailedServers->Name = L"FailedServers";
			this->FailedServers->Size = System::Drawing::Size(120, 108);
			this->FailedServers->TabIndex = 16;
			this->FailedServers->Visible = false;
			// 
			// Command_Line
			// 
			this->Command_Line->AcceptsReturn = true;
			this->Command_Line->AllowDrop = true;
			this->Command_Line->Location = System::Drawing::Point(12, 298);
			this->Command_Line->Multiline = true;
			this->Command_Line->Name = L"Command_Line";
			this->Command_Line->Size = System::Drawing::Size(446, 140);
			this->Command_Line->TabIndex = 5;
			this->Command_Line->WordWrap = false;
			// 
			// Run
			// 
			this->Run->Location = System::Drawing::Point(12, 444);
			this->Run->Name = L"Run";
			this->Run->Size = System::Drawing::Size(75, 23);
			this->Run->TabIndex = 6;
			this->Run->Text = L"Run";
			this->Run->UseVisualStyleBackColor = true;
			this->Run->Click += gcnew System::EventHandler(this, &Form1::Run_Click);
			// 
			// systemCount
			// 
			this->systemCount->AutoSize = true;
			this->systemCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->systemCount->Location = System::Drawing::Point(265, 55);
			this->systemCount->Name = L"systemCount";
			this->systemCount->Size = System::Drawing::Size(48, 17);
			this->systemCount->TabIndex = 12;
			this->systemCount->Text = L"count";
			// 
			// UserID
			// 
			this->UserID->AutoSize = true;
			this->UserID->Location = System::Drawing::Point(13, 123);
			this->UserID->Name = L"UserID";
			this->UserID->Size = System::Drawing::Size(40, 13);
			this->UserID->TabIndex = 8;
			this->UserID->Text = L"UserID";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(104, 57);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Number of systems to process: ";
			// 
			// Password
			// 
			this->Password->AutoSize = true;
			this->Password->Location = System::Drawing::Point(13, 208);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(53, 13);
			this->Password->TabIndex = 9;
			this->Password->Text = L"Password";
			// 
			// Command
			// 
			this->Command->AutoSize = true;
			this->Command->Location = System::Drawing::Point(13, 282);
			this->Command->Name = L"Command";
			this->Command->Size = System::Drawing::Size(54, 13);
			this->Command->TabIndex = 10;
			this->Command->Text = L"Command";
			// 
			// OutPutWindow
			// 
			this->OutPutWindow->AcceptsReturn = true;
			this->OutPutWindow->Dock = System::Windows::Forms::DockStyle::Fill;
			this->OutPutWindow->Location = System::Drawing::Point(10, 10);
			this->OutPutWindow->Margin = System::Windows::Forms::Padding(10);
			this->OutPutWindow->Multiline = true;
			this->OutPutWindow->Name = L"OutPutWindow";
			this->OutPutWindow->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->OutPutWindow->Size = System::Drawing::Size(418, 514);
			this->OutPutWindow->TabIndex = 8;
			this->OutPutWindow->Text = L"Process Output";
			// 
			// Configure
			// 
			this->Configure->BackColor = System::Drawing::Color::LightGray;
			this->Configure->Controls->Add(this->Config_Explain);
			this->Configure->Controls->Add(this->label9);
			this->Configure->Controls->Add(this->lFail1);
			this->Configure->Controls->Add(this->cPrompt);
			this->Configure->Controls->Add(this->pPrompt);
			this->Configure->Controls->Add(this->lPrompt);
			this->Configure->Controls->Add(this->Config_Descript);
			this->Configure->Controls->Add(this->flogin2);
			this->Configure->Controls->Add(this->flogin1);
			this->Configure->Controls->Add(this->commandPromptT);
			this->Configure->Controls->Add(this->passwordPromptT);
			this->Configure->Controls->Add(this->loginPromptT);
			this->Configure->Controls->Add(this->Set_Params);
			this->Configure->Location = System::Drawing::Point(4, 22);
			this->Configure->Name = L"Configure";
			this->Configure->Padding = System::Windows::Forms::Padding(3);
			this->Configure->Size = System::Drawing::Size(934, 556);
			this->Configure->TabIndex = 2;
			this->Configure->Text = L"Configure";
			// 
			// Config_Explain
			// 
			this->Config_Explain->AutoSize = true;
			this->Config_Explain->Location = System::Drawing::Point(24, 273);
			this->Config_Explain->Name = L"Config_Explain";
			this->Config_Explain->Size = System::Drawing::Size(410, 52);
			this->Config_Explain->TabIndex = 15;
			this->Config_Explain->Text = resources->GetString(L"Config_Explain.Text");
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(168, 189);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(73, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Failed Login 2";
			// 
			// lFail1
			// 
			this->lFail1->AutoSize = true;
			this->lFail1->Location = System::Drawing::Point(168, 163);
			this->lFail1->Name = L"lFail1";
			this->lFail1->Size = System::Drawing::Size(73, 13);
			this->lFail1->TabIndex = 13;
			this->lFail1->Text = L"Failed Login 1";
			// 
			// cPrompt
			// 
			this->cPrompt->AutoSize = true;
			this->cPrompt->Location = System::Drawing::Point(168, 139);
			this->cPrompt->Name = L"cPrompt";
			this->cPrompt->Size = System::Drawing::Size(90, 13);
			this->cPrompt->TabIndex = 12;
			this->cPrompt->Text = L"Command Prompt";
			// 
			// pPrompt
			// 
			this->pPrompt->AutoSize = true;
			this->pPrompt->Location = System::Drawing::Point(168, 113);
			this->pPrompt->Name = L"pPrompt";
			this->pPrompt->Size = System::Drawing::Size(89, 13);
			this->pPrompt->TabIndex = 11;
			this->pPrompt->Text = L"Password Prompt";
			// 
			// lPrompt
			// 
			this->lPrompt->AutoSize = true;
			this->lPrompt->Location = System::Drawing::Point(168, 87);
			this->lPrompt->Name = L"lPrompt";
			this->lPrompt->Size = System::Drawing::Size(69, 13);
			this->lPrompt->TabIndex = 10;
			this->lPrompt->Text = L"Login Prompt";
			// 
			// Config_Descript
			// 
			this->Config_Descript->AutoSize = true;
			this->Config_Descript->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Config_Descript->Location = System::Drawing::Point(20, 20);
			this->Config_Descript->Name = L"Config_Descript";
			this->Config_Descript->Size = System::Drawing::Size(270, 20);
			this->Config_Descript->TabIndex = 9;
			this->Config_Descript->Text = L"Recognition Characters / Strings";
			// 
			// flogin2
			// 
			this->flogin2->Location = System::Drawing::Point(272, 182);
			this->flogin2->Name = L"flogin2";
			this->flogin2->Size = System::Drawing::Size(152, 20);
			this->flogin2->TabIndex = 5;
			this->flogin2->Text = L"login incorrect";
			// 
			// flogin1
			// 
			this->flogin1->Location = System::Drawing::Point(272, 156);
			this->flogin1->Name = L"flogin1";
			this->flogin1->Size = System::Drawing::Size(152, 20);
			this->flogin1->TabIndex = 4;
			this->flogin1->Text = L"invalid login!";
			// 
			// commandPromptT
			// 
			this->commandPromptT->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->commandPromptT->Location = System::Drawing::Point(272, 130);
			this->commandPromptT->MaxLength = 1;
			this->commandPromptT->Name = L"commandPromptT";
			this->commandPromptT->Size = System::Drawing::Size(20, 22);
			this->commandPromptT->TabIndex = 3;
			this->commandPromptT->Text = L">";
			this->commandPromptT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// passwordPromptT
			// 
			this->passwordPromptT->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->passwordPromptT->Location = System::Drawing::Point(272, 104);
			this->passwordPromptT->MaxLength = 1;
			this->passwordPromptT->Name = L"passwordPromptT";
			this->passwordPromptT->Size = System::Drawing::Size(20, 22);
			this->passwordPromptT->TabIndex = 2;
			this->passwordPromptT->Text = L":";
			this->passwordPromptT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// loginPromptT
			// 
			this->loginPromptT->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->loginPromptT->Location = System::Drawing::Point(272, 78);
			this->loginPromptT->MaxLength = 1;
			this->loginPromptT->Name = L"loginPromptT";
			this->loginPromptT->Size = System::Drawing::Size(20, 22);
			this->loginPromptT->TabIndex = 1;
			this->loginPromptT->Text = L":";
			this->loginPromptT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Set_Params
			// 
			this->Set_Params->Location = System::Drawing::Point(171, 231);
			this->Set_Params->Name = L"Set_Params";
			this->Set_Params->Size = System::Drawing::Size(75, 23);
			this->Set_Params->TabIndex = 0;
			this->Set_Params->Text = L"Set";
			this->Set_Params->UseVisualStyleBackColor = true;
			this->Set_Params->Click += gcnew System::EventHandler(this, &Form1::Set_Params_Click);
			// 
			// Info
			// 
			this->Info->Controls->Add(this->label1);
			this->Info->Location = System::Drawing::Point(4, 22);
			this->Info->Name = L"Info";
			this->Info->Padding = System::Windows::Forms::Padding(3);
			this->Info->Size = System::Drawing::Size(934, 556);
			this->Info->TabIndex = 1;
			this->Info->Text = L"Info";
			this->Info->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 104);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Written by Scott Morton 5/2012\r\n\r\nVersion 2.1 Feb. 2013\r\n    Added background wor" 
				L"ker\r\n    Added configuration tab\r\n    Various minor enhancments\r\n\r\ncopyright Sco" 
				L"tt P. Morton 2013\r\n";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker1_RunWorkerCompleted);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(952, 592);
			this->Controls->Add(this->tabControl1);
			this->MinimumSize = System::Drawing::Size(968, 630);
			this->Name = L"Form1";
			this->Padding = System::Windows::Forms::Padding(5);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sys-Admins Friend v2.1";
			this->tabControl1->ResumeLayout(false);
			this->Telnet->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->Configure->ResumeLayout(false);
			this->Configure->PerformLayout();
			this->Info->ResumeLayout(false);
			this->Info->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Select_List_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

				ServerList->Items->Clear();
				
				int count=0;

				// Open a dialog to the file system
				if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					System::IO::StreamReader ^ sr = gcnew
					System::IO::StreamReader(openFileDialog1->FileName);
					String^ line;

					// read each line of the file
					while ((line = sr->ReadLine()) != nullptr)
					{
						// Skip blank lines
						if(line != "")
						{
							ServerList->Items->Add(line);
							++count;
						}
					}
				
					ServerList->EndUpdate();

					sr->Close();
				}
			
				systemCount->Text = Convert::ToString(count);
		
			 }

//	Runs the program
	private: System::Void Run_Click(System::Object^  /*sender*/, System::EventArgs^  /*e*/) {

				// Enable the Cancel button.
				Cancel_Async->Enabled = true;

				// Disable the Run button.
				Run->Enabled = false;
			

				 FailedServers->Items->Clear();
				
				// Basic requirements checking
				 if (User_ID->Text == "" || Pass_Word->Text == "")
				 {
					 MessageBox::Show("You must enter a userID and Password");
					 return;
				 }

				 if (Command_Line->Text == "")
				  {
					 // Initializes the variables to pass to the MessageBox::Show method.
					 String^ message = "You did not enter a command to process. Cancel this operation?";
					 String^ caption = "No Command Specified";
					 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
					 System::Windows::Forms::DialogResult result;

					 // Displays the MessageBox.
					 result = MessageBox::Show( this, message, caption, buttons );
					 if ( result == System::Windows::Forms::DialogResult::Yes )
					 {
						return;
					 }
				 }

				// Process the server list as a background worker
				 backgroundWorker1->RunWorkerAsync();
					


			 }

// This method actually performs the work and is called by the background worker
private: System::Void Process_Address( BackgroundWorker^ worker, DoWorkEventArgs ^ e )
		 {

				StreamWriter^ myStream;
			  				
			 	const int MAX_MSG_LENGTH = 4096;	// Max send message length
				const int MAX_RMSG_LENGTH = 1024;	// Max receive message length
				int x = 0, y = 0, i, rcv;			// Operating parameters
				String ^ msg;						// Contains the current message
				String ^ errormsg;					// Contains any error messages
				clock_t goal, waitTimer;			// Timer 

				// Creates the file stream for logging messages
				if (log)
				{
					myStream = gcnew StreamWriter( log_File,true,Encoding::ASCII );
				}

				// Loop through the server list
				for each(String^ ipAddr in ServerList->Items)
				{
					// Check to see if the background worker has been issued a cancel request
					if ( worker->CancellationPending )
					{
						e->Cancel = true;
					}

					// If not then process the next ipAddr in the list
					else
					{
			
						// Reset counters
						x = 0;
						y = 0;
	
						// Call method to present text in meesage window
						// Required because of background process
						this->SetText("\r\n\r\n" + "Processing server at : " + ipAddr);

						// Basic try/catch block
						try
						{
							// Open a socket and setup a connection to the this ipAddr
							Socket^ server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
							IPEndPoint^ iped = gcnew IPEndPoint(IPAddress::Parse(ipAddr), 23);
							server->Connect(iped);
							server->NoDelay = true;

							// Required type for receiving socket data
							array<unsigned char>^ rmsg = gcnew array<unsigned char>(MAX_RMSG_LENGTH);
							array<unsigned char>^ smsg = gcnew array<unsigned char>(MAX_MSG_LENGTH);

							// Clear the message buffers to a known value ( very important )
							for (i = 0; i < MAX_RMSG_LENGTH; ++i)
								rmsg[i] = 0;
							for (i = 0; i < MAX_MSG_LENGTH; ++i)
								smsg[i] = 0;

							// Loop until break
							// This loop establishes communication parameters between this application and the host
							while (true)
							{
							

								rcv = server->Receive(rmsg, MAX_RMSG_LENGTH, SocketFlags::None);
								
								// This is all RFC protocol establishing a session with echo, etc.
								if (Convert::ToByte(255) == rmsg[0])
								{
								
									while (rmsg[x] != 0 && x < MAX_RMSG_LENGTH)
									{
										++x;

										if (Convert::ToByte(253) == rmsg[x])
										{
											++x;
											if (Convert::ToByte(3) == rmsg[x])
											{
												smsg[y] = Convert::ToByte(255);
												++y;
												smsg[y] = Convert::ToByte(251);
												++y;
												smsg[y] = rmsg[x];
												++y;
											}
											else
											{
												smsg[y] = Convert::ToByte(255);
												++y;
												smsg[y] = Convert::ToByte(252);
												++y;
												smsg[y] = rmsg[x];
												++y;
											}
										}
									}

									if (y > 0)
									{
										server->Send(smsg, y, SocketFlags::None);
									}

									x = 0;
									y = 0;

									// After the send clean up for next message
									for (i = 0; i < MAX_RMSG_LENGTH; ++i)
										rmsg[i] = 0;
									for (i = 0; i < MAX_MSG_LENGTH; ++i)
										smsg[i] = 0;
								
								}

								else
									break;
							}
						
							// Recode the message into ewadable text
							msg = Encoding::ASCII->GetString(rmsg, 0, rcv);
						
							// read the system clock and add 6 seconds
							waitTimer = clock() + 60000;

							// Receive data from the host looking for loginPrompt character. Default is ':'
							while (msg->Length > 2 && !((msg[msg->Length - 2] == loginPrompt && msg[msg->Length-1] == ' ') || msg[msg->Length-1] == loginPrompt ))
							{
								// Oops, wrong parameter or host not responding
								// Waited more than 6 seconds
								if (waitTimer < clock())
									throw "Timeout error waiting on login prompt";
								goal = 100 + clock();

								// Give the host a chance to buffer data while we do nothing really fast
								while( goal > clock() )
									;

								// Check to see if data is available to process
								if (server->Available > 0)
								{
									rcv = server->Available;

									// if the data length is longer than the MAX then process only the max this round
									// This will leave the remaining data in the socket buffer for the next loop
									if (rcv > MAX_RMSG_LENGTH)
										rcv = MAX_RMSG_LENGTH;
									server->Receive(rmsg, rcv, SocketFlags::None);
									msg += Encoding::ASCII->GetString(rmsg, 0, rcv);

									// Reset the buffer for the next loop
									for (i = 0; i < MAX_RMSG_LENGTH; ++i)
										rmsg[i] = 0;
								}
							}

							// If verbose is checked then send to message box
							if (Verbose->Checked)
								this->SetText(msg);
							// If log is setup then output to log file
							if (log)
								this->SetText(msg);

							// Make sure the send buffer is clear
							for (i = 0; i < MAX_MSG_LENGTH; ++i)
								smsg[i] = 0;

							// Setup the send buffer with the next message to send ( userid )
							smsg = Encoding::ASCII->GetBytes(User_ID->Text + "\r\n");
						
							// Send the message ( userid )
							server->Send(smsg, smsg->Length, SocketFlags::None);
						
							// Set the messge box buffer to known state
							msg = "  ";

							// Wait for the host to send some data
							while (server->Available == 0)
								;

							// check for the amount of data received
							rcv = server->Available;

							// Setup to only process the max buffer size
							if (rcv > MAX_RMSG_LENGTH)
								rcv = MAX_RMSG_LENGTH;

							// While the socket contains data, process that data, same as before
							while ( rcv > 0 )
							{
								server->Receive(rmsg, rcv, SocketFlags::None);
								msg = msg + Encoding::ASCII->GetString(rmsg, 0, rcv);
								goal = 200 + clock();
								while( goal > clock() )
								;
								rcv = server->Available;
								if (rcv > MAX_RMSG_LENGTH)
									rcv = MAX_RMSG_LENGTH;
								for (i = 0; i < MAX_RMSG_LENGTH; ++i)
									rmsg[i] = 0;
							}

							// Wait another 6 seconds
							waitTimer = clock() + 60000;

							// Receive data from the host looking for passwordPrompt character. Default is ':'
							// All other is the same as prevous routine
							while ( !((msg[msg->Length - 2] == passwordPrompt && msg[msg->Length-1] == ' ') || msg[msg->Length-1] == passwordPrompt ))
							{
								if (waitTimer < clock())
									throw "Timeout error waiting on password prompt";
								goal = 100 + clock();
								while( goal > clock() )
								;
								if (server->Available > 0)
								{
									rcv = server->Available;
									if (rcv > MAX_RMSG_LENGTH)
										rcv = MAX_RMSG_LENGTH;
									server->Receive(rmsg, rcv, SocketFlags::None);
									msg += Encoding::ASCII->GetString(rmsg, 0, rcv);
									for (i = 0; i < MAX_RMSG_LENGTH; ++i)
										rmsg[i] = 0;
								}
							}

							// Same
							for (i = 0; i < MAX_RMSG_LENGTH; ++i)
								rmsg[i] = 0;

							// Same
							if (Verbose->Checked)
								this->SetText(msg);
							// Same
							if (log)
								this->SetText(msg);

							// Same
							smsg = Encoding::ASCII->GetBytes(Pass_Word->Text + "\r\n");
						
							// Same
							server->Send(smsg, smsg->Length, SocketFlags::None);

							msg = "  ";
							while (server->Available == 0);
							goal = 200 + clock();
							while( goal > clock() )
							;
							rcv = server->Available;
							if (rcv > MAX_RMSG_LENGTH)
								rcv = MAX_RMSG_LENGTH;

							while ( rcv > 0 )
							{
								server->Receive(rmsg, rcv, SocketFlags::None);
								msg = msg + Encoding::ASCII->GetString(rmsg, 0, rcv);
								// Sometimes password prompt takes extra time  to appear
								goal = 200 + clock();
								while( goal > clock() )
								;
								rcv = server->Available;
								if (rcv > MAX_RMSG_LENGTH)
									rcv = MAX_RMSG_LENGTH;
								for (i = 0; i < MAX_RMSG_LENGTH; ++i)
									rmsg[i] = 0;
							}

							waitTimer = clock() + 60000;

							// Wait for command prompt to appear. ( Default is > )
							// All else same as before
							while ( !((msg[msg->Length-2] == commandPrompt && msg[msg->Length-1] == ' ') || msg[msg->Length-1] == commandPrompt ))
							{
								if ( waitTimer < clock() )
									throw "Timeout waiting on command prompt";
								goal = 100 + clock();
								while( goal > clock() )
								;
								if (server->Available > 0)
								{
									rcv = server->Available;
									if (rcv > MAX_RMSG_LENGTH)
										rcv = MAX_RMSG_LENGTH;
									server->Receive(rmsg, rcv, SocketFlags::None);
									msg = msg + Encoding::ASCII->GetString(rmsg, 0, rcv);
									for (i = 0; i < MAX_RMSG_LENGTH; ++i)
										rmsg[i] = 0;
								}
								errormsg = msg->ToLower();
								if ( errormsg->Contains( loginFailed1 ) || errormsg->Contains( loginFailed2 ))
									throw "Invalid Login!";
							}

							if (Verbose->Checked)
								this->SetText(msg);
							if (log)
								this->SetText(msg);
						

							// This loop process each line in the command box
							// The basic functions are the same as the login functions
							// Send a command, wait for a response
							// Make sure you have processed all of the response before continuing
							for each (String^ line in Command_Line->Lines)
							{
								msg = "";
								smsg = Encoding::ASCII->GetBytes( line + "\r\n");
						
								server->Send(smsg, smsg->Length, SocketFlags::None);

								while (server->Available == 0);
								goal = 500 + clock();
								while( goal > clock() )
								;
								rcv = server->Available;
								if (rcv > MAX_RMSG_LENGTH)
									rcv = MAX_RMSG_LENGTH;

								while ( rcv > 0 )
								{
									server->Receive(rmsg, rcv, SocketFlags::None);
									msg += Encoding::ASCII->GetString(rmsg, 0, rcv);
									goal = 200 + clock();
									while( goal > clock() )
									;
									rcv = server->Available;
									if (rcv > MAX_RMSG_LENGTH)
										rcv = MAX_RMSG_LENGTH;
									for (i = 0; i < MAX_RMSG_LENGTH; ++i)
										rmsg[i] = 0;
								}
						
								while (!((msg[msg->Length-2] == commandPrompt && msg[msg->Length-1] == ' ') || msg[msg->Length-1] == commandPrompt))
								{
									goal = 100 + clock();
									while( goal > clock() )
									;
									if (server->Available > 0)
									{
										rcv = server->Available;
										if (rcv > MAX_RMSG_LENGTH)
											rcv = MAX_RMSG_LENGTH;
										server->Receive(rmsg, rcv, SocketFlags::None);
										msg = msg + Encoding::ASCII->GetString(rmsg, 0, rcv);
										for (i = 0; i < MAX_RMSG_LENGTH; ++i)
											rmsg[i] = 0;
									}
								}

								if (Verbose->Checked)
									this->SetText(msg);
								if (log)
									this->SetText(msg);

								for (i = 0; i < MAX_RMSG_LENGTH; ++i)
									rmsg[i] = 0;
							}						

							server->Shutdown(SocketShutdown::Both);
							server->Close();
							delete iped;
							delete server;

						}

						// Basic catch blocks
						catch ( char * str )
						{
							String^ message = gcnew String(str);
							if (Verbose->Checked)
								this->SetText("\r\n" + message + " for " + ipAddr);
							if (log)
								this->SetText("\r\n" + message + " for " + ipAddr);
							FailedServers->Items->Add(ipAddr);
						}
						catch ( Exception^ e ) 
						{
							if (Verbose->Checked)
							{
								this->SetText("\r\n" + e + "\r\nProcess Failed : " + ipAddr);
							if (log)
								this->SetText("\r\n" + e + "\r\nProcess Failed : " + ipAddr);
							}
							FailedServers->Items->Add(ipAddr);
						}

						catch(...)
						{
							if (Verbose->Checked)
								this->SetText("\r\nUnknown error\r\nUnable to process server : " + ipAddr);
							if (log)
								this->SetText("\r\nUnknown error\r\nUnable to process server : " + ipAddr);
							FailedServers->Items->Add(ipAddr);
						}
	
						this->SetText("\r\nCompleted processing for :" + ipAddr);
					}
				}
				
				// close the file stream
				if (log)
					myStream->Close();

				this->SetText("\r\n\r\n\r\nThe following servers failed to process :\r\n");

				// Display all failed addresses
				for each(String^ ipAddr in FailedServers->Items)
					this->SetText("\r\n" + ipAddr);

		 }

//	 This is a required method for using an parent object from a background worker
 private: System::Void SetText(String^ text)
        {
            // InvokeRequired required compares the thread ID of the 
            // calling thread to the thread ID of the creating thread. 
            // If these threads are different, it returns true. 
            if (this->OutPutWindow->InvokeRequired)
            {
                SetTextDelegate^ d = 
                    gcnew SetTextDelegate(this, &Form1::SetText);
                this->Invoke(d, gcnew array<Object^> { text });
            }
            else
            {
                this->OutPutWindow->AppendText(text);
            }
        }

// Clears the output window
private: System::Void Clear_Output_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 OutPutWindow->Clear();
		 }

// Adds the failed servers to the server list for reprocessing
private: System::Void Add_Failed_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ServerList->Items->Clear();

			 for each (String^ item in FailedServers->Items)
				ServerList->Items->Add(item);
		 }

// Sets up the file used for logging
private: System::Void Log_Output_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				log_File = saveFileDialog1->FileName;
				log = true;
				FileStream^ fs = gcnew FileStream( log_File, FileMode::Append, FileAccess::Write, FileShare::Write );
				fs->Close();
			 }
			 else
			 {
				 log_File = "";
				 log = false;
			 }
		 }

// Opens the logfile
private: System::Void Open_Log_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (log_File != "")
				Process::Start("notepad.exe", log_File);
			 else
				 OutPutWindow->AppendText("\r\nNo log file specified");
		 }

// Displays the failed server list
private: System::Void Show_Failed_Servers(System::Object^  sender, System::EventArgs^  e) 
		 {
				OutPutWindow->AppendText("\r\n\r\n\r\nThe following servers failed to process :\r\n");
				for each(String^ ipAddr in FailedServers->Items)
					OutPutWindow->AppendText("\r\n" + ipAddr);
		 }

// Exits the program .... duh
private: System::Void Exit_Bttn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Application::Exit();
		 }


// Calls set_params()
private: System::Void Set_Params_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 set_params();
		 }

// Sets the recognition characters and strings
private: void set_params()
		 {
			System::String ^str;
			size_t origsize = 2;
			const size_t newsize = 2;
			size_t convertedChars = 0;
			char nstring[newsize];

			str = loginPromptT->Text;
			pin_ptr<const wchar_t> wch = PtrToStringChars(str);
			wcstombs_s(&convertedChars, nstring, origsize, wch, _TRUNCATE);
			loginPrompt =  nstring[0];

			str = passwordPromptT->Text;
			pin_ptr<const wchar_t> wch2 = PtrToStringChars(str);
			wcstombs_s(&convertedChars, nstring, origsize, wch2, _TRUNCATE);
			passwordPrompt = nstring[0];

			str = commandPromptT->Text;
			pin_ptr<const wchar_t> wch3 = PtrToStringChars(str);
			wcstombs_s(&convertedChars, nstring, origsize, wch3, _TRUNCATE);
			commandPrompt = nstring[0];

			loginFailed1 = flogin1->Text;
			loginFailed2 = flogin2->Text;

		 }

// This is the background worker that will perform the actual work
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
		 {
			 // Get the BackgroundWorker that raised this event.
			 BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
			 
			 SA_Friend::Form1::Process_Address( worker, e);
		 }

// Cancels the background process
private: System::Void Cancel_Async_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			// Cancel the asynchronous operation. 
			this->backgroundWorker1->CancelAsync();

			// Disable the Cancel button.
			Cancel_Async->Enabled = false;
		 }

// Gets processed upon completion of the background process wheather failed, canceled or finished
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  /*sender*/, System::ComponentModel::RunWorkerCompletedEventArgs^  e) 
		 {
			// Enable the Run button.
			Run->Enabled = true;

			// Disable the Cancel button.
			Cancel_Async->Enabled = false;
		 }


};
}

