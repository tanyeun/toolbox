CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# set the project name
project(Tutorial VERSION 1.2)


# specify the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add the MathFunctions library
add_subdirectory(MathFunctions)
target_link_libraries(Tutorial PUBLIC MathFunctions)

option(USE_MYMATH "User tutorial provided math implementatoin" ON)
CONFIGURE_FILE(TutorialConfig.h.in TutorialConfig.h)

if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# add the executable
add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})



target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}"
                          )

