#include <iostream>

#include "MediaBuild.h"
#include "UIService.h"

int main()
{
    std::vector<Media *> media = MediaBuild::readMediaJSON(true);
    std::vector<Media *> myListMedia = MediaBuild::readMediaJSON(false);

    auto *service = new UIService;

    std::function<void(short)> mainLoop = [&](short window)
    {
        if (window != 0)
        {
            if (window == 1 || window == 2)
            {
                service->list(window == 1, media, myListMedia);
            }
            mainLoop(service->menu(0));
        }
    };

    mainLoop(-1);

    MediaBuild::writeListToFile(myListMedia);

    delete service;

    return 0;
}
