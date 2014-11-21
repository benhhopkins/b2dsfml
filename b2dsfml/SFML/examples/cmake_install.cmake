# Install script for directory: C:/Users/Ben/Documents/GitHub/SFML-2.1/examples

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/SFML")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("C:/Users/Ben/Documents/GitHub/bhsfml/bhsfml/bhsfml/SFML/examples/ftp/cmake_install.cmake")
  INCLUDE("C:/Users/Ben/Documents/GitHub/bhsfml/bhsfml/bhsfml/SFML/examples/opengl/cmake_install.cmake")
  INCLUDE("C:/Users/Ben/Documents/GitHub/bhsfml/bhsfml/bhsfml/SFML/examples/pong/cmake_install.cmake")
  INCLUDE("C:/Users/Ben/Documents/GitHub/bhsfml/bhsfml/bhsfml/SFML/examples/shader/cmake_install.cmake")
  INCLUDE("C:/Users/Ben/Documents/GitHub/bhsfml/bhsfml/bhsfml/SFML/examples/sockets/cmake_install.cmake")
  INCLUDE("C:/Users/Ben/Documents/GitHub/bhsfml/bhsfml/bhsfml/SFML/examples/sound/cmake_install.cmake")
  INCLUDE("C:/Users/Ben/Documents/GitHub/bhsfml/bhsfml/bhsfml/SFML/examples/sound_capture/cmake_install.cmake")
  INCLUDE("C:/Users/Ben/Documents/GitHub/bhsfml/bhsfml/bhsfml/SFML/examples/voip/cmake_install.cmake")
  INCLUDE("C:/Users/Ben/Documents/GitHub/bhsfml/bhsfml/bhsfml/SFML/examples/window/cmake_install.cmake")
  INCLUDE("C:/Users/Ben/Documents/GitHub/bhsfml/bhsfml/bhsfml/SFML/examples/win32/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

