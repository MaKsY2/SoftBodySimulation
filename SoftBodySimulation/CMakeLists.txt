cmake_minimum_required(VERSION 3.15)
project(SoftBodySimulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Автоматическое добавление исходников
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.h*")
list(FILTER SOURCES EXCLUDE REGEX ".*Source.cpp")

# Статическая библиотека проекта
add_library(SimulationLib STATIC ${SOURCES} ${HEADERS})

# Исполняемый файл
add_executable(${PROJECT_NAME} "src/Source.cpp")

# Ручное указание путей к SFML
set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/sfml/include")
set(SFML_LIB_DIR "${CMAKE_SOURCE_DIR}/libs/sfml/lib")

# Явное подключение компонентов SFML
target_include_directories(SimulationLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${SFML_INCLUDE_DIR}
)

target_link_directories(SimulationLib PRIVATE ${SFML_LIB_DIR})

# Список требуемых SFML библиотек
set(SFML_LIBS
    sfml-graphics
    sfml-window
    sfml-system
)

# Для macOS добавить необходимые фреймворки
if(APPLE)
    find_library(COCOA_LIB Cocoa)
    find_library(OPENGL_LIB OpenGL)
    list(APPEND SFML_LIBS ${COCOA_LIB} ${OPENGL_LIB})
endif()

target_link_libraries(SimulationLib PRIVATE ${SFML_LIBS})
target_link_libraries(${PROJECT_NAME} PRIVATE SimulationLib)
