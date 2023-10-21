#include <iostream>

#include "MediaBuild.h"
#include "Draw.h"
#include <iomanip>

int main()
{
    std::vector<Media*> media = (new MediaBuild)->readMediaJSON();
    std::cout << "Eps:" << media[0]->getEpisodes() << std::endl;
    Draw* draw = new Draw();
    draw->drawList(media);


    return 0;
}
