#include "crop.h"

Crop::Crop(int hp, int wLevel, int f, int a, bool bugs, bool blight, int _level, int day_save) : health(hp),waterLevel(wLevel),fertilizer(f), age(a), hasBugs(bugs), hasBlight(blight), level(_level), daySave(day_save)
{  
    
}

string Crop::getCropName() const
{
    return cropName;
}
int Crop::getHealth() const
{
    return health;
}
int Crop::getMatureLength() const
{
    return matureLength;
}
int Crop::getWaterLevel() const
{
    return waterLevel;
}
int Crop::getFertilizer() const
{
    return fertilizer;
}
int Crop::getAge() const
{
    return age;
}
bool Crop::getHarvested() const
{
    return harvested;
}
void Crop::setCropName(string name)
{
    cropName = name;
}
void Crop::setHealth(int hp)
{
    health = hp;
}
void Crop::setMatureLength(int ml)
{
    matureLength = ml;
}
void Crop::setWaterLevel(int wlevel)
{
    waterLevel = wlevel;
}
void Crop::setFertilizer(int f)
{
    fertilizer = f;
}
bool Crop::checkReady()
{
    if(waterLevel > 8 && fertilizer > 7 && health > 8) {return true;}
    return false;
}
void Crop::nextDay() // changes states
{
    checkPlant();
    age++;
    cropInfo();
}

void Crop::checkBlight()
{
    if(hasBlight) return;
    
    int base   = rand() % 30 + 1;
    int match  = rand() % 30 + 1;
    hasBlight = (base == match) ? true : false;
    
}
void Crop::checkBugs()
{
    if(hasBugs) return;

    int base   = rand() % 30 + 1;
    int match  = rand() % 30 + 1;
    if(base == match) {hasBugs = true;}
    hasBugs = (base == match) ? true : false;
    

}
void Crop::cropInfo()
{   

    if(level == 3 && health > 5)
    {
        cout << cropName << " is ready to harvest" << endl;
        readyToHarvest = true;
    } else {
        readyToHarvest = false;
    }

    string line1 = YELLOW "|" WHITE "   " + cropName;
    string line2 = YELLOW "|" WHITE "   Level: " + to_string(level);
    string line3 = YELLOW "|" GREEN "   Health: " + to_string(health);
    string line4 = YELLOW "|" CYAN  "   WaterLevel: " + to_string(waterLevel);
    string line5 = YELLOW "|" MAGENTA  "   Fertilizer level: " + to_string(fertilizer);
    string line6 = YELLOW "|" WHITE "   Age: " + to_string(age);
    string line7 = YELLOW "|" RED "   HAS BUGS";
    string line8 = YELLOW "|" RED "   HAS BLIGHT";

     if(health == 0)
    {
        cout << YELLOW << "+--------------------------+" << endl;
        for(int i = 0; i < 5; i++)
        {
           if(i == 2)
           {
             
              cout << line1 << setw(4+YELLOW_LENGTH) << YELLOW << "|" << '\n';
              cout << "|" << "   HAS DIED" << setw(line1.length()-16) << YELLOW << "|" << '\n';
           } else { 
               cout << YELLOW "|" << B_RED << setw(26) << " " << RESET << YELLOW "|" << '\n';
           }
        }
        cout << RESET;
        cout << YELLOW << "+--------------------------+" << endl;
        return;
    }

    cout << YELLOW << "+" << setw(line1.length() + 5 - YELLOW_LENGTH - WHITE_LENGTH) << setfill('-') << '+' << '\n';
    cout << setfill(' ');
    cout << line1 << setw(4 + YELLOW_LENGTH) << YELLOW << "|" << '\n';
    cout << line2 << setw(line1.length()-line2.length()+ 2 + YELLOW_LENGTH) << YELLOW << "|" << '\n';
    cout << line3 << setw(line1.length()-line3.length()+ 2 + YELLOW_LENGTH) << YELLOW << "|" << '\n';  
    cout << line4 << setw(line1.length()-line4.length()+ 2 + YELLOW_LENGTH) << YELLOW << "|" << '\n';
    cout << line5 << setw(line1.length()-line5.length()+ 2 + YELLOW_LENGTH) << YELLOW << "|" << '\n';
    cout << line6 << setw(line1.length()-line6.length()+ 2 + YELLOW_LENGTH) << YELLOW << "|" << '\n';
    if(hasBugs){cout << line7 << setw(line1.length()-line7.length()+ 2 + YELLOW_LENGTH) << YELLOW << "|" << '\n';}
    if(hasBlight){cout << line8 << setw(line1.length()-line8.length()+ 2 + YELLOW_LENGTH) << YELLOW << "|" << '\n';}
    cout << RESET;                   
    cout << YELLOW << "+" << setw(line1.length() + 5 - YELLOW_LENGTH - WHITE_LENGTH) << setfill('-') << '+' << '\n';
   
    cout << setfill(' ');

}
void Crop::tendCrop()
{
    cout << CLEAR << flush;
    cropInfo();
    cout << endl;
    cout << RESET;
    cout << "Options" << endl;
    cout << GREEN << "1| " << RESET << "Water" << endl;    
    cout << GREEN << "2| " << RESET << "Fertilize" << endl;
    cout << GREEN << "3| " << RESET << "Treat blight" << endl;
    cout << GREEN << "4| " << RESET << "Treat bugs" << endl;
    cout << RED   << "B| " << RESET << "Exit" << RESET << endl;
    if(readyToHarvest) {cout << CYAN << "H| " << RESET << "Harvest" << RESET << endl;}
    
    char option;
    cin >> option;
    cin.ignore();
    option = toupper(option);
    bool leave = false;

    switch(option) // checks user input
    {
        case '1': // add water to plant
        {
            if(waterLevel == 10)
            {
                cout << CLEAR;
                cout << RED << "Plant is already waterd" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            } else {
                waterLevel=10;
            }
        } break;
        case '2': // add fertilizer to plant
        { 
            if(fertilizer == 10)
            {
                cout << CLEAR;
                cout << RED << "Plant is already fertelized" << endl;
                this_thread::sleep_for(chrono::seconds(1));

            } else {
                fertilizer=10;
            }
        }break;
        case '3': // remove blight if plant has it
            if(hasBlight) 
            {
                hasBlight = false;
            } else {
                cout << CLEAR;
                cout << RED << "Plant has no Blight" << RESET << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            break;
        case '4': // remove bugs if plant has it
            if(hasBugs) 
            {
                hasBugs = false;
            } else {
                cout << CLEAR;
                cout << RED << "Plant has no Bugs" << RESET << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            break;
        case 'B':  // leave menu
            leave = true;
            break;
        case 'H':
            if(readyToHarvest)
            {
                harvested = true;
                leave=true;
            } break;
        default: // invalid entry
            cout << CLEAR << flush;
            cout << "Invalid option" << endl;
            this_thread::sleep_for(chrono::seconds(1));
    }
    if(!leave) // if back button is not pressed then stay in this menu
    {
        tendCrop();
    }
    printf(CLEAR);
    

}
void Crop::saveCrop(int day) // saves crop
{

    ofstream save("crops.txt", ios::app);
    save << UID << '\n';
    save << cropName        << '\n';
    save << health << " " << waterLevel << " " 
         << fertilizer << " " << age << " " 
         << hasBugs << " " << hasBlight << " "
         << level << " " << daySave << '\n';
    save << '\n';
    save.close();

}
Crop::~Crop()
{

}