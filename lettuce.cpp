#include "lettuce.h"

Lettuce::Lettuce(int hp, int wLevel, int f, int a, bool bugs, bool blight, int _level, int day_save) : Crop(hp,wLevel,f,a,bugs,blight,_level,day_save)
{
    lettuceID = nextLettuceID;
    ++nextLettuceID;
    cropName = "Lettuce plant " + to_string(lettuceID) + " 🥬";
    UID = "LETTUCE";
    matureLength = 12; 
}

int Lettuce::nextLettuceID = 1;

void Lettuce::plantMenu()
{
    Crop::cropInfo();
}
void Lettuce::checkPlant()
{

    waterLevel-=3;
    fertilizer-=3;

    if(waterLevel < 0)          {waterLevel = 0;}
    if(fertilizer < 0)          {fertilizer = 0;}

    if(waterLevel == 0 || waterLevel < health-5) {health-=2;} else {health+=2;}

    if(fertilizer == 0 || fertilizer < health-5) {health-=2;} else {health+=2;}

    if(health < 0)  {health = 0;}
    if(health > 10) {health = 10;}

     if(waterLevel > 3 && fertilizer > 3)
    {
        daySave++;
    } else if(waterLevel < 3 && fertilizer < 3)
    {
        if(level == 1) {
            if(daySave < 0) {
                daySave = 0;
            }
        } else if(level == 2) {
            if(daySave < matureLength/3) {
                daySave = matureLength/2;
            }
        } else if(level == 3) {
            daySave = matureLength;
        } else {
            daySave--;
        }
    }  

    if(daySave == matureLength/3)
    {
        level = 1;
    } else if (daySave == matureLength/2) {
        level = 2;
    } else if (daySave == matureLength) {
        level = 3;
    }
}




