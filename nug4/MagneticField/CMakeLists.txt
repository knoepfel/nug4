include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

art_make(NO_PLUGINS
          LIB_LIBRARIES
          G4GEOMETRY
          messagefacility::MF_MessageLogger
          
          canvas::canvas
          fhiclcpp::fhiclcpp
          cetlib::cetlib
          cetlib_except::cetlib_except
          CLHEP
          ${ROOT_BASIC_LIB_LIST}
          ROOT::Geom
          PUBLIC G4GEOMETRY
         )
         
install_headers()
install_fhicl()
install_source()
