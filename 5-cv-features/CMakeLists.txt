cmake_minimum_required (VERSION 2.8)

project (features)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cv_features features.cpp)

target_link_libraries(cv_features ${OpenCV_LIBS})

add_executable(cv_record record.cpp)

target_link_libraries(cv_record ${OpenCV_LIBS})
