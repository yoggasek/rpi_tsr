#ifndef DIALOG_H
#define DIALOG_H
#include <opencv2\core\core.hpp>
#include <QDialog>
#include <QImage>
#include <qtimer.h>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include "opencv2/opencv.hpp"
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\objdetect\objdetect.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <opencv2\ml.hpp>
#include <QtCore>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <QTableWidget>





using namespace cv;
using namespace std;

namespace Ui {
	class Dialog;
}

class Dialog : public QDialog
{
	Q_OBJECT

	public :
	    explicit Dialog(QWidget *parent = 0);
	~Dialog();
	

private:
	
	
	CvSVM svm;
	CascadeClassifier d2, d1, d3, d4, d5, d6;
	vector<Rect>znaki1, znaki2, znaki3, znaki4, znaki5, znaki;
	QTimer *timer = new QTimer;
	QTimer *timer2 = new QTimer;
	QTimer *timer3 = new QTimer;
	Mat e;
	Mat image2, image3, image4, image1, image5;
	Mat frameROI, frameROI1, frameROI2, frameROI3, frameROI4, frameROI5;
	Mat image;
	int counter = 0;
	Mat sign;
	Mat frame;
	bool state;
	QImage dest;
	VideoCapture capWebcam;
	Ui::Dialog *ui;
	private slots :
	QImage Mat3b2QImage(Mat3b src);
	void on_stop_Button_clicked();
	void on_zdjecie_Button_clicked();
	void on_kamera_Button_clicked();
	void on_film_Button_clicked();
	void on_wykrywanie_Button_clicked();
	void processFrameAndUpdateGUI();
	
	//void on_browse_clicked();
	//void getframeROI();
	void numberofframes();
	void kamerka();
	int svm_predict(Mat &image);
	
};

#endif // DIALOG_H
