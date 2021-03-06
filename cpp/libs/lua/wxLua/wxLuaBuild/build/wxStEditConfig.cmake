# Generated by CMake 3.6.2

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget wxStEditLib)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target wxStEditLib
add_library(wxStEditLib STATIC IMPORTED)

# Import target "wxStEditLib" for configuration "Debug"
set_property(TARGET wxStEditLib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(wxStEditLib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxscintillad.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxpngd.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxtiffd.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxjpegd.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxzlibd.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxregexud.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxexpatd.lib;opengl32;glu32;winmm;comctl32;rpcrt4;wsock32"
  IMPORTED_LOCATION_DEBUG "F:/proj/lua/wxLua/wxLuaBuild/lib/Debug/wxstedit-wx31d-1.6.0.lib"
  )

# Import target "wxStEditLib" for configuration "Release"
set_property(TARGET wxStEditLib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(wxStEditLib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxscintilla.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxpng.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxtiff.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxjpeg.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxzlib.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxregexu.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxexpat.lib;opengl32;glu32;winmm;comctl32;rpcrt4;wsock32"
  IMPORTED_LOCATION_RELEASE "F:/proj/lua/wxLua/wxLuaBuild/lib/Release/wxstedit-wx31-1.6.0.lib"
  )

# Import target "wxStEditLib" for configuration "MinSizeRel"
set_property(TARGET wxStEditLib APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(wxStEditLib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxscintilla.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxpng.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxtiff.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxjpeg.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxzlib.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxregexu.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxexpat.lib;opengl32;glu32;winmm;comctl32;rpcrt4;wsock32"
  IMPORTED_LOCATION_MINSIZEREL "F:/proj/lua/wxLua/wxLuaBuild/lib/MinSizeRel/wxstedit-wx31-1.6.0.lib"
  )

# Import target "wxStEditLib" for configuration "RelWithDebInfo"
set_property(TARGET wxStEditLib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(wxStEditLib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxscintilla.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxpng.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxtiff.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxjpeg.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxzlib.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxregexu.lib;F:/proj/cpp/libs/wxWidgets/lib/vc_lib/wxexpat.lib;opengl32;glu32;winmm;comctl32;rpcrt4;wsock32"
  IMPORTED_LOCATION_RELWITHDEBINFO "F:/proj/lua/wxLua/wxLuaBuild/lib/RelWithDebInfo/wxstedit-wx31-1.6.0.lib"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
