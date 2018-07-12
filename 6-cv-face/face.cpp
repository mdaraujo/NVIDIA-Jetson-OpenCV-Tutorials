#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{	
	cv::Mat img = cv::imread("lenna.png", CV_LOAD_IMAGE_GRAYSCALE);
	
	cv::CascadeClassifier face_detector("/usr/share/OpenCV/haarcascades/haarcascade_frontalface_alt2.xml");
	
	//cv::imshow("before", img);
	//cv::equalizeHist(img, img);
	
	std::vector<cv::Rect> faces;
	face_detector.detectMultiScale(img, faces);
	
	for (size_t i = 0; i < faces.size(); i++)
		cv::rectangle(img, faces[i], cv::Scalar(255));
		
	cv::imshow("img", img);
	cv::waitKey();
}
