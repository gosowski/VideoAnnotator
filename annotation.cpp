#include <iostream>
#include "annotation.h"

Annotation::Annotation(int newTrackId, float newTopX, float newTopY, float newBottomX, float newBottomY, int newFrameNum, bool newVisible, bool newOccluded, bool newGenerated, string newLabel){
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

bool Annotation::getVisible() {
  return visible;
}

float Annotation::getCenterX() {
  return centerX;
}

float Annotation::getCenterY() {
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
