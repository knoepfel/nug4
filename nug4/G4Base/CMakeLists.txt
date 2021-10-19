
art_make_library( LIBRARIES
                        nug4::MagneticFieldServices_MagneticFieldServiceStandard_service
                        nug4::MagneticField
                        nusimdata::SimulationBase
                        canvas::canvas
                        art::Framework_Services_Registry
                        messagefacility::MF_MessageLogger
                        fhiclcpp::fhiclcpp
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
                        Geant4::G4materials
                        Geant4::G4modeling
                        Geant4::G4particles
                        Geant4::G4persistency
                        Geant4::G4physicslists
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
