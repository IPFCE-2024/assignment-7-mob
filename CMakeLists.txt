cmake_minimum_required(VERSION 3.16)
project(assignment-7 VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20) # Needed to use designated initializers in ./tests/tests.cpp
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.6.0 # Newest release as of 12-10-2024
)

FetchContent_MakeAvailable(Catch2)

# Define static libraries
add_library(stack STATIC stack.c)
add_library(taylor_sine STATIC taylor_sine.c)

# Apply compile options to both libraries
set(libs stack taylor_sine)
foreach(lib ${libs})
    target_compile_definitions(${lib} PUBLIC -DTEST)
    target_compile_options(${lib}
        PUBLIC
        $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wpedantic>
    )
endforeach()

# Define the test executable
add_executable(unit-tests tests/tests.cpp)

# Add the directory where stack.h and taylor_sine.h are located
target_include_directories(unit-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link static libraries and Catch2 to the unit-tests target
target_link_libraries(unit-tests ${libs})
target_link_libraries(unit-tests Catch2::Catch2WithMain)