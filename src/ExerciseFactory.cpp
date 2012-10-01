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

//template<class T>
/*AbstractSolver * ExerciseFactory<T>::BuildExercise()
{
    return new T();
}
*/

//template<class T>
/*string ExerciseFactory<T>::GetName()
{
    return T::GetName();
}

*/
