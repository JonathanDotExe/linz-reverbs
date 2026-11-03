/*
  ==============================================================================

    ReverbLocation.h
    Created: 2 Nov 2026 4:00:23pm
    Author:  Jonathan Hocheneder

  ==============================================================================
*/

#pragma once
#include <string>
#include <stdio.h>
#include <vector>
#include "ReverbIR.h"

class ReverbLocation {

public:
    const std::string name;
    const std::vector<ReverbIR> irs;
    
    ReverbLocation(const std::string name, const std::vector<ReverbIR> irs);
    
};
