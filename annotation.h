#include <iostream>

using namespace std;

class Annotation {

  private:
    int trackId;
    int topX;
    int topY;
    int bottomX;
    int bottomY;
    int frameNum;
    bool visible;
    bool occluded;
    bool generated;
    string label;
    int centerX;
    int centerY;

  public:
    Annotation(int newTrackId, int newTopX, int newTopY, int newBottomX, int newBottomY, int newFrameNum, bool newVisible, bool newOccluded, bool newGenerated, string newLabel);
    // ~Annotation();

    void showAttr();

    bool operator < (Annotation &obj)const ;

    void printAttrValues();

  //setter declaration
  // void setAttributes(int newTrackId);

  // //getters declarations
  int getTrackId();
  int getTopX();
  int getTopY();
  int getBottomX();
  int getBottomY();
  int getFrameNum();
  bool getVisible();
  int getCenterX();
  int getCenterY();
};
