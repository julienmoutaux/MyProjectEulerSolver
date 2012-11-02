#ifndef EXERCISEDECLARATION_H_INCLUDED
#define EXERCISEDECLARATION_H_INCLUDED


#include "ExercisesContainer.h"
#include "ExerciseFactory.h"

#include "Exercise1.h"
#include "Exercise3.h"
#include "Exercise26.h"
#include "Exercise29.h"
#include "Exercise27.h"
#include "Exercise30.h"
#include "Exercise31.h"
#include "Exercise48.h"
#include "Exercise40.h"
#include "Exercise32.h"
#include "Exercise33.h"
#include "Exercise34.h"
#include "Exercise35.h"
#include "Exercise36.h"
#include "Exercise37.h"
#include "Exercise38.h"
#include "Exercise39.h"
#include "Exercise41.h"
#include "Exercise42.h"
#include "Exercise43.h"
#include "Exercise102.h"


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
	container->AddFactory(new ExerciseFactory<Exercise30>());
	container->AddFactory(new ExerciseFactory<Exercise31>());
	container->AddFactory(new ExerciseFactory<Exercise32>());
	container->AddFactory(new ExerciseFactory<Exercise33>());
	container->AddFactory(new ExerciseFactory<Exercise34>());
	container->AddFactory(new ExerciseFactory<Exercise35>());
	container->AddFactory(new ExerciseFactory<Exercise36>());
	container->AddFactory(new ExerciseFactory<Exercise37>());
	container->AddFactory(new ExerciseFactory<Exercise38>());
	container->AddFactory(new ExerciseFactory<Exercise39>());
	container->AddFactory(new ExerciseFactory<Exercise40>());
	container->AddFactory(new ExerciseFactory<Exercise41>());
	container->AddFactory(new ExerciseFactory<Exercise42>());
	container->AddFactory(new ExerciseFactory<Exercise43>());
	container->AddFactory(new ExerciseFactory<Exercise48>());
	container->AddFactory(new ExerciseFactory<Exercise102>());

        return container;
    }
private:
    ExerciseDeclaration() //Can't be instancied !!!!
    {

    }
};

#endif // EXERCISEDECLARATION_H_INCLUDED
