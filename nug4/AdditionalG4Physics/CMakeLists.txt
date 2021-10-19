
##find_package(Pythia8 REQUIRED)
find_library( PYTHIA8 NAMES pythia8 PATHS ENV PYTHIA8_LIB NO_DEFAULT_PATH ) ### MIGRATE-ACTION-RECOMMENDED: use of ENV ... may be UPS-dependent ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
include_directories($ENV{PYTHIA8_INC})

#art_make( NO_PLUGINS ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
art_make_library(SOURCE Py8CharmDecayerPhysics.cc Py8Decayer.cc
                         Py8TauDecayerPhysics.cc RegisterAddG4PhysicsShorthands.cc
                 LIBRARIES messagefacility::MF_MessageLogger
                        Geant4::G4event
                        Geant4::G4geometry
                        Geant4::G4global
                        Geant4::G4intercoms
                        Geant4::G4materials.so
                        Geant4::G4modeling.so
                        Geant4::G4particles.so
                        Geant4::G4physicslists.so
                        Geant4::G4processes
                        Geant4::G4run
                        Geant4::G4tracking
                        CLHEP::CLHEP
                        PYTHIA8
                        )

install_headers()
install_fhicl()
install_source()
