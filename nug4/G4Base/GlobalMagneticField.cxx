//
//  G4 interface for full magnetic field.
//
//
// Original author Eldwan Brianne 
//

// C++ includes
#include <iostream>

#include "messagefacility/MessageLogger/MessageLogger.h"

// nug4 includes.
#include "nug4/G4Base/GlobalMagneticField.h"
#include "nug4/MagneticFieldServices/MagneticFieldService.h"

#include "art/Framework/Services/Registry/ServiceHandle.h"

// CLHEP includes
#include "CLHEP/Units/SystemOfUnits.h"
#include "CLHEP/Vector/ThreeVector.h"

using CLHEP::Hep3Vector;
using namespace std;

namespace mag {

  GlobalMagneticField::GlobalMagneticField()
  {
    art::ServiceHandle<mag::MagneticFieldService> bField;
    _bFieldHandle = &*bField;
  }

  // This is the entry point called by G4.
  void GlobalMagneticField::GetFieldValue(const G4double Point[4], G4double *Bfield) const {

    //Check provider units (geant4 uses mm, your framework can use another unit...)
    const auto *pProvider = _bFieldHandle->provider();

    G4ThreeVector point(Point[0], Point[1], Point[2]);//should be in mm
    const G4ThreeVector field = pProvider->FieldAtPoint(point);//should return tesla

    Bfield[0] = field.x();
    Bfield[1] = field.y();
    Bfield[2] = field.z();

    // std::cout << "Returned field " << Bfield[0] << ", " << Bfield[1] << ", " << Bfield[2] << std::endl;

    return;
  }

} // end namespace mag
