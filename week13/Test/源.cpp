#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	// 读取图片（使用图片的绝对路径，参考自己的图所在目录）
	Mat srcImg = imread("C://Users//wendy//Desktop//IMG_20220930_181424.jpg");
	if (srcImg.empty()) {
		cout << "could not load image..." << endl;
		return -1;
	}
	imshow("Test opencv setup", srcImg);
	// 显示灰度图
	Mat Gray;
	cvtColor(srcImg, Gray, 6);
	imshow("Gray", Gray);
	// 等待任意按键按下，不添加此语句图片会一闪而过
	waitKey(0);
	cout << "Hello,world." << endl;
	return 0;
}