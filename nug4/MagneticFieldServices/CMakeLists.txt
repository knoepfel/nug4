include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

simple_plugin( MagneticFieldServiceStandard "service"
            LIBRARIES
            messagefacility::MF_MessageLogger
            messagefacility::headers
            cetlib_except
            nug4_MagneticField
            
            ${ROOT_BASIC_LIB_LIST}
            ${ROOT_GEOM} )

install_headers()
install_fhicl()
install_source()
