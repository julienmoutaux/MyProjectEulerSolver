#ifndef EXERCISEDECLARATION_H_INCLUDED
#define EXERCISEDECLARATION_H_INCLUDED


#include "ExercisesContainer.h"
#include "ExerciseFactory.h"

#include "Exercise26.h"


class ExerciseDeclaration
{
    public:
        static ExercisesContainer * PopulateExercisesContainer()
        {
                ExercisesContainer * container = ExercisesContainer::GetInstance();

                container->AddFactory(new ExerciseFactory<Exercise26>());

                return container;
        }
    private:
    ExerciseDeclaration() //Can't be instancied !!!!
    {

    }
};

#endif // EXERCISEDECLARATION_H_INCLUDED
