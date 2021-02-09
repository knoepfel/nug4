include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

art_make(NO_PLUGINS
          LIB_LIBRARIES
          ${MF_MESSAGELOGGER}
          ${MF_UTILITIES}
          canvas
          ${FHICLCPP}
          cetlib
          cetlib_except
          ${CLHEP}
          ${ROOT_BASIC_LIB_LIST}
          ${ROOT_GEOM}
         )

install_headers()
install_fhicl()
install_source()
