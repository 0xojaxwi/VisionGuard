#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace cv;
using namespace std;

/*
void main() {
	string path = "you.jpg";
	Mat image = imread(path);
	imshow("Frame", img);
	waitKey(0);
}*/

void main() {
	VideoCapture  video(1);
	CascadeClassifier facedetect;
	Mat img;
	facedetect.load("haarcascade_frontalface_default.xml");



	while (true) {
		video.read(img);

		vector<Rect> faces;

		facedetect.detectMultiScale(img, faces, 1.3, 5);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br, Scalar(50, 50, 255), 3);
			rectangle(img, Point(0,0), Point(250, 70),  Scalar(50, 50, 255), FILLED);
			putText(img, to_string(faces.size()+"Face Identified", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
		}

		imshow("Frame", img);
		waitKey(20);



	}
}