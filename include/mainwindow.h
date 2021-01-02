// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <fstream>
#include "yolo_v2_class.hpp"
#include  <time.h> 
#include <QStandardItemModel>
#include <QDebug>

using namespace std;
using namespace cv;
namespace Ui {
    class MainWindow;
}
class MainWindow : public QMainWindow {
    Q_OBJECT
     public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
    private slots:
        void openVideo();
        void startDetect();
    private:
        QStandardItemModel *model;
        void Detecto(QString url);
        void DrawBoxes(Mat &frame, vector<string> classes, int classId, float conf, int left, int top, int right, int bottom);
        void Drawer(Mat &frame, vector<bbox_t> outs, vector<string> classes);
        QImage cvMat2QImage(const cv::Mat& mat);
    private:
    Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H