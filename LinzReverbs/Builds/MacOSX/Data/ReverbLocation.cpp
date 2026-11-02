//
//  ReverbLocation.cpp
//  LinzReverbs - VST3
//
//  Created by Jonathan Hocheneder on 02.11.26.
//

#include "ReverbLocation.hpp"
#include "ReverbIR.hpp"

public class ReverbLocation {

public:
    const std::string name;
    const std::vector<ReverbIR> irs;
    
    ReverbLocation(std::string name, std::vector<ReverbIR> irs);
    
}
