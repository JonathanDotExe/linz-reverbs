/*
  ==============================================================================

    ProgramManager.h
    Created: 3 Nov 2026 1:13:23pm
    Author:  Jonathan Hocheneder

  ==============================================================================
*/

#pragma once
#include "ReverbLocation.h"
#include <functional>

struct Program {
    size_t locationIndex = 0;
    size_t irIndex = 0;
};

class ProgramManager {

private:
    const std::vector<ReverbLocation> locations;
    const std::vector<Program> programs;
    size_t currProgramIndex = 0;
    const std::function<void(const ReverbIR&)> irCallback;
    
    void notifyProgramChange();
    
public:
    
    ProgramManager(std::function<void(const ReverbIR&)> irCallback);
    
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const std::string getProgramName (int index);
    
};
