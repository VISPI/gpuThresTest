cmake_minimum_required(VERSION 2.8)
project( src/gpuTest.cpp )
find_package( OpenCV REQUIRED )
add_executable( gpuTest src/gpuTest.cpp )
target_link_libraries( gpuTest  ${OpenCV_LIBS} )

