/************************************************************************
 * Copyright(c) 2012, One Unified. All rights reserved.                 *
 * email: info@oneunified.net                                           *
 *                                                                      *
 * This file is provided as is WITHOUT ANY WARRANTY                     *
 *  without even the implied warranty of                                *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                *
 *                                                                      *
 * This software may not be used nor distributed without proper license *
 * agreement.                                                           *
 *                                                                      *
 * See the file LICENSE.txt for redistribution information.             *
 ************************************************************************/

#pragma once

#include <vector>
#include <array>

#include <boost/random.hpp>

#include "Individual.h"

namespace ou { // One Unified
namespace gp { // genetic programming

class Population {
public:
  Population( unsigned int nPopulationSize = 20 );
  ~Population(void);
protected:
private:
  // page 114, Kosa 1992
  unsigned int m_nPopulationSize; // should be multiple of ( 2 * ( size / maxdepth - 1 ) )
  unsigned int m_nMaxGenerations;

  unsigned int m_nMaxDepthOnCreation;
  unsigned int m_nMaxDepthOnCrossover;

  double m_probFunctionPointCrossover;
  double m_probTerminalPointCrossover;

  double m_probCrossover;
  double m_probReproduction;

  double m_probMutation;
  double m_probPermutation;

  double m_probDecimation;
  double m_ratioElitism;

  unsigned int m_nTournamentSize;

  unsigned int m_cntSignals;
  unsigned int m_cntAboveAverage;

  // pointer to array of individuals
  Individual* m_pCurGeneration;
  Individual* m_pNxtGeneration;

  typedef std::vector<Individual*> vGenerations_t;
  vGenerations_t m_vGenerations;

  boost::random::mt19937 m_rng;

  void CreateIndividuals( unsigned int cntIndividuals, Individual* pGeneration );

};

} // namespace gp
} // namespace ou
