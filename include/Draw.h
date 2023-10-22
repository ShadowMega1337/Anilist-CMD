//
// Created by user on 10/20/2023.
//

#ifndef M323_LB3_DRAW_H
#define M323_LB3_DRAW_H

#include <vector>
#include <iostream>
#include <iomanip>

#include "Media.h"

class Draw
{
public:

    std::string drawList(std::vector<Media *> mediaList, int show);

private:
    static std::string formatToString(MediaFormat format);

    static std::string mediaSeasonToString(MediaSeason season);

    static std::string mediaTypeToString(MediaType type);

    static std::string mediaSourceToString(MediaSource source);

    static std::string mediaStatusToString(MediaStatus status);

};

#endif //M323_LB3_DRAW_H
