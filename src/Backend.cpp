//
// Created by user on 10/22/2023.
//

#include "Backend.h"

std::vector<Media *> Backend::getFilteredList(std::vector<Media *> media, const std::string& filter)
{
    return media;
}

short Backend::getAverageScore(const std::vector<Media *>& media)
{
    return 0;
}

unsigned int Backend::getTotalEpisodes(const std::vector<Media *>& media)
{
    return 0;
}

Media* Backend::getAnimeWithId(int id)
{
    return new Media;
}

Media* Backend::getAnimeWithName(const std::string& name)
{
    return new Media; // Can be NULL (nullptr)
}
