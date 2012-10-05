project(myprojecteulersolver)

include_directories(include)

add_executable(myprojecteulersolver src/Exercise48.cpp src/Exercise31.cpp src/Exercise30.cpp src/Exercise27.cpp src/PrimeTool.cpp src/ExerciseFactory.cpp src/Exercise26.cpp src/Exercise3.cpp src/Exercise1.cpp src/Tools.cpp src/ExercisesContainer.cpp src/Exercise29.cpp src/AbstractSolver.cpp src/main.cpp)

add_custom_command(TARGET myprojecteulersolver POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources
	${CMAKE_BINARY_DIR}/resources)
