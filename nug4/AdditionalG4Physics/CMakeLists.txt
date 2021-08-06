cet_find_library( PYTHIA8 NAMES pythia8 PATHS ENV PYTHIA8_LIB NO_DEFAULT_PATH )

art_make( LIB_LIBRARIES ${MF_MESSAGELOGGER}
                        ${MF_UTILITIES}
                        cetlib
                        cetlib_except
                        ${G4FR}
                        ${G4GMOCREN}
                        ${G4RAYTRACER}
                        ${G4TREE}
                        ${G4VRML}
                        ${G4EVENT}
                        ${G4GEOMETRY}
                        ${G4GLOBAL}
                        ${G4INTERCOMS}
                        ${G4MATERIALS}
                        ${G4MODELING}
                        ${G4PARTICLES}
                        ${G4PERSISTENCY}
                        ${G4PHYSICSLISTS}
                        ${G4PROCESSES}
                        ${G4READOUT}
                        ${G4RUN}
                        ${G4TRACKING}
                        ${G4VISHEPREP}
                        ${G4VIS_MANAGEMENT}
                        ${XERCESC}
                        ${CLHEP}
                        ${PYTHIA8}
                        )

install_headers()
install_fhicl()
install_source()
