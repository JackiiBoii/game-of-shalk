cmake_minimum_required(VERSION 3.16)
project(GameOfShalk LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(RESOURCES_DIR "${PROJECT_SOURCE_DIR}/Resources")

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(game-of-shalk src/main.cpp  "src/player.h" "src/player.cpp")
target_precompile_headers(game-of-shalk PRIVATE src/pch/pch.h)

target_link_libraries(game-of-shalk PRIVATE sfml-graphics)
target_compile_features(game-of-shalk PRIVATE cxx_std_17)
target_compile_definitions(game-of-shalk PRIVATE RESOURCES_DIR="${RESOURCES_DIR}")

if(WIN32)
    add_custom_command(
        TARGET game-of-shalk
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:game-of-shalk>
        VERBATIM)
endif()
