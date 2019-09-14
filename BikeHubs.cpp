#include "BikeHubs.h"
#include "PickUpDropOff.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

BikeHubs::BikeHubs()
{
}

BikeHubs::InitHubList()
{
    int bike = 0;
    int BikeCount;

    ofstream Afile,Bfile,Cfile,Dfile,Efile,Ffile;

    Afile.open("AList.txt");
    Bfile.open("BList.txt");
    Cfile.open("CList.txt");
    Dfile.open("DList.txt");
    Efile.open("EList.txt");            // open all data files
    Ffile.open("FList.txt");

    for(BikeCount = 0; BikeCount < 5; BikeCount ++)
    {
        Afile << bike+1 << endl;
        Bfile << bike+6 << endl;
        Cfile << bike+11<< endl;
        Dfile << bike+16<< endl;             // initialise all bikes in data files
        Efile << bike+21<< endl;
        Ffile << bike+26<< endl;

        bike++;
    }

    Afile.close();
    Bfile.close();
    Cfile.close();                           // close files
    Dfile.close();
    Efile.close();
    Ffile.close();
    return(0);
}

void BikeHubs::ArrangeFiles(std::ifstream &Nfile)
{
    string line;
    std::stack<string>a;             // stack declarations of type string
    std::stack<string>b;

    while(!Nfile.eof())
    {
        getline(Nfile,line);
        a.push(line);                    // read file data line by line into stack
    }
    while(!a.empty())
    {
        b.push(a.top());                // read first stack data into another stack to deal with FILO inversion
        a.pop();
    }
    while(!b.empty())
    {
        cout<<b.top()<<"|\t ";           // out but stack data
        b.pop();
    }
    Nfile.close();                    // close file
}

BikeHubs::ReadHubList()
{
    ifstream Afile("AList.txt");
    ifstream Bfile("BList.txt");
    ifstream Cfile("CList.txt");
    ifstream Dfile("DList.txt");      // open files to read from
    ifstream Efile("EList.txt");
    ifstream Ffile("FList.txt");

    cout <<"\n";
    cout <<"\n";


    cout <<"\t\t\t"<<"HUBS"<<"\t\t\t"<<endl;


    cout<<Hub[0]<<"\t|  ";
    ArrangeFiles(Afile);
    cout <<"\n";
    cout<<Hub[1]<<"\t|  ";
    ArrangeFiles(Bfile);
    cout <<"\n";
    cout<<Hub[2]<<"\t|   ";
    ArrangeFiles(Cfile);
    cout <<"\n";
    cout<<Hub[3]<<"\t|  ";               // output stack Hub data
    ArrangeFiles(Dfile);
    cout <<"\n";
    cout<<Hub[4]<<"\t|   ";
    ArrangeFiles(Efile);
    cout <<"\n";
    cout<<Hub[5]<<"\t|   ";
    ArrangeFiles(Ffile);
    cout <<"\n";
    cout<<"\n";

    Afile.close();
    Bfile.close();
    Cfile.close();           // close files
    Dfile.close();
    Efile.close();
    Ffile.close();
    return(0);
}

BikeHubs::OnHire(std::vector<string>& a,std::vector<int>& b,std::vector<char>& c,int i)
{
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";                          // output the vectors holding the bikes out on hire
                                         // by using a for loop to go through all the data containers.
    cout<<"Bikes"<<"|\t"<<"R -Time"<<"|\t"<<"R-Hub"<<"|\t"<<"C-Time"<<"|\t"<<endl;
    for(unsigned int x = 0; x < a.size(); x ++)
    {
        cout<<a[x]<<"|\t"<<b[x]<<"|\t"<<c[x]<<"|\t"<<i<<"|\t"<<endl;
    }
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";

    return(0);
}
