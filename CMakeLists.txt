cmake_minimum_required(VERSION 3.7)
project(ProgettoLaboratorio2_0)

set(CMAKE_CXX_STANDARD 11)

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES main.cpp MainFrame.cpp MainFrame.h MyApp.cpp MyApp.h)
add_executable(ProgettoLaboratorio2_0 ${SOURCE_FILES})

target_link_libraries(ProgettoLaboratorio2_0 ${wxWidgets_LIBRARIES})