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

  fstream speedFile;
  speedFile.open("/home/ubuntu-vm/Desktop/file.txt", ios::out | ios::trunc);

  for(it=annotationList.begin(), prev=annotationList.end(); it != annotationList.end(); prev=it, ++it ) {

    if((*it).getFrameNum() > 0 && (*it).getTrackId() == (*prev).getTrackId()) {
      int speedX = abs((*it).getCenterX() - (*prev).getCenterX());
      int speedY = abs((*it).getCenterY() - (*prev).getCenterY());
      int trackId = (*it).getTrackId();
      int topX = (*it).getTopX();
      int topY = (*it).getTopY();
      int bottomX = (*it).getBottomX();
      int bottomY = (*it).getBottomY();
      int frameNum = (*it).getFrameNum();
      bool visible = (*it).getVisible();
      bool occluded = (*it).getOccluded();
      bool generated = (*it).getGenerated();
      string label = (*it).getLabel();

      speedFile<<trackId<<" "<<topX<<" "<<topY<<" "<<bottomX<<" "<<bottomY<<" "<<frameNum<<" "<<visible<<" "<<occluded<<" "<<generated<<" "<<label<<" "<<(*it).getCenterX()<<" "<<(*it).getCenterY()<<" "<<speedX<<" "<<speedY<<endl;
    }
  }
  speedFile.close();

  return 0;
}
