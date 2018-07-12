#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	cv::Mat img = cv::imread("lenna.png");
	
	cv::Mat dst;
	cv::Sobel(img, dst, CV_32F, 1, 1);
	
	//cv::imshow("img", dst / 256);
	//cv::waitKey();
	
	cv::imwrite("lenna_sobel.png", dst);
	
	cv::VideoCapture input("parking_sfm.mp4");
	//cv::VideoCapture input(1);
	
	cv::VideoWriter output(
		"parking_sfm_sobel.avi",
		CV_FOURCC('X', 'V', 'I', 'D'),
		30,
		cv::Size(input.get(CV_CAP_PROP_FRAME_WIDTH),
				 input.get(CV_CAP_PROP_FRAME_HEIGHT)));
	
	for (;;)
	{
		if (!input.read(img))
			break;
			
		cv::Sobel(img, dst, CV_8U, 1, 1);
		
		output.write(dst);
			
		cv::imshow("img", img);
		char c = cv::waitKey(1);
		
		if (c == ' ')
			break;
	}
}
