#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void usage()
{
  std::cout << "Usage :" << std::endl;
  std::cout << "prog file" << std::endl;
}

cv::Mat apply_filter(cv::Mat frame, int filter, bool multithread)
{
  if (filter == 0 && multithread) // bullshit for no warning
    return frame;
  //basi struct, maybe add a number un parameter to choise the filter
  //to apply?
  return frame;
}

int select_filter()
{
  return 0;
}

bool select_multithread()
{
  return false;
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

    //Buged for the moment, it eat the .avi extension (quickfix: add back
    //maybe?)

    /*
    char *tok = std::strtok(str, ".");
    tok = std::strtok(NULL, ".");
    while ((tok = std::strtok(NULL, ".")) && tok[0] != '.')
    {
      if (std::strcmp(tok, "avi") != 0)
      {
        std::cerr << "The selected file is not a .avi" << std::endl;
        return 1;
      }
    }*/
  }

  std::cout << "Opening: " << argv[1] << std::endl;//checking the file name
  cv::VideoCapture vc;
  vc.open(argv[1]);
  if (!vc.isOpened())
  {
    std::cerr << "The file couldn't be opened !" << std::endl;
    return 1;
  }

  int nb_filter = select_filter();//Not used yet
  bool multithread = select_multithread();//false == single thread

  cv::Mat edges;
  cv::namedWindow("J'aime les chatons :3", 1);

  cv::Size frame_size(vc.get(CV_CAP_PROP_FRAME_HEIGHT),
      vc.get(CV_CAP_PROP_FRAME_WIDTH));
  cv::VideoWriter output("output.mp4", vc.get(CV_CAP_PROP_FOURCC),
      vc.get(CV_CAP_PROP_FPS), frame_size, true);

  if (!output.isOpened())
  {
    std::cout << "Failed to write ouput file!" << std::endl;
    return 1;
  }

  int nb_frame = 0;
  int max_frame = vc.get(CV_CAP_PROP_FRAME_COUNT);

  while (nb_frame < max_frame)
  {
    cv::Mat frame;
    vc >> frame;



    cv::Mat filtred_frame = apply_filter(frame, nb_filter, multithread);
    //apply effect here on frame the display it with imshow


    output.write(filtred_frame);

    cv::imshow("J'aime les chatons :3", filtred_frame);
    if (cv::waitKey(30) >= 0)
      break;
    nb_frame++;
  }

  return 0;
}
