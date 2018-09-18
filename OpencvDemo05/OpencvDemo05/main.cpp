#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat linuxLogo, windowsLogo, dest;
	linuxLogo = imread("D:/cv-data/LinuxLogo.jpg");
	windowsLogo = imread("D:/cv-data/WindowsLogo.jpg");
	if (linuxLogo.empty() || windowsLogo.empty()) {
		printf("could not load image...\n");
	}
	namedWindow("linux logo", CV_WINDOW_AUTOSIZE);
	imshow("linux logo", linuxLogo);
	namedWindow("windows logo", CV_WINDOW_AUTOSIZE);
	imshow("windows logo", windowsLogo);

	double alpha = 0.5;
	if (linuxLogo.rows == windowsLogo.rows && linuxLogo.cols == windowsLogo.cols && linuxLogo.type() == windowsLogo.type()) {
		//addWeighted(linuxLogo, alpha, windowsLogo, 1 - alpha, 0.0, dest);
		//add(linuxLogo, windowsLogo, dest, Mat());
		multiply(linuxLogo, windowsLogo, dest);
		namedWindow("dest", CV_WINDOW_AUTOSIZE);
		imshow("dest", dest);
	}
	else {
		printf("the size of images is not same....\n");
		return -1;
	}

	waitKey(0);
	return 0;
}