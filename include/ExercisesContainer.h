#ifndef EXERCISESCONTAINER_H
#define EXERCISESCONTAINER_H

#include "ExerciseFactory.h"
#include <list>

using namespace std;

class ExercisesContainer
{
    public:
        static ExercisesContainer * GetInstance();

        void AddFactory(ExerciseFactoryBase * factory);
        virtual ~ExercisesContainer();

        list<ExerciseFactoryBase *> GetExerciseList();
    private:
        static ExercisesContainer * _instance;

        list<ExerciseFactoryBase *>  _exerciseList;

        ExercisesContainer();

};

#endif // EXERCISESCONTAINER_H
