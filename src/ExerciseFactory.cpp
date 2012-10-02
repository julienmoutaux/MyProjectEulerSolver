#include "ExerciseFactory.h"

int ExerciseFactoryBase::_cpt = 1;

ExerciseFactoryBase::ExerciseFactoryBase()
{
    _idx = _cpt++;
}

int ExerciseFactoryBase::GetIdx()
{
    return _idx;
}

