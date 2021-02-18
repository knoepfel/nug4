////////////////////////////////////////////////////////////////////////
// \file MagneticFieldStandard.h
//
// \brief header of class for storing/accessing magnetic fields
//
// \author ebrianne@fnal.gov
//
////////////////////////////////////////////////////////////////////////
#ifndef MAGNETICFIELD_MAGNETICFIELDSTANDARD_H
#define MAGNETICFIELD_MAGNETICFIELDSTANDARD_H

// nug4 libraries
#include "nug4/MagneticField/MagneticField.h"

// std includes
#include <string>

// Geant4 includes
#include "Geant4/G4ThreeVector.hh"

// FHiCL libraries
namespace fhicl { class ParameterSet; }

namespace mag {

  class MagneticFieldStandard : public MagneticField {

    public:

      explicit MagneticFieldStandard(fhicl::ParameterSet const& pset);
      MagneticFieldStandard(MagneticFieldStandard const&) = delete;
      virtual ~MagneticFieldStandard() = default;

      void reconfigure(fhicl::ParameterSet const& pset);

      //Return std::vector<MagneticFieldDescription>
      std::vector<MagneticFieldDescription> const& Fields()                   const override { return fFieldDescriptions;            }

      //Return the size of std::vector<MagneticFieldDescription>
      size_t                                       NumFields()                const override { return fFieldDescriptions.size();     }

      //Return the field mode
      MagFieldMode_t                        const& UseField(size_t f)         const override { return fFieldDescriptions[f].fMode;   }

      //return the magnetized volumes
      std::string                           const& MagnetizedVolume(size_t f) const override { return fFieldDescriptions[f].fVolume; }

      // return the field at a particular point
      G4ThreeVector const FieldAtPoint(G4ThreeVector const& p=G4ThreeVector(0)) const override;

      // This method will only return a uniform field based on the input
      // volume name.  If the input volume does not have a uniform field
      // caveat emptor
      G4ThreeVector const UniformFieldInVolume(std::string const& volName) const override;

    private:

      // The simplest implmentation has a constant field inside a named
      // detector volume
      std::vector<MagneticFieldDescription> fFieldDescriptions; ///< Descriptions of the fields

    protected:

  }; // class MagneticFieldStandard
} //namespace mag
#endif // MAGNETICFIELD_MAGNETICFIELDSTANDARD_H