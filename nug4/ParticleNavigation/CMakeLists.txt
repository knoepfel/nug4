
# for classes_def.xml!!
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

art_make( NO_PLUGINS
          LIB_LIBRARIES nusimdata_SimulationBase
                        art::Framework_Core
			art::Framework_Principal
			art::Framework_Services_Registry
			art::Persistency_Common
			art::Persistency_Provenance
			art::Utilities
			canvas::canvas
			messagefacility::MF_MessageLogger
			${MF_UTILITIES}
        		cetlib::cetlib
			cetlib_except::cetlib_except
			${ROOT_BASIC_LIB_LIST}
        )

install_headers()
install_fhicl()
install_source()
