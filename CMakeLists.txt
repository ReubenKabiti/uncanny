cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME uncanny)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/SDL/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/SDL)

if(WIN32)
    add_compile_definitions(WIN)
elseif(APPLE)
    add_compile_definitions(MACOS)
elseif(UNIX)
    add_compile_definitions(LINUX)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(RELEASE)
endif()

macro(gather_sources target_name src_dir)
    file(GLOB_RECURSE SOURCES "${src_dir}/*.cpp")
    add_executable(${target_name} ${SOURCES})
endmacro()

gather_sources(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3-static)
