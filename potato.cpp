#include "potato.h"

Potato::Potato(int hp, int wLevel, int f, int a, bool bugs, bool blight, int _level, int day_save) : Crop(hp,wLevel,f,a,bugs,blight,_level,day_save)
{
    potatoID = nextPotatoID;
    ++nextPotatoID;
    cropName = "Potato  plant " + to_string(potatoID) + " 🥔";
    UID = "POTATO";
    matureLength = 6; 
 
}

int Potato::nextPotatoID = 1;

void Potato::plantMenu()
{
   
   Crop::cropInfo();
  
}
void Potato::checkPlant()
{
    waterLevel--;
    fertilizer--;
    if(waterLevel < 0) {waterLevel = 0;} // if water level falls below 0 then set it to 0
    if(fertilizer < 0) {fertilizer = 0;} // same as waterlevel
    if(waterLevel == 0 || waterLevel < health-3) {health--;} else {health++;} // subtract health based on water level
    if(fertilizer == 0 || fertilizer < health-4) {health--;} else {health++;} // subtract health based on fertilizer level
    if(health < 0)  {health = 0;} // keep health at 0 if it falls below 0
    if(health > 10) {health = 10;} // keep health at 10 if it goes above 10
    if(waterLevel > 7 && fertilizer > 7) // start checking if plant can level up
    {
        daySave++; // add to daySave
    } else if(waterLevel < 7 && fertilizer < 7) // threshold for subtracting the daysave 
    {
        if(level == 1) {  
            if(daySave < 0) {
                daySave = 0;
            }
        } else if(level == 2) { // if level 2
            if(daySave < matureLength/3) { // and if daySave is below level 3
                daySave = matureLength/2; // daySave will equal level 2 matureLength
            }
        } else if(level == 3) {
            daySave = matureLength;
        } else {
            daySave--; // else then subtract daySave
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


