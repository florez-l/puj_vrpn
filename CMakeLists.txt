CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

## ========================
## == Project definition ==
## ========================

SET(prj_NAME puj_vrpn)
SET(prj_MAJOR_VERSION   0)
SET(prj_MINOR_VERSION   0)
SET(prj_RELEASE_VERSION 1)

## ==========================
## == Some useful policies ==
## ==========================

SET(_policies CMP0015 CMP0020 CMP0042)
FOREACH(_p ${_policies})
  IF(POLICY ${_p})
    CMAKE_POLICY(SET ${_p} NEW)
  ENDIF(POLICY ${_p})
ENDFOREACH(_p)

## ===========================
## == Project configuration ==
## ===========================

PROJECT(${prj_NAME})
SET(
  prj_VERSION
  "${prj_MAJOR_VERSION}.${prj_MINOR_VERSION}.${prj_RELEASE_VERSION}"
  )
SET(prj_SHORT_VERSION "${prj_MAJOR_VERSION}")

## =====================================
## == Functions, packages and options ==
## =====================================

INCLUDE(cmake/puj_vrpn_FindVRPN.cmake)
INCLUDE(cmake/puj_vrpn_Restrictions.cmake)

FIND_PACKAGE(Boost 1.40 COMPONENTS thread REQUIRED )

## ===========================
## == Use all valid subdirs ==
## ===========================

SET(
  _include_dirs
  .
  lib
  )
FOREACH(_dir ${_include_dirs})
  INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}/${_dir}
    ${PROJECT_BINARY_DIR}/${_dir}
    )
ENDFOREACH(_dir)

## ===========================
## == Build different parts ==
## ===========================

SUBDIRS(appli lib)

## eof - $RCSfile$
