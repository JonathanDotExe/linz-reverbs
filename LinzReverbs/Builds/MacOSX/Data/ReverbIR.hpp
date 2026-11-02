//
//  ReverbIR.hpp
//  LinzReverbs - VST3
//
//  Created by Jonathan Hocheneder on 02.11.26.
//

#pragma once

public class ReverbIR {

public:
    const std::string name;
    const char* data;
    const size_t size;
    
    ReverbIR(std::string name, const char* data, const size_t size);

}


