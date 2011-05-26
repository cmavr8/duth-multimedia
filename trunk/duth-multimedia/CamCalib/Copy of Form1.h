#pragma once
#include "cv.h"
#include "highgui.h"
#include <time.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <msclr\marshal.h>


namespace CamCalib {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}
		int n_boards;  //Number of snapshots of the chessboard
		int frame_step;   //Frames to be skipped
		int board_w;   //Enclosed corners horizontally on the chessboard

	public: 
		int board_h;   //Enclosed corners vertically on the chessboard
	//	double rt[3][4];//To save R and T matrices (all together)
	//	double a[3][3];

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
	private: System::Windows::Forms::Button^  Transform;	
	private: System::Windows::Forms::Button^  Calibrate;
	private: System::Windows::Forms::TextBox^  NoOfFrames;
	private: System::Windows::Forms::TextBox^  FramesToSkip;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
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
			this->Calibrate = (gcnew System::Windows::Forms::Button());
			this->NoOfFrames = (gcnew System::Windows::Forms::TextBox());
			this->FramesToSkip = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Transform = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Calibrate
			// 
			this->Calibrate->Location = System::Drawing::Point(61, 118);
			this->Calibrate->Name = L"Calibrate";
			this->Calibrate->Size = System::Drawing::Size(64, 36);
			this->Calibrate->TabIndex = 0;
			this->Calibrate->Text = L"Calibrate";
			this->Calibrate->UseVisualStyleBackColor = true;
			this->Calibrate->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// NoOfFrames
			// 
			this->NoOfFrames->Location = System::Drawing::Point(32, 29);
			this->NoOfFrames->Name = L"NoOfFrames";
			this->NoOfFrames->Size = System::Drawing::Size(107, 20);
			this->NoOfFrames->TabIndex = 1;
			this->NoOfFrames->Text = L"20";
			this->NoOfFrames->TextChanged += gcnew System::EventHandler(this, &Form1::NoOfFrames_TextChanged);
			// 
			// FramesToSkip
			// 
			this->FramesToSkip->Location = System::Drawing::Point(32, 74);
			this->FramesToSkip->Name = L"FramesToSkip";
			this->FramesToSkip->Size = System::Drawing::Size(106, 20);
			this->FramesToSkip->TabIndex = 2;
			this->FramesToSkip->Text = L"2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(438, 318);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"X:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"X:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"X:";
			// 
			// Transform
			// 
			this->Transform->Location = System::Drawing::Point(58, 208);
			this->Transform->Name = L"Transform";
			this->Transform->Size = System::Drawing::Size(67, 37);
			this->Transform->TabIndex = 7;
			this->Transform->Text = L"Transform";
			this->Transform->UseVisualStyleBackColor = true;
			this->Transform->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(830, 429);
			this->Controls->Add(this->Transform);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->FramesToSkip);
			this->Controls->Add(this->NoOfFrames);
			this->Controls->Add(this->Calibrate);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 CvCapture* capture;

			 n_boards = System::Int32::Parse(this->NoOfFrames->Text);
			 frame_step = System::Int32::Parse(this->FramesToSkip->Text);

			 board_w  = 9;
			 board_h  = 6;
   
			 int board_total  = board_w * board_h;          //Total enclosed corners on the board
			 CvSize board_sz = cvSize( board_w, board_h );
 
			 capture = cvCreateCameraCapture( 0 );
			 if(!capture) 
			 { 
		//	  printf("\nCouldn't open the camera\n"); 
		//	  return -1;
			 }
 
			 cvNamedWindow( "Snapshot" );
			 cvNamedWindow( "Raw Video");
 
			 //Allocate storage for the parameters according to total number of 
					//corners and number of snapshots
			 CvMat* image_points      = cvCreateMat(n_boards*board_total,2,CV_32FC1);
			 CvMat* object_points     = cvCreateMat(n_boards*board_total,3,CV_32FC1);
			 CvMat* point_counts      = cvCreateMat(n_boards,1,CV_32SC1);
			 CvMat* intrinsic_matrix  = cvCreateMat(3,3,CV_32FC1);
			 CvMat* distortion_coeffs = cvCreateMat(4,1,CV_32FC1);
 
			 //Note:
			 //Intrinsic Matrix - 3x3 (aka a matrix") Lens Distorstion Matrix - 4x1
			 // [fx 0 cx]              [k1 k2 p1 p2   k3(optional)]
			 // [0 fy cy]
			 // [0  0  1]
 
 
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
			   int found = cvFindChessboardCorners(image, 
												 board_sz, corners,&corner_count,
										   CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS );
 
			   cvCvtColor(image, gray_image, CV_BGR2GRAY);           
                         
									//Get Subpixel accuracy on those corners
			   cvFindCornerSubPix(gray_image, corners, corner_count, 
														 cvSize(11,11),cvSize(-1,-1), 
										   cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));
 
			   cvDrawChessboardCorners(image, board_sz, corners, corner_count, found);   
									//Draw it
    
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
			//   printf("\r%d successful Snapshots out of %d collected.",successes,n_boards);
			   }
			   else
			   cvShowImage( "Snapshot", gray_image );          
									//Show Gray if we didn't collect the image
			   
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
 
			  image = cvQueryFrame( capture );        
							//Get next image
			  cvShowImage("Raw Video", image);
			 } 
 
			 //End WHILE loop with enough successful captures
 
			 cvDestroyWindow("Snapshot");
			 cvDestroyWindow("Raw Video");
	//		 printf("\n\n *** Calibrating the camera now...\n");
  
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
						 //These are all the same number
			 }
			 cvReleaseMat(&object_points);
			 cvReleaseMat(&image_points);
			 cvReleaseMat(&point_counts);
 
			 // Initialize the intrinsic matrix with both the two focal lengths in a ratio of 1.0
 
			 CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0f;
			 CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0f;
 
			 //Calibrate the camera
			 //______________________________________________________
  
			 cvCalibrateCamera2(object_points2, image_points2, point_counts2,  
									   cvGetSize( image ), 
									   intrinsic_matrix, distortion_coeffs, NULL, NULL,0 );
                              
			 cvSave("Intrinsics.xml",intrinsic_matrix);
			 cvSave("Distortion.xml",distortion_coeffs);
			 cvSave("ObjectPoints2.xml",object_points2);
			 cvSave("ImagePoints2.xml",image_points2);



			 
			


		};


		
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {

				
			 //Sample: load the matrices from the file
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
			double test = cvGetReal2D(rvec2, 0, 0);
/*			//Parse R matrix into rt
			for (int i=0;i<=2;i++){
				for (int j=0; j<=2;j++){
					rt[i][j] = cvGetReal2D(rvec2, i, j);
				}
			}
			//parse T matrix into rt
			for (int i=0;i<=2; i++){
				rt[i][3] = cvGetReal2D(tvec,  i, 0);		
			} 


			//copy intrisic_matrix to a

			for (int i=0;i<=2;i++){
				for (int j=0; j<=2;j++){
					a[i][j] = cvGetReal2D(intrinsic_matrix, i, j);
				}
			}

*/



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

			  //TODO: Draw grid here
			  //PASTE CODE HERE

			  //Draw grid:
			  CvPoint x,y; //2d Grid Co-ordinate variables
			  int length,height;
			  length = 319;
			  height = 239;

				x.x=0;
				x.y=0;
				y.x=320;
				y.y=0;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );//Draws top Border Line

				x.x=0;
				x.y=0;
				y.x=0;
				y.y=240;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );//Draws Left Hand Border Line

				x.x=319;
				x.y=0;
				y.x=319;
				y.y=240;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );//Draws Right Hand Border Line

				x.x=0;
				x.y=239;
				y.x=320;
				y.y=239;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );//Draws Top Border Line


				//1st horizontal line:
				x.x=0;
				x.y=height/3;
				y.x = length;
				y.y = height/3;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );
				//2nd horizontal line:
				x.x=0;
				x.y=2*height/3;
				y.x = length;
				y.y = 2*height/3;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );

				//1st vertical line:
				x.x=length/3;
				x.y=0;
				y.x = length/3;
				y.y = height;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );
				//2nd vertical line:
				x.x=2*length/3;
				x.y=0;
				y.x = 2*length/3;
				y.y = height;
				cvLine(image,x,y,CV_RGB(255,0,0),1, 8 );
	
			  cvShowImage("Undistort", image);  // Show corrected image


			  //Catch and print mouse clicks:
			  int mouseParam=5; // parameter for mouse events
			  
				CamCalib::Form1 ^ a = gcnew CamCalib::Form1;
				MyDel ^ StaticDelInst = gcnew MyDel(a,&CamCalib::Form1::mouseHandlerr);
		//	  cvSetMouseCallback( "Undistort", &CamCalib::Form1::mouseHandlerr, &mouseParam);
			  cvSetMouseCallback( "Undistort", gcnew Form1(this,&CamCalib::Form1::mouseHandlerr), &mouseParam);

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
		}
						 
			 
