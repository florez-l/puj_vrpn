FIND_PATH(
  VRPN_INCLUDE_DIR
  vrpn_Types.h
  /usr/include
  /usr/local/include
  $ENV{HOME}/include
  $ENV{HOME}/local/include
  )
IF(NOT EXISTS ${VRPN_INCLUDE_DIR}/vrpn_Types.h)
  SET(
    VRPN_INCLUDE_DIR
    VRPN_INCLUDE_DIR-NOTFOUND
    CACHE PATH "path to vrpn headers (vrpn_*.h)"
    FORCE
    )
  MESSAGE(FATAL_ERROR "VRPN headers not found!")
ENDIF(NOT EXISTS ${VRPN_INCLUDE_DIR}/vrpn_Types.h)
INCLUDE_DIRECTORIES(${VRPN_INCLUDE_DIR})

FIND_LIBRARY(
  VRPN_LIBRARY
  NAMES
  vrpn
  PATHS
  /usr/lib
  /usr/local/lib
  $ENV{HOME}/lib
  $ENV{HOME}/local/lib
  )
IF(NOT VRPN_LIBRARY)
  MESSAGE(FATAL_ERROR "VRPN library not found!")
ENDIF(NOT VRPN_LIBRARY)

FIND_LIBRARY(
  VRPN_QUAT_LIBRARY
  NAMES
  quat
  PATHS
  /usr/lib
  /usr/local/lib
  $ENV{HOME}/lib
  $ENV{HOME}/local/lib
  )
IF(NOT VRPN_QUAT_LIBRARY)
  MESSAGE(FATAL_ERROR "VRPN_QUAT (libquat.a) library not found!")
ENDIF(NOT VRPN_QUAT_LIBRARY)

SET(
  VRPN_LIBRARIES
  ${VRPN_LIBRARY}
  ${VRPN_QUAT_LIBRARY}
  )

## eof - $RCSfile$
