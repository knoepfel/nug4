include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ) ### MIGRATE-ACTION-RECOMMENDED: use target_link_directories() with target semantics

art_make(NO_PLUGINS ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
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
