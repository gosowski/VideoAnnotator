#ifndef functions_h
#define functions_h

#include <list>
#include "annotation.h"

void help(); //print using instructions
void drawRectangle(list <Annotation>::iterator &, list <Annotation> &, string path, int blue[], int green[], int red[]); //draw a bounding box on each frame on video
int randomNumber(); //find random number from 0 - 255
int countNumberOfObjects(list <Annotation>::iterator &, list <Annotation> &); //cout number of different objects
void randomColor(int (*randomNumber)(), int red[], int green[], int blue[], int objectsNumber); //find random colors and assign it to the arrays
void getLogs(int, float, float, float, float, int);
bool pushDataAndSort(std::list<Annotation> &, std::string);

#endif
