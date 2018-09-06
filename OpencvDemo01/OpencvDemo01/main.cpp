#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {
	Mat mat = imread("D:\\cv-data\\lena.jpg");
	if (mat.empty()) {
		printf("could not load image\n");
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", mat);
	waitKey(0);
	return 0;
}