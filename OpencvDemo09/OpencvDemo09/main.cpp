#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat src, dest;
int size = 3;

void onTrackBarValueChange(int, void*);

int main(int argc, char** argv) {
	src = imread("D:/cv-data/LinuxLogo.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);
	namedWindow("dest", CV_WINDOW_AUTOSIZE);
	createTrackbar("size:", "dest", &size, 21, onTrackBarValueChange);
	onTrackBarValueChange(0, 0);
	waitKey(0);
	return 0;
}

void onTrackBarValueChange(int e, void* userData) {
	int s = size * 2 + 1;
	Mat ker = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));
	// ���Ͳ�����ȡ���ص����ֵ
	// dilate(src, dest, ker);
	// ��ʴ����,ȡ���ص���Сֵ
	erode(src, dest, ker);
	imshow("dest", dest);
	return;
}