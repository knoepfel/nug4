////////////////////////////////////////////////////////////////////////
// \file MagneticFieldService.h
//
// \brief pure virtual service interface for magnetic field
//
// \author ebrianne@fnal.gov
//
////////////////////////////////////////////////////////////////////////
#ifndef MAGNETICFIELDSERVICE_H
#define MAGNETICFIELDSERVICE_H

#include "nug4/MagneticField/MagneticField.h"

#include "art/Framework/Services/Registry/ServiceDeclarationMacros.h"

namespace mag {
  class MagneticFieldService {
  public:
    using provider_type = mag::MagneticField;

    virtual ~MagneticFieldService() = default;
    virtual const mag::MagneticField* provider() const = 0;
  };
}

DECLARE_ART_SERVICE_INTERFACE(mag::MagneticFieldService, SHARED)

#endif // MAGNETICFIELDSERVICE_H
