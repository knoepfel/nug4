cet_find_library( PYTHIA8 NAMES pythia8 PATHS ENV PYTHIA8_LIB NO_DEFAULT_PATH )

art_make( NO_PLUGINS
          LIB_LIBRARIES messagefacility::MF_MessageLogger
                        # cetlib::cetlib
                        # cetlib_except::cetlib_except
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
                        # XERCESC
                        CLHEP
                        PYTHIA8
                        )

install_headers()
install_fhicl()
install_source()
