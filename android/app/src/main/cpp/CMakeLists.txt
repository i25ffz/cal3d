#
# Copyright (C) The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.4.1)

set(C3D_ROOT "${CMAKE_SOURCE_DIR}/../../../../..")
MESSAGE( STATUS "C3D_ROOT: " ${C3D_ROOT} )

# build native_app_glue as a static lib
add_library(app-glue STATIC
            ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

# add cal3d static library
add_subdirectory(${C3D_ROOT}/src/cal3d cal3d)
add_subdirectory(${C3D_ROOT}/android/ndk_helper ndk_helper)

# now build app's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# cal3d cally demo shared library
add_library(cally-demo SHARED
            main.cpp
            ${C3D_ROOT}/examples/cally/src/demo.cpp
            ${C3D_ROOT}/examples/cally/src/menu.cpp
            ${C3D_ROOT}/examples/cally/src/tga.cpp
            ${C3D_ROOT}/examples/cally/src/model.cpp
            ${C3D_ROOT}/examples/cally/src/tick.cpp)

target_include_directories(cally-demo PRIVATE
                           ${C3D_ROOT}/src
                           ${C3D_ROOT}/examples/cally/src
                           ${C3D_ROOT}/android/ndk_helper
                           ${ANDROID_NDK}/sources/android/native_app_glue)

# add lib dependencies
target_link_libraries(cally-demo
                      cal3d
                      app-glue
                      ndk-helper
                      android
                      EGL
                      GLESv1_CM
                      log)
