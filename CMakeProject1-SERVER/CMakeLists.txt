cmake_minimum_required(VERSION 3.20)
project(CMakeProject1-SERVER)

set(CMAKE_CXX_STANDARD 17)

 
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Matvei/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(Boost REQUIRED COMPONENTS system)
find_package(SQLite3 REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(WebServer
    src/main.cpp
    src/server/server.cpp
    src/server/session.cpp
)
target_include_directories(WebServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(WebServer
    PRIVATE
        Boost::system
        SQLite::SQLite3
        nlohmann_json::nlohmann_json
)