// Seung-Chan Kim
// ver 0.1


#pragma once


#include "opencv2/opencv.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;



namespace DD {


	#define CVTICK double __time_in_ticks = (double)cv::getTickCount();
	#define CVTOK(msg) std::cout << msg << ((double)cv::getTickCount() - __time_in_ticks)/cv::getTickFrequency() << "s" << std::endl;

    template<typename T>
    static void PrintPoint3x(const T& pt)
    {
        cout << pt.x << "," << pt.y << "," << pt.z << endl;

    }


	static void DescMat(const Mat& mat)
	{
		cout << "Size of mat : " << mat.rows << " X " << mat.cols << " X "<< mat.channels() <<  endl;


	}

	template<typename T>
	static void PrintMat(const Mat& mat, bool bDisplayType=false)
	{
		int i, j;
		for (i = 0; i < mat.rows; i++)
		{
			for (j = 0; j < mat.cols; j++)
			{
				printf("%f ", mat.at<T>(i, j));

			}
			printf("\n");
		}
		if(bDisplayType)
		{
            printf("type: %d\n", mat.type());
		}
	}

    // will be deprecated in the future.
	static void cvPrintMat(const CvMat& mat)
	{
		int i, j;
		for (i = 0; i < mat.rows; i++)
		{
			for (j = 0; j < mat.cols; j++)
			{
				printf("%f ", cvmGet(&mat, i, j));

			}
			printf("\n");
		}

	}





}
