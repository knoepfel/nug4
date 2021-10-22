#[================================================================[.rst:
FindPythia8
----------
  find Pythia8

#]================================================================]
if (Pythia8_FIND_REQUIRED)
  set(_cet_Pythia8_FIND_REQUIRED ${Pythia8_FIND_REQUIRED})
  unset(Pythia8_FIND_REQUIRED)
else()
  unset(_cet_Pythia8_FIND_REQUIRED)
endif()
find_package(Pythia8 CONFIG QUIET)
if (_cet_Pythia8_FIND_REQUIRED)
  set(Pythia8_FIND_REQUIRED ${_cet_Pythia8_FIND_REQUIRED})
  unset(_cet_Pythia8_FIND_REQUIRED)
endif()
if (Pythia8_FOUND)
  set(_cet_Pythia8_config_mode CONFIG_MODE)
else()
  unset(_cet_Pythia8_config_mode)
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
endif()
if (Pythia8_FOUND)
  set(_fug_liblist pythia8 pythia8lhapdf6)
  set(PYTHIA8_LIB_LIST)
  foreach (_fug IN LISTS _fug_liblist)
    string(TOUPPER ${_fug} _FUG)
    find_library(${_FUG} NAMES ${_fug} PATHS ${Pythia8_LIBRARY_DIR})
    if (NOT TARGET Pythia8::${_fug})
      add_library(Pythia8::${_fug} SHARED IMPORTED)
      set_target_properties(Pythia8::${_fug} PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${Pythia8_INCLUDE_DIRS}"
        IMPORTED_LOCATION "${${_FUG}}"
        )
    endif()
    if (${_FUG})
      list(APPEND PYTHIA8_LIB_LIST ${_FUG})
    endif()
  endforeach()
  unset(_fug)
  unset(_FUG)
  include_directories("${Pythia8_INCLUDE_DIRS}")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Pythia8 ${_cet_Pythia8_config_mode}
  REQUIRED_VARS Pythia8_FOUND PYTHIA8
  Pythia8_INCLUDE_DIRS
  PYTHIA8_LIB_LIST)

unset(_cet_Pythia8_FIND_REQUIRED)
unset(_cet_Pythia8_config_mode)
unset(_cet_Pythia8_dir)
unset(_cet_Pythia8_include_dir)
unset(_fug_liblist)
unset(_cet_Pythia_h CACHE)

