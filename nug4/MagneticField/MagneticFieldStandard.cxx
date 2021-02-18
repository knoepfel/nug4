////////////////////////////////////////////////////////////////////////
// \file MagneticFieldStandard.cxx
//
// \brief implementation of class for storing/accessing magnetic fields
//
// \author ebrianne@fnal.gov
//
////////////////////////////////////////////////////////////////////////

//nug4 includes
#include "nug4/MagneticField/MagneticFieldStandard.h"

//ROOT includes
#include "TGeoManager.h"

// Framework includes
#include "fhiclcpp/ParameterSet.h"

//std includes
#include <vector>
#include <string>

namespace mag {

  //-----------------------------------------------
  MagneticFieldStandard::MagneticFieldStandard(fhicl::ParameterSet const& pset)
  {
    this->reconfigure(pset);
  }

  //------------------------------------------------
  void MagneticFieldStandard::reconfigure(fhicl::ParameterSet const& pset)
  {
      auto fieldDescriptions = pset.get<std::vector<fhicl::ParameterSet> >("FieldDescriptions");
      
      MagneticFieldDescription fieldDescription;
      for(auto itr : fieldDescriptions){
        fieldDescription.fMode   = (mag::MagFieldMode_t)(itr.get<int>("UseField"));
        // if the mode is turned to off, no point looking for a volume or 
        // trying to put a description into the fFieldDescriptions data member.
        // if all input field descriptions are set to fMode = kNoBFieldMode, then the 
        // methods to return the fields will not go into the loop over fFieldDescriptions
        // and will just return a 0 field.
        if(fieldDescription.fMode == mag::kNoBFieldMode) continue;
        fieldDescription.fVolume = itr.get<std::string>("MagnetizedVolume");
        fieldDescription.fGeoVol = gGeoManager->FindVolumeFast(fieldDescription.fVolume.c_str());
        // check that we have a good volume
        if( fieldDescription.fGeoVol == nullptr )
          throw cet::exception("MagneticField")
          << "cannot locat volume "
          << fieldDescription.fVolume
          << " in gGeoManager, bail";
        // These need to be read as types that FHICL know about, but they
        // are used by Geant, so I store them in Geant4 types.
        std::vector<double> field = itr.get<std::vector<double> >("ConstantField");
        
        // Force the dimension of the field definition
        field.resize(3);
        for(size_t i = 0; i < 3; ++i) fieldDescription.fField[i] = field[i];
        
        fFieldDescriptions.push_back(fieldDescription);
      }
      
      return;
  }

  //------------------------------------------------------------
  G4ThreeVector const MagneticFieldStandard::FieldAtPoint(G4ThreeVector const& p) const
  {
      // check that the input point is in the magnetized volume
      // Use the gGeoManager to determine what node the point
      // is in
      double point[3] = { p.x(), p.y(), p.z() };
      // loop over the field descriptions to see if the point is in any of them
      for(auto fd : fFieldDescriptions){
          // we found a node, see if its name is the same as
          // the volume with the field
          if(fd.fGeoVol->Contains(point)) return fd.fField;
      }
      // if we get here, we can't find a field
      return G4ThreeVector(0);
  }

  //------------------------------------------------------------
  G4ThreeVector const MagneticFieldStandard::UniformFieldInVolume(std::string const& volName) const
  {
      // if the input volume name is the same as the magnetized volume
      // return the uniform field

      for(auto fd : fFieldDescriptions){
          if (fd.fVolume.compare(volName) == 0) return fd.fField;
      }

      // if we get here, we can't find a field
      return G4ThreeVector(0);
  }
}//namespace mag