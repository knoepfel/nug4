
cet_build_plugin( MagneticFieldServiceStandard art::service
      LIBRARIES
            messagefacility::MF_MessageLogger
            cetlib_except::cetlib_except
            nug4::MagneticField
            Geant4::G4geometry
            CLHEP::CLHEP
            ROOT::Core
            ROOT::Geom )

install_headers()
install_fhicl()
install_source()
