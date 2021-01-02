// main.cpp
#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include "test.h"
#include<yolo_v2_class.hpp>
#include<darknet.h>
int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MainWindow m;
    m.show();
    Test *s = new Test();
    qDebug()<< s->getS() ;
    qDebug() << "hello vs qt";
    return app.exec();
}
// #include <opencv2/opencv.hpp>
// #include <opencv2/imgproc.hpp>
// #include <opencv2/highgui.hpp>
// #include <vector>
// #include <fstream>
// #include "yolo_v2_class.hpp"
// #include  <time.h> 

// using namespace std;
// using namespace cv;
// // #define GPU

// //画出检测框和相关信息
// void DrawBoxes(Mat &frame, vector<string> classes, int classId, float conf, int left, int top, int right, int bottom)
// {
// 	//画检测框
// 	rectangle(frame, Point(left, top), Point(right, bottom), Scalar(255, 178, 50), 3);
// 	//该检测框对应的类别和置信度
// 	string label = format("%.2f", conf);
// 	if (!classes.empty())
// 	{
// 		CV_Assert(classId < (int)classes.size());
// 		label = classes[classId] + ":" + label;
// 	}
// 	//将标签显示在检测框顶部
// 	int baseLine;
// 	Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
// 	top = max(top, labelSize.height);
// 	rectangle(frame, Point(left, top - round(1.5*labelSize.height)), Point(left + round(1.5*labelSize.width), top + baseLine), Scalar(255, 255, 255), FILLED);
// 	putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 0), 1);
// }


// //画出检测结果
// void Drawer(Mat &frame, vector<bbox_t> outs, vector<string> classes)
// {
// 	//获取所有最佳检测框信息
// 	for (int i = 0; i < outs.size(); i++)
// 	{
// 		// std::cout<< classes[i]  << "\t" <<outs[i] .obj_id<<std::endl;
//  		if(classes[outs[i].obj_id] == "person" || classes[outs[i].obj_id] == "boat"){
// 			DrawBoxes(frame, classes, outs[i].obj_id, outs[i].prob, outs[i].x, outs[i].y,
// 			outs[i].x + outs[i].w, outs[i].y + outs[i].h);
// 		}
// 	}
// }


// int main(void)
// {
// 	string classesFile = "/home/laizl/目标检测代码/qtTest/yolo/coco.names";
// 	string modelConfig = "/home/laizl/目标检测代码/qtTest/yolo/yolov4.cfg";
// 	string modelWeights = "/home/laizl/目标检测代码/qtTest/yolo/yolov4.weights";

// 	//加载类别名
// 	vector<string> classes;
// 	ifstream ifs(classesFile.c_str());
// 	string line;
// 	while (getline(ifs, line)) classes.push_back(line);
// 	//加载网络模型，0是指定第一块GPU
// 	Detector detector(modelConfig, modelWeights, 1);

// 	string mode = "video";
// 	//图像
// 	if (mode == "image")
// 	{
// 		Mat frame = imread("/home/laizl/目标检测代码/qtTest/data/test.jpg");
//         imshow("src", frame);
//         Mat src1 = imread("/home/laizl/目标检测代码/qtTest/data/test.jpg", 0);
// 	    imshow("原图", src1);
//         cout << "L= (C)" << endl << format(frame, Formatter::FMT_C) << endl << endl;
// 		//Mat图像转为yolo输入格式
// 		shared_ptr<image_t> detImg = detector.mat_to_image_resize(frame);
//          std::cout<< detImg.get() <<std::endl;
//           std::cout<< " henshuai" <<std::endl;
// 		//前向预测
// 		vector<bbox_t> outs = detector.detect_resized(*detImg, frame.cols, frame.rows, 0.5);
//         std::cout<< " henshuai" <<std::endl;
//         std::cout<< " henshuai" <<std::endl;
//         std::cout<< " henshuai" <<std::endl;
//         std::cout<< " henshuai" <<std::endl;
//         std::cout<< " henshuai" <<std::endl;
//         std::cout<< " length"<<  classes.size() <<std::endl;
// 		std::cout<< " length"<<  classes[11] <<std::endl;
// 		//画图
// 		Drawer(frame, outs, classes);
// 		imwrite("/home/laizl/目标检测代码/qtTest/data/result2.jpg", frame);
// 	}
// 	//视频
// 	else if (mode == "video")
// 	{

// 		VideoCapture cap("/home/laizl/目标检测代码/qtTest/data/test.mp4");
// 		int totalFrames = (int) cap.get(cv::CAP_PROP_FRAME_COUNT);
// 		int frameH    = (int) cap.get(cv::CAP_PROP_FRAME_WIDTH);  
// 	    int frameW    = (int)  cap.get(cv::CAP_PROP_FRAME_HEIGHT); 
// 		std::cout << frameH <<std::endl;
// 		std::cout<< frameW <<std::endl;
// 		Size size(frameW, frameH);
// 		VideoWriter writer("/home/laizl/目标检测代码/qtTest/data/result.mp4", cv::VideoWriter::fourcc('M', 'P', '4', '2'), 25, size);
// 		// VideoWriter writer("/home/laizl/目标检测代码/qtTest/data/result.mp4", cv::VideoWriter::fourcc('M', 'P', '4', 'V'), 25, size);
//         int n = 1;
// 		while (1) 
// 		{
// 			clock_t start = clock();
// 			Mat frame;
// 			cap >> frame;
// 			if (frame.empty()) {
// 				cout << "Finish" << endl;
// 				break;
// 			}
			
//             // n = n + 1;
// 			// if(n % 2 == 0){
// 			// std::cout<< "jindu" << n << "\t" <<  totalFrames <<std::endl;
// 			 //Mat图像转为yolo输入格式
// 			shared_ptr<image_t> detImg = detector.mat_to_image_resize(frame);
// 			//前向预测
// 			vector<bbox_t> outs = detector.detect_resized(*detImg, frame.cols, frame.rows, 0.10);
// 			//  画图
// 			// std::cout<< " length"<<  classes.size() <<std::endl;
// 			// std::cout<< " length"<<  outs.size() <<std::endl;
// 			 Drawer(frame, outs, classes);
// 			// }
			
// 			imshow("Input video", frame);

//              waitKey(1);//这是显示刷新间隔意思，如果是0，将不刷新，固定图像，这个函数与保存视频功能无关
// 			if (char(waitKey(1)) == 'q') break;
// 			clock_t end = clock();
// 			// std::cout << (double)(end - start) / CLOCKS_PER_SEC <<std::endl;
// 			// writer << frame;
// 		}
// 		writer.release();
// 		cap.release();
// 	}
//     return 0;
// }