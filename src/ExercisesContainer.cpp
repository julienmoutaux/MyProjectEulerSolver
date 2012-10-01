#include "ExercisesContainer.h"

ExercisesContainer * ExercisesContainer::_instance = 0;

ExercisesContainer::ExercisesContainer()
{
}

ExercisesContainer::~ExercisesContainer()
{
    //dtor
}

ExercisesContainer * ExercisesContainer::GetInstance()
{
    if (_instance == 0)
        _instance = new ExercisesContainer();
    return _instance;
}

void ExercisesContainer::AddFactory(ExerciseFactoryBase * factory)
{
    _exerciseList.push_back(factory);
}

list<ExerciseFactoryBase *> ExercisesContainer::GetExerciseList()
{
    return _exerciseList;
}
