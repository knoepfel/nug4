##include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ) ### MIGRATE-ACTION-RECOMMENDED: use target_link_directories() with target semantics

cet_build_plugin( MagneticFieldServiceStandard art::service
      LIBRARIES
            messagefacility::MF_MessageLogger
            cetlib_except::cetlib_except
            nug4::MagneticField
            G4GEOMETRY
            CLHEP::CLHEP
            ROOT::Core
            ROOT::Geom )

install_headers()
install_fhicl()
install_source()
