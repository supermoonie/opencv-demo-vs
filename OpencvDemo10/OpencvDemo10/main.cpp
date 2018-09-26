#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {
	// ���������ȸ�ʴ�����ͣ�����С�׵�
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
	// �ղ����������ͺ�ʴ������С�ڵ�
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
	// ��̬ѧ�ݶȣ����ͼ���ʴ
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
	// ��ñ��ԭͼ���뿪����֮��Ĳ�ֵͼ��
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
	// ��ñ��ԭͼ����ղ���֮��Ĳ�ֵͼ��
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