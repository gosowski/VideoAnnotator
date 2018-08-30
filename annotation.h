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
    bool visible;
    bool occluded;
    bool generated;
    string label;
    float centerX;
    float centerY;

  public:
    Annotation(int newTrackId, float newTopX, float newTopY, float newBottomX, float newBottomY, int newFrameNum, bool newVisible, bool newOccluded, bool newGenerated, string newLabel);
    ~Annotation();
    bool operator < (Annotation &obj)const ;

    int getTrackId();
    float getTopX();
    float getTopY();
    float getBottomX();
    float getBottomY();
    int getFrameNum();
    bool getVisible();
    float getCenterX();
    float getCenterY();
    bool getOccluded();
    bool getGenerated();
    string getLabel();
};
