#include <iostream>
#include <list>

#include "ExerciseDeclaration.h"
#include "ExercisesContainer.h"

using namespace std;

int main()
{
    cout<<"hello world"<<endl;
    ExercisesContainer * container = ExerciseDeclaration::PopulateExercisesContainer();

    list<ExerciseFactoryBase *> myList = container->GetExerciseList();
    for(list<ExerciseFactoryBase *>::iterator iter = myList.begin();iter != myList.end();iter++)
    {
            cout<<(*iter)->GetIdx()<<" - "<<(*iter)->GetName()<<endl;
            (*iter)->BuildExercise()->ResolveProblem();
    }

    delete container;
    return 0;
}
