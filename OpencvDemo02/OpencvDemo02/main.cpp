#include <opencv2\opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;

int main(int argc, char** argv) {
	Mat src, dest;
	src = imread("D://cv-data//baboon.jpg");
	if (src.empty()) {
		printf("could not load image .... \n");
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	/*int offset = src.channels();
	int cols = (src.cols - 1) * offset;
	int rows = src.rows;
	dest = Mat::zeros(src.size(), src.type());
	for (int row = 1; row < (rows - 1); row++) {
		const uchar* previous = src.ptr<uchar>(row - 1);
		const uchar* current = src.ptr<uchar>(row);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar* output = dest.ptr<uchar>(row);
		for (int col = offset; col < cols; col++) {
			output[col] = saturate_cast<uchar>(5*current[col] - (current[col - offset] + current[col + offset] + previous[col] + next[col]));
		}
	}*/

	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dest, src.depth(), kernel);

	namedWindow("dest", CV_WINDOW_AUTOSIZE);
	imshow("dest", dest);

	waitKey(0);
	return 0;
}