#include <iostream>
#include "annotation.h"

using namespace std;

Annotation::Annotation(int newTrackId, int newTopX, int newTopY, int newBottomX, int newBottomY, int newFrameNum, bool newVisible, bool newOccluded, bool newGenerated, string newLabel) {
  trackId = newTrackId;
  topX = newTopX;
  topY = newTopY;
  bottomX = newBottomX;
  bottomY = newBottomY;
  frameNum = newFrameNum;
  visible = newVisible;
  occluded = newOccluded;
  generated = newGenerated;
  label = newLabel;
  centerX = (newTopX + newBottomX)/2;
  centerY = (newTopY + newBottomY)/2;
}

// Annotation::~Annotation() {
//   cout<<"destruct"<<endl;
// }

void Annotation::showAttr() {
  cout<<"trackId: "<<trackId<<endl;
  cout<<"top X coordinate: "<<topX<<endl;
  cout<<"top Y coordinate: "<<topY<<endl;
  cout<<"bottom X coordinate: "<<bottomX<<endl;
  cout<<"bottom Y coordinate: "<<bottomY<<endl;
  cout<<"frame number: "<<frameNum<<endl;
  if(visible) {
    cout<<"Frame visible"<<endl;
  } else {
    cout<<"Frame not visible"<<endl;
  }
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

int Annotation::getTopX() {
  return topX;
}

int Annotation::getTopY() {
  return topY;
}

int Annotation::getBottomX() {
  return bottomX;
}

int Annotation::getBottomY() {
  return bottomY;
}

int Annotation::getFrameNum() {
  return frameNum;
}

bool Annotation::getVisible() {
  return visible;
}

int Annotation::getCenterX() {
  return centerX;
}

int Annotation::getCenterY() {
  return centerY;
}

bool Annotation::getOccluded() {
  return occluded;
}

bool Annotation::getGenerated() {
  return generated;
}

string Annotation::getLabel() {
  return label;
}
