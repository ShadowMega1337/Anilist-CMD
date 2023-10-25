//
// Created by user on 10/22/2023.
//

#ifndef M323_LB3_ENUMMAPPING_H
#define M323_LB3_ENUMMAPPING_H

#include <string>
#include "MediaFormat.h"
#include "MediaSeason.h"
#include "MediaType.h"
#include "MediaSource.h"
#include "MediaStatus.h"


class EnumMapping
{
public:
    static std::string formatToString(MediaFormat format);

    static std::string mediaSeasonToString(MediaSeason season);

    static std::string mediaTypeToString(MediaType type);

    static std::string mediaSourceToString(MediaSource source);

    static std::string mediaStatusToString(MediaStatus status);

    static MediaSeason mapToMediaSeason(const std::string &seasonStr);

    static MediaType mapToMediaType(const std::string &typeStr);

    static MediaFormat mapToMediaFormat(const std::string &formatStr);

    static MediaStatus mapToMediaStatus(const std::string &statusStr);

    static MediaSource mapToMediaSource(const std::string &sourceStr);
};


#endif //M323_LB3_ENUMMAPPING_H
