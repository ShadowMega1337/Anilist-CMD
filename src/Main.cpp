#include <iostream>

#include "MediaBuild.h"
#include "Draw.h"

int main()
{
    std::vector<Media*> media = (new MediaBuild)->readMediaJSON();
    Draw* draw = new Draw();
    draw->drawList(media, 0);


    return 0;
}
