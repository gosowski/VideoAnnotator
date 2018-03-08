#ifndef functions_h
#define functions_h

#include <list>
#include "annotation.h"

void help();
void readCenterCoordinates(list <Annotation>::iterator itList, list <Annotation> annotations);
int speedMeasurement(list <Annotation>::iterator itList, list <Annotation> annotations, list <Annotation>::iterator prev);
void drawRectangle(list <Annotation>::iterator itList, list <Annotation> annotations, string path);

#endif
