cmake_minimum_required(VERSION 3.5.0)
project(tetris VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)           # Use C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Enforce the standard
set(CMAKE_CXX_EXTENSIONS OFF)        # Disable compiler-specific extensions

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.1.1 
)
  
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
)
    
FetchContent_MakeAvailable(fmt raylib)
set(SOURCE_FILES main.cpp game/Game.cpp game/Game.h game/Tetris.cpp game/Tetris.h)
add_executable(tetris ${SOURCE_FILES})

include(CTest)
enable_testing()

# Link both fmt and raylib libraries to the target
target_link_libraries(tetris PRIVATE fmt::fmt raylib)
