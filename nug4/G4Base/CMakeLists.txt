
art_make( LIB_LIBRARIES nusimdata_SimulationBase
                        nug4_MagneticField_MagneticField_service
			canvas
                        ${MF_MESSAGELOGGER}
                        ${MF_UTILITIES}
                        ${FHICLCPP}
                        cetlib
                        ${CLHEP_LIBRARIES}
                        ${Geant4_LIBRARIES}
                        )

install_headers()
install_fhicl()
