#include <opencv2/opencv.hpp>
#include <iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("D://23.jpg", 0);
	cv::Mat src;
	cv::Mat src1;
	int i, j, t, k = 0, kk = 0, k1 = 0;
	cv::Mat dst = imread("D://23.jpg", 0);
	int halfheight = dst.rows / 2;
	int halfwidth = dst.cols / 2;
	vector<vector<Point>>contours;
	threshold(srcMat, src, 100, 255, THRESH_BINARY_INV);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(20, 30));

	dilate(src, src1, kernel);
	erode(src1, src, kernel);


	findContours(src, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	for (i = 0; i < contours.size(); i++) {
		k = 0;
		for (j = 0; j < contours[i].size(); j++) {
			if (contours[i][j].x>halfwidth)
				k++;
		}

		if (k>100 && k<1000)
			drawContours(srcMat, contours, i, Scalar(220, 20, 60), -1, 0);
	}
	
	imshow("draw", srcMat);
	waitKey(0);
}