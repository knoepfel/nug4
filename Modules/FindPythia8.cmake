#[================================================================[.rst:
FindPythia8
----------

Finds Pythia8 libraries and headers

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``Pythia8::pythia8``
  The pythia8 library
``Pythia8::pythia8lhapdf6``
  The pythia8lhapdf6 library


#]================================================================]
# headers
find_file(_cet_Pythia_h NAMES Pythia.h HINTS ENV PYTHIA8_INC
  PATH_SUFFIXES Pythia8)
if (_cet_Pythia_h)
  get_filename_component(_cet_Pythia8_include_dir "${_cet_Pythia_h}" PATH)
  get_filename_component(_cet_Pythia8_include_dir "${_cet_Pythia8_include_dir}" PATH)
  if (_cet_Pythia8_include_dir STREQUAL "/")
    unset(_cet_Pythia8_include_dir)
  endif()
endif()
if (EXISTS "${_cet_Pythia8_include_dir}")
  set(Pythia8_FOUND TRUE)
  set(PYTHIA8_FOUND TRUE)
  get_filename_component(_cet_Pythia8_dir "${_cet_Pythia8_include_dir}" PATH)
  if (_cet_Pythia8_dir STREQUAL "/")
    unset(_cet_Pythia8_dir)
  endif()
  set(Pythia8_INCLUDE_DIRS "${_cet_Pythia8_include_dir}")
  set(Pythia8_LIBRARY_DIR "${_cet_Pythia8_dir}/lib}")
endif()
if (Pythia8_FOUND)
  find_library(Pythia8_LIBRARY NAMES pythia8 PATHS ${Pythia8_LIBRARY_DIR})
  if (NOT TARGET Pythia8::pythia8)
    add_library(Pythia8::pythia8 SHARED IMPORTED)
    set_target_properties(Pythia8::pythia8 PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${Pythia8_INCLUDE_DIRS}"
      IMPORTED_LOCATION "${Pythia8_LIBRARY}"
      )
  endif()
  find_library(Pythia8Lhapdf6_Library NAMES pythia8lhapdf6 PATHS ${Pythia8_LIBRARY_DIR})
  if (NOT TARGET Pythia8::lhapdf6)
    add_library(Pythia8::lhapdf6 SHARED IMPORTED)
    set_target_properties(Pythia8::lhapdf6 PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${Pythia8_INCLUDE_DIRS}"
      IMPORTED_LOCATION "${Pythia8Lhapdf6_Library}"
      )
  endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Pythia8 ${_cet_Pythia8_config_mode}
  REQUIRED_VARS Pythia8_FOUND
  Pythia8_INCLUDE_DIRS
  Pythia8_LIBRARY)

unset(_cet_Pythia8_FIND_REQUIRED)
unset(_cet_Pythia8_config_mode)
unset(_cet_Pythia8_dir)
unset(_cet_Pythia8_include_dir)
unset(_cet_Pythia_h CACHE)

