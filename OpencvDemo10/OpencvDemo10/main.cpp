#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {
	// 开操作：先腐蚀后膨胀，消灭小白点
	Mat openSrc;
	openSrc = imread("D:/cv-data/open.png");
	if (!openSrc.data) {
		printf("could not load open.png...\n");
		return -1;
	}
	namedWindow("openSrc", CV_WINDOW_AUTOSIZE);
	imshow("openSrc", openSrc);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(11, 11), Point(-1, -1));
	Mat openDest;
	morphologyEx(openSrc, openDest, MORPH_OPEN, kernel);
	namedWindow("open", CV_WINDOW_AUTOSIZE);
	imshow("open", openDest);
	waitKey(0);
	destroyWindow("openSrc");
	destroyWindow("open");
	// 闭操作：先膨胀后腐蚀，消灭小黑点
	Mat closeSrc = imread("D:/cv-data/close.png");
	if (!closeSrc.data) {
		printf("could not load close.png...\n");
		return -1;
	}
	namedWindow("closeSrc", CV_WINDOW_AUTOSIZE);
	imshow("closeSrc", closeSrc);
	Mat closeKernel = getStructuringElement(MORPH_RECT, Size(11, 11), Point(-1, -1));
	Mat closeDest;
	morphologyEx(closeSrc, closeDest, MORPH_CLOSE, closeKernel);
	namedWindow("close", CV_WINDOW_AUTOSIZE);
	imshow("close", closeDest);
	waitKey(0);
	destroyWindow("closeSrc");
	destroyWindow("close");
	// 形态学梯度：膨胀减腐蚀
	Mat gradientSrc = imread("D:/cv-data/lena.jpg");
	if (!gradientSrc.data) {
		printf("could not load lena.jpg...\n");
		return -1;
	}
	Mat gradientDest;
	Mat gradientKernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	morphologyEx(gradientSrc, gradientDest, MORPH_GRADIENT, gradientKernel);
	namedWindow("gradientSrc", CV_WINDOW_AUTOSIZE);
	imshow("gradientSrc", gradientSrc);
	namedWindow("gradient", CV_WINDOW_AUTOSIZE);
	imshow("gradient", gradientDest);
	waitKey(0);
	destroyWindow("gradientSrc");
	destroyWindow("gradient");
	// 顶帽：原图像与开操作之间的差值图像
	namedWindow("openSrc", CV_WINDOW_AUTOSIZE);
	imshow("openSrc", openSrc);
	Mat topHatDest;
	Mat topHatKernel = getStructuringElement(MORPH_RECT, Size(11, 11));
	morphologyEx(openSrc, topHatDest, MORPH_TOPHAT, topHatKernel);
	namedWindow("topHatDest", CV_WINDOW_AUTOSIZE);
	imshow("topHatDest", topHatDest);
	waitKey(0);
	destroyWindow("openSrc");
	destroyWindow("topHatDest");
	// 黑帽：原图像与闭操作之间的差值图像
	namedWindow("closeSrc", CV_WINDOW_AUTOSIZE);
	imshow("closeSrc", closeSrc);
	Mat blackHatDest;
	Mat blackHatKernel = getStructuringElement(MORPH_RECT, Size(11, 11));
	morphologyEx(closeSrc, blackHatDest, MORPH_BLACKHAT, blackHatKernel);
	namedWindow("blackHatDest", CV_WINDOW_AUTOSIZE);
	imshow("blackHatDest", blackHatDest);
	waitKey(0);
	destroyWindow("closeSrc");
	destroyWindow("blackHatDest");
	return 0;
}