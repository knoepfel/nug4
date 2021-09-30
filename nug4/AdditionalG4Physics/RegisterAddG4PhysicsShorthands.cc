#include "RegisterAddG4PhysicsShorthands.hh"

#include "Geant4/globals.hh"
#include "Geant4/G4PhysListFactoryAlt.hh"
#include "Geant4/G4PhysicsConstructorRegistry.hh"

#include  "Geant4/G4PhysListRegistry.hh"


// trigger registration of shorthands
// for now be very verbose (2) ... so we know things have happened
const bool AddG4PhysicsShorthandsRegistered = RegisterAddG4PhysicsShorthands(2);


void PrintAvailablePhysicsLists(G4int verbosity) {
  G4cout << G4endl;
  G4cout << "extensibleFactory: here are the available physics lists:"
         << G4endl;
  g4alt::G4PhysListFactory factory;
  factory.PrintAvailablePhysLists();

  // if user asked for extra verbosity then print physics ctors as well
  if ( verbosity > 1 ) {
    G4cout << G4endl;
    G4cout << "extensibleFactory: "
           << "here are the available physics ctors that can be added:"
           << G4endl;
    G4PhysicsConstructorRegistry* g4pctorFactory =
      G4PhysicsConstructorRegistry::Instance();
    g4pctorFactory->PrintAvailablePhysicsConstructors();
  }
}

// set a short name for the plugin physics constructors

bool RegisterAddG4PhysicsShorthands(int verbose) {

  G4PhysListRegistry* plReg = G4PhysListRegistry::Instance();

  plReg->AddPhysicsExtension("PY8TAUDK","Py8TauDecayerPhysics");
  plReg->AddPhysicsExtension("PY8CHARMDK","Py8CharmDecayerPhysics");

  if (verbose > 0) {
    //G4cout << G4endl;
    //G4cout << __FILE__ << "::" << __LINE__ << G4endl;
    //G4cout << G4endl;
    PrintAvailablePhysicsLists(verbose);
  }

  return true;
}
