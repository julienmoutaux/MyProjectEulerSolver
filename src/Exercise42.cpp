#include "Exercise42.h"

#include <Tools.h>
#include <fstream>
#include <list>

#include <PandigitalTool.h>

void Exercise42::Solve()
{
    long long max = 0;
    long long value;
    ifstream infile;
    infile.open ( _filename.c_str(), ifstream::in );
    string input;
    list<long long> words;
    while ( getline ( infile,input,',' ) )
    {
        input = input.substr ( 1,input.size()-2 );
        value = GetSize ( input );
        if ( value > max )
            max = value;
        words.push_back ( value );
    }
    BuildTrianglesTo ( max );
    int cpt = 0;
    for ( list<long long>::iterator iter = words.begin(); iter != words.end(); iter++ )
        if ( _triangles.find ( *iter ) != _triangles.end() )
            cpt++;
    cout<<"Number of triangle words : "<<cpt<<endl;
}

void Exercise42::BuildTrianglesTo ( long long max )
{
    int i = 1;
    long long value ;
    do
    {
        value = 0.5*i* ( i+1 );
        _triangles.insert ( value );
        i++;
    }
    while ( value<max );
}

long long Exercise42::GetSize ( string word )
{
    const char * tab = word.c_str();
    long long returnValue = 0;
    for ( int i = 0; i<word.size(); ++i )
    {
        returnValue += tab[i] - 'A'+ 1;
    }
    return returnValue;
}

void Exercise42::SetDefaultValues()
{
    _filename = "../resources/words.txt";
    cout<<"Using filename "<<_filename<<endl;
}

void Exercise42::AskForParams()
{
    _filename = Tools::Cin::GetValue<string> ( "Wich filename do you want to load ?","../resources/words.txt" );
}

Exercise42::Exercise42()
{

}

Exercise42::~Exercise42()
{

}

