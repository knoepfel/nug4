////////////////////////////////////////////////////////////////////////
// \file MagneticFieldServiceStandard_service.cc
//
// \brief implementation of class for storing/accessing magnetic fields
//
// \author ebrianne@fnal.gov
//
////////////////////////////////////////////////////////////////////////

#include "nug4/MagneticField/MagneticFieldStandard.h"
#include "nug4/MagneticFieldServices/MagneticFieldService.h"

#include "art/Framework/Services/Registry/ActivityRegistry.h"
#include "art/Framework/Services/Registry/GlobalSignal.h"
#include "art/Framework/Services/Registry/ServiceDeclarationMacros.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Principal/Run.h"
#include "fhiclcpp/ParameterSet.h"

namespace mag {
  class MagneticFieldServiceStandard: public MagneticFieldService {
  public:
    MagneticFieldServiceStandard(fhicl::ParameterSet const& pset, art::ActivityRegistry& reg);

  private:
    void reconfigure(fhicl::ParameterSet const& pset);
    void preBeginRun(const art::Run& run);

    const provider_type* provider() const override { return &fProp; }

    mag::MagneticFieldStandard fProp;
  };
}

DECLARE_ART_SERVICE_INTERFACE_IMPL(mag::MagneticFieldServiceStandard,
                                   mag::MagneticFieldService,
                                   SHARED)


#include "art/Framework/Services/Registry/ServiceDefinitionMacros.h"
////////////////////////////////////////////////////////////////////////
// \file MagneticFieldServiceStandard_service.cc
//
// \brief implementation of class for storing/accessing magnetic fields
//
// \author ebrianne@fnal.gov
//
////////////////////////////////////////////////////////////////////////

// C++ language includes

//Framework includes

//-----------------------------------------------
mag::MagneticFieldServiceStandard::MagneticFieldServiceStandard(fhicl::ParameterSet const& pset, art::ActivityRegistry& reg)
: fProp{pset}
{
  reg.sPreBeginRun.watch(this, &MagneticFieldServiceStandard::preBeginRun);
}

//----------------------------------------------
void mag::MagneticFieldServiceStandard::preBeginRun(const art::Run& run)
{

}

//------------------------------------------------
void mag::MagneticFieldServiceStandard::reconfigure(fhicl::ParameterSet const& pset)
{
  fProp.reconfigure(pset);
}


//------------------------------------------------
DEFINE_ART_SERVICE_INTERFACE_IMPL(mag::MagneticFieldServiceStandard, mag::MagneticFieldService)
