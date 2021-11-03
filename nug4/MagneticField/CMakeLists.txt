
art_make_library( SOURCE MagneticFieldStandard.cxx
          LIBRARIES PRIVATE
          Geant4::G4geometry
          messagefacility::MF_MessageLogger
          canvas::canvas
          fhiclcpp::fhiclcpp
          cetlib::cetlib
          cetlib_except::cetlib_except
          CLHEP::CLHEP
          PUBLIC
          ROOT::Core
          ROOT::Geom
          ROOT::Physics
         )
         
install_headers()
install_fhicl()
install_source()
