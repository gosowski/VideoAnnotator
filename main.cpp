#include <iostream>
#include "annotation.h"
#include "functions.h"
#include <fstream>
#include <list>
#include <opencv2/opencv.hpp>
// #include <algorithm>
#include <stdlib.h>

using namespace cv;
using namespace std;

void drawRectangle(list <Annotation>::iterator itList, list <Annotation> annotations, string path);
void readCenterCoordinates(list <Annotation>::iterator itList, list <Annotation> annotations);
int speedMeasurement(list <Annotation>::iterator itList, list <Annotation> annotations, list <Annotation>::iterator prev);

int main(int arg, char* argv[]) {

  help();

  ifstream annotation;
  annotation.open(argv[1]);

  //declare variables;
  int newTrackId, newTopX, newTopY, newBottomX, newBottomY, newFrameNum, newCenterX, newCenterY;
  bool newVisible, newOccluded, newGenerated;
  string newLabel;

  //create list for annotation objects and iterator
  list <Annotation> annotationList;
  list <Annotation>::iterator it;

  while(annotation >> newTrackId >> newTopX >> newTopY >> newBottomX >> newBottomY >> newFrameNum >> newVisible >> newOccluded >> newGenerated >> newLabel) {

    //create an instance of object and push it to the end of the list
    Annotation i(newTrackId, newTopX, newTopY, newBottomX, newBottomY, newFrameNum, newVisible, newOccluded, newGenerated, newLabel);

    annotationList.push_back(i);
  }

  //sort objects by frame number
  annotationList.sort();

  drawRectangle(it, annotationList, argv[2]);

  // readCenterCoordinates(it, annotationList);
  return 0;
}

void drawRectangle(list <Annotation>::iterator itList, list <Annotation> annotations, string path) {

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

void readCenterCoordinates(list <Annotation>::iterator itList, list <Annotation> annotations) {

  // itList = annotations.begin();
  for(itList = annotations.begin(); itList != annotations.end(); itList++) {
    cout<<"Track ID "<<(*itList).getTrackId()<<" center coordinates are: ("<<(*itList).getCenterX()<<" , "<<(*itList).getCenterY()<<")"<<endl;
  }
}

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
