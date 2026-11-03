/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   JKU_HS10_Clap1_wav;
    const int            JKU_HS10_Clap1_wavSize = 471140;

    extern const char*   JKU_HS10_Clap2_wav;
    const int            JKU_HS10_Clap2_wavSize = 729734;

    extern const char*   JKU_HS10_Long_wav;
    const int            JKU_HS10_Long_wavSize = 415802;

    extern const char*   JKU_HS10_Short_wav;
    const int            JKU_HS10_Short_wavSize = 392690;

    extern const char*   JKU_Garage_Clap1_wav;
    const int            JKU_Garage_Clap1_wavSize = 1018118;

    extern const char*   JKU_Garage_Clap2_wav;
    const int            JKU_Garage_Clap2_wavSize = 968582;

    extern const char*   JKU_Garage_Long_wav;
    const int            JKU_Garage_Long_wavSize = 1592996;

    extern const char*   JKU_Garage_Short_wav;
    const int            JKU_Garage_Short_wavSize = 1156952;

    extern const char*   Under_The_Bridge_Clap2_wav;
    const int            Under_The_Bridge_Clap2_wavSize = 544994;

    extern const char*   Under_The_Bridge_Clap1_wav;
    const int            Under_The_Bridge_Clap1_wavSize = 667574;

    extern const char*   ARS_Long_wav;
    const int            ARS_Long_wavSize = 1418102;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 11;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
