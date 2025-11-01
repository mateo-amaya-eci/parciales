cmake_minimum_required(VERSION 3.10)


project(Estudiante)

set(CMAKE_CXX_STANDARD 17)              
set(CMAKE_CXX_STANDARD_REQUIRED ON)    


include_directories(include)           

# Archivos fuente
set(SOURCES                           
    src/Estudiante.cpp                     
    src/main.cpp                     
)


add_executable(Estudiante ${SOURCES})