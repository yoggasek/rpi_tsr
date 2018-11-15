#include "dialog.h"
#include "ui_dialog.h"

using namespace cv;


Dialog::Dialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::Dialog)
{
	/*Mat src, dst;

	/// Load image
	src = imread("d.jpg",0);
	dst = imread("frame_118.jpg",0);
	

	/// Establish the number of bins
	int histSize = 256;
	
	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	const float* histRange = { range };
	Mat hist1, hist2;
	int const hist_height = 256;
	Mat3b hist_image = Mat3b::zeros(hist_height, 256);
	calcHist(&src, 1, 0, Mat(), hist1, 1, &histSize, &histRange, true, false);
	calcHist(&dst, 1, 0, Mat(), hist2, 1, &histSize, &histRange, true, false);
	normalize(hist1, hist1, 0, 1, NORM_MINMAX, -1, Mat());
	normalize(hist2, hist2, 0, 1, NORM_MINMAX, -1, Mat());
	double elo=compareHist(hist1, hist2, CV_COMP_BHATTACHARYYA);
	
	qDebug() << "%f" << elo;
	*/
	
	ui->setupUi(this);
	//d5.load("c5.xml");
	//d4.load("beka.xml");
	//d3.load("d-1.xml");
  //  d2.load("c12.xml");
	d1.load("nowka.xml");
	//d6.load("c4.xml");
	svm.load("eroz.xml");
	
	ui->wykrywanie_Button->setEnabled(false);
	ui->stop_Button->setEnabled(false);
	
	ui->display_screen->setScaledContents(true);

	ui->display_screen->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

	
}


/*void Dialog::on_browse_clicked()
{
	QFileDialog xml(this);
	xml.setNameFilter(tr("Cascade (*.xml)"));
	xml.setViewMode(QFileDialog::Detail);
	QString cascade = QFileDialog::getOpenFileName(this, tr("Open File"), "C: / ", tr("Cascade (*.xml)"));
	
	
	if (!cascade.isEmpty())
	{
		d1.load((cascade.toStdString()));
		QFileDialog lol(this);
		lol.setNameFilter(tr("SVM (*.xml)"));
		lol.setViewMode(QFileDialog::Detail);
		QString xml2 = QFileDialog::getOpenFileName(this, tr("Open File"), "C: / ", tr("SVM (*.xml)"));
		if (!xml2.isEmpty())
		{
			svm.load(xml2.toLatin1());
		}
	}
}*/


void Dialog::on_stop_Button_clicked()
{
	timer->stop();
	timer2->stop();
	counter = 0;
	capWebcam.release();
	image.release();
	ui->display_screen->clear();
	ui->kamera_Button->setEnabled(true);
	ui->zdjecie_Button->setEnabled(true);

	ui->wykrywanie_Button->setEnabled(false);
	ui->stop_Button->setEnabled(false);


}




