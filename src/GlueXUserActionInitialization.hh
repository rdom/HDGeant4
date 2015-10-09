//
// GlueXUserActionInitalization - class header
//
// author: richard.t.jones at uconn.edu
// version: august 24, 2015
//
// In the context of the Geant4 event-level multithreading model,
// this class is "shared", ie. has no thread-local state.

#ifndef _GlueXUserActionInitialization_
#define _GlueXUserActionInitialization_

#include <G4VUserActionInitialization.hh>

#include <GlueXPrimaryGeneratorAction.hh>
#include <GlueXRunAction.hh>
#include <GlueXEventAction.hh>
#include <GlueXSteppingAction.hh>
#include <GlueXSteppingVerbose.hh>

class GlueXUserActionInitialization : public G4VUserActionInitialization
{
 public:
   
   GlueXUserActionInitialization() {}
   ~GlueXUserActionInitialization() {}
   
   virtual void Build() const {
      SetUserAction(new GlueXRunAction());
      SetUserAction(new GlueXEventAction());
      SetUserAction(new GlueXSteppingAction());
      SetUserAction(new GlueXPrimaryGeneratorAction());
   }

   virtual void BuildForMaster() const {
      SetUserAction(new GlueXRunAction());
   }

   virtual G4VSteppingVerbose* InitializeSteppingVerbose() const {
      G4VSteppingVerbose *verb = G4VSteppingVerbose::GetInstance();
      if (verb)
         return verb;
      else
         return new GlueXSteppingVerbose();
   }
};

#endif // _GlueXUserActionInitialization_