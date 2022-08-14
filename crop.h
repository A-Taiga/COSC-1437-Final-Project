#ifndef CROP_H
#define CROP_H
#include <iostream>
#include "escapeCodes.h"
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;


class Crop
{


    public:
  
    Crop(int,int,int,int,bool,bool,int,int);
    virtual ~Crop();
    string getCropName()const;
    int getHealth() const;
    int getMatureLength() const;
    int getWaterLevel() const;
    int getFertilizer() const;
    int getAge() const;
    bool getHarvested() const;
    void setCropName(string);
    void setHealth(int);
    void setMatureLength(int);
    void setWaterLevel(int);
    void setFertilizer(int);
    bool checkReady();
    void nextDay();
    void checkBlight();
    void checkBugs();
    void cropInfo();
    void tendCrop();
    void saveCrop(int);
    void virtual plantMenu() = 0;
    void virtual checkPlant() = 0;

    protected:
    string cropName;
    int health;
    int matureLength;
    int waterLevel;
    int fertilizer;
    int age;
    bool hasBugs;
    bool hasBlight;
    int level;
    int daySave;
    bool readyToHarvest;
    bool harvested;
    string UID;

    

};


#endif