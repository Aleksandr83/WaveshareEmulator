cmake_minimum_required (VERSION 3.23)

set(CMAKE_CXX_COMPILER 	"g++" 	)  # g++ или clang++
set(CMAKE_C_COMPILER   	"gcc"  	)  # gcc или clang

set(CMAKE_SYSTEM_PROCESSOR aarch64)
#set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS        ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fexceptions -g -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++abi -lX11 ")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)


project (waveshare-e-ink
	VERSION   0.0.0.2
	LANGUAGES CXX
)

include(GNUInstallDirs)

find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})

set(APP_SOURCES     "")
set(APP_INCLUDEDIRS "")
set(PROJECT_SOURCE_DIR "./src")

file(GLOB_RECURSE APP_SOURCES_TOP
       ${PROJECT_SOURCE_DIR}/*.cpp 
       ${PROJECT_SOURCE_DIR}/*.c
       )
       
list(APPEND APP_SOURCES ${APP_SOURCES_TOP}) 

file(GLOB_RECURSE APP_HEADERS_TOP
      ${PROJECT_SOURCE_DIR}/*.h
      ${PROJECT_SOURCE_DIR}/*.hpp
      ${PROJECT_SOURCE_DIR}/*.tpp)       
       
list(APPEND APP_HEADERS ${APP_HEADERS_TOP}) 

foreach (headerfile ${APP_HEADERS})   
    get_filename_component(dirname  ${headerfile} DIRECTORY)        
	list(APPEND APP_INCLUDEDIRS "${dirname}")
endforeach (headerfile ${APP_HEADERS}) 

include_directories("/usr/include/X11" ${APP_INCLUDEDIRS})


add_executable(waveshare-e-ink ${APP_SOURCES})

