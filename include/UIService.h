//
// Created by user on 10/22/2023.
//

#ifndef M323_LB3_UISERVICE_H
#define M323_LB3_UISERVICE_H

#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

#include "UI.h"
#include "Backend.h"

class UIService
{
public:
    static short menu();

    static void list(const std::vector<Media *> &media, UI *draw);

    static void stats(const std::vector<Media *>& media);

    static void editMedia(Media *media);
};


#endif //M323_LB3_UISERVICE_H
