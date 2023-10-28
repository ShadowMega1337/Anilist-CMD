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

    static int getAverageScore(const std::vector<Media *>& media);

    static int getTotalEpisodes(const std::vector<Media *>& media);

    static Media* getAnimeWithId(const std::vector<Media *>& media, int id);

    static Media* getAnimeWithName(const std::vector<Media *>& media, const std::string& name);

    static void resetScore(const std::vector<Media *> &media);
};


#endif //M323_LB3_BACKEND_H
