
art_make_library( SOURCE MagneticFieldStandard.cxx
          LIBRARIES
          Geant4::G4geometry
          messagefacility::MF_MessageLogger
          canvas::canvas
          fhiclcpp::fhiclcpp
          cetlib::cetlib
          cetlib_except::cetlib_except
          CLHEP::CLHEP
          ROOT::Core
          ROOT::Geom
          ROOT::Physics
          PUBLIC
         )
         
install_headers()
install_fhicl()
install_source()
