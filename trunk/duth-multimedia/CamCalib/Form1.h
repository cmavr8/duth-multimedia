#pragma once
#include "cv.h"
#include "highgui.h"
#include <time.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <msclr\marshal.h>
#include <vector>


namespace CamCalib {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace std;

	
	void mouseHandlerr(int event,int x,int y,int flags,void* param);
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public: static Form1 ^ myptr; //Static pointer to point at Form1
	public:
		Form1(void) //Constructor
		{
			InitializeComponent();
			myptr = this; //Save this object to my pointer
		}
		int n_boards;  //Number of snapshots of the chessboard
		int frame_step;   //Frames to be skipped
		int board_w;   //Enclosed corners horizontally on the chessboard
		int board_h;   //Enclosed corners vertically on the chessboard
		int width,height;//Width and height of camera

	private: System::Windows::Forms::TextBox^  fx;
	public: 
	private: System::Windows::Forms::TextBox^  fy;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtcy;

	private: System::Windows::Forms::TextBox^  txtcx;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	public: System::Windows::Forms::TextBox^  txtY;
	public: System::Windows::Forms::TextBox^  txtX;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	public: System::Windows::Forms::TextBox^  txtZ;
	private: System::Windows::Forms::Label^  label10;
	public: 
	public: System::Windows::Forms::TextBox^  txtv;
	private: 
	public: System::Windows::Forms::TextBox^  txtu;
	private: System::Windows::Forms::Label^  label11;
	public: 
	private: System::Windows::Forms::Label^  label12;
	public: System::Windows::Forms::TextBox^  txtheight;
	private: 
	public: System::Windows::Forms::TextBox^  txtwidth;
	private: System::Windows::Forms::Label^  label13;
	public: 
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  status;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label22;
	public: System::Windows::Forms::TextBox^  Scale;

