////////////////////////////////////////////////////////////////////////
// \file MagneticField.h
//
// \brief pure virtual base interface for magnetic fields
//
// \author ebrianne@fnal.gov
//
////////////////////////////////////////////////////////////////////////
#ifndef MAG_MAGNETICFIELD_H
#define MAG_MAGNETICFIELD_H

// std includes
#include <string>
#include <vector>

// Geant4 includes
#include "Geant4/G4ThreeVector.hh"

// ROOT includes
#include "TGeoVolume.h"
#include "TVector3.h"

namespace mag {

  // assumes a square grid of R, Z samples for speed in lookup, starting at an origin 0,0
  struct RZFieldMap
  {
      TVector3 CoordOffset;
      TVector3 ZAxis;
      float dr;
      float dz;
      std::vector<std::vector<float>> br;
      std::vector<std::vector<float>> bz;
      size_t nr() const { return br.size(); };
      size_t nz() const
      {
          if(nr() > 0)
          {
              return br[0].size();
          }
          else
          {
              return 0;
          }
      };
  };

  using Field3D = std::vector<std::vector<std::vector<float>>>;
  struct XYZFieldMap
  {
      TVector3 CoordOffset;
      TVector3 ZAxis;
      bool UseSymmetry;
      float xo, yo, zo;
      float dx, dy, dz;
      Field3D fx;
      Field3D fy;
      Field3D fz;
  };

  typedef enum MagneticFieldMode {
    kAutomaticBFieldMode=-1, // Used by DriftElectronsAlg
    kNoBFieldMode=0,         // no field
    kConstantBFieldMode=1,   // constant field
    kFieldRZMapMode= 2, // read a map as a function of r and z
    kFieldXYZMapMode= 3 // read a map as a function of x,y,z
    /*, kFieldMapMode, ... */
  } MagFieldMode_t;
  
  struct MagneticFieldDescription
  {
    MagFieldMode_t fMode;   ///< type of field used
    G4ThreeVector  fField;  ///< description of the field (uniform only)
    G4String       fVolume; ///< G4 volume containing the field
    TGeoVolume*    fGeoVol; ///< pointer to TGeoVolume with the field
    std::string    fFieldMapFilename; ///< file name for reading in the field map
    RZFieldMap     fRZFieldMap; ///< RZ field map if needed
    XYZFieldMap    fXYZFieldMap; ///< XYZ field map if needed
    float          fScaleFactor; ///< Used to scale the magnetic field.
  };

  class MagneticField {
    public:
    
      MagneticField(const MagneticField &) = delete;
      MagneticField(MagneticField &&) = delete;
      MagneticField& operator = (const MagneticField &) = delete;
      MagneticField& operator = (MagneticField &&) = delete;
      virtual ~MagneticField() = default;

      virtual std::vector<MagneticFieldDescription> const& Fields()                   const = 0;
      virtual size_t                                       NumFields()                const = 0;
      virtual MagFieldMode_t                        const& UseField(size_t f)         const = 0;
      virtual std::string                           const& MagnetizedVolume(size_t f) const = 0;

      // return the field at a particular point
      virtual G4ThreeVector const FieldAtPoint(G4ThreeVector const& p=G4ThreeVector(0)) const = 0;

      // This method will only return a uniform field based on the input
      // volume name.  If the input volume does not have a uniform field
      // caveat emptor
      virtual G4ThreeVector const UniformFieldInVolume(std::string const& volName) const = 0;

    protected:

      MagneticField() = default;
  
  };

}

#endif // MAG_MAGNETICFIELD_H
