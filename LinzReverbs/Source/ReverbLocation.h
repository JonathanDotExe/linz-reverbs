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

public class ReverbLocation {

public:
    const std::string name;
    const std::vector<ReverbIR> irs;
    
    ReverbIR(const std::string name, const char* data, const size_t size);
    
}
