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

class MediaBuild
{
public:
    std::vector<Media*> readMediaJSON();

private:
    static MediaSeason mapToMediaSeason(const std::string &seasonStr);

    static MediaType mapToMediaType(const std::string &typeStr);

    static MediaFormat mapToMediaFormat(const std::string &formatStr);

    static MediaStatus mapToMediaStatus(const std::string &statusStr);

    static MediaSource mapToMediaSource(const std::string &sourceStr);

};

#endif //M323_LB3_MEDIABUILD_H
