#include <iostream>
#include "functions.h"
#include <fstream>
#include <list>
#include <stdlib.h>

using namespace std;

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

  readCenterCoordinates(it, annotationList);
  return 0;
}
