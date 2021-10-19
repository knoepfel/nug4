////////////////////////////////////////////////////////////////////////
// \file MagneticFieldServiceStandard_service.cc
//
// \brief implementation of class for storing/accessing magnetic fields
//
// \author ebrianne@fnal.gov
//
////////////////////////////////////////////////////////////////////////

// C++ language includes

//nug4 includes
#include "nug4/MagneticFieldServices/MagneticFieldServiceStandard.h"

//Framework includes
#include "art/Framework/Services/Registry/ServiceDefinitionMacros.h"


//------------------------------------------------
DEFINE_ART_SERVICE_INTERFACE_IMPL(mag::MagneticFieldServiceStandard, mag::MagneticFieldService)
