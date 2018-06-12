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

float speedMeasurement(list <Annotation>::iterator itList, list <Annotation> annotations, list <Annotation>::iterator prev, char axis) {
  prev = itList;
  prev--;

  float speed = 0.0;

  if((*itList).getFrameNum() > 0) {
    while((*prev).getTrackId() != (*itList).getTrackId()) {
      prev--;
      speed = (*itList).getCenterX() - (*prev).getCenterX();
      if(axis == 'y' || axis == 'Y') {
        speed = (*itList).getCenterY() - (*prev).getCenterY();
      }
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

void randomColor(int (*randomNumber)(), int red[], int green[], int blue[], int objectsNumber) {
  for(int i=0; i<=objectsNumber; i++) {
    blue[i] = (*randomNumber)();
    green[i] = (*randomNumber)();
    red[i] = (*randomNumber)();
  }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

void drawRectangle(list <Annotation>::iterator itList, list <Annotation> annotations, string path, int blue[], int green[], int red[]) {

  using namespace cv;

  // create video
  VideoCapture video(path);

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
  
  int checkFrameNum = 0;

  //read video
  for(;;) {
    Mat frame;

    video >> frame;

    //read objects attr values
    while(checkFrameNum == (*itList).getFrameNum()) {

      itList++;
      std::cout<<"Inside While loop"<<std::endl;

      trackId = (*itList).getTrackId();
      xTop = (*itList).getTopX();
      yTop = (*itList).getTopY();
      xBottom = (*itList).getBottomX();
      yBottom = (*itList).getBottomY();
      frameOut = (*itList).getVisible();
      centerX = (*itList).getCenterX();
      centerY = (*itList).getCenterY();

      std::cout<<"Read from: "<<(*itList).getFrameNum()<<" | "<<checkFrameNum<<" | "<<trackId<<" | "<<xTop<<" | "<<yTop<<" | "<<xBottom<<" | "<<frameOut<<std::endl;

      //if frame is visible draw a rectangle and text above it with speed
      //beetwen each frame

      if(frameOut == 0) {

        rectangle(frame, Point(xTop, yTop), Point(xBottom, yBottom), Scalar(blue[trackId], green[trackId], red[trackId]), 1, 8, 0);

        float speedX = 0.0;
        float speedY = 0.0;

        speedX = fabs(speedMeasurement(itList, annotations, prev));
        speedY = fabs(speedMeasurement(itList, annotations, prev, 'y'));

        string imageTextX = to_string(speedX);
        string imageTextY = to_string(speedY);

        putText(frame, imageTextX, Point(xTop+30, yTop-10), FONT_HERSHEY_SIMPLEX, 0.3, Scalar(0, 255, 0), 1);
        putText(frame, imageTextY, Point(xTop-30, yTop-10), FONT_HERSHEY_SIMPLEX, 0.3, Scalar(0, 255, 0), 1);

      }
    }
    checkFrameNum++;    

    //break for loop if there is no frame left
    if(frame.empty()) {
      std::cout<<"End of file"<<std::endl;
      break;
    }

    namedWindow("Frame", 1);
    imshow("Frame", frame);
    char c=(char)waitKey(0);
    if(c==27) {
      break;
    }
  }
}

void readWriteSpeed(list <Annotation>::iterator itList, list <Annotation> annotations, list <Annotation>::iterator prev) {

  fstream speedFile;
  speedFile.open("/home/ubuntu-vm/Desktop/file.txt", ios::out | ios::trunc);

  for(itList=annotations.begin(), prev=annotations.end(); itList != annotations.end(); prev=itList, ++itList ) {

    float speedX = fabs((*itList).getCenterX() - (*prev).getCenterX());
    float speedY = fabs((*itList).getCenterY() - (*prev).getCenterY());
    int trackId = (*itList).getTrackId();
    float topX = (*itList).getTopX();
    float topY = (*itList).getTopY();
    float bottomX = (*itList).getBottomX();
    float bottomY = (*itList).getBottomY();

    if((*itList).getFrameNum() > 0 && (*itList).getTrackId() == (*prev).getTrackId()) {

      speedFile<<trackId<<" "<<topX<<" "<<topY<<" "<<bottomX<<" "<<bottomY<<" "<<speedX<<" "<<speedY<<endl;
    } else {

      speedFile<<trackId<<" "<<topX<<" "<<topY<<" "<<bottomX<<" "<<bottomY<<" 0 0 "<<endl;
    }
  }
  speedFile.close();

}
