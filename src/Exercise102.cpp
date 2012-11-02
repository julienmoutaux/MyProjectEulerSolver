#include "Exercise102.h"

#include <fstream>
#include <Tools.h>
#include <list>
#include <cstdlib>

using namespace std;

void Exercise102::Solve()
{
  ifstream infile;
    infile.open ( _filename.c_str(), ifstream::in );
    string input;    
    int xA,yA,xB,yB,xC,yC;
    long long AB,BC,CA;
    int cpt = 0;
    while ( getline ( infile,input ) )
    {
      std::vector<std::string> vect = split(input, ',') ;
      xA = std::atoi( vect[0].c_str());
      yA = std::atoi( vect[1].c_str());
      xB = std::atoi( vect[2].c_str());
      yB = std::atoi( vect[3].c_str());
      xC = std::atoi( vect[4].c_str());
      yC = std::atoi( vect[5].c_str());
      AB = xA * yB - xB * yA;
      BC = xB * yC - xC * yB;
      CA = xC * yA - xA * yC;
      if ( (AB > 0 && BC > 0 && CA >0) || (AB < 0 && BC < 0 && CA <0) )
	cpt++;
    }
    cout<<"count of tiangles : "<<cpt<<endl;
}

void Exercise102::SetDefaultValues()
{
 _filename = "../resources/triangles.txt";
    cout<<"Using filename "<<_filename<<endl;
}

void Exercise102::AskForParams()
{
     _filename = Tools::Cin::GetValue<string> ( "Wich filename do you want to load ?","../resources/triangles.txt" );
}

Exercise102::Exercise102()
{

}

Exercise102::~Exercise102()
{

}

std::vector<std::string> &Exercise102::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> Exercise102::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

