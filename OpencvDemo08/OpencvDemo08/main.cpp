#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dest;
	src = imread("D:/cv-data/flower_with_noise.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);
	blur(src, dest, Size(3, 3), Point(-1, -1));
	namedWindow("blur", CV_WINDOW_AUTOSIZE);
	imshow("blur", dest);
	Mat gaussianDest;
	GaussianBlur(src, gaussianDest, Size(3, 3), 11, 11);
	namedWindow("gaussianBlur", CV_WINDOW_AUTOSIZE);
	imshow("gaussianBlur", gaussianDest);
	
	Mat medianDest;
	medianBlur(src, medianDest, 3);
	namedWindow("medianBlur", CV_WINDOW_AUTOSIZE);
	imshow("medianBlur", medianDest);

	Mat bilateralDest;
	bilateralFilter(src, bilateralDest, 15, 150, 3);
	namedWindow("bilateralBlur", CV_WINDOW_AUTOSIZE);
	imshow("bilateralBlur", medianDest);

	waitKey(0);
	return 0;
}