#include "PickUpDropOff.h"
#include "BikeHubs.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

PickUpDropOff::PickUpDropOff()
{
}

PickUpDropOff::UpdateFiles(string a[],int b,std::ofstream &Nfile)
{
    for(x = 0; x < b-1; x ++)
    {
        Nfile<< a[1+x]<<endl;           // writes data from arrays into specified files
    }

    Nfile.close();
    return(0);
}

PickUpDropOff::UpdateDropOffFiles(string a[],int b,std::ofstream &Nfile)
{
    for(x = 0; x < b; x ++)
    {
        Nfile<< a[x]<<endl;         // writes data from arrays into specified files (differs from the above function);
    }

    Nfile.close();
    return(0);
}

string PickUpDropOff::PickUpBike()
{
    string resp,line,Hired;
    string data[30];         // strings to hold response and file

    cout <<"\n";
    cout <<"\n";

    cout << "Would You Like To Hire A Bike ? yes or no"<< "\n";
    cin >> resp;
    while (resp != "yes" && resp != "no")
    {
        if(resp != "yes" && resp != "no")
        {
            cout <<"Please enter either yes or no"<<endl;
            cin >> resp;                                              // reject all input not yes or no
        }
    }

    if(resp == "yes")
    {
        cout << "Please Select Which Hub To Pick-Up From:" <<endl;
        for(x = 0; x < 6; x ++)
        {
            cout << "  " <<Hub[x]<< endl;
        }
        cout << "\n";
        while(1)
        {
            int i = 0;
            char select;
            cin >> select;
            while (select != 'A' && select!= 'B' && select!= 'C'&& select!= 'D' && select!= 'E' && select!= 'F')
            {
                if(select != 'A' && select!= 'B' && select!= 'C'&& select!= 'D' && select!= 'E' && select!= 'F')
                {
                    cout <<"Please enter either A,B,C,D,E or F"<<endl;
                    cin >> select;                                              // and run reject all input not a hub designation
                }
            }

            if(select == 'A')
            {
                ifstream Afile;
                Afile.open("AList.txt");
                while(!Afile.eof())             // read through the file and extract each line as a string
                {
                    getline(Afile,line);
                    data[i] = line;           // save each line as an array
                    cout << data[i] <<endl;
                    i = i+1;                      // count the number of lines in the file.
                }
                if(i == 1)                 // if there is no data left in the file ask used to choose another hub
                {
                    cout << "There Are No Bike At This Hub Currently" <<endl;
                    cout << "Please Choose another Hub" <<endl;
                }
                else                   // otherwise...
                {
                    Hired = data[0];   // give the user the first(Topmost) bike on the list
                    Afile.close();    // close file
                    ofstream N1file("AList.txt");
                    UpdateFiles(data,i-1,N1file);     // re- open file then update list of bikes in file
                    cout << "You Have Been Assigned Bike no."<<Hired<<endl;
                    break;
                }
            }
                                                    // similarly for all other hubs
            else if(select == 'B')
            {
                ifstream Bfile;
                Bfile.open("BList.txt");
                while(!Bfile.eof())
                {
                    getline(Bfile,line);
                    data[i] = line;
                    cout << data[i] <<endl;
                    i = i+1;
                }
                if(i == 1)
                {
                    cout << "There Are No Bike At This Hub Currently" <<endl;
                    cout << "Please Choose another Hub" <<endl;
                }
                else
                {
                    Hired = data[0];
                    Bfile.close();
                    ofstream N1file("BList.txt");
                    UpdateFiles(data,i-1,N1file);
                    cout << "You Have Been Assigned Bike no."<<Hired<<endl;
                    break;
                }
            }

            if(select == 'C')
            {
                ifstream Cfile;
                Cfile.open("CList.txt");
                while(!Cfile.eof())
                {
                    getline(Cfile,line);
                    data[i] = line;
                    cout << data[i] <<endl;
                    i = i+1;
                }
                if(i == 1)
                {
                    cout << "There Are No Bike At This Hub Currently" <<endl;
                    cout << "Please Choose another Hub" <<endl;
                }
                else
                {
                    Hired = data[0];
                    Cfile.close();
                    ofstream N1file("CList.txt");
                    UpdateFiles(data,i-1,N1file);
                    cout << "You Have Been Assigned Bike no."<<Hired<<endl;
                    break;
                }
            }

            if(select == 'D')
            {
                ifstream Dfile;
                Dfile.open("DList.txt");
                while(!Dfile.eof())
                {
                    getline(Dfile,line);
                    data[i] = line;
                    cout << data[i] <<endl;
                    i = i+1;
                }
                if(i == 1)
                {
                    cout << "There Are No Bike At This Hub Currently" <<endl;
                    cout << "Please Choose another Hub" <<endl;
                }
                else
                {
                    Hired = data[0];
                    Dfile.close();
                    ofstream N1file("DList.txt");
                    UpdateFiles(data,i-1,N1file);
                    cout << "You Have Been Assigned Bike no."<<Hired<<endl;
                    break;
                }
            }

            if(select == 'E')
            {
                ifstream Efile;
                Efile.open("EList.txt");
                while(!Efile.eof())
                {
                    getline(Efile,line);
                    data[i] = line;
                    cout << data[i] <<endl;
                    i = i+1;
                }
                if(i == 1)
                {
                    cout << "There Are No Bike At This Hub Currently" <<endl;
                    cout << "Please Choose another Hub" <<endl;
                }
                else
                {
                    Hired = data[0];
                    Efile.close();
                    ofstream N1file("EList.txt");
                    UpdateFiles(data,i-1,N1file);
                    cout << "You Have Been Assigned Bike no."<<Hired<<endl;
                    break;
                }
            }

            if(select == 'F')
            {
                ifstream Ffile;
                Ffile.open("FList.txt");
                while(!Ffile.eof())
                {
                    getline(Ffile,line);
                    data[i] = line;
                    cout << data[i] <<endl;
                    i = i+1;
                }
                if(i == 1)
                {
                    cout << "There Are No Bike At This Hub Currently" <<endl;
                    cout << "Please Choose another Hub" <<endl;
                }
                else
                {
                    Hired = data[0];
                    Ffile.close();
                    ofstream N1file("FList.txt");
                    UpdateFiles(data,i-1,N1file);
                    cout << "You Have Been Assigned Bike no."<<Hired<<endl;
                    break;
                }
            }

        }
    }
    else
    {
        Hired = "non";
    }
     return(Hired);
}