	private: System::Windows::Forms::GroupBox^  groupBox2;
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
	public: delegate void MyDel(int event,int x,int y,int flags,void* param);
	public: static Form1 ^ Tracking_var = gcnew Form1();
	private: System::Windows::Forms::Button^  Transform;	
	private: System::Windows::Forms::Button^  Calibrate;
	public: System::Windows::Forms::TextBox^  NoOfFrames;
	public: System::Windows::Forms::TextBox^  FramesToSkip;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	protected: 
	// Returns a managed array of Double.
	#define ARRAY_SIZE 4
	public: array<Double, 2>^ Test1() {
	   int i, j;
	array< Double,2 >^ local = gcnew array< Double,2 >(ARRAY_SIZE, ARRAY_SIZE);
	   for (i = 0 ; i < ARRAY_SIZE ; i++)
			 for (j = 0 ; j < ARRAY_SIZE ; j++)				
				 local[i,j] = i + 10;
	   return local;
	}
	array< Double, 2 >^ rt; //Declare rotation-translation array
	array< Double, 2 >^ a; //Declare intrinsic array
			
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
			this->Calibrate = (gcnew System::Windows::Forms::Button());
			this->NoOfFrames = (gcnew System::Windows::Forms::TextBox());
			this->FramesToSkip = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Transform = (gcnew System::Windows::Forms::Button());
			this->fx = (gcnew System::Windows::Forms::TextBox());
			this->fy = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtcy = (gcnew System::Windows::Forms::TextBox());
			this->txtcx = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtY = (gcnew System::Windows::Forms::TextBox());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtZ = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtv = (gcnew System::Windows::Forms::TextBox());
			this->txtu = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->txtheight = (gcnew System::Windows::Forms::TextBox());
			this->txtwidth = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Scale = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->status = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Calibrate
			// 
			this->Calibrate->Location = System::Drawing::Point(228, 44);
			this->Calibrate->Name = L"Calibrate";
			this->Calibrate->Size = System::Drawing::Size(123, 69);
			this->Calibrate->TabIndex = 0;
			this->Calibrate->Text = L"Calibrate camera and save results to file";
			this->Calibrate->UseVisualStyleBackColor = true;
			this->Calibrate->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// NoOfFrames
			// 
			this->NoOfFrames->Location = System::Drawing::Point(123, 41);
			this->NoOfFrames->Name = L"NoOfFrames";
			this->NoOfFrames->Size = System::Drawing::Size(41, 20);
			this->NoOfFrames->TabIndex = 1;
			this->NoOfFrames->Text = L"20";
			this->NoOfFrames->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->NoOfFrames->TextChanged += gcnew System::EventHandler(this, &Form1::NoOfFrames_TextChanged);
			// 
			// FramesToSkip
			// 
			this->FramesToSkip->Location = System::Drawing::Point(123, 93);
			this->FramesToSkip->Name = L"FramesToSkip";
			this->FramesToSkip->Size = System::Drawing::Size(41, 20);
			this->FramesToSkip->TabIndex = 2;
			this->FramesToSkip->Text = L"15";
			this->FramesToSkip->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(590, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"fx:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Snapshots to take:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 96);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Frames to skip:";
			// 
			// Transform
			// 
			this->Transform->Location = System::Drawing::Point(35, 60);
			this->Transform->Name = L"Transform";
			this->Transform->Size = System::Drawing::Size(129, 68);
			this->Transform->TabIndex = 7;
			this->Transform->Text = L"Load data from file and transform realtime capture";
			this->Transform->UseVisualStyleBackColor = true;
			this->Transform->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// fx
			// 
			this->fx->Location = System::Drawing::Point(629, 37);
			this->fx->Name = L"fx";
			this->fx->ReadOnly = true;
			this->fx->Size = System::Drawing::Size(77, 20);
			this->fx->TabIndex = 8;
			// 
			// fy
			// 
			this->fy->Location = System::Drawing::Point(629, 63);
			this->fy->Name = L"fy";
			this->fy->ReadOnly = true;
			this->fy->Size = System::Drawing::Size(77, 20);
			this->fy->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(590, 66);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(18, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"fy:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(590, 118);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(21, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"cy:";
			// 
			// txtcy
			// 
			this->txtcy->Location = System::Drawing::Point(629, 115);
			this->txtcy->Name = L"txtcy";
			this->txtcy->ReadOnly = true;
			this->txtcy->Size = System::Drawing::Size(77, 20);
			this->txtcy->TabIndex = 13;
			// 
			// txtcx
			// 
			this->txtcx->Location = System::Drawing::Point(629, 89);
			this->txtcx->Name = L"txtcx";
			this->txtcx->ReadOnly = true;
			this->txtcx->Size = System::Drawing::Size(77, 20);
			this->txtcx->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(590, 92);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"cx:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(578, 85);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(17, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Y:";
			// 
			// txtY
			// 
			this->txtY->Location = System::Drawing::Point(617, 82);
			this->txtY->Name = L"txtY";
			this->txtY->ReadOnly = true;
			this->txtY->Size = System::Drawing::Size(77, 20);
			this->txtY->TabIndex = 17;
			// 
			// txtX
			// 
			this->txtX->Location = System::Drawing::Point(617, 56);
			this->txtX->Name = L"txtX";
			this->txtX->ReadOnly = true;
			this->txtX->Size = System::Drawing::Size(77, 20);
			this->txtX->TabIndex = 16;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(578, 59);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"X:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(578, 111);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 13);
			this->label9->TabIndex = 20;
			this->label9->Text = L"Z:";
			// 
			// txtZ
			// 
			this->txtZ->Location = System::Drawing::Point(617, 108);
			this->txtZ->Name = L"txtZ";
			this->txtZ->ReadOnly = true;
			this->txtZ->Size = System::Drawing::Size(77, 20);
			this->txtZ->TabIndex = 19;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(314, 85);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(16, 13);
			this->label10->TabIndex = 24;
			this->label10->Text = L"v:";
			// 
			// txtv
			// 
			this->txtv->Location = System::Drawing::Point(341, 82);
			this->txtv->Name = L"txtv";
			this->txtv->ReadOnly = true;
			this->txtv->Size = System::Drawing::Size(39, 20);
			this->txtv->TabIndex = 23;
			// 
			// txtu
			// 
			this->txtu->Location = System::Drawing::Point(341, 56);
			this->txtu->Name = L"txtu";
			this->txtu->ReadOnly = true;
			this->txtu->Size = System::Drawing::Size(39, 20);
			this->txtu->TabIndex = 22;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(314, 59);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(16, 13);
			this->label11->TabIndex = 21;
			this->label11->Text = L"u:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(420, 88);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(39, 13);
			this->label12->TabIndex = 28;
			this->label12->Text = L"height:";
			// 
			// txtheight
			// 
			this->txtheight->Location = System::Drawing::Point(465, 85);
			this->txtheight->Name = L"txtheight";
			this->txtheight->ReadOnly = true;
			this->txtheight->Size = System::Drawing::Size(38, 20);
			this->txtheight->TabIndex = 27;
			// 
			// txtwidth
			// 
			this->txtwidth->Location = System::Drawing::Point(465, 59);
			this->txtwidth->Name = L"txtwidth";
			this->txtwidth->ReadOnly = true;
			this->txtwidth->Size = System::Drawing::Size(38, 20);
			this->txtwidth->TabIndex = 26;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(420, 62);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(35, 13);
			this->label13->TabIndex = 25;
			this->label13->Text = L"width:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(509, 63);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(18, 13);
			this->label14->TabIndex = 29;
			this->label14->Text = L"px";
			this->label14->Click += gcnew System::EventHandler(this, &Form1::label14_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(509, 89);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(18, 13);
			this->label15->TabIndex = 30;
			this->label15->Text = L"px";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label19);
			this->groupBox1->Controls->Add(this->label18);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->txtheight);
			this->groupBox1->Controls->Add(this->txtwidth);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->txtcy);
			this->groupBox1->Controls->Add(this->txtcx);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->fy);
			this->groupBox1->Controls->Add(this->fx);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->FramesToSkip);
			this->groupBox1->Controls->Add(this->NoOfFrames);
			this->groupBox1->Controls->Add(this->Calibrate);
			this->groupBox1->Location = System::Drawing::Point(6, 19);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(736, 158);
			this->groupBox1->TabIndex = 31;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Step 1: Camera Calibration";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(573, 16);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(157, 13);
			this->label19->TabIndex = 32;
			this->label19->Text = L"Focal length and principal point:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(420, 37);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(60, 13);
			this->label18->TabIndex = 31;
			this->label18->Text = L"Image size:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Scale);
			this->groupBox2->Controls->Add(this->label22);
			this->groupBox2->Controls->Add(this->label21);
			this->groupBox2->Controls->Add(this->label20);
			this->groupBox2->Controls->Add(this->label16);
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->txtv);
			this->groupBox2->Controls->Add(this->txtu);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->txtZ);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->txtY);
			this->groupBox2->Controls->Add(this->txtX);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->Transform);
			this->groupBox2->Location = System::Drawing::Point(6, 222);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(736, 182);
			this->groupBox2->TabIndex = 32;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Step 2: Realtime Image Correction";
			// 
			// Scale
			// 
			this->Scale->Location = System::Drawing::Point(373, 133);
			this->Scale->Name = L"Scale";
			this->Scale->Size = System::Drawing::Size(39, 20);
			this->Scale->TabIndex = 36;
			this->Scale->Text = L"1.0";
			this->Scale->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(289, 136);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(78, 13);
			this->label22->TabIndex = 35;
			this->label22->Text = L"Scaling Factor:";
			this->label22->Click += gcnew System::EventHandler(this, &Form1::label22_Click);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(566, 40);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(164, 13);
			this->label21->TabIndex = 34;
			this->label21->Text = L"Corresponding world coordinates:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(289, 40);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(139, 13);
			this->label20->TabIndex = 33;
			this->label20->Text = L"Projected point coordinates:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(386, 85);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(18, 13);
			this->label16->TabIndex = 32;
			this->label16->Text = L"px";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(386, 59);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(18, 13);
			this->label17->TabIndex = 31;
			this->label17->Text = L"px";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->status});
			this->statusStrip1->Location = System::Drawing::Point(0, 407);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(748, 22);
			this->statusStrip1->TabIndex = 33;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// status
			// 
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(39, 17);
			this->status->Text = L"Ready";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 429);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Calibration Button:
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->status->Text = "Calibrating camera...";
			 CvCapture* capture;

			 n_boards = System::Int32::Parse(this->NoOfFrames->Text);
			 frame_step = System::Int32::Parse(this->FramesToSkip->Text);

			 board_w  = 9;
			 board_h  = 6;
   
			 int board_total  = board_w * board_h;          //Total enclosed corners on the board
			 CvSize board_sz = cvSize( board_w, board_h );
 
			 capture = cvCreateCameraCapture( 0 );
			 
			 width = (int) cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH);
 			 this->txtwidth->Text = width+""; //Set image width to interface
			 height = (int) cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT);
 			 this->txtheight->Text = height+""; //Set image height to interface

			 //Open two windows
			 cvNamedWindow( "Snapshot" );
			 cvNamedWindow( "Raw Video");
 
			 //Allocate storage for the parameters according to total number of 
			 //corners and number of snapshots
			 CvMat* image_points      = cvCreateMat(n_boards*board_total,2,CV_32FC1);
			 CvMat* object_points     = cvCreateMat(n_boards*board_total,3,CV_32FC1);
			 CvMat* point_counts      = cvCreateMat(n_boards,1,CV_32SC1);
			 CvMat* intrinsic_matrix  = cvCreateMat(3,3,CV_32FC1);
			 CvMat* distortion_coeffs = cvCreateMat(4,1,CV_32FC1);
 
 
 
			 CvPoint2D32f* corners = new CvPoint2D32f[ board_total ];
			 int corner_count;
			 int successes = 0;
			 int step, frame = 0;
 
			 IplImage *image = cvQueryFrame( capture );
			 IplImage *gray_image = cvCreateImage(cvGetSize(image),8,1);    //subpixel
 
			 //Loop while successful captures equals total snapshots
			 //Successful captures implies when all the enclosed corners 
			 //are detected from a snapshot
 
			 while(successes < n_boards)     
			 {
			  char c = cvWaitKey(33); //delay
			  if((frame++ % frame_step) == 0)                             
							//Skip frames
			  {
			   //Find chessboard corners:
			   int found = cvFindChessboardCorners(image,board_sz, corners,&corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS );
			   cvCvtColor(image, gray_image, CV_BGR2GRAY);                  
			   //Get Subpixel accuracy on those corners
			   cvFindCornerSubPix(gray_image, corners, corner_count, cvSize(11,11),cvSize(-1,-1), cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));
			   cvDrawChessboardCorners(image, board_sz, corners, corner_count, found);  //Draw it
    
			   // If we got a good board, add it to our data
			   if(corner_count == board_total) 
			   {
				cvShowImage( "Snapshot", image );            
											//show in color if we did collect the image
				step = successes*board_total;
				for( int i=step, j=0; j<board_total; ++i,++j ) {
				CV_MAT_ELEM(*image_points, float,i,0) = corners[j].x;
				CV_MAT_ELEM(*image_points, float,i,1) = corners[j].y;
				CV_MAT_ELEM(*object_points,float,i,0) = (float) j/board_w;
				CV_MAT_ELEM(*object_points,float,i,1) = (float) (j%board_w);
				CV_MAT_ELEM(*object_points,float,i,2) = 0.0f;
			   }
			   CV_MAT_ELEM(*point_counts, int,successes,0) = board_total;    
			   successes++;
			
			   }
			   else cvShowImage( "Snapshot", gray_image ); //Show Gray if we didn't collect the image
			  } 
   
			  //Handle pause/unpause and ESC
			  int ch = cvWaitKey(15);
			  if(ch == 'p')
			  {  
			   ch = 0;
			   while(ch != 'p' && ch != 27)
			   {
				ch = cvWaitKey(250);
			   }
			  }
			  if(ch == 27)
			   break;
			  image = cvQueryFrame( capture );      //Get next image  
			  cvShowImage("Raw Video", image);
			 } 
 
			 //End WHILE loop with enough successful captures
			 cvDestroyWindow("Snapshot");
			 cvDestroyWindow("Raw Video");
	  
			 //Allocate matrices according to successful number of captures
			 CvMat* object_points2  = cvCreateMat(successes*board_total,3,CV_32FC1);
			 CvMat* image_points2   = cvCreateMat(successes*board_total,2,CV_32FC1);
			 CvMat* point_counts2   = cvCreateMat(successes,1,CV_32SC1);
 
			 //Tranfer the points to matrices
			 for(int i = 0; i<successes*board_total; ++i)
			 {
				  CV_MAT_ELEM( *image_points2, float, i, 0) = CV_MAT_ELEM( *image_points, float, i, 0);
				  CV_MAT_ELEM( *image_points2, float,i,1)   = CV_MAT_ELEM( *image_points, float, i, 1);
				  CV_MAT_ELEM(*object_points2, float, i, 0) = CV_MAT_ELEM( *object_points, float, i, 0) ;
				  CV_MAT_ELEM( *object_points2, float, i, 1)= CV_MAT_ELEM( *object_points, float, i, 1) ;
				  CV_MAT_ELEM( *object_points2, float, i, 2)= CV_MAT_ELEM( *object_points, float, i, 2) ;
			 } 
  
			 for(int i=0; i<successes; ++i)
			 { 
				  CV_MAT_ELEM( *point_counts2, int, i, 0)= CV_MAT_ELEM( *point_counts, int, i, 0);   
			 }
			 cvReleaseMat(&object_points);
			 cvReleaseMat(&image_points);
			 cvReleaseMat(&point_counts);
 
			 // Initialize the intrinsic matrix with both the two focal lengths in a ratio of 1.0
			 CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0f;
			 CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0f;
 
			 //Calibrate the camera
			   
			 cvCalibrateCamera2(object_points2, image_points2, point_counts2,  
									   cvGetSize( image ), 
									   intrinsic_matrix, distortion_coeffs, NULL, NULL,0 );
                              
			 //Save calculated values to files
			 cvSave("Intrinsics.xml",intrinsic_matrix);
			 cvSave("Distortion.xml",distortion_coeffs);
			 cvSave("ObjectPoints2.xml",object_points2);
			 cvSave("ImagePoints2.xml",image_points2);

			 //Update interface textboxes:
			 this->status->Text = "Ready";
			 this->fx->Text = cvGetReal2D(intrinsic_matrix, 0, 0)+"";
			 this->fy->Text = cvGetReal2D(intrinsic_matrix, 1, 1)+"";
			 this->txtcx->Text = cvGetReal2D(intrinsic_matrix, 0, 2)+"";
			 this->txtcy->Text = cvGetReal2D(intrinsic_matrix, 1, 2)+"";
		};
				
	//Button that starts corrected display:
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {	
			 this->status->Text = "Corrected display running...";
			 //Load the matrices from the respective files
			 CvMat *intrinsic = (CvMat*)cvLoad("Intrinsics.xml");
			 CvMat *distortion = (CvMat*)cvLoad("Distortion.xml");
			 CvMat *object_points2 = (CvMat*)cvLoad("ObjectPoints2.xml");
			 CvMat *image_points2 = (CvMat*)cvLoad("ImagePoints2.xml");
			 CvMat* rvec = cvCreateMat(3,1,CV_32FC1); //3x1 matrix to store rotation vector
			 CvMat* rvec2 = cvCreateMat(3,3,CV_32FC1); //3x3 matrix to store rotation array
			 CvMat* tvec = cvCreateMat(3,1,CV_32FC1); //3x1 matrix to store translation vector
 
			//Find Extrinsic parameters:
			cvFindExtrinsicCameraParams2(object_points2,image_points2, intrinsic, distortion, rvec, tvec, 0);
			cvRodrigues2(rvec,rvec2); //Convert rotation vector to rotation array
			
			 rt = Test1(); //Create  rotation-translation array
			 a = Test1();

			//Parse R matrix into rt
			for (int i=0;i<=2;i++){
				for (int j=0; j<=2;j++){
					rt[i,j] = cvGetReal2D(rvec2, i, j);
				}
			}

			//parse T matrix into rt
			for (int i=0;i<=2; i++){
				rt[i,3] = cvGetReal2D(tvec,  i, 0);		
			} 

			//copy intrisic_matrix to a
			for (int i=0;i<=2;i++){
				for (int j=0; j<=2;j++){
					a[i,j] = cvGetReal2D(intrinsic, i, j);
				}
			}

			
			this->fx->Text = a[0,0]+"";
			this->fy->Text = a[1,1]+"";
			this->txtcx->Text = a[0,2]+"";
			this->txtcy->Text = a[1,2]+"";
			

			 // Build the undistort map used for all subsequent frames.
			  CvCapture* capture;
			 capture = cvCreateCameraCapture( 0 );
			 IplImage *image = cvQueryFrame( capture );
			 IplImage* mapx = cvCreateImage( cvGetSize(image), IPL_DEPTH_32F, 1 );
			 IplImage* mapy = cvCreateImage( cvGetSize(image), IPL_DEPTH_32F, 1 );
			 cvInitUndistortMap(intrinsic,distortion,mapx,mapy);
 
			 // Run the camera to the screen, showing the raw and the undistorted image.
			 cvNamedWindow( "Undistort" );
			 cvNamedWindow( "Raw Video" );
			 while(image) 
			 {
			  cvWaitKey(33); //delay
			  IplImage *t = cvCloneImage(image);
			  cvShowImage( "Raw Video", image );  // Show raw image
			  cvRemap( t, image, mapx, mapy );  // Undistort image
			  cvReleaseImage(&t);

			  //Draw grid:
			  CvPoint x,y; //2d Grid Co-ordinate variables
				x.x=0;
				x.y=0;
				y.x=width;
				y.y=0;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );//Draws top Border Line
				x.x=0;
				x.y=0;
				y.x=0;
				y.y=height;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );//Draws Left Hand Border Line
				x.x=319;
				x.y=0;
				y.x=width;
				y.y=height;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );//Draws Right Hand Border Line
				x.x=0;
				x.y=height;
				y.x=width;
				y.y=height;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );//Draws Top Border Line
				//1st horizontal line:
				x.x=0;
				x.y=height/3;
				y.x = width;
				y.y = height/3;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );
				//2nd horizontal line:
				x.x=0;
				x.y=2*height/3;
				y.x = width;
				y.y = 2*height/3;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );
				//1st vertical line:
				x.x=width/3;
				x.y=0;
				y.x = width/3;
				y.y = height;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );
				//2nd vertical line:
				x.x=2*width/3;
				x.y=0;
				y.x = 2*width/3;
				y.y = height;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );
	
			  cvShowImage("Undistort", image);  // Show corrected image

			  //Catch and print mouse clicks:
			  int mouseParam=5; // parameter for mouse events
			  cvSetMouseCallback( "Undistort", mouseHandlerr, &mouseParam);
		
			  //Handle pause/unpause and ESC
			  int c = cvWaitKey(15);
			  if(c == 'p'){ 
				   c = 0;
				   while(c != 'p' && c != 27){
						c = cvWaitKey(250);
				   }
			  }
			  if(c == 27)
			   break;
			  cvShowImage("Undistort", image);  // Show corrected image
			  image = cvQueryFrame( capture );
			 }
			this->status->Text = "Ready";
		}
						 
			 
