#include <iostream>

#include "MediaBuild.h"
#include "UIService.h"

int main()
{
    std::vector<Media *> media = MediaBuild::readMediaJSON(true);
    std::vector<Media *> myListMedia = MediaBuild::readMediaJSON(false);

    UIService* service = new UIService;
    service->setBrowseMedia(media);
    service->setMyListMedia(myListMedia);

    std::string input;
    short window = 0; // 0: Menu, 1: List, 2: Stats

    do
    {
        if (window == 1)
        {
            service->list(true);
        }
        else if (window == 2)
        {
            service->list(false);
        }
        window = service->menu();
    }
    while (window != 0);

    MediaBuild::writeListToFile(service->getMyListMedia());

    delete service;

    return 0;
}
