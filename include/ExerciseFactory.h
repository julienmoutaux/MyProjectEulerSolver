#ifndef EXERCISEFACTORY_H
#define EXERCISEFACTORY_H

#include "AbstractSolver.h"
#include "Tools.h"

class ExerciseFactoryBase
{
    public:
        virtual AbstractSolver * BuildExercise() = 0;
        virtual string GetName() = 0;

        int GetIdx();
    protected:
        ExerciseFactoryBase();
    private:
    int _idx;
    static int _cpt;
};


template<class T>
class ExerciseFactory:
private Tools::HeritageChecker<T,AbstractSolver>,
public ExerciseFactoryBase
{
    public:
        ExerciseFactory(){}
        virtual ~ExerciseFactory(){}
        AbstractSolver * BuildExercise(){return new T();}
        string GetName(){return T::GetName();}

        //T * BuildExercise();
    protected:
    private:
};


#endif // EXERCISEFACTORY_H
