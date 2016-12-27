//
// GlueXBeamConversionProcess class header
//
// author: richard.t.jones at uconn.edu
// version: december 24, 2016
//
// In the context of the Geant4 event-level multithreading model,
// this class is "thread-local", ie. has thread-local state.
// Separate object instances are created for each worker thread,
// but virtually all of its functions need to be serialized, so
// it maintains its own interlocks for this purpose. Resources
// are created once when the first object is instantiated, and
// destroyed once when the last object is destroyed.

#ifndef _GLUEXBEAMCONVERSIONPROCESS_H_
#define _GLUEXBEAMCONVERSIONPROCESS_H_

#include <G4VDiscreteProcess.hh>
#include <G4VParticleChange.hh>
#include <ImportanceSampler.hh>
#include <PairConversionGeneration.hh>
#include <G4Event.hh>
#include <G4Step.hh>

class GlueXBeamConversionProcess : G4VDiscreteProcess
{
 public:
   GlueXBeamConversionProcess(const G4String &name, 
                              G4ProcessType aType=fNotDefined);
   GlueXBeamConversionProcess(GlueXBeamConversionProcess &src);
   virtual ~GlueXBeamConversionProcess();

   virtual G4double PostStepGetPhysicalInteractionLength(const G4Track &track,
                                                  G4double previousStepSize,
                                                  G4ForceCondition *condition);
   virtual G4VParticleChange *PostStepDoIt(const G4Track &track, 
                                           const G4Step &step);
   virtual G4double AlongStepGetPhysicalInteractionLength(const G4Track &track,
                                                   G4double previousStepSize,
                                                   G4double currentMinimumStep,
                                                   G4double &currentSafety,
                                                   G4GPILSelection *selection);
   virtual G4VParticleChange *AlongStepDoIt(const G4Track &track,
                                            const G4Step &step);
   virtual G4double AtRestGetPhysicalInteractionLength(const G4Track &track,
                                                   G4ForceCondition *condition);
   virtual G4VParticleChange *AtRestDoIt(const G4Track &track, 
                                         const G4Step &step);
   void GenerateBeamPairConversion(const G4Step &step);

 protected:
   virtual G4double GetMeanFreePath(const G4Track &track, 
                                    G4double previousStepSize,
                                    G4ForceCondition *condition);

   static PairConversionGeneration *fPairsGeneration;

   void prepareImportanceSamplingPDFs();

   static ImportanceSampler fPaircohPDF;
   static ImportanceSampler fTripletPDF;

 private:
   GlueXBeamConversionProcess operator=(GlueXBeamConversionProcess &src);
};

#endif