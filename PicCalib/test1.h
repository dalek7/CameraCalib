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

static
bool readStringList2(const string& filename, vector<string>& l)
{
	l.clear();
	FileStorage fs(filename, FileStorage::READ);
	if (!fs.isOpened())
		return false;
	FileNode n = fs.getFirstTopLevelNode();
	if (n.type() != FileNode::SEQ)
		return false;
	FileNodeIterator it = n.begin(), it_end = n.end();
	for (; it != it_end; ++it)
		l.push_back((string)*it);
	return true;
}

static
void testx()
{
	//test
	vector<string> l1;
	const string fn1 = "../images/VID5.xml";
	readStringList2(fn1, l1);
	cout << l1.size() << endl;
}


int mainOri(int argc, char** argv) {

	std::string outdir = "../out";
	MakeSurePathExists(outdir);
	cout << "video" << endl;

	std::cout << "hello" << std::endl;

#ifdef WINDOWS
	std::string location;
	location = "../images/20190429_Note9_calib_640";
#else
	location = "/home/seung/work/dataset/TUM-rgbd/rgbd_dataset_freiburg1_xyz/rgb";
#endif

	std::vector<std::string> vfn1;
	string fn_video;
	int nimg = GetFilesofExtInDirectory(vfn1, location, "jpg");

	if (nimg>0)
	{
		fn_video = vfn1[0];
		cout << "found " << nimg << " pic file(s)" << endl;
		cout << fn_video << endl;
	}
	else
	{
		cout << "no video found" << endl;
	}


	//! [file_read]
	Settings s;
	const string inputSettingsFile = "../images/default.xml";
	FileStorage fs(inputSettingsFile, FileStorage::READ); // Read the settings
	if (!fs.isOpened())
	{
		cout << "Could not open the configuration file: \"" << inputSettingsFile << "\"" << endl;
		return -1;
	}
	else
	{
		cout << "Loaded configuration file: \"" << inputSettingsFile << "\"" << endl;
	}

	fs["Settings"] >> s;
	fs.release();                                         // close Settings file

														  //! [file_read]
	if (!s.goodInput)
	{
		cout << "Invalid input detected. Application stopping. " << endl;

		getchar();

		return -1;
	}

	vector<vector<Point2f> > imagePoints;
	Mat cameraMatrix, distCoeffs;
	Size imageSize;
	int mode = s.inputType == Settings::IMAGE_LIST ? CAPTURING : DETECTION;
	clock_t prevTimestamp = 0;
	const Scalar RED(0, 0, 255), GREEN(0, 255, 0);
	const char ESC_KEY = 27;


	printf("== Main End! ==");
	getchar();

	return 0;
}
