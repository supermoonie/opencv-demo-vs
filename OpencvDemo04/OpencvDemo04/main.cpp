#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat src = imread("D:/cv-data/lena.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	namedWindow("gray", CV_WINDOW_AUTOSIZE);
	imshow("gray", gray);

	int rows = gray.rows;
	int cols = gray.cols;
	// 单通道
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			int grayColor = gray.at<uchar>(row, col);
			gray.at<uchar>(row, col) = 255 - grayColor;
		}
	}
	imshow("gray convert", gray);

	// 三通道
	Mat dest;
	dest.create(src.size(), src.type());
	rows = dest.rows;
	cols = dest.cols;
	int nc = src.channels();
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (nc == 1) {
				int color = src.at<uchar>(row, col);
				dest.at<uchar>(row, col) = 255 - color;
			} else if (nc = 3) {
				// Vec3b 对应三通道的Blue、Green、Red的 uchar 类型数据
				// Vec3f 对应三通道的float 类型数据
				int b = src.at<Vec3b>(row, col)[0];
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[2];
				dest.at<Vec3b>(row, col)[0] = 255 - b;
				dest.at<Vec3b>(row, col)[1] = 0;
				dest.at<Vec3b>(row, col)[2] = 255 - r;
			}
		}
	}
	namedWindow("three", CV_WINDOW_AUTOSIZE);
	imshow("three", dest);
	bitwise_not(src, dest);
	namedWindow("bitwiseNot", CV_WINDOW_AUTOSIZE);
	imshow("bitwiseNot", dest);
	waitKey(0);
	return 0;
}