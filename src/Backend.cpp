//
// Created by user on 10/22/2023.
//

#include "Backend.h"

std::string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

std::vector<Media *> Backend::getFilteredList(std::vector<Media *> media, const std::string &filter)
{
    std::vector<Media *> filteredList;
        for (Media* mediaItem : media) {
            std::string titleEn = mediaItem->getTitle()->getEnglish();
            std::string titleJp = mediaItem->getTitle()->getRomaji();
            for (char &c: titleEn)
            {
                c = std::tolower(c);
            }
            for (char &c: titleJp)
            {
                c = std::tolower(c);
            }
            if (mediaItem != nullptr && mediaItem->getTitle() != nullptr) {
                if (titleEn.find(filter) != std::string::npos ||
                    titleJp.find(filter) != std::string::npos) {
                    filteredList.push_back(mediaItem);
                }
            }
        }
        return filteredList;

}

short Backend::getAverageScore(const std::vector<Media *> &media)
{
    double totalScore = 0.0;
    int max = 0;

    for (Media *mediaItem: media)
    {
        if (mediaItem->getWatchedEpisodes() != 0)
        {
            if (mediaItem != nullptr)
            {
                int score = mediaItem->getAverageScore();
                if (score >= 0)
                {
                    totalScore += static_cast<double>(score);
                    max++;
                }
            }
        }
    }

    if (max > 0)
    {
        return totalScore / static_cast<double>(max);
    }
    else
    {
        return 0.0;
    }
}

unsigned int Backend::getTotalEpisodes(const std::vector<Media *> &media)
{
    return std::accumulate(media.begin(), media.end(), 0, [](unsigned int sum, Media* mediaItem) {
        if (mediaItem != nullptr) {
            return sum + static_cast<unsigned int>(mediaItem->getWatchedEpisodes());
        }
        return sum;
    });
}

Media *Backend::getAnimeWithId(const std::vector<Media *> &media, int id)
{
    for (Media *mediaItem: media)
    {
        if (mediaItem != nullptr && mediaItem->getId() == id)
        {
            return mediaItem;
        }
    }
    return nullptr;
}

Media *Backend::getAnimeWithName(const std::vector<Media *> &media, const std::string &name)
{
    for (Media *mediaItem: media)
    {
        std::string titleEn = mediaItem->getTitle()->getEnglish();
        std::string titleJp = mediaItem->getTitle()->getRomaji();
        for (char &c: titleEn)
        {
            c = std::tolower(c);
        }
        for (char &c: titleJp)
        {
            c = std::tolower(c);
        }

        if (mediaItem->getTitle())
        {
            if ((titleEn == trim(name) && !titleEn.empty()) || (titleJp == trim(name) && !titleJp.empty()))
            {
                return mediaItem;
            }

        }

    }
    return nullptr;
}

void Backend::resetScore(const std::vector<Media *> &media)
{
    for (const auto &medium: media)
    {
        if (medium != nullptr) {
            medium->setAverageScore(0);
        }
    }
}
