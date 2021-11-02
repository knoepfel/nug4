
find_package(Pythia8 REQUIRED)

art_make_library(SOURCE Py8CharmDecayerPhysics.cc Py8Decayer.cc
                         Py8TauDecayerPhysics.cc RegisterAddG4PhysicsShorthands.cc
                 LIBRARIES PRIVATE
                        messagefacility::MF_MessageLogger
                        Geant4::G4event
                        Geant4::G4geometry
                        Geant4::G4global
                        Geant4::G4intercoms
                        Geant4::G4materials
                        Geant4::G4modeling
                        Geant4::G4particles
                        Geant4::G4physicslists
                        Geant4::G4processes
                        Geant4::G4run
                        Geant4::G4tracking
                        CLHEP::CLHEP
                        Pythia8::pythia8
                        )

install_headers()
install_fhicl()
install_source()
