#include <iostream>
#include "functions.h"
#include <fstream>
#include <list>
#include <stdlib.h>
#include <time.h>

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
  list <Annotation>::iterator prev;

  while(annotation >> newTrackId >> newTopX >> newTopY >> newBottomX >> newBottomY >> newFrameNum >> newVisible >> newOccluded >> newGenerated >> newLabel) {

    //create an instance of object and push it to the end of the list
    Annotation i(newTrackId, newTopX, newTopY, newBottomX, newBottomY, newFrameNum, newVisible, newOccluded, newGenerated, newLabel);

    annotationList.push_back(i);
  }

  readWriteSpeed(it, annotationList, prev);

  return 0;
}
