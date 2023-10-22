//
// Created by user on 10/20/2023.
//

#include "UI.h"

void UI::drawList(std::vector<Media *> mediaList, int page, bool isBrowse)
{
    if (page == -1)
    {
        return;
    }
    else if (page == 0)
    {
        std::cout << "+" << std::setfill('-') << std::setw(200) << "+" << std::endl;
        if (isBrowse)
        {

            printf("|%-6s|%-149s|%-10s|%-10s|%-20s|\n", "Id", "Title", "Score", "Episodes", "Status");
        }
        else
        {
            printf("|%-6s|%-149s|%-10s|%-10s|%-20s|\n", "Id", "Title", "Score", "Progress", "Status");
        }
    }
    for (int i = page * 50; i < page * 50 + 50 && i < mediaList.size(); ++i)
    {
        auto media = mediaList[i];
        std::cout << "+" << std::setfill('-') << std::setw(200) << "+" << std::endl;
        if (isBrowse)
        {

            printf("|%-6d|%-149s|%10d|%10d|%20s|\n",
                   media->getId(), UIService::getTitle(media->getTitle()).c_str(),
                   media->getAverageScore(),
                   media->getEpisodes(),
                   EnumMapping::mediaStatusToString(media->getStatus()).c_str());
        }
        else
        {
            printf("|%-6d|%-149s|%10d|%10d|%20s|\n",
                   media->getId(), UIService::getTitle(media->getTitle()).c_str(),
                   media->getAverageScore(),
                   media->getEpisodes(),
                   getWatchedStatus(media->getEpisodes(), media->getWatchedEpisodes()).c_str());
        }
    }
    std::cout << "+" << std::setfill('-') << std::setw(200) << "+" << std::endl;
    std::cout << "Page " << page + 1 << " out of " << mediaList.size() / 50 + 1 << std::endl;

    if (!isBrowse)
    {
        std::cout << "\nPress 1, to see your stats" << std::endl;
    }

    std::cout << "\nPress F, to search" << "\n"
              << "Press N, to see the next 50 entries" << "\n"
              << "Press S, to select a Anime" << "\n"
              << "Press P, to go to a specific page" << "\n\n"
              << "Press 0, to go back" << std::endl;
}

void UI::drawMenu()
{
    std::cout << "Press 1, to see browse" << "\n"
              << "Press 2, to see your list" << "\n\n"
              << "Press 0, to exit" << std::endl;
}

void UI::drawStats(const std::vector<Media *> &mediaList)
{
    std::cout << "Stats" << "\n"
              << "Total Anime: " << mediaList.size() << "\n"
              << "Average Score: " << Backend::getAverageScore(mediaList) << "\n"
              << "Total Episodes: " << Backend::getTotalEpisodes(mediaList) << std::endl;

    std::cout << "\nPress any button to go back" << std::endl;
}

std::string UI::getWatchedStatus(int episodes, int watchedEpisodes)
{
    if (watchedEpisodes == 0)
    {
        return "PLANNING";
    }
    else if (watchedEpisodes == episodes)
    {
        return "COMPLETED";
    }
    else
    {
        return "WATCHING";
    }
}
