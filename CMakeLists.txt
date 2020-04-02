# ======================================================================
#  nug4 main build file
#
#  cd .../path/to/build/directory
#  source .../path/to/nug4/ups/setup_for_development
#  cmake [-DCMAKE_INSTALL_PREFIX=/install/path]
#        -DCMAKE_BUILD_TYPE=$CETPKG_TYPE
#        $CETPKG_SOURCE
#
#  make
#  make test
#  make install
#  make package (builds distribution tarfile)
# ======================================================================

cmake_minimum_required(VERSION 3.12)  # use cmake 3.12 or later

project(nug4 VERSION 1.04.01 LANGUAGES CXX)

# cetbuildtools contains our cmake modules
set(fcl_dir job)
find_package(cetmodules REQUIRED)

list(APPEND CMAKE_MODULE_PATH
  $ENV{CANVAS_ROOT_IO_DIR}/Modules
  $ENV{ART_DIR}/Modules)

include(CetCMakeEnv)
cet_cmake_env()


# these are minimum required versions, not the actual product versions
find_package( art )
find_package( art_root_io)
find_package( nusimdata )
find_package( cetlib )
find_package( cetlib_except )
find_package( Geant4 )
include(${Geant4_USE_FILE})
# macros
include(ArtMake)
include(BuildPlugins)
include(CetRootCint)

# include search path
include_directories ( ${Geant4_INCLUDE_DIRS} )
include_directories ( $ENV{XERCES_C_INC} )

# source
add_subdirectory (nug4)

# ups - table and config files
#add_subdirectory(ups)

# packaging utility
add_subdirectory(cmakeConfig)
