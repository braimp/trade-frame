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

#include "Individual.h"

namespace ou { // One Unified
namespace gp { // genetic programming

Individual::Individual(void)
  : m_bComputed( false ), m_nCount( 1 ), m_id( m_nCount++ ),
  m_dblRawFitness( 0.0 ), m_dblRelativeFitness( 0.0 ), m_dblAdjustedFitness( 0.0 ), m_dblNormalizedFitness( 0.0 )
{
}

Individual::~Individual(void) {
}

void Individual::TreeToString( std::stringstream& ss ) const {
  ss << "LEnter=";
  m_Signals.rnLongEnter.TreeToString( ss );
  ss << "\nLExit=";
  m_Signals.rnLongExit.TreeToString( ss );
  ss << "\nSEnter=";
  m_Signals.rnShortEnter.TreeToString( ss );
  ss << "\nLExit=";
  m_Signals.rnShortExit.TreeToString( ss );
  ss << "\n";
}

} // namespace gp
} // namespace ou
