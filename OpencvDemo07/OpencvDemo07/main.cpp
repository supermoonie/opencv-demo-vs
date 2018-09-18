#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void MyLine(Mat &bg);
void MyRectangle(Mat &bg);
void MyElipse(Mat &bg);
void MyCircle(Mat &bg);
void MyPolygon(Mat &bg);

void RandomLineDemo();

int main(int argc, char** argv) {
	Mat bg = Mat::zeros(Size(500, 500), CV_8UC3);

	MyLine(bg);
	MyRectangle(bg);
	MyElipse(bg);
	MyCircle(bg);
	MyPolygon(bg);

	putText(bg, "Hello OpenCV", Point(200, 200), CV_FONT_HERSHEY_COMPLEX, 1.0, Scalar(255, 255, 200), 3, LINE_8);

	namedWindow("bg", CV_WINDOW_AUTOSIZE);
	imshow("bg", bg);

	RandomLineDemo();

	waitKey(0);
	return 0;
}

void MyLine(Mat &bg) {
	Point p1(20, 30);
	Point p2;
	p2.x = 200;
	p2.y = 300;
	Scalar color(0, 0, 255);
	line(bg, p1, p2, color, 1, LINE_8, 0);
}

void MyRectangle(Mat &bg) {
	Rect rect(100, 100, 300, 300);
	Scalar color(0, 255, 0);
	rectangle(bg, rect, color, 1, LINE_8, 0);
}

void MyElipse(Mat &bg) {
	ellipse(bg, Point(bg.rows / 2, bg.cols / 2), Size(bg.rows / 4, bg.cols / 8), 90, 0, 360, Scalar(255, 0, 0), 1, LINE_8, 0);
}

void MyCircle(Mat &bg) {
	circle(bg, Point(bg.rows / 2, bg.cols / 2), 200, Scalar(0, 255, 255), 1, LINE_8, 0);
}

void MyPolygon(Mat &bg) {
	Point pts[1][5];
	pts[0][0] = Point(100, 100);
	pts[0][1] = Point(200, 100);
	pts[0][2] = Point(200, 200);
	pts[0][3] = Point(100, 200);
	pts[0][4] = Point(100, 100);

	const Point* ppts[] = { pts[0] };
	int npt[] = { 5 };
	Scalar color(255, 100, 255);
	fillPoly(bg, ppts, npt, 1, color, LINE_8);
}

void RandomLineDemo() {
	Mat bg = Mat::zeros(Size(500, 500), CV_8UC3);
	namedWindow("randomLine", CV_WINDOW_AUTOSIZE);
	RNG rng(123456);
	Point p1;
	Point p2;
	for (int i = 0; i < 100000; i++) {
		p1.x = rng.uniform(0, bg.cols);
		p2.x = rng.uniform(0, bg.cols);
		p1.y = rng.uniform(0, bg.rows);
		p2.y = rng.uniform(0, bg.rows);
		Scalar color(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		int code = waitKey(50);
		if (code == 27) {
			break;
		}
		
		line(bg, p1, p2, color, 1, LINE_8);
		imshow("randomLine", bg);
		
	}


}