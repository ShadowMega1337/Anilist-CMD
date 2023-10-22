#include <iostream>

#include "MediaBuild.h"
#include "UI.h"
#include "Backend.h"

short menu()
{
    UI::drawMenu();

    std::string input;
    std::cin >> input;
    short number = 0;

    std::istringstream stream(input);
    if (stream >> number && (number < 3 && number >= 0))
    {
        return number;
    }
    std::cout << "Not an valid Input, try again." << std::endl;
    return menu();
}

void list(const std::vector<Media *> &media, UI *draw)
{
    std::vector<Media *> filteredMedia = media;
    std::string filter;
    int page = 0;
    std::string input;
    do
    {
        UI::drawList(filteredMedia, page);

        std::cout << "Press F, to search" << "\n"
                  << "Press N, to see the next 50 entries" << "\n"
                  << "Press P, to go to a specific page" << "\n\n"
                  << "Press 0, to go back" << std::endl;

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
            std::cin >> filter;
            filteredMedia = Backend::getFilteredList(media, filter);
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
                    page = checkPageInput;
                    running = false;
                }
                std::cout << "Not an valid Input, try again." << std::endl;
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

void stats(std::vector<Media *> media)
{

}

int main()
{
    std::vector<Media *> media = (new MediaBuild)->readMediaJSON(); // 19232
    UI *draw = new UI();

    std::string input;
    short window = 0; // 0: Menu, 1: List, 2: Stats

    do
    {
        if (window == 1)
        {
            list(media, draw);
        }
        else if (window == 2)
        {
            stats(media);
        }
        window = menu(draw);
    }
    while (window != 0);

    return 0;
}
