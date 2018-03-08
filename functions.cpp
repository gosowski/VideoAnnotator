#include <iostream>
#include "functions.h"
#include <list>
#include <opencv2/opencv.hpp>

void readCenterCoordinates(list <Annotation>::iterator itList, list <Annotation> annotations) {

  for(itList = annotations.begin(); itList != annotations.end(); itList++) {
    cout<<"Track ID "<<(*itList).getTrackId()<<" center coordinates are: ("<<(*itList).getCenterX()<<" , "<<(*itList).getCenterY()<<")"<<endl;
  }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

int speedMeasurement(list <Annotation>::iterator itList, list <Annotation> annotations, list <Annotation>::iterator prev) {
  prev = itList;
  prev--;

  int speed = 0;

  if((*itList).getFrameNum() > 0) {
    while((*prev).getTrackId() != (*itList).getTrackId()) {
      prev--;
      speed = (*itList).getCenterX() - (*prev).getCenterX();
    }
  }
  return speed;
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

void drawRectangle(list <Annotation>::iterator itList, list <Annotation> annotations, string path) {

  using namespace cv;

  // create video
  VideoCapture video(path);
  int checkFrameNum = 0;

  //set iterator to the beginning of the list and create new list iterator
  itList = annotations.begin();
  list <Annotation>::iterator prev;
  int trackId = 0;
  int xTop = 0;
  int yTop = 0;
  int xBottom = 0;
  int yBottom = 0;
  int frameNum = 0;
  bool frameOut = 0;
  int centerX = 0;
  int centerY = 0;

  //read video
  for(;;) {
    Mat frame;

    video >> frame;

    //read objects attr values
    while(checkFrameNum == (*itList).getFrameNum()) {
      trackId = (*itList).getTrackId();
      xTop = (*itList).getTopX();
      yTop = (*itList).getTopY();
      xBottom = (*itList).getBottomX();
      yBottom = (*itList).getBottomY();
      frameOut = (*itList).getVisible();
      centerX = (*itList).getCenterX();
      centerY = (*itList).getCenterY();

      //if frame is visible draw a rectangle and text above it with speed
      //beetwen each frame

      if(frameOut == 0) {

        rectangle(frame, Point(xTop, yTop), Point(xBottom, yBottom), Scalar(51, 255, 255), 1, 8, 0);

        int speed = 0;

        speed = abs(speedMeasurement(itList, annotations, prev));
        cout<<"TrackId: "<<trackId<<" speed: "<<speed<<endl;
        string imageText = to_string(speed);
        putText(frame, imageText, Point(xTop, yTop-10), FONT_HERSHEY_SIMPLEX, 0.3, Scalar(0, 255, 0), 1);

      }

      itList++;

    }
    checkFrameNum++;

    //break for loop if there is no frame left
    if(frame.empty()) {
      break;
    }

    namedWindow("Frame", 1);
    imshow("Frame", frame);
    char c=(char)waitKey(50);
    if(c==27) {
      break;
    }
  }
}
