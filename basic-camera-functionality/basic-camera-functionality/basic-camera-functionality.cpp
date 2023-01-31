// Read, write, and display an image using opencv
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	int colorMap = -1;

	// connect to flir serial virtual COM Port

	////set high gain
	//bosonSetGainMode(0);
	////get serial number
	//auto const serialNumber = bosonGetCameraSN();

	//check for camera
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	// gets the resolutions and creates a video writer object
	int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

	VideoWriter video("basic-HOT.mp4", cv::VideoWriter::fourcc('Y', '1', '6', ' '), 60, Size(frame_width, frame_height));

	//// create ici handle
	//auto handle = CreateFlirBosonRawCountsToTemperatureInCelsiusHandle();

	//if (handle)
	//{

		while (1) {
			Mat frame;
			Mat coloredFrame;

			cap >> frame;

			if (frame.empty()) {
				break;
			}
			//// get FPA value from camera
			//auto const fpa = roicGetFPATemp();
			//// call ici convert function need: void* handle , uint16_t* rawCounts , int rawDataLen , uint32_t fpa , uint32_t cameraSerialNumber
			//auto temperatureInCeslius = ConvertFlirBosonCameraRawCountsToTemperatureInCelsius(handle, rawCounts.data(), rawCounts.size(), fpa, serialNumber);


			// asethetic changes
            if (colorMap != -1) {
                if  (colorMap == 2) {
                    applyColorMap(frame, coloredFrame, COLORMAP_JET);
                } else if (colorMap == 11) {
                    applyColorMap(frame, coloredFrame, COLORMAP_HOT);
                }
                //saving video
                video.write(coloredFrame);

                // display video
                imshow("Frame", coloredFrame);
            } else {
                //saving video
                video.write(frame);

                // display video
                imshow("Frame", frame);
            }


			// exit video recording
			char c = (char)waitKey(1);
            if (c == 104) {
                colorMap = 11;
                printf("color map hot:");
                cout << colorMap << endl;
            } else if (c == 106){
                colorMap = 2;
                printf("color map jet:");
                cout << colorMap << endl;
            } else if (c == 119){
                colorMap = -1;
                printf("back to basics:");
                cout << colorMap << endl;
            } else if (c == 27) {
				break;
			}
		}

		//// destroy handle and leave if
		//DestroyFlirBosonRawCountsToTemperatureInCelsiusHandle(handle);
	//}
	// when everything is done release the video capture object and then close all frames

	cap.release();
	video.release();
	destroyAllWindows();

	 
	return 0;
}