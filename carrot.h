#ifndef CARROT_H
#define CARROT_H
#include "crop.h"


class Carrot : public Crop
{

    public:
    Carrot(int,int,int,int,bool,bool,int = 0,int = 0);


    void plantMenu();
    void checkPlant();

    static int nextCarrotID;

    



    private:
    int carrotID = 0;


};

#endif