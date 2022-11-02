cet_make_library(INTERFACE SOURCE MagneticFieldService.h
  LIBRARIES INTERFACE
  art_plugin_types::serviceDeclaration
  nug4::MagneticField
)

cet_build_plugin(MagneticFieldServiceStandard art::service
  LIBRARIES PRIVATE
  nug4::MagneticFieldStandard
  nug4::MagneticFieldServices
  art::Framework_Services_Registry
  art::Framework_Principal
  fhiclcpp::fhiclcpp
)

install_headers()
install_fhicl()
install_source()
