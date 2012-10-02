#include <iostream>
#include <list>
#include <sstream>

#include "ExerciseDeclaration.h"
#include "ExercisesContainer.h"

using namespace std;

int PrintUsage();

int main(int argc, char * argv[])
{
    ExercisesContainer * container = ExerciseDeclaration::PopulateExercisesContainer();

    /* Analyse des parametres fournis à l'exe */
    bool modeUseDefaultValues = false;
    string specificExercise;
    list<ExerciseFactoryBase *> exercisesFactory = container->GetExerciseList();

    if (argc > 0)
    {
        for(int i = 0; i<argc; i++)
        {
            string t(argv[i]);
            if (t == "--help" || t=="-h")
                return PrintUsage();
            else if (t == "--defaultValues" || t == "-d")
                modeUseDefaultValues = true;
            else if (t== "--exercise" || t == "-e")
            {
                i++;
                if (i>=argc || !specificExercise.empty() )
                    return PrintUsage();
                specificExercise = argv[i];
            }
        }

        if (!specificExercise.empty())
        {
            for(list<ExerciseFactoryBase *>::iterator iter = exercisesFactory.begin(); iter != exercisesFactory.end(); iter++)
                if ((*iter)->GetName() == specificExercise)
                {
                    AbstractSolver * solver = (*iter)->BuildExercise();
                    if (modeUseDefaultValues)
                        solver->ResolveProblemWithDefaultValues();
                    else
                        solver->ResolveProblem();
                    delete solver;
                    return 0;
                }
            cout<<"Parameter error '"<<specificExercise<<"' doesn't exist"<<endl;
            return 0;
        }
    }

    AbstractSolver * solver = 0;
    int numb;
    do
    {
        cout<<"Select the exercise : "<<endl;
        for(list<ExerciseFactoryBase *>::iterator iter = exercisesFactory.begin(); iter != exercisesFactory.end(); iter++)
        {
            cout<<(*iter)->GetIdx()<<" - "<<(*iter)->GetName()<<endl;
        }
        cout<<"Q - Quit application"<<endl;
        cout<<"What is your choice ?"<<endl;

        string input;
        getline(cin,input);

        if (input == "Q")
        {
            cout<<"Bye bye"<<endl;
            return 0;
        }

        istringstream ( input ) >> numb;

        list<ExerciseFactoryBase *>::iterator iter = exercisesFactory.begin();
        for(; iter != exercisesFactory.end(); iter++)
            if ((*iter)->GetIdx() == numb)
            {
                solver = (*iter)->BuildExercise();
                break;
            }
        if (iter == exercisesFactory.end())
            cout<<"invalid entry"<<endl;
        else
        {
            if (modeUseDefaultValues)
                solver->ResolveProblemWithDefaultValues();
            else
                solver->ResolveProblem();
        }

    }
    while(true);

    delete container;
    return 0;
}

int PrintUsage()
{
    cerr<<"ProjectEulerSolver"<<endl;
    cerr<<"\tMade by Jubis"<<endl;
    cerr<<endl;
    cerr<<"Usage : "<<endl;
    cerr<<"\t-h or --help\tprint help"<<endl;
    cerr<<"\t-d or --defaultValues\tUse default values"<<endl;
    cerr<<"\t-e {name} or --exercise {name}\tLaunch exercise {name} directly"<<endl;
    return 0;
}
