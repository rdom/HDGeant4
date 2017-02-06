//
// GlueXBremsstrahlungGenerator class implementation
//
// author: richard.t.jones at uconn.edu
// version: february 4, 2017
//
// In the context of the Geant4 event-level multithreading model,
// this class is "shared", ie. has no thread-local state. It is
// invoked from the GlueXGeneratorAction class, which is
// responsible for managing the interlocks to ensure thread safety.
//
// Notes:
// This is an auxilliary class that is not used in the main production
// version of HDGeant4. It was written to provide an alternate means to
// calculate statistical properties of the bremsstrahlung beam from the
// underlying QED processes. The primary photon beam generator class is
// GlueXPhotonBeamGenerator, which uses analytic distribution formulas
// to generate distributions in photon energy, angle, and polarization.
// By contrast, this GlueXBremsstrahlungGenerator directly computes the
// QED amplitude for a specific choise for the event kinematics, and
// then employs importance sampling to achieve a true reproduction of
// the parent distribution without needing to know any formulas that
// describe them. This latter method has the advantage that one can
// use it to sample any property of the reaction (eg. the polarization
// of the recoil electron, correlation of the photon polarization with
// emission angle, etc.) simply by histogramming it over a sample.

#ifndef GlueXBremsstrahlungGenerator_H
#define GlueXBremsstrahlungGenerator_H

#include <GlueXBremsstrahlungGenerator.hh>

#if USING_DIRACXX

GlueXBremsstrahlungGenerator::GlueXBremsstrahlungGenerator()
 : fBeamEnergy(12.), fMinEnergy(3.)
{}

GlueXBremsstrahlungGenerator::~GlueXBremsstrahlungGenerator()
{}

void GlueXBremsstrahlungGenerator::GenerateBeamPhotons(int nevents)
{}

double GlueXBremsstrahlungGenerator::AtomicFormFactor(double q2)
{}

void GlueXBremsstrahlungGenerator::prepareImportanceSamplingPDFs()
{}

};

#endif