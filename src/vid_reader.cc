#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

void usage()
{
  std::cout << "Usage :" << std::endl;
  std::cout << "prog file" << std::endl;
}

int main(int argc, char** argv)
{
  if (argc == 1)
  {
    std::cerr << "Missing argument" << std::endl;
    usage();
    return 1;
  }
  else
  {
    char *str(argv[1]);
    char *tok = std::strtok(str, ".");
    tok = std::strtok(NULL, "");
    if (std::strcmp(tok, ".avi") != 0)
    {
      std::cerr << "The selected file is not a .avi" << std::endl;
      return 1;
    }
  }

  // Opening a file via openCV
  cv::VideoCapture vc(argv[1]);
  if (!vc.isOpened())
  {
    std::cerr << "The file couldn't be opened !" << std::endl;
  }

  cv::Mat edges;
  cv::namedWindow("edges", 1);

  while (1)
  {
    cv::Mat frame;
    vc >> frame;
    //cvtColor(frame, edges, CV_BGR2GRAY);
    cv::Canny(edges, edges, 0, 30, 3);
    cv::imshow("edges", edges);
    if (cv::waitKey(30) >= 0)
      break;
  }

  return 0;
}
