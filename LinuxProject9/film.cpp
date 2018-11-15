#include "dialog.h"
#include "ui_dialog.h"

QImage Dialog::Mat3b2QImage(Mat3b src)
{
	QImage dest(src.cols, src.rows, QImage::Format_ARGB32);
	for (int y = 0; y < src.rows; ++y) {
		const cv::Vec3b *srcrow = src[y];
		QRgb *destrow = (QRgb*)dest.scanLine(y);
		for (int x = 0; x < src.cols; ++x) {
			destrow[x] = qRgba(srcrow[x][2], srcrow[x][1], srcrow[x][0], 255);
		}
	}
	return dest;
}

void Dialog::on_film_Button_clicked()
{
	ui->kamera_Button->setEnabled(false);
	ui->zdjecie_Button->setEnabled(false);
	ui->tableWidget->clear();
	timer->stop();
	capWebcam.release();
	ui->display_screen->clear();
	image.release();

	QFileDialog dialog(this);
	dialog.setNameFilter(tr("Videos (*.mp4 *.avi *.mpeg)"));
	dialog.setViewMode(QFileDialog::Detail);
	QString videofileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C: / ", tr("Videos(*.mp4 *.avi *.mpeg)"));



	if (!videofileName.isEmpty())
	{
		
		String videopath;
		videopath = videofileName.toLocal8Bit().constData();

		bool playVideo = true;
		VideoCapture cap(videopath);
		if (!cap.isOpened())
		{
			QMessageBox::warning(this, tr("Warning"), tr("Error loadeing video."));
			exit(0);
		}

		ui->wykrywanie_Button->setEnabled(true);
		ui->stop_Button->setEnabled(true);


		while (1)
		{

			if (playVideo)
				cap >> image;
			cvtColor(image, image, CV_BGR2RGB);
			//Mat3b src = image;
			QImage dest((uchar*)image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);

			//dest = Mat3b2QImage(src); //To convert Mat3b to QImage

			ui->display_screen->setPixmap(QPixmap::fromImage(dest));

			ui->display_screen->setScaledContents(true);

			ui->display_screen->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
			QApplication::processEvents();
			
			counter++;
			numberofframes();
			if (image.empty())
			{
				//QMessageBox::warning(this, tr("Warning"), tr("Video frame cannot be openned."));
				cap.release();

				break;



			}
		}
	}
}