//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// this is a modified version of Geant4 class:
/// \file eventgenerator/pythia/pythia8decayer/src/Py8TauDecayerPhysics.cc
/// \brief Implementation of the Py8TauDecayerPhysics class
///        is does not decay B+ (521) like the original, only taus
///
/// \author J. Yarba; FNAL

#include "Py8TauDecayerPhysics.hh"
#include "Py8Decayer.hh"

#include "Geant4/G4ParticleDefinition.hh"
#include "Geant4/G4ProcessManager.hh"
#include "Geant4/G4Decay.hh"
#include "Geant4/G4DecayTable.hh"

// factory
//
#include "Geant4/G4PhysicsConstructorFactory.hh"
//
// register it with contructor factory
//
G4_DECLARE_PHYSCONSTR_FACTORY(Py8TauDecayerPhysics);

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

Py8TauDecayerPhysics::Py8TauDecayerPhysics(G4int)
  : G4VPhysicsConstructor("Py8TauDecayerPhysics")
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

Py8TauDecayerPhysics::~Py8TauDecayerPhysics()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void Py8TauDecayerPhysics::ConstructParticle()
{
   // Nothing needs to be done here
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void Py8TauDecayerPhysics::ConstructProcess()
{

   // Loop over all particles instantiated and add external decayer
   // to all decay processes where there's no decay table, plus tau's

   // Create external decayer for G4Decay process
   // NOTE: The extDecayer will be deleted in G4Decay destructor
   Py8Decayer* extDecayer = new Py8Decayer();

   auto particleIterator=GetParticleIterator();
   particleIterator->reset();
   while ((*particleIterator)())
   {
      G4ParticleDefinition* particle = particleIterator->value();
      G4ProcessManager* pmanager = particle->GetProcessManager();
/*
      if ( verboseLevel > 1 ) {
         G4cout << "Setting ext decayer for: "
                <<  particleIterator->value()->GetParticleName()
                << G4endl;
      }
*/
      G4ProcessVector* processVector = pmanager->GetProcessList();
      for ( size_t i=0; i<processVector->length(); ++i )
      {
         G4Decay* decay = dynamic_cast<G4Decay*>((*processVector)[i]);
         if ( decay )
         {
            // remove native/existing decay table for
            // a) tau's
            // and replace with external decayer
            if ( std::abs(particle->GetPDGEncoding()) == 15 )
            {
               if ( particle->GetDecayTable() )
               {
                  delete particle->GetDecayTable();
                  particle->SetDecayTable(nullptr);
               }
               decay->SetExtDecayer(extDecayer);
            }
            // now set external decayer to all particles
            // that don't yet have a decay table
            if ( !particle->GetDecayTable() )
            {
               decay->SetExtDecayer(extDecayer);
            }
         }
      }
   }

   return;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
