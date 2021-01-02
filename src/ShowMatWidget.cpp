#include "ShowMatWidget.h"

//  #include <QDebug>
 
ShowMatWidget::ShowMatWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
 
	// m_thread = new DecodeOpencv(this);
 
	// connect(m_thread, &DecodeOpencv::sigSendFrame, this, &ShowMatWidget::slotGetFrame);
 
	// connect(ui.pushButton, &QPushButton::clicked, this, &ShowMatWidget::slotBtnConnected);
}
 
ShowMatWidget::~ShowMatWidget()
{
}
 
// void ShowMatWidget::slotBtnConnected()
// {
// 	m_thread->setUrl(ui.lineEdit->text());
// 	m_thread->start();
// }
 
// void ShowMatWidget::slotGetFrame(cv::Mat mat)
// {
// 	QImage image = cvMat2QImage(mat);
 
// 	ui.label->setPixmap(QPixmap::fromImage(image));
// }
 
// QImage ShowMatWidget::cvMat2QImage(const cv::Mat& mat)
// {
// 	//8位，通道数为1
// 	if (mat.type() == CV_8UC1)
// 	{
// 		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
// 		image.setColorCount(256);
// 		for (int i = 0; i < 256; i++)
// 		{
// 			image.setColor(i, qRgb(i, i, i));
// 		}
 
// 		uchar *pSrc = mat.data;
// 		for (int row = 0; row < mat.rows; row++)
// 		{
// 			uchar *pDest = image.scanLine(row);
// 			memcpy(pDest, pSrc, mat.cols);
// 			pSrc += mat.step;
// 		}
// 		return image;
// 	}
// 	//8位，通道数为3
// 	else if (mat.type() == CV_8UC3)
// 	{
// 		const uchar *pSrc = (const uchar*)mat.data;
// 		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
// 		return image.rgbSwapped();
// 	}
// 	//8位，通道数为4
// 	else if (mat.type() == CV_8UC4)
// 	{
// 		qDebug() << "CV_8UC4";
 
// 		const uchar *pSrc = (const uchar*)mat.data;
// 		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
// 		return image.copy();
// 	}
// 	//32位，通道数为3
// 	else if (mat.type() == CV_32FC3)
// 	{
// 		cv::Mat temp;
// 		mat.convertTo(temp, CV_8UC3);
 
// 		const uchar *pSrc = (const uchar*)temp.data;
// 		QImage image(pSrc, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
// 		return image.rgbSwapped();
// 	}
// 	else
// 	{
// 		qDebug() << "ERROR: Mat could not be converted to QImage.";
// 		return QImage();
// 	}
// }