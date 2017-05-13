set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wall -fexceptions")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=format-security")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=c++11-narrowing")
MESSAGE( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS} )

file(GLOB C3D_SRC_LIST *.cpp)

add_library(cal3d STATIC
		${C3D_SRC_LIST})

target_include_directories(cal3d PRIVATE
                           ${C3D_ROOT}/src)