private: System::Void NoOfFrames_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
		 /*
	// function prototype for mouse handler
	public: System::Void mouseHandler(int event,int x,int y,int flags,void* param)
	{
		double X, Y, Z;
	//IplImage* image = (IplImage*) param;
		switch( event ){
			case CV_EVENT_LBUTTONDOWN:
				//printf("LBUTTONDOWN\n");
			//	printf("x: %i y: %i\n", x, y);

				ProjectTo3D(x, y, X, Y, Z);
				// printf (

				break;

			case CV_EVENT_RBUTTONDOWN:
			//	printf("RBUTTONDOWN\n");
				break;

			case CV_EVENT_FLAG_CTRLKEY:
			//	printf("FLAG_LBUTTONDBLCLK\n");
				break;
		}
}*/

public: System::Void mouseHandlerr(int event,int x,int y,int flags,void* param){
		double X, Y, Z;
		switch( event ){
		case CV_EVENT_LBUTTONDOWN:
			//printf("LBUTTONDOWN\n");
		//	printf("x: %i y: %i\n", x, y);

		//	ProjectTo3D(x, y, X, Y, Z);
			// printf (

			break;

		case CV_EVENT_RBUTTONDOWN:
		//	printf("RBUTTONDOWN\n");
			break;

		case CV_EVENT_FLAG_CTRLKEY:
		//	printf("FLAG_LBUTTONDBLCLK\n");
			break;
	}
				 }

};
}

