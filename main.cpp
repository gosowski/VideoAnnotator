#include <iostream>
#include "functions.h"

int main(int argc, char* argv[]) {

  if(argc == 1) {
    help();
    return 0;
  }
  
  std::string annotationPath = argv[1];

  //create list for annotation objects and iterator
  list <Annotation> annotationList;
  list <Annotation>::iterator it;

  pushDataAndSort(annotationList, annotationPath);
  
  int objects = countNumberOfObjects(it, annotationList);

  int *blue = new int [objects];
  int *green = new int [objects];
  int *red = new int [objects];

  //calling functions
  srand(time(NULL));

  randomColor(&randomNumber, red, green, blue, objects);
  drawRectangle(it, annotationList, argv[2], blue, green, red);

  delete [] blue;
  delete [] green;
  delete [] red;
  
  return 0;
}
