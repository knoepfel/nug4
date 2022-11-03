cet_make_library(INTERFACE SOURCE MagneticField.h
  LIBRARIES INTERFACE
  Geant4::G4geometry
  ROOT::Geom
  ROOT::Physics
)
cet_make_library(LIBRARY_NAME MagneticFieldStandard USE_PROJECT_NAME
  SOURCE MagneticFieldStandard.cxx
  LIBRARIES
  PUBLIC
  nug4::MagneticField
  Geant4::G4geometry
  PRIVATE
  fhiclcpp::fhiclcpp
)
         
install_headers()
install_fhicl()
install_source()
