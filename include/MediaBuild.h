//
// Created by user on 9/27/2023.
//

#ifndef M323_LB3_MEDIABUILD_H
#define M323_LB3_MEDIABUILD_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

#include "Media.h"
#include "Title.h"
#include "MediaType.h"
#include "MediaSeason.h"
#include "MediaFormat.h"
#include "MediaStatus.h"
#include "MediaSource.h"
#include "MediaSort.h"
#include "EnumMapping.h"

class MediaBuild
{
public:
    static std::vector<Media*> readMediaJSON(bool isBrowseTab);

    static void writeListToFile(const std::vector<Media *> &mediaList);

private:
    static std::vector<std::string> getGenres(const Json::Value& genres);
};

#endif //M323_LB3_MEDIABUILD_H
