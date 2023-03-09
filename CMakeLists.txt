cmake_minimum_required(VERSION 3.14)

project(benchmark_rapidjson)

find_package(rapidjson)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    rapidjson::rapidjson
)
