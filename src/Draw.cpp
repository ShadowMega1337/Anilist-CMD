//
// Created by user on 10/20/2023.
//

#include "Draw.h"

std::string Draw::drawList(std::vector<Media *> mediaList, int show)
{
    if (show == 0) {
        std::cout << "+" << std::setfill('-') << std::setw(200) << "+" << std::endl;
        printf("|%-166s|%-10s|%-10s|%-10s|\n", "Title", "Score", "Episodes", "Status");

    }
    for (int i = show; i < show + 20; ++i) {
        auto media = mediaList[i];
        std::cout << "+" << std::setfill('-') << std::setw(200) << "+" << std::endl;
        printf("|%-166s|%10d|%10d|%10s|\n", media->getTitle().getEnglish().c_str(), media->getAverageScore(),
               media->getEpisodes(), mediaStatusToString(media->getStatus()).c_str());
    }
    std::cout << "+" << std::setfill('-') << std::setw(200) << "+" << std::endl;

    std::string input;
    std::cin >> input;
    return input;
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
