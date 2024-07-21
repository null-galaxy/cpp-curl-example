cmake_minimum_required(VERSION 3.10)
project(curl_example)

set(CMAKE_CXX_STANDARD 14)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

add_executable(1_simplest_http_get 1_simplest_http_get.cpp)
target_link_libraries(1_simplest_http_get ${CURL_LIBRARIES})

add_executable(2_http_get_post 2_http_get_post.cpp)
target_link_libraries(2_http_get_post ${CURL_LIBRARIES})
