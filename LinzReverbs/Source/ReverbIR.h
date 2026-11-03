/*
  ==============================================================================

    ReverbIR.h
    Created: 2 Nov 2026 4:00:08pm
    Author:  Jonathan Hocheneder

  ==============================================================================
*/

#pragma once
#include <string>
#include <stdio.h>

class ReverbIR {

public:
    const std::string name;
    const char* data;
    const size_t size;
    
    ReverbIR(const std::string name, const char* data, const size_t size);
    
};
