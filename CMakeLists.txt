
project(test)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(ExternalProject)

ExternalProject_Add(spdlog
    PREFIX spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.3.1
    GIT_SHALLOW ON
    GIT_PROGRESS ON
    BUILD_COMMAND ""
    CONFIGURE_COMMAND ""
    INSTALL_COMMAND ""
)
ExternalProject_Get_Property(spdlog SOURCE_DIR)
set(
    SPDLOG_INCLUDES ${SOURCE_DIR}/include)

include_directories( 
    PRIVATE ${SPDLOG_INCLUDES})

add_executable(myapp
    main.cpp
    formatting.cpp
)

target_link_libraries(myapp
PRIVATE stdc++fs)

add_dependencies(myapp
spdlog)
    
add_executable(tests
    main_test.cpp
    formatting.cpp
    regex.cpp
)

add_dependencies(tests
spdlog)
