/*
  ==============================================================================

    ProgramManager.cpp
    Created: 3 Nov 2026 1:13:23pm
    Author:  Jonathan Hocheneder

  ==============================================================================
*/

#include "ProgramManager.h"

#include "BinaryData.h"

ProgramManager::ProgramManager(std::function<void(const ReverbIR&)> irCallback)
: locations({
    ReverbLocation("JKU HS10", {
        ReverbIR("Long", BinaryData::JKU_HS10_Long_wav, BinaryData::JKU_HS10_Long_wavSize),
        ReverbIR("Short", BinaryData::JKU_HS10_Short_wav, BinaryData::JKU_HS10_Short_wavSize),
        ReverbIR("Clap 1", BinaryData::JKU_HS10_Clap1_wav, BinaryData::JKU_HS10_Clap1_wavSize),
        ReverbIR("Clap 2", BinaryData::JKU_HS10_Clap2_wav, BinaryData::JKU_HS10_Clap2_wavSize)
    }),
    ReverbLocation("JKU Garage", {
        ReverbIR("Long", BinaryData::JKU_Garage_Long_wav, BinaryData::JKU_Garage_Long_wavSize),
        ReverbIR("Short", BinaryData::JKU_Garage_Short_wav, BinaryData::JKU_Garage_Short_wavSize),
        ReverbIR("Clap 1", BinaryData::JKU_Garage_Clap1_wav, BinaryData::JKU_Garage_Clap1_wavSize),
        ReverbIR("Clap 2", BinaryData::JKU_Garage_Clap2_wav, BinaryData::JKU_Garage_Clap2_wavSize)
    }),
    ReverbLocation("Unterführung ARS Electronica Center", {
        ReverbIR("Long", BinaryData::ARS_Long_wav, BinaryData::ARS_Long_wavSize),
        //        ReverbIR("Short", BinaryData::ARS_Short_wav, BinaryData::ARS_Short_wavSize),
        //        ReverbIR("Clap 1", BinaryData::ARS_Clap1_wav, BinaryData::ARS_Clap1_wavSize),
        //        ReverbIR("Clap 2", BinaryData::ARS_Clap2_wav, BinaryData::ARS_Clap2_wavSize)
    }),
    ReverbLocation("Under The Bridge", {
        ReverbIR("Clap 1", BinaryData::Under_The_Bridge_Clap1_wav, BinaryData::JKU_Garage_Clap1_wavSize),
        ReverbIR("Clap 2", BinaryData::Under_The_Bridge_Clap2_wav, BinaryData::JKU_Garage_Clap2_wavSize)
    }),
}),
programs({
    Program{0, 0},
    Program{0, 1},
    Program{0, 2},
    Program{0, 3},
    Program{1, 0},
    Program{1, 1},
    Program{1, 2},
    Program{1, 3},
    Program{2, 0},
    Program{3, 0},
    Program{3, 1}
}),
irCallback(irCallback)
{
    notifyProgramChange();
}

int ProgramManager::getNumPrograms() {
    return static_cast<int>(programs.size());
}

int ProgramManager::getCurrentProgram() {
    return static_cast<int>(currProgramIndex);
}

void ProgramManager::setCurrentProgram (int index) {
    if (index >= 0 && index < programs.size()) {
        currProgramIndex = index;
        notifyProgramChange();
    }
}

void ProgramManager::notifyProgramChange() {
    const Program& prog = programs.at(currProgramIndex);
    const ReverbLocation& loc = locations.at(prog.locationIndex);
    const ReverbIR& ir = loc.irs.at(prog.irIndex);
    
    irCallback(ir);
}

const std::string ProgramManager::getProgramName (int index) {
    const Program& prog = programs.at(currProgramIndex);
    const ReverbLocation& loc = locations.at(prog.locationIndex);
    const ReverbIR& ir = loc.irs.at(prog.irIndex);

    return loc.name + " - " + ir.name;
}
