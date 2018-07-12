#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	cv::VideoCapture input(1);
	cv::Mat img;
	
	cv::VideoWriter output(
		"cube.avi",
		CV_FOURCC('X', 'V', 'I', 'D'),
		30,
		cv::Size(input.get(CV_CAP_PROP_FRAME_WIDTH),
				 input.get(CV_CAP_PROP_FRAME_HEIGHT)));
				 
	cv::Mat cube;
	input.read(cube);
	cv::imwrite("cube.png", cube);
	
	for (;;)
	{
		if (!input.read(img))
			break;
		
		output.write(img);
			
		cv::imshow("img", img);
		char c = cv::waitKey(30);
		
		if (c == ' ')
			break;
	}
}