void Dialog::on_zdjecie_Button_clicked()
{
	ui->tableWidget->clear();
	timer->stop();
	capWebcam.release();
	image.release();
	ui->display_screen->clear();
	
	
	
	QFileDialog dialog(this);
	dialog.setNameFilter(tr("Zdjêcie (*.jpg *.jpeg *.png *.bmp)"));
	dialog.setViewMode(QFileDialog::Detail);
	QString imagefileName = QFileDialog::getOpenFileName(this, tr("Open File"), "D:/inzynierka/test/znaki ", tr("Zdjêcie(*.jpg *.jpeg *.png *.bmp)"));
	
	if (!imagefileName.isEmpty())
	{
		QString napis = QString("%1").arg(QString::number(counter));
		image = imread(imagefileName.toStdString());
		int x = 0;
		image.copyTo(e);
		cv::cvtColor(image, image2, CV_BGR2GRAY);
		equalizeHist(image2, image2);
		d1.detectMultiScale(image2, znaki1, 1.1, 3, 0, Size(40, 40));
		//d2.detectMultiScale(image2, znaki2, 1.02, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
		//d3.detectMultiScale(image2, znaki3, 1.02, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
		//d4.detectMultiScale(image2, znaki4, 1.02, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
		//d5.detectMultiScale(image2, znaki5, 1.02, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
		//d6.detectMultiScale(image2, znaki, 1.02, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
		ui->tableWidget->setRowCount(10);
		ui->tableWidget->setColumnCount(3);
		
		
		for (size_t i = 0; i < znaki1.size(); i++)
		{
			Point pt1(znaki1[i].x + znaki1[i].width, znaki1[i].y + znaki1[i].height);
			Point pt2(znaki1[i].x, znaki1[i].y);
			rectangle(image, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
			frameROI1 = e(znaki1[i]);
			float erosion_size = 0.5;
			Mat element = getStructuringElement(MORPH_RECT,
				Size(2 * erosion_size + 1, 2 * erosion_size + 1),
				Point(erosion_size, erosion_size));
			medianBlur(frameROI1, frameROI1, 3);
			threshold(frameROI1, frameROI1, 120, 120, THRESH_BINARY);
			erode(frameROI1, frameROI1, element);
			
			
			imwrite("chuj.jpg", frameROI1);
			//namedWindow("",CV_WINDOW_NORMAL);
			//imshow("", frameROI1);
			
			
			//int result1 = svm_predict(frameROI1);
			cv::cvtColor(frameROI1, frameROI1, CV_BGR2RGB);
			
			//	if ((result1 < 6) || (result1 > 6))
			//	{

					QImage qimg((uchar*)frameROI1.data, frameROI1.cols, frameROI1.rows, frameROI1.step, QImage::Format_RGB888);


			QTableWidgetItem *svmr = new QTableWidgetItem;
			QTableWidgetItem *numer_klatki = new QTableWidgetItem;
			QTableWidgetItem *item = new QTableWidgetItem;
			item->setData(Qt::DecorationRole, QPixmap::fromImage(qimg).scaled(100, 100));
			numer_klatki->setData(0, QString::number(x));
			numer_klatki->setTextAlignment(Qt::AlignCenter);
			ui->tableWidget->setItem(x, 0, numer_klatki);

/*
			switch (result1)
			{
			case 1:
				svmr->setData(Qt::DecorationRole, QPixmap("5.jpg").scaled(100, 100));
				break;
			case 2:
				svmr->setData(Qt::DecorationRole, QPixmap("10.jpg").scaled(100, 100));
				break;
			case 3:
				svmr->setData(Qt::DecorationRole, QPixmap("20.jpg").scaled(100, 100));
				break;
			case 4:
				svmr->setData(Qt::DecorationRole, QPixmap("30.jpg").scaled(100, 100));
				break;
			case 5:
				svmr->setData(Qt::DecorationRole, QPixmap("40.jpg").scaled(100, 100));
				break;
			case 6:
				svmr->setData(Qt::DecorationRole, QPixmap("50.jpg").scaled(100, 100));
				break;
			case 7:
				svmr->setData(Qt::DecorationRole, QPixmap("60.jpg").scaled(100, 100));
				break;
			case 8:
				svmr->setData(Qt::DecorationRole, QPixmap("70.jpg").scaled(100, 100));
				break;
			case 9:
				svmr->setData(Qt::DecorationRole, QPixmap("80.jpg").scaled(100, 100));
				break;
			case -1:
				svmr->setData(Qt::DecorationRole, QPixmap("90.jpg").scaled(100, 100));
				break;
			case -2:
				svmr->setData(Qt::DecorationRole, QPixmap("100.jpg").scaled(100, 100));
				break;
			case -3:
				svmr->setData(Qt::DecorationRole, QPixmap("110.jpg").scaled(100, 100));
				break;
			case -4:
				svmr->setData(Qt::DecorationRole, QPixmap("120.jpg").scaled(100, 100));
				break;

			default:
				break;
			}*/

			svmr->setTextAlignment(Qt::AlignCenter);
			ui->tableWidget->setItem(x, 2, svmr);

			ui->tableWidget->setItem(x, 1, item);
			ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
			ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
			x++;

			//}

		}/*
		for (size_t i = 0; i < znaki2.size(); i++)
		{
			Point pt1(znaki2[i].x + znaki2[i].width, znaki2[i].y + znaki2[i].height);
			Point pt2(znaki2[i].x, znaki2[i].y);
			frameROI2 = e(znaki2[i]);
			rectangle(image, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);


			cvtColor(frameROI2, frameROI2, CV_BGR2RGB);
			int result2 = svm_predict(frameROI2);
			if ((result2 < 6) || (result2 > 6))
			{

				QImage qimg((uchar*)frameROI2.data, frameROI2.cols, frameROI2.rows, frameROI2.step, QImage::Format_RGB888);


				QTableWidgetItem *svmr = new QTableWidgetItem;
				QTableWidgetItem *numer_klatki = new QTableWidgetItem;
				QTableWidgetItem *item = new QTableWidgetItem;
				item->setData(Qt::DecorationRole, QPixmap::fromImage(qimg).scaled(100, 100));
				numer_klatki->setData(0, QString::number(x));
				numer_klatki->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 0, numer_klatki);


				switch (result2)
				{
				case 1:
					svmr->setData(Qt::DecorationRole, QPixmap("c-2.jpg").scaled(100, 100));
					break;
				case 2:
					svmr->setData(Qt::DecorationRole, QPixmap("c-4.jpg").scaled(100, 100));
					break;
				case 3:
					svmr->setData(Qt::DecorationRole, QPixmap("c-5.jpg").scaled(100, 100));
					break;
				case 4:
					svmr->setData(Qt::DecorationRole, QPixmap("c-1.jpg").scaled(100, 100));
					break;
				case 5:
					svmr->setData(Qt::DecorationRole, QPixmap("c-3.jpg").scaled(100, 100));
					break;
				case 7:
					svmr->setData(Qt::DecorationRole, QPixmap("c-12.jpg").scaled(100, 100));
					break;
				case 8:
					svmr->setData(Qt::DecorationRole, QPixmap("d1.jpg").scaled(100, 100));
					break;
				case 9:
					svmr->setData(Qt::DecorationRole, QPixmap("d6.jpg").scaled(100, 100));
					break;
				default:
					break;
				}

				svmr->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 2, svmr);

				ui->tableWidget->setItem(x, 1, item);
				ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				x++;
			}
		}



		for (size_t i = 0; i < znaki3.size(); i++)
		{
			Point pt1(znaki3[i].x + znaki3[i].width, znaki3[i].y + znaki3[i].height);
			Point pt2(znaki3[i].x, znaki3[i].y);
			frameROI3 = e(znaki3[i]);
			cvtColor(frameROI3, frameROI3, CV_BGR2RGB);
			int result3 = svm_predict(frameROI3);
			rectangle(image, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
			if ((result3 < 6) || (result3 > 6))
			{

				QImage qimg((uchar*)frameROI3.data, frameROI3.cols, frameROI3.rows, frameROI3.step, QImage::Format_RGB888);


				QTableWidgetItem *svmr = new QTableWidgetItem;
				QTableWidgetItem *numer_klatki = new QTableWidgetItem;
				QTableWidgetItem *item = new QTableWidgetItem;
				item->setData(Qt::DecorationRole, QPixmap::fromImage(qimg).scaled(100, 100));
				numer_klatki->setData(0, QString::number(x));
				numer_klatki->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 0, numer_klatki);


				switch (result3)
				{
				case 1:
					svmr->setData(Qt::DecorationRole, QPixmap("c-2.jpg").scaled(100, 100));
					break;
				case 2:
					svmr->setData(Qt::DecorationRole, QPixmap("c-4.jpg").scaled(100, 100));
					break;
				case 3:
					svmr->setData(Qt::DecorationRole, QPixmap("c-5.jpg").scaled(100, 100));
					break;
				case 4:
					svmr->setData(Qt::DecorationRole, QPixmap("c-1.jpg").scaled(100, 100));
					break;
				case 5:
					svmr->setData(Qt::DecorationRole, QPixmap("c-3.jpg").scaled(100, 100));
					break;
				case 7:
					svmr->setData(Qt::DecorationRole, QPixmap("c-12.jpg").scaled(100, 100));
					break;
				case 8:
					svmr->setData(Qt::DecorationRole, QPixmap("d1.jpg").scaled(100, 100));
					QSound::play("d1.wav");
					
					break;
				case 9:
					svmr->setData(Qt::DecorationRole, QPixmap("d6.jpg").scaled(100, 100));
					break;
				default:
					break;
				}

				svmr->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 2, svmr);

				ui->tableWidget->setItem(x, 1, item);
				ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				x++;
			}
		}


		for (size_t i = 0; i < znaki.size(); i++)
		{
			Point pt1(znaki[i].x + znaki[i].width, znaki[i].y + znaki[i].height);
			Point pt2(znaki[i].x, znaki[i].y);
			frameROI = e(znaki[i]);
			cvtColor(frameROI, frameROI, CV_BGR2RGB);
			int result = svm_predict(frameROI);
			rectangle(image, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
			if ((result < 6) || (result > 6))
			{

				QImage qimg((uchar*)frameROI.data, frameROI.cols, frameROI.rows, frameROI.step, QImage::Format_RGB888);


				QTableWidgetItem *svmr = new QTableWidgetItem;
				QTableWidgetItem *numer_klatki = new QTableWidgetItem;
				QTableWidgetItem *item = new QTableWidgetItem;
				item->setData(Qt::DecorationRole, QPixmap::fromImage(qimg).scaled(100, 100));
				numer_klatki->setData(0, QString::number(x));
				numer_klatki->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 0, numer_klatki);


				switch (result)
				{
				case 1:
					svmr->setData(Qt::DecorationRole, QPixmap("c-2.jpg").scaled(100, 100));
					break;
				case 2:
					svmr->setData(Qt::DecorationRole, QPixmap("c-4.jpg").scaled(100, 100));
					break;
				case 3:
					svmr->setData(Qt::DecorationRole, QPixmap("c-5.jpg").scaled(100, 100));
					break;
				case 4:
					svmr->setData(Qt::DecorationRole, QPixmap("c-1.jpg").scaled(100, 100));
					break;
				case 5:
					svmr->setData(Qt::DecorationRole, QPixmap("c-3.jpg").scaled(100, 100));
					break;
				case 7:
					svmr->setData(Qt::DecorationRole, QPixmap("c-12.jpg").scaled(100, 100));
					break;
				case 8:
					svmr->setData(Qt::DecorationRole, QPixmap("d1.jpg").scaled(100, 100));
					break;
				case 9:
					svmr->setData(Qt::DecorationRole, QPixmap("d6.jpg").scaled(100, 100));
					break;
				default:
					break;
				}

				svmr->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 2, svmr);

				ui->tableWidget->setItem(x, 1, item);
				ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				x++;
			}
		}




		for (size_t i = 0; i < znaki4.size(); i++)
		{
			Point pt1(znaki4[i].x + znaki4[i].width, znaki4[i].y + znaki4[i].height);
			Point pt2(znaki4[i].x, znaki4[i].y);
			frameROI4 = e(znaki4[i]);
			cvtColor(frameROI4, frameROI4, CV_BGR2RGB);
			int result4 = svm_predict(frameROI4);
			string lol = to_string(i) + ".jpg";

			imwrite(lol, frameROI4);
			
			qDebug() << "wynik" << result4;
			rectangle(image, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
			if ((result4 < 6) || (result4 > 6))
			{

				QImage qimg((uchar*)frameROI4.data, frameROI4.cols, frameROI4.rows, frameROI4.step, QImage::Format_RGB888);


				QTableWidgetItem *svmr = new QTableWidgetItem;
				QTableWidgetItem *numer_klatki = new QTableWidgetItem;
				QTableWidgetItem *item = new QTableWidgetItem;
				item->setData(Qt::DecorationRole, QPixmap::fromImage(qimg).scaled(100, 100));
				numer_klatki->setData(0, QString::number(x));
				numer_klatki->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 0, numer_klatki);


				switch (result4)
				{
				case 1:
					svmr->setData(Qt::DecorationRole, QPixmap("c-2.jpg").scaled(100, 100));
					break;
				case 2:
					svmr->setData(Qt::DecorationRole, QPixmap("c-4.jpg").scaled(100, 100));
					break;
				case 3:
					svmr->setData(Qt::DecorationRole, QPixmap("c-5.jpg").scaled(100, 100));
					break;
				case 4:
					svmr->setData(Qt::DecorationRole, QPixmap("c-1.jpg").scaled(100, 100));
					break;
				case 5:
					svmr->setData(Qt::DecorationRole, QPixmap("c-3.jpg").scaled(100, 100));
					break;
				case 7:
					svmr->setData(Qt::DecorationRole, QPixmap("c-12.jpg").scaled(100, 100));
					break;
				case 8:
					svmr->setData(Qt::DecorationRole, QPixmap("d1.jpg").scaled(100, 100));
					break;
				case 9:
					svmr->setData(Qt::DecorationRole, QPixmap("d6.jpg").scaled(100, 100));
					QSound::play("d6.wav");
					break;
				default:
					break;
				}

				svmr->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 2, svmr);

				ui->tableWidget->setItem(x, 1, item);
				ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				x++;
				
			}
		}


		for (size_t i = 0; i < znaki5.size(); i++)
		{
			Point pt1(znaki5[i].x + znaki5[i].width, znaki5[i].y + znaki5[i].height);
			Point pt2(znaki5[i].x, znaki5[i].y);
			frameROI5 = e(znaki5[i]);
			cvtColor(frameROI5, frameROI5, CV_BGR2RGB);
			int result5 = svm_predict(frameROI5);
			rectangle(image, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
			if ((result5 < 6) || (result5> 6))
			{

				QImage qimg((uchar*)frameROI5.data, frameROI5.cols, frameROI5.rows, frameROI5.step, QImage::Format_RGB888);


				QTableWidgetItem *svmr = new QTableWidgetItem;
				QTableWidgetItem *numer_klatki = new QTableWidgetItem;
				QTableWidgetItem *item = new QTableWidgetItem;
				item->setData(Qt::DecorationRole, QPixmap::fromImage(qimg).scaled(100, 100));
				numer_klatki->setData(0, QString::number(x));
				numer_klatki->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 0, numer_klatki);


				switch (result5)
				{
				case 1:
					svmr->setData(Qt::DecorationRole, QPixmap("c-2.jpg").scaled(100, 100));
					break;
				case 2:
					svmr->setData(Qt::DecorationRole, QPixmap("c-4.jpg").scaled(100, 100));
					break;
				case 3:
					svmr->setData(Qt::DecorationRole, QPixmap("c-5.jpg").scaled(100, 100));
					break;
				case 4:
					svmr->setData(Qt::DecorationRole, QPixmap("c-1.jpg").scaled(100, 100));
					break;
				case 5:
					svmr->setData(Qt::DecorationRole, QPixmap("c-3.jpg").scaled(100, 100));
					break;
				case 7:
					svmr->setData(Qt::DecorationRole, QPixmap("c-12.jpg").scaled(100, 100));
					break;
				case 8:
					svmr->setData(Qt::DecorationRole, QPixmap("d1.jpg").scaled(100, 100));
					break;
				case 9:
					svmr->setData(Qt::DecorationRole, QPixmap("d6.jpg").scaled(100, 100));
					break;
				default:
					break;
				}

				svmr->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 2, svmr);

				ui->tableWidget->setItem(x, 1, item);
				ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				x++;
			}
		}*/
		
		
		cvtColor(image, image, CV_BGR2RGB);
		QImage zdjecie((uchar*)image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
		ui->display_screen->setPixmap(QPixmap::fromImage(zdjecie));


		ui->wykrywanie_Button->setEnabled(false);
		ui->stop_Button->setEnabled(false);
	}
}

void Dialog::on_kamera_Button_clicked()
{
	
	image.release();
	ui->display_screen->clear();
	
	ui->tableWidget->clear();



	capWebcam.open(0);
	if (capWebcam.isOpened() == false) {
		QMessageBox::critical(this, tr("B³¹d"), tr("brak kamerki"));
		return;
	}

	ui->wykrywanie_Button->setEnabled(true);
	ui->stop_Button->setEnabled(true);


		
	connect(timer, SIGNAL(timeout()), this, SLOT(kamerka()));
	timer->start(100);

		
		
	
		
	
}



void Dialog::on_wykrywanie_Button_clicked()
{
	
	
	connect(timer2, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));

	timer2->start(500);

	
	//processFrameAndUpdateGUI();
}


Dialog::~Dialog()
{
	delete ui;
}

