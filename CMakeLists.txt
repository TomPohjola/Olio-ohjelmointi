cmake_minimum_required(VERSION 3.16)

project(Kotitehtava_yksi_olio LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Kotitehtava_yksi_olio main.cpp)

include(GNUInstallDirs)
install(TARGETS Kotitehtava_yksi_olio
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
