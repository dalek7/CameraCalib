#include <iostream>
#include "Thirdparty\bbutil.h"
#include "Thirdparty\cvUtilDBG.h"
#include "Settings.h"
const char ESC_KEY = 27;
using namespace std;
int main(int argc, char** argv) {
	std::string outdir = "../examples/undistort";
	MakeSurePathExists(outdir);

	Settings s;
	const string inputSettingsFile = "../PicCalib/out_camera_data.xml";
	FileStorage fs(inputSettingsFile, FileStorage::READ); // Read the settings
	if (!fs.isOpened())
	{
		cout << "Could not open the calibration file: \"" << inputSettingsFile << "\"" << endl;
		return -1;
	}
	else
	{
		cout << "Loaded calibration file: \"" << inputSettingsFile << "\"" << endl;
	}

	Mat cameraMatrix;
	Mat distCoeffs;
	Size imageSize;

	fs["camera_matrix"] >> cameraMatrix;
	fs["distortion_coefficients"] >> distCoeffs;
	fs["image_width"] >> imageSize.width;
	fs["image_height"] >> imageSize.height;

	cout << "camera_matrix=" << endl;
	DD::PrintMat<double>(cameraMatrix);
	cout << endl;
	cout << "distortion_coefficients=" << endl;
	DD::PrintMat<double>(distCoeffs);
	cout << endl;
	cout << "imageSize=" << endl;
	cout << imageSize.width << "x" << imageSize.height << endl;

	Mat map1, map2;

	Mat cm1 = getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize, 0);
	initUndistortRectifyMap(
		cameraMatrix, distCoeffs, Mat(),
		cm1, imageSize,
		CV_16SC2, map1, map2);


	Mat view, rview;
	view = imread("test1.png", IMREAD_COLOR);

	if (view.empty())
		return 0;
	remap(view, rview, map1, map2, INTER_LINEAR);

	string fnout = outdir + "/test1_undist.png";
	cout << fnout << endl;
	fnout = outdir + "/test1.png";
	imwrite(fnout, view);
	cout << fnout << endl;

	imshow("Image View", rview);
	char c = (char)waitKey();
	if (c == ESC_KEY || c == 'q' || c == 'Q')
	{
		destroyAllWindows();
		return 0;
	}
	destroyAllWindows();

	printf("== Main End! ==");
	getchar();

	return 0;
}
