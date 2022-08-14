#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>

#include "potato.h"
#include "carrot.h"
#include "lettuce.h"

using namespace std;

bool checkInput(string input) {
    for(int i = 0; i < input.size(); i++)
    {
        if(isdigit(input[i]) == false)
        {
            return false;
        }
    }
    return true;
}

void options(vector<Crop*> crops) // crops menu 
{
    cout << RESET;
    cout << "Select plant to tend" << endl;
    cout << "-+-------------------" << endl;
    for(int i = 0; i < crops.size(); i++)
    {
        if(crops.at(i)->getHealth() > 0)
        {
            cout << GREEN << i << RESET << "| " << crops.at(i)->getCropName() << endl;
            cout << "-+-------------------" << endl;
        }
        
    }
    cout << YELLOW << "N" << RESET << "| " << "Start next week" << endl;
    cout << RED << "Q" << RESET << "| " << "Quit and save" << endl;

}

int main() 
{   

    
    bool harvestAtLeastOne = false;
    srand(time(NULL));
    int week = 1;
    Crop* crop;
    vector<Crop*> crops; // vector of crops 
    int newOrLoad;      // user selection of new game or laod

                                                                                                                          
                                                                                                                          
    cout << CLEAR << flush;
    cout << CYAN;
    cout << " ██████ ██████   ██████  ██████      ███████ ██ ███    ███ " << '\n';
    cout << "██      ██   ██ ██    ██ ██   ██     ██      ██ ████  ████ " << '\n';
    cout << "██      ██████  ██    ██ ██████      ███████ ██ ██ ████ ██ " << '\n';
    cout << "██      ██   ██ ██    ██ ██               ██ ██ ██  ██  ██ " << '\n';
    cout << " ██████ ██   ██  ██████  ██          ███████ ██ ██      ██ " << '\n';
    cout << "                                                           " << '\n';

    cout << RESET;

    cout << "Select Option" << endl;
    cout << GREEN << "1| " << RESET << "New game"  << RESET << '\n';
    cout << GREEN << "2| " << RESET << "Load game" << RESET << '\n';


    cin >> newOrLoad; 
    cin.ignore();

       
    





    if(newOrLoad == 1) // if new game then add the crops to the vector
    {
        string potatoCount;
        string carrotCount;
        string lettuceCount;

    
        bool start = false;
           
            moveUp(4);  //move cursor up 4 spaces to erase load and start new game menu
            cout << WHITE << "Potato" << RESET << "  mature length = 6" << '\n';
            cout << MAGENTA << "Carrot" << RESET << "  mature length = 15" << '\n';
            cout << GREEN << "Lettuce" << RESET << " mature length = 12" << '\n';
            cout << "--------------------------------------------------------------------------------------------" << '\n';
            cout << "Potatos are easer to grow and take less water and fertilizer than a carrot and lettuce plant" << endl;
            cout << "Carrot plants take the longest to grow" << endl;
            cout << "Lettuce plants take the most amount of water and fertilizer to grow after each week" << endl;
            cout << "--------------------------------------------------------------------------------------------" << '\n';
            moveDown(1);
            do { //do while user input does not equal an integer
                moveUp(1); // if user input is not an integer move back up one space so user can still enter on the same line
                moveLeft(100);
                cout << WHITE << "Potato" << RESET << " plant count: " << flush;
                getline(cin,potatoCount);
            } while(checkInput(potatoCount) == false);
            moveDown(1);
            do { //do while user input does not equal an integer
                moveUp(1);
                moveLeft(100);
                cout << MAGENTA << "Carrot" << RESET << " plant count: " << flush;
                getline(cin,carrotCount);
            } while(checkInput(carrotCount) == false);
            moveDown(1);
            do { //do while user input does not equal an integer
                moveUp(1);
                moveLeft(100);
                cout << GREEN << "Lettuce" << RESET << " plant count: " << flush;
                getline(cin,lettuceCount);
            } while(checkInput(lettuceCount) == false);

            for(int i = 0;  i < stoi(potatoCount); i++)
            {
                Crop *temp1 = new Potato(10,10,10,0,0,0);
                crops.push_back(temp1);
            }
            
            for(int i = 0;  i < stoi(carrotCount); i++) {
                Crop *temp2 = new Carrot(10,10,10,0,0,0);
                crops.push_back(temp2);
            }
            
            for(int i = 0;  i < stoi(lettuceCount); i++) {
                Crop *temp3 = new Lettuce(10,10,10,0,0,0);
                crops.push_back(temp3);
            }


    } else if (newOrLoad == 2) { // load saved game
        string line;
        ifstream loadFile("crops.txt");
        if(!loadFile.is_open())
        {
            cout << "COULD NOT OPEN FILE" << endl;
        }
        int cropCount = 0;
        while(getline(loadFile,line)) // get line count in file
        {
            if(line.empty())
            {
                cropCount++;
                cout << cropCount << endl;
            }
        }
        string uid;
        string name;
        int s1,s2,s3,s4;
        bool s5,s6;
        int s7,s8;
        loadFile.close();
        loadFile.open("crops.txt");
        loadFile >> week;
        loadFile.ignore();
        while(getline(loadFile,uid))
        {   
            getline(loadFile,name);
            loadFile >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8;
            loadFile.ignore(256,'\n');
            loadFile.ignore(256,'\n');
            
            if(uid == "POTATO")
            {
                crop = new Potato(s1,s2,s3,s4,s5,s6,s7,s8);
            } else if(uid == "CARROT") {
                crop = new Carrot(s1,s2,s3,s4,s5,s6,s7,s8);
            } else if (uid == "LETTUCE") {
                crop = new Lettuce(s1,s2,s3,s4,s5,s6,s7,s8);
            }
            crop->setCropName(name);
            crops.push_back(crop);
        }
    }
    cout << CLEAR << flush;
    bool exit = false; // exit status;
    bool isNextDay = false;
    
    do // game loop
    {   
        if(isNextDay)
        {
            week++;
            for(int i = 0; i < 20; i++)
            {
                cout << CLEAR;
                cout << setw(i) << '.' << flush;
                this_thread::sleep_for(chrono::milliseconds(200));
            }
            printf(CLEAR);
            for(int i = 0; i < crops.size(); i++)  // calling next day function for each crop
            {
                if(crops.at(i)->getHealth() > 0)
                {
                    crops.at(i)->checkBlight();
                    crops.at(i)->checkBugs();
                    crops.at(i)->nextDay();
                }
            }
            for(int i = 0; i < crops.size(); i++)  // delete crop from vector if its dead
                {
                        if(crops.at(i)->getHealth() == 0)
                        {
                            if(crops.at(i)!=nullptr)
                            {   
                                delete crops.at(i);
                                crops.at(i) = nullptr;
                            }
                            crops.erase(crops.begin()+i);
                        }
                }
             if(crops.size() == 0 && harvestAtLeastOne == true)
                {
                    cout << "CONGRATS you Harvested at least one plant" << endl;
                    return 0;
                }

            if(crops.size() == 0)
            {
                cout << CLEAR;
                cout << "GAME OVER" << endl;
                return 0;
            }
            isNextDay = false;   
        } else {
            for(int i = 0; i < crops.size(); i++)
            {
                if(crops.at(i)->getHarvested())
                {   
                    if(crops.at(i)!=nullptr)
                    {   
                        delete crops.at(i);
                        crops.at(i) = nullptr;
                    }
                    crops.erase(crops.begin()+i);
                    harvestAtLeastOne = true;
                }
                if(crops.size() == 0 && harvestAtLeastOne == true)
                {
                    cout << "CONGRATS you Harvested at least one plant" << endl;
                    return 0;
                }
                crops.at(i)->cropInfo();
            }
		}
        string selectedOption;
        cout << endl;
        cout << B_GREEN << WHITE << "WEEK: " << week << RESET << '\n';
            options(crops);
            getline(cin,selectedOption);
            try {
                if(selectedOption == "N" || selectedOption == "n")
                {
                    isNextDay = true;
                } else if(selectedOption == "Q" || selectedOption == "q") {
                    exit = true;
                } else if (stoi(selectedOption) >= 0 && stoi(selectedOption) <= crops.size()) {
                    
                    crops.at(stoi(selectedOption))->tendCrop();
                    
                } else {
                    throw out_of_range("Invalid option");
                }
            } catch(...) {
                cout << CLEAR;
                cout << RED << "Invalid option" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
        remove("crops.txt");// deletes the saved crops so it can be overwritten
        ofstream saveDay("crops.txt");
        saveDay << week << '\n';
        saveDay.close();
        for(int i = 0; i < crops.size(); i++)
        {
            crops.at(i)->saveCrop(week); // save crops
        }
        cout << CLEAR;
    }while(exit != true); // do until user selects q

}