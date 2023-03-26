#ifndef M_LIBRARIES_H
#define M_LIBRARIES_H

// Frequently used libraries
#include <stdexcept>
#include <string>

// Functions
#include "functions/m_rand.hxx"
#include "functions/m_mapper.hxx"
RANDOM_FUNCTIONS funcRand;
MAP_HANDLER funcMap;
// Handling
#include "handlers/m_players.h"
#include "handlers/m_cards.h"
// Final fixes
#include "make/m_makeall.hh"

#endif