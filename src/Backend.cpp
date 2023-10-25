//
// Created by user on 10/22/2023.
//

#include "Backend.h"
#include <algorithm>
#include <functional>
#include <numeric>
#include <cctype>

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

//todo: done
bool isMatch(const std::string& titleEn, const std::string& titleJp, const std::string& filter) {
    std::string lowerFilter = filter;
    std::transform(lowerFilter.begin(), lowerFilter.end(), lowerFilter.begin(), ::tolower);

    std::string lowerTitleEn = titleEn;
    std::transform(lowerTitleEn.begin(), lowerTitleEn.end(), lowerTitleEn.begin(), ::tolower);

    std::string lowerTitleJp = titleJp;
    std::transform(lowerTitleJp.begin(), lowerTitleJp.end(), lowerTitleJp.begin(), ::tolower);

    return (lowerTitleEn.find(lowerFilter) != std::string::npos || lowerTitleJp.find(lowerFilter) != std::string::npos);
}

std::vector<Media *> Backend::getFilteredList(std::vector<Media *> media, const std::string &filter)
{
    std::vector<Media *> filteredList;

    std::copy_if(media.begin(), media.end(), std::back_inserter(filteredList), [&](Media* mediaItem) {
        if (mediaItem != nullptr && mediaItem->getTitle() != nullptr) {
            std::string titleEn = mediaItem->getTitle()->getEnglish();
            std::string titleJp = mediaItem->getTitle()->getRomaji();
            return isMatch(titleEn, titleJp, filter);
        }
        return false;
    });

    return filteredList;
}

//todo: done
short Backend::getAverageScore(const std::vector<Media *> &media)
{
    int totalScore = std::accumulate(media.begin(), media.end(), 0, [](int sum, Media* mediaItem) {
        if (mediaItem != nullptr && mediaItem->getWatchedEpisodes() != 0) {
            int score = mediaItem->getAverageScore();
            if (score >= 0) {
                return sum + score;
            }
        }
        return sum;
    });

    int max = std::count_if(media.begin(), media.end(), [](Media* mediaItem) {
        return (mediaItem != nullptr && mediaItem->getWatchedEpisodes() != 0 && mediaItem->getAverageScore() >= 0);
    });

    if (max > 0) {
        return static_cast<short>(totalScore / max);
    } else {
        return 0;
    }
}

//todo: done
unsigned int Backend::getTotalEpisodes(const std::vector<Media *> &media)
{
    return std::accumulate(media.begin(), media.end(), 0, [](unsigned int sum, Media* mediaItem) {
        if (mediaItem != nullptr) {
            return sum + static_cast<unsigned int>(mediaItem->getWatchedEpisodes());
        }
        return sum;
    });
}

//todo: done
Media *Backend::getAnimeWithId(const std::vector<Media *> &media, int id)
{
    auto it = std::find_if(media.begin(), media.end(), [id](Media* mediaItem) {
        return (mediaItem != nullptr && mediaItem->getId() == id);
    });

    if (it != media.end()) {
        return *it;
    }

    return nullptr;
}

//todo: done
char toLower(char c) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}

//todo: done
Media *Backend::getAnimeWithName(const std::vector<Media *> &media, const std::string &name)
{
    auto it = std::find_if(media.begin(), media.end(), [&](Media* mediaItem) {
        if (mediaItem != nullptr && mediaItem->getTitle() != nullptr) {
            std::string titleEn = mediaItem->getTitle()->getEnglish();
            std::string titleJp = mediaItem->getTitle()->getRomaji();

            std::transform(titleEn.begin(), titleEn.end(), titleEn.begin(), toLower);
            std::transform(titleJp.begin(), titleJp.end(), titleJp.begin(), toLower);

            return ((titleEn == trim(name) && !titleEn.empty()) || (titleJp == trim(name) && !titleJp.empty()));
        }
        return false;
    });

    if (it != media.end()) {
        return *it;
    }

    return nullptr;
}

//todo: done
void Backend::resetScore(const std::vector<Media *> &media)
{
    std::vector<Media*> updatedMedia;

    std::transform(media.begin(), media.end(), std::back_inserter(updatedMedia), [](Media* medium) {
        if (medium != nullptr) {
            medium->setAverageScore(0);
        }
        return medium;
    });
}
