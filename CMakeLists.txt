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
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)


find_package(cetmodules 2.29.06 REQUIRED)
project(nug4 VERSION 1.11.00 LANGUAGES CXX)

include(CetCMakeEnv)
cet_cmake_env()

# -D_GLIBCXX_USE_NANOSLEEP is needed to make std::this_thread::sleep_for available. (IFDatabase)
cet_set_compiler_flags(DIAGS CAUTIOUS WERROR
                       NO_UNDEFINED
                       EXTRA_FLAGS -pedantic 
                                   $<$<COMPILE_LANGUAGE:CXX>:-D_GLIBCXX_USE_NANOSLEEP 
                                   -Wno-unused-local-typedefs -Wno-variadic-macros>)
cet_report_compiler_flags(REPORT_THRESHOLD VERBOSE)

find_package(art REQUIRED)
find_package(art_root_io REQUIRED)
find_package(canvas_root_io REQUIRED)
find_package(nusimdata REQUIRED)
find_package(cetlib REQUIRED)
find_package(cetlib_except REQUIRED)
find_package(CLHEP REQUIRED)
find_package(Boost REQUIRED)
find_package(Geant4 REQUIRED)
find_package(ROOT COMPONENTS Core REQUIRED PUBLIC)

# macros
include(ArtMake)
include(BuildPlugins)
include(CetRootCint)

# headers
### MIGRATE-ACTION-RECOMMENDED: using UPS environmental variables here
include_directories($ENV{G4INCLUDE})

# source
add_subdirectory (nug4)

# ups - table and config files

# packaging utility

cet_cmake_config()
