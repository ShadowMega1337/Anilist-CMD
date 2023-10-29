//
// Created by user on 10/22/2023.
//

#include "UIService.h"


short UIService::menu(short previousResult)
{
    UI::drawMenu();
    std::string input;
    std::getline(std::cin, input);
    std::istringstream stream(input);
    short number = 0;

    if (stream >> number && (number < 3 && number >= 0))
    {
        return number;
    }
    else
    {
        std::cout << "Not an valid Input, try again." << std::endl;
        return menu(previousResult); // Recursive call
    }
}

void UIService::list(bool isBrowse, std::vector<Media *> browseMedia, std::vector<Media *> &myListMedia)
{
    std::vector<Media *> &media = isBrowse ? browseMedia : myListMedia;
    std::vector<Media *> filteredMedia = media;

    listRecursive(isBrowse, 0, media, filteredMedia, myListMedia);
}

void UIService::listRecursive(bool isBrowse, int page, std::vector<Media *> &media, std::vector<Media *> &filteredMedia,
                              std::vector<Media *> &myListMedia)
{
    UI::drawList(filteredMedia, page, isBrowse);

    std::string input;
    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "n")
    {
        listRecursive(isBrowse, page + 1, media, filteredMedia, myListMedia);
    }
    else if (input == "f")
    {
        std::cout << "Input search string" << std::endl;
        std::string filter;
        std::getline(std::cin, filter);

        std::transform(filter.begin(), filter.end(), filter.begin(), ::tolower);

        filteredMedia = Backend::getFilteredList(media, filter);
        listRecursive(isBrowse, 0, media, filteredMedia, myListMedia);
    }
    else if (input == "s")
    {
        std::cout << "Input id or the EXACT name to select an anime" << std::endl;
        std::string selectInput;

        selectAnime(selectInput, isBrowse, media, myListMedia);
        listRecursive(isBrowse, page, media, filteredMedia, myListMedia);
    }
    else if (input == "p")
    {
        std::cout << "Input page number?" << std::endl;
        page = goToPage(media);
        listRecursive(isBrowse, page, media, filteredMedia, myListMedia);
    }
    else if (input == "0")
    {
        // Terminate the recursion
    }
    else
    {
        if (input == "1")
        {
            stats(media);
        }
        else
        {
            std::cout << "Not a valid input, try again." << std::endl;
        }
        listRecursive(isBrowse, page, media, filteredMedia, myListMedia);
    }
}

void UIService::stats(const std::vector<Media *> &media)
{
    UI::drawStats(media);

    std::string input;
    std::getline(std::cin, input);

    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "r")
    {
        Backend::resetScore(media);
    }
}

void UIService::editMedia(Media &media, bool isBrowse, std::vector<Media *> &myListMedia)
{
    std::string input;
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

    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "r" && !isBrowse)
    {
        inputRating(media);
        editMedia(media, isBrowse, myListMedia);
    }
    else if (input == "p" && !isBrowse)
    {
        updateProgress(media);

        editMedia(media, isBrowse, myListMedia);
    }
    else if (input == "a" && isBrowse)
    {
        if (
                !std::any_of(myListMedia.begin(), myListMedia.end(),
                             [media](const Media *myListMedium)
                             {
                                 return myListMedium->getId() == media.getId();
                             }
                ))
        {
            media.setWatchedEpisodes(0);
            media.setAverageScore(0);
            myListMedia.push_back(&media);
            editMedia(media, isBrowse, myListMedia);
        }
        else
        {
            std::cout << "Already in your list" << std::endl;
            editMedia(media, isBrowse, myListMedia);
        }
    }
    else if (input == "0")
    {
        // Terminate recursion
    }
    else
    {
        std::cout << "Not an valid Input, try again." << std::endl;
        editMedia(media, isBrowse, myListMedia);
    }
}

std::string UIService::getTitle(Title *title)
{
    if (title->getEnglish().empty())
    {
        return title->getRomaji();
    }
    return title->getEnglish();
}

void
UIService::selectAnime(std::string input, bool isBrowse, std::vector<Media *> media, std::vector<Media *> &myListMedia)
{
    std::getline(std::cin, input);

    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    Media *selectedMedia;

    std::istringstream stream(input);
    int id;

    if (stream >> id)
    {
        selectedMedia = Backend::getAnimeWithId(media, id);
    }
    else
    {
        selectedMedia = Backend::getAnimeWithName(media, input);
    }

    if (selectedMedia)
    {
        selectedMedia->printAttributes();
        editMedia(*selectedMedia, isBrowse, myListMedia);
    }
    else
    {
        std::cout << "Not found" << std::endl;
        selectAnime(input, isBrowse, media, myListMedia);
    }
}

int UIService::goToPage(const std::vector<Media *> &media)
{
    std::string pageInput;
    std::getline(std::cin, pageInput);
    std::istringstream stream(pageInput);
    int checkPageInput;

    if (stream >> checkPageInput && (checkPageInput <= media.size() / 50 + 1 && checkPageInput > 0))
    {
        return checkPageInput - 1;
    }
    else
    {
        std::cout << "Not a valid input, try again." << std::endl;
        return goToPage(media);
    }
}

void UIService::inputRating(Media &media)
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
    }
    else
    {
        std::cout << "Not an valid Input, try again." << std::endl;
        inputRating(media);
    }
}

void UIService::updateProgress(Media &media)
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
    }
    else
    {
        std::cout << "Not an valid Input, try again." << std::endl;
        updateProgress(media);
    }
}