## =====================
## == Get source code ==
## =====================

FILE(GLOB_RECURSE _hdr_h   "${CMAKE_CURRENT_SOURCE_DIR}/puj_vrpn/*.h")
FILE(GLOB_RECURSE _hdr_hxx "${CMAKE_CURRENT_SOURCE_DIR}/puj_vrpn/*.hxx")
FILE(GLOB_RECURSE _hdr_hpp "${CMAKE_CURRENT_SOURCE_DIR}/puj_vrpn/*.hpp")
FILE(GLOB_RECURSE _src_c   "${CMAKE_CURRENT_SOURCE_DIR}/puj_vrpn/*.c")
FILE(GLOB_RECURSE _src_cxx "${CMAKE_CURRENT_SOURCE_DIR}/puj_vrpn/*.cxx")
FILE(GLOB_RECURSE _src_cpp "${CMAKE_CURRENT_SOURCE_DIR}/puj_vrpn/*.cpp")

## =====================
## == Compile library ==
## =====================

ADD_LIBRARY(puj_vrpn SHARED ${_src_c} ${_src_cpp} ${_src_cxx})
SET_TARGET_PROPERTIES(
  puj_vrpn
  PROPERTIES
  VERSION "${prj_VERSION}"
  SOVERSION "${prj_SHORT_VERSION}"
  )
GENERATE_EXPORT_HEADER(
  puj_vrpn
  BASE_NAME puj_vrpn
  EXPORT_MACRO_NAME puj_vrpn_EXPORT
  EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/puj_vrpn/puj_vrpn_Export.h
  STATIC_DEFINE puj_vrpn_BUILT_AS_STATIC
  )
TARGET_LINK_LIBRARIES(puj_vrpn ${Boost_LIBRARIES} ${VRPN_LIBRARIES})

## eof - $RCSfile$
