#ifndef POTATO_H
#define POTATO_H
#include "crop.h"
#include <iostream>
using namespace std;


class Potato : public Crop
{

    public:
    Potato(int,int,int,int,bool,bool,int = 0,int = 0);
    
    void plantMenu();
    void checkPlant();
    static int nextPotatoID;

    private:
    int potatoID = 0;
    
   

};

#endif