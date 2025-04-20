cmake_minimum_required(VERSION 3.15)
project(SoftBodySimulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(APPLE)
    set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};/usr/local/;/opt/homebrew/")
endif()

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

set(PUBLIC_CLASSES
    block
    graphics
    point
)

set(HEADERS_ONLY
    service
)

foreach(class ${PUBLIC_CLASSES})
    list(APPEND SOURCES src/${class}.cpp)
    list(APPEND HEADERS src/${class}.hpp)
endforeach()

foreach(class ${HEADERS_ONLY})
    list(APPEND HEADERS src/${class}.hpp)
endforeach()

add_library(SimulationLib STATIC ${SOURCES} ${HEADERS})

add_executable(${PROJECT_NAME} src/source.cpp)

target_include_directories(SimulationLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(SimulationLib PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

if(APPLE)
    target_link_libraries(SimulationLib PRIVATE
        "-framework Cocoa"
        "-framework OpenGL"
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SimulationLib
    SFML::Graphics
    SFML::Window
    SFML::System
)
