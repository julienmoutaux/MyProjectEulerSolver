#ifndef EXERCISEDECLARATION_H_INCLUDED
#define EXERCISEDECLARATION_H_INCLUDED


#include "ExercisesContainer.h"
#include "ExerciseFactory.h"

#include "Exercise1.h"
#include "Exercise3.h"
#include "Exercise26.h"
#include "Exercise29.h"
#include "Exercise27.h"


class ExerciseDeclaration
{
public:
    static ExercisesContainer * PopulateExercisesContainer()
    {
        ExercisesContainer * container = ExercisesContainer::GetInstance();

        container->AddFactory(new ExerciseFactory<Exercise1>());
        container->AddFactory(new ExerciseFactory<Exercise3>());
        container->AddFactory(new ExerciseFactory<Exercise26>());
	container->AddFactory(new ExerciseFactory<Exercise27>());
        container->AddFactory(new ExerciseFactory<Exercise29>());

        return container;
    }
private:
    ExerciseDeclaration() //Can't be instancied !!!!
    {

    }
};

#endif // EXERCISEDECLARATION_H_INCLUDED
