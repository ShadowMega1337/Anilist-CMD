//
// Created by user on 10/20/2023.
//

#ifndef M323_LB3_UI_H
#define M323_LB3_UI_H

#include <vector>
#include <iostream>
#include <iomanip>

#include "Media.h"
#include "Backend.h"
#include "UIService.h"
#include "EnumMapping.h"

class UI
{
public:

    static void drawList(std::vector<Media *> mediaList, int show, bool isBrowse);
    static void drawMenu();
    static void drawStats(const std::vector<Media *>& mediaList);

    static std::string getWatchedStatus(int episodes, int episodes1);
};

#endif //M323_LB3_UI_H
