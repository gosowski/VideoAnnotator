#ifndef functions_h
#define functions_h

#include <list>
#include "annotation.h"

void help(); //print using instructions
void readCenterCoordinates(list <Annotation>::iterator itList, list <Annotation> annotations); //read and print coordinates of centered pount of bounding box
int speedMeasurement(list <Annotation>::iterator itList, list <Annotation> annotations, list <Annotation>::iterator prev); //count speed of object beetwen current and previous frame
void drawRectangle(list <Annotation>::iterator itList, list <Annotation> annotations, string path); //draw a bounding box on each frame on video
int randomNumber(); //find random number from 0 - 255
int countNumberOfObjects(list <Annotation>::iterator itList, list <Annotation> annotations); //cout number of different objects

#endif
