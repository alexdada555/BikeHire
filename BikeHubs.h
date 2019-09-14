#ifndef BIKEHUBS_H
#define BIKEHUBS_H

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>


using std::string;
using namespace std;


class BikeHubs
{
    public:
        BikeHubs();
        ReadHubList();
        InitHubList();
        OnHire(std::vector<string>& a,std::vector<int>& b,std::vector<char>& c,int i);

        char Hub[6] = {'A','B','C','D','E','F'};    // hub designations in an array

    private:
        void ArrangeFiles(std::ifstream &Nfile);

};

#endif // BIKEHUBS_H
