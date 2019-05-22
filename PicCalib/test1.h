#pragma once
//created just for test
#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
#include <iostream>
using namespace std;
// tested okay
static void test1()
{
	Size patternsize(9, 6); //interior number of corners
	Mat rgb = imread("../images/20190429_Note9_calib_640/20190429_125729.jpg", IMREAD_COLOR);
	Mat gray;
	cvtColor(rgb, gray, COLOR_BGR2GRAY);
	vector<Point2f> corners; //this will be filled by the detected corners

							 //CALIB_CB_FAST_CHECK saves a lot of time on images
							 //that do not contain any chessboard corners
	bool patternfound = findChessboardCorners(gray, patternsize, corners,
		CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE
	);//+ CALIB_CB_FAST_CHECK

	if (patternfound)
		cornerSubPix(gray, corners, Size(11, 11), Size(-1, -1),
			TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));

	drawChessboardCorners(rgb, patternsize, Mat(corners), patternfound);

	imshow("Image View", rgb);
	char key1 = (char)waitKey(-1);

}