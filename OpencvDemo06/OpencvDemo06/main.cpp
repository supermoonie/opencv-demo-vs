#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dest;
	src = imread("D:/cv-data/lena.jpg");
	if (!src.data) {
		printf("could not load image...\n");
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	dest = Mat::zeros(src.size(), src.type());
	int rows = src.rows;
	int cols = src.cols;
	int channels = src.channels();
	float alpha = 1.3;
	float beta = 30;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (channels == 3) {
				int b = src.at<Vec3b>(row, col)[0];
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[2];
				dest.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(alpha * b + beta);
				dest.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(alpha * g + beta);
				dest.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(alpha * r + beta);
			}
			else if(channels == 1) {
				int gray = src.at<uchar>(row, col);
				dest.at<uchar>(row, col) = saturate_cast<uchar>(alpha * gray + beta);
			}
		}
	}
	namedWindow("dest", CV_WINDOW_AUTOSIZE);
	imshow("dest", dest);

	waitKey(0);
	return 0;
}