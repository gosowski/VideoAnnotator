#include <iostream>
#include "functions.h"
#include <fstream>
#include <list>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]) {
  if(argc == 1) {
    help();
    return 0;
  }

  ifstream annotation;
  annotation.open(argv[1]);

  //declare variables;
  int newTrackId, newFrameNum;
  float newTopX, newTopY, newBottomX, newBottomY, newCenterX, newCenterY;
  bool newVisible, newOccluded, newGenerated;
  string newLabel;

  //create list for annotation objects and iterator
  list <Annotation> annotationList;
  list <Annotation>::iterator it;
  list <Annotation>::iterator prev;

  while(annotation >> newTrackId >> newTopX >> newTopY >> newBottomX >> newBottomY >> newFrameNum >> newVisible >> newOccluded >> newGenerated >> newLabel) {

    //create an instance of object and push it to the end of the list
    Annotation i(newTrackId, newTopX, newTopY, newBottomX, newBottomY, newFrameNum, newVisible, newOccluded, newGenerated, newLabel);

    annotationList.push_back(i);
  }

  readWriteSpeed(it, annotationList, prev);

  //sort objects by frame number
  annotationList.sort();

  int objects = countNumberOfObjects(it, annotationList);

  int *blue = new int [objects];
  int *green = new int [objects];
  int *red = new int [objects];


  //calling functions
  srand(time(NULL));

  randomColor(&randomNumber, red, green, blue, objects);
  drawRectangle(it, annotationList, argv[2], blue, green, red);
  // readCenterCoordinates(it, annotationList);

  return 0;
}
