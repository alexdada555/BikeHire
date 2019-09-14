#ifndef PICKUPDROPOFF_H
#define PICKUPDROPOFF_H

#include <string>
#include <fstream>
#include <vector>

using std::string;

class PickUpDropOff
{
    public:
        PickUpDropOff();
        string PickUpBike();
        char DropOffBike(std::vector<string>& a,std::vector<int>& b, int i);

        char Hub[6] = {'A','B','C','D','E','F'};
        int x;  // global int for for loops

    private:
        UpdateFiles(string a[],int b,std::ofstream &Nfile);
        UpdateDropOffFiles(string a[],int b,std::ofstream &Nfile);
};

#endif // PICKUPDROPOFF_H
