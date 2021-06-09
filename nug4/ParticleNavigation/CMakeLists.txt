
# for classes_def.xml!!
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

art_make( NO_PLUGINS
          LIB_LIBRARIES nusimdata_SimulationBase
                        art::Framework_Core
			art::Framework_Principal
			art::Framework_Services_Registry
			art_Persistency_Common
			art_Persistency_Provenance
			art_Utilities
			canvas
			messagefacility::MF_MessageLogger
			messagefacility::headers
        		cetlib
			cetlib_except
			${ROOT_BASIC_LIB_LIST}
        )

install_headers()
install_fhicl()
install_source()
