#ifndef ShowMatWidget_H
#define ShowMatWidget_H

#include <QWidget>
#include "ui_ShowMatWidget.h"

class ShowMatWidget : public QWidget
{
	Q_OBJECT
 
public:
	ShowMatWidget(QWidget *parent = Q_NULLPTR);
	~ShowMatWidget();
 
// private Q_SLOTS:
	// void slotBtnConnected();
 
	// void slotGetFrame(cv::Mat mat);
 
	// QImage cvMat2QImage(const cv::Mat& mat);
 
private:
	Ui::ShowMatWidget ui;
 
	// DecodeOpencv *m_thread = nullptr;
};
#endif