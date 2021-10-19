
art_make_library( SOURCE EmEveIdCalculator.cxx  EveIdCalculator.cxx
                         ParticleHistory.cxx  ParticleList.cxx
          LIBRARIES nusimdata::SimulationBase
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
                        ROOT::Core
        )

install_headers()
install_fhicl()
install_source()
