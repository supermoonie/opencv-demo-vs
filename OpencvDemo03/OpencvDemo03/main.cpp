#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat src;
	src = imread("D:/cv-data/lena.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	Mat dest_1;
	dest_1 = Mat(src.size(), src.type());
	dest_1 = Scalar(0, 0, 255);
	namedWindow("dest_1", CV_WINDOW_AUTOSIZE);
	imshow("dest_1", dest_1);

	Mat dest_2;
	// 完全的数据拷贝，即只有 clone() 与 copyTo() 才会拷贝数据
	// dest_2 = src.clone();
	src.copyTo(dest_2);
	namedWindow("dest_2", CV_WINDOW_AUTOSIZE);
	imshow("dest_2", dest_2);

	Mat dest_3;
	cvtColor(src, dest_3, CV_BGR2GRAY);
	printf("src channels : %d\n", src.channels());
	printf("dest_3 channels : %d\n", dest_3.channels());
	namedWindow("dest_3", CV_WINDOW_AUTOSIZE);
	imshow("dest_3", dest_3);

	int cols = dest_3.cols;
	int rows = dest_3.rows;
	const uchar* firstRow = dest_3.ptr<uchar>(0);
	printf("first pixel value : %d \n", *firstRow);
	printf("rows : %d  cols : %d \n", rows, cols);
	// CV_8UC3 中的 8 表示每个通道占 8 位，U 表示无符号，C 表示 Char 类型，3 表示通道的数目为 3
	// 第四个参数是向量表示初始化每个像素值是多少，向量长度应与通道数目一致
	Mat m_1(3, 3, CV_8UC3, Scalar(0, 0, 255));
	cout << "m_1 = " << m_1 << endl;

	Mat m_2;
	m_2.create(src.size(), src.type());
	m_2 = Scalar(0, 0, 100);
	namedWindow("m_2", CV_WINDOW_AUTOSIZE);
	imshow("m_2", m_2);

	waitKey(0);
	return 0;
}