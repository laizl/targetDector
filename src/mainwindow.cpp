// mainwindow.cpp
#include "mainwindow.h"
#include "QFileDialog"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) , ui(new Ui::MainWindow){
        ui->setupUi(this);
        this->setWindowTitle("视频检测");
        //bind openvideo
        connect(ui->openVideo,SIGNAL(clicked()),this,SLOT(openVideo()));
        connect(ui->startCheck,SIGNAL(clicked()),this,SLOT(startDetect()));
        //set table
       model = new QStandardItemModel();
      model->setColumnCount(3);    
      model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("POSITION"));
      model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("TIME"));
      model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("COUNT"));
      ui->CheckResult_tableView->setModel(model);
    //    ui->CheckResult_tableView->re
    }

MainWindow::~MainWindow() {
    
}

void MainWindow::openVideo() {
    QString testFileName = QFileDialog::getOpenFileName(this,tr(""),"",tr("*.mp4")); //选择路径
    ui->lineEdit_video->setText(testFileName);
}

void MainWindow::startDetect(){
   QString url = ui->lineEdit_video->text();
   this->Detecto(url);
}

void MainWindow::DrawBoxes(Mat &frame, vector<string> classes, int classId, float conf, int left, int top, int right, int bottom)
{
	//画检测框
	rectangle(frame, Point(left, top), Point(right, bottom), Scalar(255, 178, 50), 3);
	//该检测框对应的类别和置信度
	string label = format("%.2f", conf);
	if (!classes.empty())
	{
		CV_Assert(classId < (int)classes.size());
		label = classes[classId] + ":" + label;
	}
	//将标签显示在检测框顶部
	int baseLine;
	Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
	top = max(top, labelSize.height);
	rectangle(frame, Point(left, top - round(1.5*labelSize.height)), Point(left + round(1.5*labelSize.width), top + baseLine), Scalar(255, 255, 255), FILLED);
	putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 0), 1);
}


//画出检测结果
void MainWindow::Drawer(Mat &frame, vector<bbox_t> outs, vector<string> classes)
{
	//获取所有最佳检测框信息
	for (int i = 0; i < outs.size(); i++)
	{
		// std::cout<< classes[i]  << "\t" <<outs[i] .obj_id<<std::endl;
        int n = 0;
 		if(classes[outs[i].obj_id] == "person" || classes[outs[i].obj_id] == "boat"){
			DrawBoxes(frame, classes, outs[i].obj_id, outs[i].prob, outs[i].x, outs[i].y,
			outs[i].x + outs[i].w, outs[i].y + outs[i].h);
            n++;
		}
        model->setItem(model->rowCount() , 0, new QStandardItem("张三"));
        model->setItem(model->rowCount() , 1, new QStandardItem(n +""));
        model->setItem(model->rowCount() , 2, new QStandardItem("张三"));
	}
}

void MainWindow::Detecto(QString url){
	string classesFile = "/home/laizl/目标检测代码/qtTest/yolo/coco.names";
	string modelConfig = "/home/laizl/目标检测代码/qtTest/yolo/yolov4.cfg";
	string modelWeights = "/home/laizl/目标检测代码/qtTest/yolo/yolov4.weights";

	//加载类别名
	vector<string> classes;
	ifstream ifs(classesFile.c_str());
	string line;
	while (getline(ifs, line)) classes.push_back(line);
	//加载网络模型，0是指定第一块GPU
	Detector detector(modelConfig, modelWeights, 1);

	string mode = "video";
	//图像
	if (mode == "image")
	{
		Mat frame = imread("/home/laizl/目标检测代码/qtTest/data/test.jpg");
        imshow("src", frame);
        Mat src1 = imread("/home/laizl/目标检测代码/qtTest/data/test.jpg", 0);
	    imshow("原图", src1);
        // cout << "L= (C)" << endl << format(frame, Formatter::FMT_C) << endl << endl;
		//Mat图像转为yolo输入格式
		shared_ptr<image_t> detImg = detector.mat_to_image_resize(frame);
		//前向预测
		vector<bbox_t> outs = detector.detect_resized(*detImg, frame.cols, frame.rows, 0.5);
		//画图
		Drawer(frame, outs, classes);
		imwrite("/home/laizl/目标检测代码/qtTest/data/result2.jpg", frame);
	}
	//视频
	else if (mode == "video")
	{

		VideoCapture cap(url.toStdString());
		int totalFrames = (int) cap.get(cv::CAP_PROP_FRAME_COUNT);
		int frameH    = (int) cap.get(cv::CAP_PROP_FRAME_WIDTH);  
	    int frameW    = (int)  cap.get(cv::CAP_PROP_FRAME_HEIGHT); 
		// std::cout << frameH <<std::endl;
		// std::cout<< frameW <<std::endl;
		Size size(frameW, frameH);
		VideoWriter writer("/home/laizl/目标检测代码/qtTest/data/result.mp4", cv::VideoWriter::fourcc('M', 'P', '4', '2'), 25, size);
		// VideoWriter writer("/home/laizl/目标检测代码/qtTest/data/result.mp4", cv::VideoWriter::fourcc('M', 'P', '4', 'V'), 25, size);
        int n = 1;
		while (1) 
		{
			clock_t start = clock();
			Mat frame;
			cap >> frame;
			if (frame.empty()) {
				cout << "Finish" << endl;
				break;
			}
			 //Mat图像转为yolo输入格式
			shared_ptr<image_t> detImg = detector.mat_to_image_resize(frame);
			//前向预测
			vector<bbox_t> outs = detector.detect_resized(*detImg, frame.cols, frame.rows, 0.10);
			//  画图
			// std::cout<< " length"<<  classes.size() <<std::endl;
			// std::cout<< " length"<<  outs.size() <<std::endl;
			 Drawer(frame, outs, classes);
			// }
			QImage image = cvMat2QImage(frame);
	        ui->videoPlayer->setPixmap(QPixmap::fromImage(image));
             ui->videoPlayer->setScaledContents(true);
			// imshow("Input video", frame);
             waitKey(1);//这是显示刷新间隔意思，如果是0，将不刷新，固定图像，这个函数与保存视频功能无关
			// std::cout << (double)(end - start) / CLOCKS_PER_SEC <<std::endl;
			// writer << frame;
		}
		writer.release();
		cap.release();
	}
}

QImage MainWindow::cvMat2QImage(const cv::Mat& mat)
{
	//8位，通道数为1
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
 
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	//8位，通道数为3
	else if (mat.type() == CV_8UC3)
	{
		const uchar *pSrc = (const uchar*)mat.data;
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	//8位，通道数为4
	else if (mat.type() == CV_8UC4)
	{
		std::cout << "CV_8UC4" <<std::endl;
 
		const uchar *pSrc = (const uchar*)mat.data;
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	//32位，通道数为3
	else if (mat.type() == CV_32FC3)
	{
		cv::Mat temp;
		mat.convertTo(temp, CV_8UC3);
 
		const uchar *pSrc = (const uchar*)temp.data;
		QImage image(pSrc, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else
	{
		qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}
}