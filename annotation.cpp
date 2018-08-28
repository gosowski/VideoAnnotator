#include <iostream>
#include "annotation.h"

using namespace std;

Annotation::Annotation(int newTrackId, float newTopX, float newTopY, float newBottomX, float newBottomY, int newFrameNum) {
  trackId = newTrackId;
  topX = newTopX;
  topY = newTopY;
  bottomX = newBottomX;
  bottomY = newBottomY;
  frameNum = newFrameNum;
  centerX = (newTopX + newBottomX)/2;
  centerY = (newTopY + newBottomY)/2;
}

Annotation::~Annotation() {}

void Annotation::showAttr() {
  cout<<"trackId: "<<trackId<<endl;
  cout<<"top X coordinate: "<<topX<<endl;
  cout<<"top Y coordinate: "<<topY<<endl;
  cout<<"bottom X coordinate: "<<bottomX<<endl;
  cout<<"bottom Y coordinate: "<<bottomY<<endl;
  cout<<"frame number: "<<frameNum<<endl;
}

bool Annotation::operator < (Annotation &obj)const {
  return frameNum < obj.frameNum;
}

void Annotation::printAttrValues() {
  cout<<"trackId: "<<trackId<<endl;
  cout<<"Frame number: "<<frameNum<<endl;
  cout<<"--------------"<<endl;
}

//setter definition
// void setAttributes(int newTrackId) {
//   int trackId = newTrackId;
// }


//getters definitions

int Annotation::getTrackId() {
  return trackId;
}

float Annotation::getTopX() {
  return topX;
}

float Annotation::getTopY() {
  return topY;
}

float Annotation::getBottomX() {
  return bottomX;
}

float Annotation::getBottomY() {
  return bottomY;
}

int Annotation::getFrameNum() {
  return frameNum;
}

float Annotation::getCenterX() {
  return centerX;
}

float Annotation::getCenterY() {
  return centerY;
}
