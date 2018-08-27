#include <iostream>

using namespace std;

class Annotation {

  private:
    int trackId;
    float topX;
    float topY;
    float bottomX;
    float bottomY;
    int frameNum;
    float centerX;
    float centerY;

  public:
    Annotation(int newTrackId, float newTopX, float newTopY, float newBottomX, float newBottomY, int newFrameNum);
    ~Annotation();

    void showAttr();

    bool operator < (Annotation &obj)const ;

    void printAttrValues();

  //setter declaration
  // void setAttributes(int newTrackId);

  // //getters declarations
  int getTrackId();
  float getTopX();
  float getTopY();
  float getBottomX();
  float getBottomY();
  int getFrameNum();
  float getCenterX();
  float getCenterY();
};