char PickUpDropOff::DropOffBike(std::vector<string>& a,std::vector<int>& b, int i)
{
    string data[30],line;

    int j = 0;

    cout << "Please Select Which Hub To Drop-Off At"<<endl;
    char select;
    cin >> select;
    while (select != 'A' && select!= 'B' && select!= 'C'&& select!= 'D' && select!= 'E' && select!= 'F')
    {
        if(select != 'A' && select!= 'B' && select!= 'C'&& select!= 'D' && select!= 'E' && select!= 'F')
        {
            cout <<"Please enter either A,B,C,D,E or F"<<endl;
            cin >> select;                                              // rejects all input not a hub designation
        }
    }
    if(select == 'A')        // if hub A is selected
    {
        for(unsigned int x = 0; x < a.size() ; x++)  // check through all the data in the vector
        {
            if(b[x] == i)                           // if the current time matches the return time...
            {
                ifstream Afile;
                Afile.open("AList.txt");              // open file
                while(!Afile.eof())
                {
                    getline(Afile,line);              // read, modify and store file data in an array
                    data[0] = a[x];
                    data[j+1] = line;
                    j = j+1;                      // count the number of lines in the file.
                }
                Afile.close();                    // close file
                ofstream N1file("AList.txt");      // open and update file data with the array data
                UpdateDropOffFiles(data,j,N1file);
            }
        }
    }
                                                // similarly for other Hub choices below...
    if(select == 'B')
    {
        for(unsigned int x = 0; x < a.size() ; x++)
        {
            if(b[x] == i)
            {
                ifstream Bfile;
                Bfile.open("BList.txt");
                while(!Bfile.eof())
                {
                    getline(Bfile,line);
                    data[0] = a[x];
                    data[j+1] = line;
                    j = j+1;
                }
                Bfile.close();
                ofstream N1file("BList.txt");
                UpdateDropOffFiles(data,j,N1file);
            }
        }
    }
    if(select == 'C')
    {
        for(unsigned int x = 0; x < a.size() ; x++)
        {
            if(b[x] == i)
            {
                ifstream Cfile;
                Cfile.open("CList.txt");
                while(!Cfile.eof())
                {
                    getline(Cfile,line);
                    data[0] = a[x];
                    data[j+1] = line;
                    j = j+1;
                }
                Cfile.close();
                ofstream N1file("CList.txt");
                UpdateDropOffFiles(data,j,N1file);
            }
        }
    }
    if(select == 'D')
    {
        for(unsigned int x = 0; x < a.size() ; x++)
        {
            if(b[x] == i)
            {
                ifstream Dfile;
                Dfile.open("DList.txt");
                while(!Dfile.eof())
                {
                    getline(Dfile,line);
                    data[0] = a[x];
                    data[j+1] = line;
                    j = j+1;
                }
                Dfile.close();
                ofstream N1file("DList.txt");
                UpdateDropOffFiles(data,j,N1file);
            }
        }
    }
    if(select == 'E')
    {
        for(unsigned int x = 0; x < a.size() ; x++)
        {
            if(b[x] == i)
            {
                ifstream Efile;
                Efile.open("EList.txt");
                while(!Efile.eof())
                {
                    getline(Efile,line);
                    data[0] = a[x];
                    data[j+1] = line;
                    j = j+1;
                }
                Efile.close();
                ofstream N1file("EList.txt");
                UpdateDropOffFiles(data,j,N1file);
            }
        }
    }
    if(select == 'F')
    {
        for(unsigned int x = 0; x < a.size() ; x++)
        {
            if(b[x] == i)
            {
                ifstream Ffile;
                Ffile.open("FList.txt");
                while(!Ffile.eof())
                {
                    getline(Ffile,line);
                    data[0] = a[x];
                    data[j+1] = line;
                    j = j+1;
                }
                Ffile.close();
                ofstream N1file("FList.txt");
                UpdateDropOffFiles(data,j,N1file);
            }
        }
    }
    return(select);   // out put the choosen hub
}
