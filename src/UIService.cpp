//
// Created by user on 10/22/2023.
//

#include "UIService.h"


short UIService::menu()
{
    std::string input;
    short number = 0;

    do
    {
        UI::drawMenu();
        std::cin >> input;
        std::istringstream stream(input);
        if (stream >> number && (number < 3 && number >= 0))
        {
            return number;
        }
        else
        {
            std::cout << "Not an valid Input, try again." << std::endl;
        }

    }
    while (true);
}

void UIService::list(const std::vector<Media *> &media, bool isBrowse)
{
    std::vector<Media *> filteredMedia = media;
    int page = 0;
    std::string input;
    do
    {
        UI::drawList(filteredMedia, page, isBrowse);

        std::cin >> input;

        for (char &c: input)
        {
            c = std::tolower(c);
        }

        if (input == "n")
        {
            page += 1;
        }
        else if (input == "f")
        {
            std::cout << "Input search string" << std::endl;
            std::string filter;
            std::cin >> filter;
            filteredMedia = Backend::getFilteredList(media, filter);
        }
        else if (input == "s")
        {
            std::cout << "Input id or the EXACT name to select an anime" << std::endl;
            std::string selectInput;
            std::cin >> selectInput;

            Media *selectedMedia;

            std::istringstream stream(selectInput);

            int id;
            if (stream >> id)
            {
                selectedMedia = Backend::getAnimeWithId(media, id);
            }
            else
            {
                selectedMedia = Backend::getAnimeWithName(media, selectInput);
            }

            selectedMedia->printAttributes();

            editMedia(selectedMedia, isBrowse);
        }
        else if (input == "p")
        {
            std::cout << "Input page number?" << std::endl;

            bool running = true;
            do
            {
                std::string pageInput;
                std::cin >> pageInput;
                std::istringstream stream(pageInput);

                int checkPageInput;
                if (stream >> checkPageInput && (checkPageInput <= media.size() / 50 + 1 && checkPageInput > 0))
                {
                    page = checkPageInput - 1;
                    running = false;
                }
                else
                {
                    std::cout << "Not an valid Input, try again." << std::endl;
                }
            }
            while (running);
        }
        else if (input == "0")
        {
            break;
        }
        else
        {
            std::istringstream stream(input);

            short checkIfNum;
            if (stream >> checkIfNum)
            {
                UIService::stats(media);
            }
            else
            {
                std::cout << "Not an valid Input, try again." << std::endl;
            }
        }
    }
    while (true);
}

void UIService::stats(const std::vector<Media *> &media)
{
    UI::drawStats(media);

    std::string input;
    std::cin >> input;
}

void UIService::editMedia(Media *media, bool isBrowse)
{
    std::string input;
    do
    {
        if (isBrowse)
        {
            std::cout << "\nPress A, to add to your list" << std::endl;
        }
        else
        {
            std::cout << "\nPress R, to edit your rating" << "\n"
                      << "Press P, to edit your progress" << std::endl;

        }
        std::cout << "Press 0, to go back" << std::endl;

        std::cin >> input;

        for (char &c: input)
        {
            c = std::tolower(c);
        }

        if (input == "R" && !isBrowse)
        {
            do
            {
                std::cout << "Input your rating" << std::endl;

                std::string ratingInput;

                std::cin >> ratingInput;

                std::istringstream stream(ratingInput);

                int rating;
                if (stream >> rating)
                {
                    if (rating > 100)
                    {
                        rating = 100;
                    }
                    else if (rating < 0)
                    {
                        rating = 0;
                    }
                    media->setAverageScore(rating);
                    break;
                }
                else
                {
                    std::cout << "Not an valid Input, try again." << std::endl;
                }
            }
            while (true);
        }
        else if (input == "P" && !isBrowse)
        {
            do
            {
                std::cout << "Input watched episodes" << std::endl;

                std::string episodeInput;

                std::cin >> episodeInput;

                std::istringstream stream(episodeInput);

                int progress;
                if (stream >> progress)
                {
                    if (progress > media->getEpisodes())
                    {
                        progress = media->getEpisodes();
                    }
                    else if (progress < 0)
                    {
                        progress = 0;
                    }
                    media->setWatchedEpisodes(progress);
                    break;
                }
                else
                {
                    std::cout << "Not an valid Input, try again." << std::endl;
                }
            }
            while (true);
        }
        else if (input == "a" && isBrowse)
        {
            std::vector<Media *> myListMedia = MediaBuild::readMediaJSON(false);
            bool found = false;
            for (const auto *myListMedium: myListMedia)
            {
                if (myListMedium->getId() == media->getId())
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                myListMedia.push_back(media);
            }
            else
            {
                std::cout << "Already in your list" << std::endl;
            }
        }
        else if (input == "0")
        {
            break;
        }
        else
        {
            std::cout << "Not an valid Input, try again." << std::endl;
        }
    }
    while (true);
}

std::string UIService::getTitle(Title *title)
{
    if (title->getEnglish().empty())
    {
        return title->getRomaji();
    }
    return title->getEnglish();
}