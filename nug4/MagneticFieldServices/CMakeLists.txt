include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ) ### MIGRATE-ACTION-RECOMMENDED: use target_link_directories() with target semantics

simple_plugin( MagneticFieldServiceStandard "service"
            messagefacility::MF_MessageLogger
            
            cetlib_except::cetlib_except
            nug4_MagneticField
            G4GEOMETRY
            CLHEP
            ${ROOT_BASIC_LIB_LIST}
            ROOT::Geom )

install_headers()
install_fhicl()
install_source()
