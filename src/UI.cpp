//
// Created by user on 10/20/2023.
//

#include "UI.h"

void UI::drawList(std::vector<Media *> mediaList, int page)
{
    if (page == -1)
    {
        return;
    }
    else if (page == 0)
    {
        std::cout << "+" << std::setfill('-') << std::setw(200) << "+" << std::endl;
        printf("|%-6s|%-149s|%-10s|%-10s|%-20s|\n", "Id", "Title", "Score", "Episodes", "Status");
    }
    for (int i = page * 50; i < page * 50 + 50 && i < mediaList.size(); ++i)
    {
        auto media = mediaList[i];
        std::cout << "+" << std::setfill('-') << std::setw(200) << "+" << std::endl;
        printf("|%-6d|%-149s|%10d|%10d|%20s|\n", media->getId(), media->getTitle().getEnglish().c_str(), media->getAverageScore(),
               media->getEpisodes(), mediaStatusToString(media->getStatus()).c_str());
    }
    std::cout << "+" << std::setfill('-') << std::setw(200) << "+" << std::endl;
    std::cout << "Page " << page + 1 << " out of " << mediaList.size() / 50 + 1 << std::endl;

    std::cout << "\nPress F, to search" << "\n"
              << "Press N, to see the next 50 entries" << "\n"
              << "Press S, to select a Anime" << "\n"
              << "Press P, to go to a specific page" << "\n\n"
              << "Press 0, to go back" << std::endl;
}

void UI::drawMenu()
{
    std::cout << "Press 1, to see your list" << "\n"
              << "Press 2, to see your stats" << "\n\n"
              << "Press 0, to exit" << std::endl;
}

void UI::drawStats(const std::vector<Media *>& mediaList)
{
    std::cout << "Stats" << "\n"
              << "Total Anime: " << mediaList.size() << "\n"
              << "Average Score: " << Backend::getAverageScore(mediaList) << "\n"
              << "Total Episodes: " << Backend::getTotalEpisodes(mediaList) << std::endl;

    std::cout << "\nPress any button to go back" << std::endl;
}

std::string UI::mediaSeasonToString(MediaSeason season)
{
    switch (season)
    {
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

std::string UI::mediaTypeToString(MediaType type)
{
    switch (type)
    {
        case MediaType::ANIME:
            return "ANIME";
        case MediaType::MANGA:
            return "MANGA";
        default:
            return "UNKNOWN";
    }
}

std::string UI::formatToString(MediaFormat format)
{
    switch (format)
    {
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

std::string UI::mediaSourceToString(MediaSource source)
{
    switch (source)
    {
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


std::string UI::mediaStatusToString(MediaStatus status)
{
    switch (status)
    {
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

