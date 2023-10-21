//
// Created by user on 10/20/2023.
//

#include "Draw.h"

void Draw::drawList(std::vector<Media *> mediaList)
{
    std::cout << mediaList.size() << std::endl;
    if (!mediaList.empty() && mediaList[0] != nullptr) {
        // Check if the vector is not empty and the pointer is valid
        Media *firstMedia = mediaList[0];
        std::cout << firstMedia->getEpisodes() << std::endl;
    } else {
        std::cout << "The vector is empty or the first element is nullptr." << std::endl;
    }
    for (auto media : mediaList) {
        std::cout << "Title: " << media->getTitle().getEnglish() << std::endl;
        std::cout << "Score: " << media->getAverageScore() << std::endl;
        std::cout << "Eps.: " << media->getEpisodes() << std::endl;
        std::cout << "Startdate: " << media->getStartDate().getMonth() << std::endl;
        std::cout << "Id: " << media->getId() << std::endl;
        std::cout << "CountryCode: " << media->getCountryCode() << std::endl;
        std::cout << "Duration: " << media->getDuration() << std::endl;
        std::cout << "Enddate: " << media->getEndDate().getMonth() << std::endl;
        std::cout << "Format: " << formatToString(media->getFormat()) << std::endl;
        std::cout << "Popularity: " << media->getPopularity() << std::endl;
        std::cout << "Season: " << mediaSeasonToString(media->getSeason()) << std::endl;
        std::cout << "SeasonYear: " << media->getSeasonYear() << std::endl;
        std::cout << "Source: " << mediaSourceToString(media->getSource()) << std::endl;
        std::cout << "Status: " << mediaStatusToString(media->getStatus()) << std::endl;
        std::cout << "Type: " << mediaTypeToString(media->getType()) << std::endl;
    }

}


std::string Draw::mediaSeasonToString(MediaSeason season)
{
    switch (season) {
        case MediaSeason::SPRING:
            return "SPRING";
        case MediaSeason::SUMMER:
            return "SUMMER";
        case MediaSeason::FALL:
            return "FALL";
        case MediaSeason::WINTER:
            return "WINTER";
        default:
            return "UNKNOWN";
    }
}

std::string Draw::mediaTypeToString(MediaType type)
{
    switch (type) {
        case MediaType::ANIME:
            return "ANIME";
        case MediaType::MANGA:
            return "MANGA";
        default:
            return "UNKNOWN";
    }
}

std::string Draw::formatToString(MediaFormat format)
{
    switch (format) {
        case MediaFormat::TV:
            return "TV";
        case MediaFormat::TV_SHORT:
            return "TV_SHORT";
        case MediaFormat::MOVIE:
            return "MOVIE";
        case MediaFormat::SPECIAL:
            return "SPECIAL";
        case MediaFormat::OVA:
            return "OVA";
        case MediaFormat::ONA:
            return "ONA";
        case MediaFormat::MUSIC:
            return "MUSIC";
        case MediaFormat::MANGA:
            return "MANGA";
        case MediaFormat::NOVEL:
            return "NOVEL";
        default:
            return "ONE_SHOT";
    }
}

std::string Draw::mediaSourceToString(MediaSource source)
{
    switch (source) {
        case MediaSource::ORIGINAL:
            return "ORIGINAL";
        case MediaSource::MANGA:
            return "MANGA";
        case MediaSource::LIGHT_NOVEL:
            return "LIGHT_NOVEL";
        case MediaSource::VISUAL_NOVEL:
            return "VISUAL_NOVEL";
        case MediaSource::VIDEO_GAME:
            return "VIDEO_GAME";
        case MediaSource::OTHER:
            return "OTHER";
        case MediaSource::NOVEL:
            return "NOVEL";
        case MediaSource::DOUJINSHI:
            return "DOUJINSHI";
        case MediaSource::ANIME:
            return "ANIME";
        case MediaSource::WEB_NOVEL:
            return "WEB_NOVEL";
        case MediaSource::LIVE_ACTION:
            return "LIVE_ACTION";
        case MediaSource::GAME:
            return "GAME";
        case MediaSource::COMIC:
            return "COMIC";
        case MediaSource::MULTIMEDIA_PROJECT:
            return "MULTIMEDIA_PROJECT";
        default:
            return "PICTURE_BOOK";
    }
}


std::string Draw::mediaStatusToString(MediaStatus status)
{
    switch (status) {
        case MediaStatus::FINISHED:
            return "FINISHED";
        case MediaStatus::RELEASING:
            return "RELEASING";
        case MediaStatus::NOT_YET_RELEASED:
            return "NOT_YET_RELEASED";
        case MediaStatus::CANCELLED:
            return "CANCELLED";
        default:
            return "HIATUS";
    }
}
