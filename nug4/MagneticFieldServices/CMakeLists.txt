include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

simple_plugin( MagneticFieldServiceStandard "service"
            ${MF_MESSAGELOGGER}
            ${MF_UTILITIES}
            cetlib_except
            nug4_MagneticField
            G4GEOMETRY
            ${CLHEP}
            ${ROOT_BASIC_LIB_LIST}
            ${ROOT_GEOM} )

install_headers()
install_fhicl()
install_source()
