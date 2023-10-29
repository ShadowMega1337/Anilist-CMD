//
// Created by user on 10/22/2023.
//

#ifndef M323_LB3_UISERVICE_H
#define M323_LB3_UISERVICE_H

#include <iostream>
#include <fstream>
#include <limits>
#include <jsoncpp/json/json.h>
#include <algorithm>

#include "UI.h"
#include "Backend.h"
#include "MediaBuild.h"

class UIService
{
public:
    short menu(short previousResult);

    void list(bool isBrowse, std::vector<Media*> browseMedia, std::vector<Media*> &myListMedia);

    void listRecursive(bool isBrowse, int page, std::vector<Media *> &media, std::vector<Media *> &filteredMedia, std::vector<Media*> &myListMedia);

    static void stats(const std::vector<Media *>& media);

    void editMedia(Media &media, bool isBrowse, std::vector<Media*> &myListMedia);

    static std::string getTitle(Title* title);

    void selectAnime(std::string input, bool isBrowse, std::vector<Media*> media, std::vector<Media*> &myListMedia);

    int goToPage(const std::vector<Media*>& media);

    void inputRating(Media &media);

    void updateProgress(Media &media);
};


#endif //M323_LB3_UISERVICE_H
