//
// Created by user on 10/22/2023.
//

#ifndef M323_LB3_UISERVICE_H
#define M323_LB3_UISERVICE_H

#include <iostream>
#include <fstream>
#include <limits>
#include <jsoncpp/json/json.h>

#include "UI.h"
#include "Backend.h"
#include "MediaBuild.h"

class UIService
{
private:
    std::vector<Media*> browseMedia;
    std::vector<Media*> myListMedia;
public:
    short menu();

    void list(bool isBrowse);

    static void stats(const std::vector<Media *>& media);

    void editMedia(Media &media, bool isBrowse);

    static std::string getTitle(Title* title);

    const std::vector<Media *> &getBrowseMedia() const;

    void setBrowseMedia(const std::vector<Media *> &browseMedia);

    const std::vector<Media *> &getMyListMedia() const;

    void setMyListMedia(const std::vector<Media *> &myListMedia);
};


#endif //M323_LB3_UISERVICE_H
