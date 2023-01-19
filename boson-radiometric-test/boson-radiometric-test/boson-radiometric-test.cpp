//basic file that has the fucntions that need to be used. Currently links with OpenCV and the ICI sdk. Boson SDK is another issue to be tackled next 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include "FrameGrabber.h"
#include "ICIRtnErrors.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);

	// connect ti flir serial virtual COM Port

	//set high gain
	bosonSetGainMode(0);
	//get serial number
	auto const serialNumber = bosonGetCameraSN();

	//check for camera
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	// gets the resolutions and creates a video writer object
	int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

	VideoWriter video("outfaster.mp4", cv::VideoWriter::fourcc('Y', '1', '6', ' '), 30, Size(frame_width, frame_height));

	// create ici handle
	auto handle = CreateFlirBosonRawCountsToTemperatureInCelsiusHandle();

	if (handle)
	{

		while (1) {
			Mat frame;
			Mat coloredFrame;

			cap >> frame;

			if (frame.empty()) {
				break;
			}
			// get FPA value from camera
			auto const fpa = roicGetFPATemp();
			// call ici convert function need: void* handle , uint16_t* rawCounts , int rawDataLen , uint32_t fpa , uint32_t cameraSerialNumber
			auto temperatureInCeslius = ConvertFlirBosonCameraRawCountsToTemperatureInCelsius(handle, rawCounts.data(), rawCounts.size(), fpa, serialNumber);


			// asethetic changes
			applyColorMap(frame, coloredFrame, COLORMAP_HOT);

			//saving video
			video.write(coloredFrame);

			// display video
			imshow("Frame", coloredFrame);


			// exit video recording
			char c = (char)waitKey(1);
			if (c == 27) {
				break;
			}
		}

		// destroy handle and leave if
		DestroyFlirBosonRawCountsToTemperatureInCelsiusHandle(handle);
	}
	// when everything is done release the video capture object and then close all frames

	cap.release();
	video.release();
	destroyAllWindows();


	return 0;
}