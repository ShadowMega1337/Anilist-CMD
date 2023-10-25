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
        std::getline(std::cin, input);
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

void UIService::list(bool isBrowse)
{
    std::vector<Media *> &media = isBrowse ? browseMedia : myListMedia;
    std::vector<Media *> filteredMedia = media;
    int page = 0;
    std::string input;
    do
    {
        UI::drawList(filteredMedia, page, isBrowse);

        std::getline(std::cin, input);

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
            std::getline(std::cin, filter);

            for (char &c: filter)
            {
                c = std::tolower(c);
            }

            filteredMedia = Backend::getFilteredList(media, filter);
        }
        else if (input == "s")
        {
            std::cout << "Input id or the EXACT name to select an anime" << std::endl;
            std::string selectInput;
            do
            {
                std::getline(std::cin, selectInput);

                for (char &c: selectInput)
                {
                    c = std::tolower(c);
                }

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
                if (selectedMedia)
                {
                    selectedMedia->printAttributes();

                    editMedia(*selectedMedia, isBrowse);
                    break;
                }
                else
                {
                    std::cout << "Not found" << std::endl;
                }
            }
            while (true);
        }
        else if (input == "p")
        {
            std::cout << "Input page number?" << std::endl;

            bool running = true;
            do
            {
                std::string pageInput;
                std::getline(std::cin, pageInput);
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
            if (input == "1")
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
    std::getline(std::cin, input);

    for (char &c: input)
    {
        c = std::tolower(c);
    }
    if (input == "r")
    {
        Backend::resetScore(media);
    }
}

void UIService::editMedia(Media &media, bool isBrowse)
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

        std::getline(std::cin, input);

        for (char &c: input)
        {
            c = std::tolower(c);
        }

        if (input == "r" && !isBrowse)
        {
            do
            {
                std::cout << "Input your rating" << std::endl;

                std::string ratingInput;

                std::getline(std::cin, ratingInput);


                std::istringstream stream(ratingInput);

                int rating;
                if (stream >> rating)
                {
                    std::cout << rating;
                    if (rating > 100)
                    {
                        rating = 100;
                    }
                    else if (rating < 0)
                    {
                        rating = 0;
                    }
                    media.setAverageScore(rating);
                    break;
                }
                else
                {
                    std::cout << "Not an valid Input, try again." << std::endl;
                }
            }
            while (true);
        }
        else if (input == "p" && !isBrowse)
        {
            do
            {
                std::cout << "Input watched episodes" << std::endl;

                std::string episodeInput;

                std::getline(std::cin, episodeInput);


                std::istringstream stream(episodeInput);

                int progress;
                if (stream >> progress)
                {
                    if (progress > media.getEpisodes())
                    {
                        progress = media.getEpisodes();
                    }
                    else if (progress < 0)
                    {
                        progress = 0;
                    }
                    media.setWatchedEpisodes(progress);
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
            bool found = false;
            for (const auto *myListMedium: myListMedia)
            {
                if (myListMedium->getId() == media.getId())
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                media.setWatchedEpisodes(0);
                media.setAverageScore(0);
                myListMedia.push_back(&media);
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

const std::vector<Media *> &UIService::getBrowseMedia() const
{
    return browseMedia;
}

void UIService::setBrowseMedia(const std::vector<Media *> &browseMedia)
{
    UIService::browseMedia = browseMedia;
}

const std::vector<Media *> &UIService::getMyListMedia() const
{
    return myListMedia;
}

void UIService::setMyListMedia(const std::vector<Media *> &myListMedia)
{
    UIService::myListMedia = myListMedia;
}
