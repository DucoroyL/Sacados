cmake_minimum_required (VERSION 3.0)
project (Sacados)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -Wall -Wextra " )

find_package( PkgConfig REQUIRED)
pkg_check_modules ( PKG REQUIRED libglog cpputest)
include_directories ( ${PKG_INCLUDE_DIRS} )

add_executable(sacados src/main.cpp src/Sacados.cpp src/RechercheAleatoire.cpp src/RechercheLocale.hpp src/MarcheAleatoire.cpp src/HillBest.cpp src/HillFirst.cpp src/HillWorst.cpp)
target_link_libraries( sacados ${PKG_LIBRARIES} )
