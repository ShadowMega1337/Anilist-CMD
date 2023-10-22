//
// Created by user on 10/22/2023.
//

#ifndef M323_LB3_BACKEND_H
#define M323_LB3_BACKEND_H

#include <iostream>
#include <vector>

#include "Media.h"


class Backend
{
public:
    static std::vector<Media*> getFilteredList(std::vector<Media*> media, const std::string& filter);

    static short getAverageScore(const std::vector<Media *>& media);

    static unsigned int getTotalEpisodes(const std::vector<Media *>& media);

    static Media* getAnimeWithId(int id);

    static Media* getAnimeWithName(const std::string& name);
};


#endif //M323_LB3_BACKEND_H