private: System::Void NoOfFrames_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void label14_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label22_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
}; //Form1 object ends here


void mouseHandlerr(int event,int u,int v,int flags,void* param){
	double X, Y, Z, S;
	
	switch( event ){
	case CV_EVENT_LBUTTONDOWN:		
		Form1::myptr->txtu->Text = u+""; //Show u coordinate (captured from mouse) to GUI
		Form1::myptr->txtv->Text = v+""; //Show u coordinate (captured from mouse) to GUI
		
//TODO what is that:?
		//Form1::myptr->FramesToSkip->Text = Form1::myptr->rt[0,0]+""+Form1::myptr->rt[0,1]+Form1::myptr->rt[0,2]+Form1::myptr->rt[1,0];
		S = System::Double::Parse(Form1::myptr->Scale->Text); //Get scale factor
		//Do the math:
		X = -(S*Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,2] - S*Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,1] - S*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,1]*Form1::myptr->rt[2,2] + S*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,2]*Form1::myptr->rt[2,1] + S*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,2] - S*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,1] - S*Form1::myptr->a[1,1]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,2]*u + S*Form1::myptr->a[1,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,1]*u + S*Form1::myptr->a[0,0]*Form1::myptr->rt[0,1]*Form1::myptr->rt[2,2]*v - S*Form1::myptr->a[0,0]*Form1::myptr->rt[0,2]*Form1::myptr->rt[2,1]*v + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,3] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,3]*Form1::myptr->rt[2,2] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,3] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,3]*Form1::myptr->rt[2,1] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,3]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,2] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,3]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,1])/(Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,2] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,1] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,2] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,0] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,1] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,0] + 2*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,1]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,2] - 2*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,1] - 2*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,2] + 2*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,1]);
		Y = (S*Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,2] - S*Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,0] - S*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,0]*Form1::myptr->rt[2,2] + S*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,2]*Form1::myptr->rt[2,0] + S*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,2] - S*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,0] - S*Form1::myptr->a[1,1]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,2]*u - S*Form1::myptr->a[1,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,0]*u + 2*S*Form1::myptr->a[1,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,2]*u + S*Form1::myptr->a[0,0]*Form1::myptr->rt[0,0]*Form1::myptr->rt[2,2]*v + S*Form1::myptr->a[0,0]*Form1::myptr->rt[0,2]*Form1::myptr->rt[2,0]*v - 2*S*Form1::myptr->a[0,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,2]*v + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,3] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,3]*Form1::myptr->rt[2,2] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,3] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,3]*Form1::myptr->rt[2,0] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,3]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,2] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,3]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,0] + 2*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,3] - 2*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,3]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,2] - 2*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,3] + 2*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,3]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,2])/(Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,2] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,1] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,2] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,0] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,1] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,0] + 2*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,1]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,2] - 2*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,1] - 2*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,2] + 2*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,1]);
		Z = -(S*Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,1] - S*Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,0] - S*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,0]*Form1::myptr->rt[2,1] + S*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,1]*Form1::myptr->rt[2,0] + S*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,1] - S*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,0] - S*Form1::myptr->a[1,1]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,1]*u - S*Form1::myptr->a[1,1]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,0]*u + 2*S*Form1::myptr->a[1,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,1]*u + S*Form1::myptr->a[0,0]*Form1::myptr->rt[0,0]*Form1::myptr->rt[2,1]*v + S*Form1::myptr->a[0,0]*Form1::myptr->rt[0,1]*Form1::myptr->rt[2,0]*v - 2*S*Form1::myptr->a[0,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,1]*v + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,3] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,3]*Form1::myptr->rt[2,1] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,3] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,3]*Form1::myptr->rt[2,0] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,3]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,1] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,3]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,0] + 2*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,1]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,3] - 2*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,3]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,1] - 2*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,3] + 2*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,3]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,1])/(Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,2] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,0]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,1] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,2] - Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,0] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,0]*Form1::myptr->rt[2,1] + Form1::myptr->a[0,0]*Form1::myptr->a[1,1]*Form1::myptr->rt[0,2]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,0] + 2*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,1]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,2] - 2*Form1::myptr->a[0,0]*Form1::myptr->a[1,2]*Form1::myptr->rt[0,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,1] - 2*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,1]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,2] + 2*Form1::myptr->a[0,2]*Form1::myptr->a[1,1]*Form1::myptr->rt[1,2]*Form1::myptr->rt[2,0]*Form1::myptr->rt[2,1]);

		Form1::myptr->txtX->Text = X+""; //Show X coordinate (calculated) to GUI
		Form1::myptr->txtY->Text = Y+""; //Show X coordinate (calculated) to GUI
		Form1::myptr->txtZ->Text = Z+""; //Show X coordinate (calculated) to GUI

		break;

	case CV_EVENT_RBUTTONDOWN:
		break;

	case CV_EVENT_FLAG_CTRLKEY:
		break;
	}
} //Mousehandler ends here

}

