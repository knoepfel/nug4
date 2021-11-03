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
#include "nug4/MagneticField/MagneticFieldStandard.h"
#include "nug4/MagneticFieldServices/MagneticFieldServiceStandard.h"

//Framework includes
#include "art/Framework/Principal/Run.h" // for Run
#include "art/Framework/Services/Registry/ActivityRegistry.h"
#include "art/Framework/Services/Registry/GlobalSignal.h"
#include "canvas/Persistency/Provenance/RunID.h"

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
