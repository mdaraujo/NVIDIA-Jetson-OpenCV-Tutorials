#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>

int main()
{
	cv::VideoCapture input("cube.avi");
	cv::Mat img;
	
	cv::Ptr<cv::ORB> detector = cv::ORB::create(5000);
	cv::Ptr<cv::DescriptorExtractor> extractor = cv::ORB::create();
	std::vector<cv::KeyPoint> img_keypoints, cube_keypoints;
	cv::Mat img_descriptors, cube_descriptors;
	
	
	cv::Mat cube = cv::imread("cube_1.png");
	detector->detect(cube, cube_keypoints);
	extractor->compute(cube, cube_keypoints, cube_descriptors);
	drawKeypoints(cube, cube_keypoints, cube);
	
	for (;;)
	{
		if (!input.read(img))
			break;
			
		detector->detect(img, img_keypoints);
		extractor->compute(img, img_keypoints, img_descriptors);
		drawKeypoints(img, img_keypoints, img);
		
		cv::BFMatcher matcher;
		std::vector<cv::DMatch> matches;
		matcher.match(cube_descriptors, img_descriptors, matches);
		
		cv::Mat img_matches;
		cv::drawMatches(cube, cube_keypoints, img, img_keypoints,
			matches, img_matches);
		
			
		//~ int nMatches = (int) matches.size();
		//~ printf("------- Number of matches: %d \n", nMatches);
		//~ for (int i = 0; i < nMatches; i++)
		//~ {
			//~ printf("-- Good Match [%d] Keypoint 1: %d -- Keypoint 2: %d\n", 
				//~ i, matches[i].queryIdx, matches[i].trainIdx);
		//~ }
		
		
		cv::imshow("img matches", img_matches);
		char c = cv::waitKey();
		
		if (c == 27) // 27 is ESC code
			break;
	}
}
