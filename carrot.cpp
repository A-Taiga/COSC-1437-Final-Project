#include "carrot.h"

Carrot::Carrot(int hp, int wLevel, int f, int a, bool bugs, bool blight, int _level, int day_save) : Crop(hp,wLevel,f,a,bugs,blight,_level,day_save)
{
    carrotID = nextCarrotID;
    ++nextCarrotID;
    cropName = "Carrot  plant " + to_string(carrotID) + " 🥕";
    UID = "CARROT";
    matureLength = 15; 
}

int Carrot::nextCarrotID = 1;

void Carrot::plantMenu()
{
    Crop::cropInfo();
    
}
void Carrot::checkPlant()
{
    waterLevel-=2;
    fertilizer-=2;

    if(waterLevel < 0)          {waterLevel = 0;}
    if(fertilizer < 0)          {fertilizer = 0;}

    if(waterLevel == 0 || waterLevel < health-3) {health-=2;} else {health+=2;}

    if(fertilizer == 0 || fertilizer < health-4) {health-=2;} else {health+=2;}

    if(health < 0)  {health = 0;}
    if(health > 10) {health = 10;}


     if(waterLevel > 5 && fertilizer > 5)
    {
        daySave++;
    } else if(waterLevel < 5 && fertilizer < 5)
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
