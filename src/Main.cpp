#include <iostream>

#include "MediaBuild.h"
#include "UIService.h"

int main()
{
    std::vector<Media *> media = MediaBuild::readMediaJSON(true);
    UI *draw = new UI();

    std::string input;
    short window = 0; // 0: Menu, 1: List, 2: Stats

    do
    {
        if (window == 1)
        {
            UIService::list(media, draw);
        }
        else if (window == 2)
        {
            UIService::stats(media);
        }
        window = UIService::menu();
    }
    while (window != 0);

    return 0;
}
