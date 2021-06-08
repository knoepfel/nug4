include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

art_make(NO_PLUGINS
          LIB_LIBRARIES
          messagefacility::MF_MessageLogger
          messagefacility::headers
          canvas
          fhiclcpp::fhiclcpp fhiclcpp::types
          cetlib
          cetlib_except
          
          ${ROOT_BASIC_LIB_LIST}
          ${ROOT_GEOM}
         )
         
install_headers()
install_fhicl()
install_source()
