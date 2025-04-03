cmake_minimum_required(VERSION 3.20)
project(CMakeProject1-SERVER)

set(CMAKE_CXX_STANDARD 17)

 
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Matvei/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(Boost REQUIRED COMPONENTS system)
find_package(SQLite3 REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(CMakeProject1-SERVER
    CMakeProject1-SERVER.cpp
)

target_link_libraries(CMakeProject1-SERVER
    PRIVATE
        Boost::system
        SQLite::SQLite3
        nlohmann_json::nlohmann_json
)