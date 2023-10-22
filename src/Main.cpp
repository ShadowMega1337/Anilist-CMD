#include <iostream>

#include "MediaBuild.h"
#include "UIService.h"

int main()
{
    std::vector<Media *> media = MediaBuild::readMediaJSON(true);
    std::vector<Media *> myListMedia = MediaBuild::readMediaJSON(false);

    std::string input;
    short window = 0; // 0: Menu, 1: List, 2: Stats

    do
    {
        if (window == 1)
        {
            UIService::list(media, true);
        }
        else if (window == 2)
        {
            UIService::list(myListMedia, false);
        }
        window = UIService::menu();
    }
    while (window != 0);

    MediaBuild::writeListToFile(myListMedia);

    return 0;
}
