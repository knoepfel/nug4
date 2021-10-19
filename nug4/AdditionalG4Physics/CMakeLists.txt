
##find_package(Pythia8 REQUIRED)
find_library( PYTHIA8 NAMES pythia8 PATHS ENV PYTHIA8_LIB NO_DEFAULT_PATH ) ### MIGRATE-ACTION-RECOMMENDED: use of ENV ... may be UPS-dependent ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
include_directories($ENV{PYTHIA8_INC})

#art_make( NO_PLUGINS ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
art_make_library(SOURCE Py8CharmDecayerPhysics.cc Py8Decayer.cc
                         Py8TauDecayerPhysics.cc RegisterAddG4PhysicsShorthands.cc
                 LIBRARIES messagefacility::MF_MessageLogger
                        G4EVENT
                        G4GEOMETRY
                        G4GLOBAL
                        G4INTERCOMS
                        G4MATERIALS
                        G4MODELING
                        G4PARTICLES
                        G4PHYSICSLISTS
                        G4PROCESSES
                        G4RUN
                        G4TRACKING
                        CLHEP::CLHEP
                        PYTHIA8
                        )

install_headers()
install_fhicl()
install_source()
