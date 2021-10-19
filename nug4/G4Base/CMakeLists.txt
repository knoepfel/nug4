
art_make( LIB_LIBRARIES nusimdata::SimulationBase ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
                        nug4::MagneticFieldServices_MagneticFieldServiceStandard_service
                        nug4::MagneticField
			                  canvas::canvas
                        ART_FRAMEWORK_SERVICES_REGISTRY
                        MF_MESSAGELOGGER
                        FHICLCPP
                        cetlib::cetlib
                        cetlib_except::cetlib_except
                        Geant4::G4FR
                        Geant4::G4GMocren
                        Geant4::G4RayTracer
                        Geant4::G4Tree
                        Geant4::G4VRML
                        Geant4::G4event
                        Geant4::G4geometry
                        Geant4::G4global
                        Geant4::G4intercoms
                        Geant4::G4materials.so
                        Geant4::G4modeling.so
                        Geant4::G4particles.so
                        Geant4::G4persistency.so
                        Geant4::G4physicslists.so
                        Geant4::G4processes
                        Geant4::G4readout
                        Geant4::G4run
                        Geant4::G4tracking
                        Geant4::G4visHepRep
                        Geant4::G4vis_management
                        XercesC::XercesC
                        CLHEP::CLHEP
                        )

install_headers()
install_fhicl()
install_source()
