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

void UIService::list(const std::vector<Media *> &media, UI *draw)
{
    std::vector<Media *> filteredMedia = media;
    int page = 0;
    std::string input;
    do
    {
        UI::drawList(filteredMedia, page);

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
            std::cout << "What do you wanna search?" << std::endl;
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
                selectedMedia = Backend::getAnimeWithId(id);
            }
            else
            {
                selectedMedia = Backend::getAnimeWithName(selectInput);
            }
            editMedia(selectedMedia);
        }
        else if (input == "p")
        {
            std::cout << "To which page do you wanna go?" << std::endl;

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
        else
        {
            std::istringstream stream(input);

            int checkInput;
            if (stream >> checkInput && (checkInput < media.size() / 50 && checkInput > 0))
            {
                page = checkInput - 1;
            }
            else
            {
                page = -1;
                std::cout << "Not an valid Input, try again." << std::endl;
            }
        }
    }
    while (input != "0");
}

void UIService::stats(const std::vector<Media *> &media)
{
    UI::drawStats(media);

    std::string input;
    std::cin >> input;
}

void UIService::editMedia(Media *media)
{
    std::string input;
    do
    {
        std::cout << "Press S, to edit your rating" << "\n"
                  << "Press 0, to go back" << std::endl;

        std::cin >> input;

        for (char &c: input)
        {
            c = std::tolower(c);
        }

        if (input == "s")
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
                UI::drawList({media}, 0);
            }
            else
            {
                std::cout << "Not an valid Input, try again." << std::endl;
            }
        }
    }
    while (input != "0");
}