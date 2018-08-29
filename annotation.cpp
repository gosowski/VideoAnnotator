#include <iostream>
#include "annotation.h"

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

bool Annotation::operator < (Annotation &obj)const {
  return frameNum < obj.frameNum;
}

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
