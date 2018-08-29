#include <iostream>
#include "functions.h"
#include <list>
#include <opencv2/opencv.hpp>


void getLogs(int fr, float tX, float tY, float bX, float bY) {
  std::cout<<fr<<" "<<tX<<" "<<tY<<" "<<bX<<" "<<bY<<"\n";
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

int randomNumber() {
  int color = rand() % 256;
  return color;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

int countNumberOfObjects(list <Annotation>::iterator itList, list <Annotation> annotations) {

  itList = annotations.begin();
  int objCounter = 0;

  while((*itList).getFrameNum() == 0) {
    objCounter++;
    itList++;
  }
  return objCounter;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

void randomColor(int (*randomNumber)(), int red[], int green[], int blue[], int objectsNumber) {
  for(int i=0; i<=objectsNumber; i++) {
    blue[i] = (*randomNumber)();
    green[i] = (*randomNumber)();
    red[i] = (*randomNumber)();
  }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

void drawRectangle(list <Annotation>::iterator itList, list <Annotation> annotations, string path, int blue[], int green[], int red[]) {

  // create video
  cv::VideoCapture video(path);

  //set iterator to the beginning of the list and create new list iterator
  itList = annotations.begin();
  list <Annotation>::iterator prev;
  int trackId = 0;
  float xTop = 0.0;
  float yTop = 0.0;
  float xBottom = 0.0;
  float yBottom = 0.0;
  int frameNum = 0;
  bool frameOut = 0;
  int centerX = 0;
  int centerY = 0;
  
  int checkFrameNum = 0;

  //read video
  for(;;) {
    cv::Mat frame;

    video >> frame;

    //read objects attr values
    while(checkFrameNum == (*itList).getFrameNum()) {

      trackId = (*itList).getTrackId();
      xTop = (*itList).getTopX();
      yTop = (*itList).getTopY();
      xBottom = (*itList).getBottomX();
      yBottom = (*itList).getBottomY();
      centerX = (*itList).getCenterX();
      centerY = (*itList).getCenterY();

      //if frame is visible draw a rectangle and text above it with speed
      //beetwen each frame
        
      getLogs(trackId, xTop, yTop, xBottom, yBottom);

      rectangle(frame, cv::Point(xTop, yTop), cv::Point(xBottom, yBottom), cv::Scalar(blue[trackId], green[trackId], red[trackId]), 1, 8, 0);  
      
      itList++;
    }
    
    checkFrameNum++;    

    //break for loop if there is no frame left
    if(frame.empty()) {
      std::cout<<"End of file"<<std::endl;
      break;
    }

    cv::namedWindow("Frame", 1);
    imshow("Frame", frame);
    char c=(char)cv::waitKey(0);
    if(c==27) {
      break;
    }
  }
}

