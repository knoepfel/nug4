////////////////////////////////////////////////////////////////////////
// \file MagneticFieldService.h
//
// \brief pure virtual service interface for magnetic field
//
// \author ebrianne@fnal.gov
//
////////////////////////////////////////////////////////////////////////
#ifndef MAGNETICFIELDSERVICESTANDARD_H
#define MAGNETICFIELDSERVICESTANDARD_H

#include "art/Framework/Principal/Run.h"
#include "art/Framework/Services/Registry/ActivityRegistry.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Services/Registry/ServiceMacros.h"
#include "fhiclcpp/ParameterSet.h"
#include "nug4/MagneticField/MagneticFieldStandard.h"
#include "nug4/MagneticFieldServices/MagneticFieldService.h"

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

#endif // MAGNETICFIELDSERVICESTANDARD_H