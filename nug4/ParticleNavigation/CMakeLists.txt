
# for classes_def.xml!!
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ) ### MIGRATE-ACTION-RECOMMENDED: use target_link_directories() with target semantics

art_make( NO_PLUGINS ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
          LIB_LIBRARIES nusimdata::SimulationBase
                        art::Framework_Core
			art::Framework_Principal
			art::Framework_Services_Registry
			art::Persistency_Common
			art::Persistency_Provenance
			art::Utilities
			canvas::canvas
			messagefacility::MF_MessageLogger
			
        		cetlib::cetlib
			cetlib_except::cetlib_except
			${ROOT_BASIC_LIB_LIST}
        )

install_headers()
install_fhicl()
install_source()
