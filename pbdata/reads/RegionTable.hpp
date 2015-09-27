// Copyright (c) 2014-2015, Pacific Biosciences of California, Inc.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted (subject to the limitations in the
// disclaimer below) provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above
//    copyright notice, this list of conditions and the following
//    disclaimer in the documentation and/or other materials provided
//    with the distribution.
//
//  * Neither the name of Pacific Biosciences nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
// GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY PACIFIC
// BIOSCIENCES AND ITS CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL PACIFIC BIOSCIENCES OR ITS
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

// Author: Mark Chaisson

#ifndef _BLASR_REGION_TABLE_HPP_
#define _BLASR_REGION_TABLE_HPP_

#include <cassert>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <ostream>
#include "Types.h"
#include "Enumerations.h"
#include "PacBioDefs.h"
#include "RegionAnnotation.hpp"


class RegionTable {
public:
    std::vector<RegionAnnotation> table;
    std::vector<std::string> columnNames;
    std::vector<std::string> regionTypes;
    std::vector<std::string> regionDescriptions;
    std::vector<std::string> regionSources;
    std::vector<RegionType>  regionTypeEnums;
    // Different region tables have different ways of encoding regions.
    // This maps from the way they are encoded in the rgn table to a
    // standard encoding.

    // Return default region types used in a region table 
    // Note that the ORDER of region types does matter.
    static std::vector<RegionType> DefaultRegionTypes(void);

    int LookupRegionsByHoleNumber(int holeNumber, int &low, int &high) const; 

    // Define a bunch of accessor functions.
    RegionType GetType(int regionIndex) const; 

    int GetStart(const int regionIndex) const; 

    void SetStart(int regionIndex, int start); 

    int GetEnd(const int regionIndex) const; 

    void SetEnd(int regionIndex, int end); 

    int GetHoleNumber(int regionIndex) const;

    void SetHoleNumber(int regionIndex, int holeNumber); 

    int GetScore(int regionIndex) const; 

    void SetScore(int regionIndex, int score); 

    void SortTableByHoleNumber(); 

    void Reset(); 

    void CreateDefaultAttributes(); 
};

#endif // _BLASR_REGION_TABLE_HPP_
