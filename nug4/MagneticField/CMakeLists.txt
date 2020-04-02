
simple_plugin( MagneticField service
               ${MF_MESSAGELOGGER}
               ${MF_UTILITIES}
	       cetlib_except
               ${CLHEP}
               ${ROOT_LIBRARIES}
               ROOT::Geom )

install_headers()
install_fhicl()
