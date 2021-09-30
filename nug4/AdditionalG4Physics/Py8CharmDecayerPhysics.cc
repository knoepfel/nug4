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
/// \file eventgenerator/pythia/pythia8decayer/src/Py8CharmDecayerPhysics.cc
/// \brief Implementation of the Py8CharmDecayerPhysics class
///        it decays charm and bottom hadrons 
///
/// \author J. Yarba; FNAL

#include "Py8CharmDecayerPhysics.hh"
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
G4_DECLARE_PHYSCONSTR_FACTORY(Py8CharmDecayerPhysics);

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

Py8CharmDecayerPhysics::Py8CharmDecayerPhysics(G4int)
  : G4VPhysicsConstructor("Py8CharmDecayerPhysics")
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

Py8CharmDecayerPhysics::~Py8CharmDecayerPhysics()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void Py8CharmDecayerPhysics::ConstructParticle()
{
   // Nothing needs to be done here
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void Py8CharmDecayerPhysics::ConstructProcess()
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
            // a) charm hadrons
            // b) B hadrons
            // and replace with external decayer
            // for taus:  if ( std::abs(particle->GetPDGEncoding()) == 15 )
#ifdef EXPLICIT_CHARM_LIST
            std::set<int> abspdglist = {   411,   421, 10411, 10421,   413,
                                           423, 10413, 10423, 20413, 20423,
                                           415,   425,   431, 10431,   433,
                                         10433, 20433,   435,   441, 10441,
                                        100441,   443, 10443, 20443,100443,
                                         30443,   445,
            };
            int abspdg = abs(particle->GetPDGEncoding());
            if ( abspdglist.find(abspdg) != abspdglist.end() )
#else
            int abspdg = abs(particle->GetPDGEncoding());
            // PDG encoding: +/-n n_r N-L n_q1 n_q2 n_q3 n_J
          //int n_q3 = (abspdg/10  )%10;
            int n_q2 = (abspdg/100 )%10;
            int n_q1 = (abspdg/1000)%10;
            // charm  mesons have n_q2=4, charm  baryons n_q1=4
            // bottom mesons have n_q2=5, bottom baryons n_q1=5
            if ( n_q2 == 4 || n_q1 == 4 || n_q2 == 5 || n_q1 == 5 )
#endif
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
