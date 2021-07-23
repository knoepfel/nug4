
art_make( LIB_LIBRARIES nusimdata_SimulationBase
                        nug4_MagneticFieldServices_MagneticFieldServiceStandard_service
                        nug4_MagneticField
			                  canvas::canvas
                        ART_FRAMEWORK_SERVICES_REGISTRY
                        MF_MESSAGELOGGER
                        FHICLCPP
                        cetlib::cetlib
                        cetlib_except::cetlib_except
                        G4FR
                        G4GMOCREN
                        G4RAYTRACER
                        G4TREE
                        G4VRML
                        G4EVENT
                        G4GEOMETRY
                        G4GLOBAL
                        G4INTERCOMS
                        G4MATERIALS
                        G4MODELING
                        G4PARTICLES
                        G4PERSISTENCY
                        G4PHYSICSLISTS
                        G4PROCESSES
                        G4READOUT
                        G4RUN
                        G4TRACKING
                        G4VISHEPREP
                        G4VIS_MANAGEMENT
                        XERCESC
                        CLHEP
                        )

install_headers()
install_fhicl()
install_source()
