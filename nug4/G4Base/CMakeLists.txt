
art_make( LIB_LIBRARIES nusimdata_SimulationBase
                        nug4_MagneticFieldServices_MagneticFieldServiceStandard_service
                        nug4_MagneticField
			canvas
                        ${ART_FRAMEWORK_SERVICES_REGISTRY}
                        messagefacility::MF_MessageLogger
                        messagefacility::headers
                        fhiclcpp::fhiclcpp fhiclcpp::types
                        cetlib
                        cetlib_except
                        Geant4::G4FR
                        Geant4::G4Mocren
                        Geant4::G4RayTracer
                        Geant4::G4Tree
                        Geant4::G4VRML
                        Geant4::G4Event
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
                        ${XERCESC}
                        ${CLHEP}
                        )

install_headers()
install_fhicl()
install_source()
