#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/gpu/gpu.hpp>

using namespace std;
using namespace cv;

#define THRESH 144.0

cv::Mat src_host;
cv::Mat result_host;
cv::gpu::GpuMat dst;
cv::gpu::GpuMat src;

int main(int argc, char* argv[]){
	try{
	cout << "Beginning\n";
	
	src_host = cv::imread("/home/ubuntu/Desktop/gpuThreshTest/ZEDDisparity2.png", CV_LOAD_IMAGE_GRAYSCALE);

	cout << "Declaring GPU Mat\n";
	
	cout << "Uploading to GPU\n";
	src.upload(src_host);
	cout << "Successful Upload to GPU\n";
	
	cout << "Beginning GPU Threshold\n";
	cv::gpu::threshold(src, dst, THRESH, 255.0, THRESH_BINARY);
	//cv::gpu::Canny(src, dst, THRESH, 255.0, false);
	cout << "Successful Threshold";

	src.download(result_host);
	cv::imshow("Result", result_host);
	cv::waitKey();
	}
	
	catch(const cv::Exception& ex){
	std::cout << "Error: " << ex.what() << "\n";	
	}

	return 0;
}
