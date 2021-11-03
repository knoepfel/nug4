
cet_build_plugin( MagneticFieldServiceStandard art::service
      LIBRARIES PRIVATE
            messagefacility::MF_MessageLogger
            cetlib_except::cetlib_except
            Geant4::G4geometry
            CLHEP::CLHEP
            PUBLIC
            nug4::MagneticField
            ROOT::Core
            ROOT::Geom )

install_headers()
install_fhicl()
install_source()
