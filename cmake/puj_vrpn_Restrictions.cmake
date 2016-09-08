## =======================================================================
## == Force c++11 language version                                      ==
## == NOTE: It seems that by default on Visual Studio Compiler supports ==
## ==       c++11, so it only need to be tested on other OS.            ==
## =======================================================================

IF(NOT MSVC)
  INCLUDE(CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
  IF(COMPILER_SUPPORTS_CXX11)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  ELSE(COMPILER_SUPPORTS_CXX11)
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
    IF(COMPILER_SUPPORTS_CXX0X)
      SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    ELSE(COMPILER_SUPPORTS_CXX0X)
      MESSAGE(
        FATAL_ERROR
        "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support."
        )
    ENDIF(COMPILER_SUPPORTS_CXX0X)
  ENDIF(COMPILER_SUPPORTS_CXX11)
ENDIF(NOT MSVC)

## ===================================================
## == Prepare header generator to build shared libs ==
## ===================================================

INCLUDE(GenerateExportHeader)

## ==================================================
## == Do not allow to build inside the source tree ==
## ==================================================

IF(PROJECT_BINARY_DIR STREQUAL ${PROJECT_SOURCE_DIR})
  MESSAGE(FATAL_ERROR "Building in the source tree is not allowed.")
ENDIF(PROJECT_BINARY_DIR STREQUAL ${PROJECT_SOURCE_DIR})

## =================================================
## == Where to put targets (executables and libs) ==
## =================================================

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
MARK_AS_ADVANCED(
  CMAKE_BACKWARDS_COMPATIBILITY
  EXECUTABLE_OUTPUT_PATH
  LIBRARY_OUTPUT_PATH
  )

## eof - $RCSfile$
