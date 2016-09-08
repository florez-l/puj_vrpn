## =====================
## == Get source code ==
## =====================

FILE(GLOB_RECURSE _prog_src "${CMAKE_CURRENT_SOURCE_DIR}/*.cxx")

## ======================
## == Compile examples ==
## ======================

FOREACH(_prog ${_prog_src})
  GET_FILENAME_COMPONENT(_name ${_prog} NAME_WE)
  ADD_EXECUTABLE(puj_vrpn_example_${_name} ${_prog})
  TARGET_LINK_LIBRARIES(puj_vrpn_example_${_name} puj_vrpn)
ENDFOREACH(_prog)

## eof - $RCSfile$
