//
// Created by user on 10/22/2023.
//

#include "EnumMapping.h"


std::string EnumMapping::mediaSeasonToString(MediaSeason season)
{
    switch (season)
    {
        case MediaSeason::SPRING:
            return "SPRING";
        case MediaSeason::SUMMER:
            return "SUMMER";
        case MediaSeason::FALL:
            return "FALL";
        case MediaSeason::WINTER:
            return "WINTER";
        default:
            return "UNKNOWN";
    }
}

std::string EnumMapping::mediaTypeToString(MediaType type)
{
    switch (type)
    {
        case MediaType::ANIME:
            return "ANIME";
        case MediaType::MANGA:
            return "MANGA";
        default:
            return "UNKNOWN";
    }
}

std::string EnumMapping::formatToString(MediaFormat format)
{
    switch (format)
    {
        case MediaFormat::TV:
            return "TV";
        case MediaFormat::TV_SHORT:
            return "TV_SHORT";
        case MediaFormat::MOVIE:
            return "MOVIE";
        case MediaFormat::SPECIAL:
            return "SPECIAL";
        case MediaFormat::OVA:
            return "OVA";
        case MediaFormat::ONA:
            return "ONA";
        case MediaFormat::MUSIC:
            return "MUSIC";
        case MediaFormat::MANGA:
            return "MANGA";
        case MediaFormat::NOVEL:
            return "NOVEL";
        default:
            return "ONE_SHOT";
    }
}

std::string EnumMapping::mediaSourceToString(MediaSource source)
{
    switch (source)
    {
        case MediaSource::ORIGINAL:
            return "ORIGINAL";
        case MediaSource::MANGA:
            return "MANGA";
        case MediaSource::LIGHT_NOVEL:
            return "LIGHT_NOVEL";
        case MediaSource::VISUAL_NOVEL:
            return "VISUAL_NOVEL";
        case MediaSource::VIDEO_GAME:
            return "VIDEO_GAME";
        case MediaSource::OTHER:
            return "OTHER";
        case MediaSource::NOVEL:
            return "NOVEL";
        case MediaSource::DOUJINSHI:
            return "DOUJINSHI";
        case MediaSource::ANIME:
            return "ANIME";
        case MediaSource::WEB_NOVEL:
            return "WEB_NOVEL";
        case MediaSource::LIVE_ACTION:
            return "LIVE_ACTION";
        case MediaSource::GAME:
            return "GAME";
        case MediaSource::COMIC:
            return "COMIC";
        case MediaSource::MULTIMEDIA_PROJECT:
            return "MULTIMEDIA_PROJECT";
        default:
            return "PICTURE_BOOK";
    }
}


std::string EnumMapping::mediaStatusToString(MediaStatus status)
{
    switch (status)
    {
        case MediaStatus::FINISHED:
            return "FINISHED";
        case MediaStatus::RELEASING:
            return "RELEASING";
        case MediaStatus::NOT_YET_RELEASED:
            return "NOT_YET_RELEASED";
        case MediaStatus::CANCELLED:
            return "CANCELLED";
        default:
            return "HIATUS";
    }
}


MediaSeason EnumMapping::mapToMediaSeason(const std::string &seasonStr)
{
    if (seasonStr == "SPRING")
    {
        return MediaSeason::SPRING;
    }
    else if (seasonStr == "SUMMER")
    {
        return MediaSeason::SUMMER;
    }
    else if (seasonStr == "FALL")
    {
        return MediaSeason::FALL;
    }
    else
    {
        return MediaSeason::WINTER;
    }
}

MediaType EnumMapping::mapToMediaType(const std::string &typeStr)
{
    if (typeStr == "ANIME")
    {
        return MediaType::ANIME;
    }
    else
    {
        return MediaType::MANGA;
    }
}


MediaFormat EnumMapping::mapToMediaFormat(const std::string &formatStr)
{
    if (formatStr == "TV")
    {
        return MediaFormat::TV;
    }
    else if (formatStr == "TV_SHORT")
    {
        return MediaFormat::TV_SHORT;
    }
    else if (formatStr == "MOVIE")
    {
        return MediaFormat::MOVIE;
    }
    else if (formatStr == "SPECIAL")
    {
        return MediaFormat::SPECIAL;
    }
    else if (formatStr == "OVA")
    {
        return MediaFormat::OVA;
    }
    else if (formatStr == "ONA")
    {
        return MediaFormat::ONA;
    }
    else if (formatStr == "MUSIC")
    {
        return MediaFormat::MUSIC;
    }
    else if (formatStr == "MANGA")
    {
        return MediaFormat::MANGA;
    }
    else if (formatStr == "NOVEL")
    {
        return MediaFormat::NOVEL;
    }
    else
    {
        return MediaFormat::ONE_SHOT;
    }
}


MediaStatus EnumMapping::mapToMediaStatus(const std::string &statusStr)
{
    if (statusStr == "FINISHED")
    {
        return MediaStatus::FINISHED;
    }
    else if (statusStr == "RELEASING")
    {
        return MediaStatus::RELEASING;
    }
    else if (statusStr == "NOT_YET_RELEASED")
    {
        return MediaStatus::NOT_YET_RELEASED;
    }
    else if (statusStr == "CANCELLED")
    {
        return MediaStatus::CANCELLED;
    }
    else
    {
        return MediaStatus::HIATUS;
    }
}

MediaSource EnumMapping::mapToMediaSource(const std::string &sourceStr)
{
    if (sourceStr == "ORIGINAL")
    {
        return MediaSource::ORIGINAL;
    }
    else if (sourceStr == "MANGA")
    {
        return MediaSource::MANGA;
    }
    else if (sourceStr == "LIGHT_NOVEL")
    {
        return MediaSource::LIGHT_NOVEL;
    }
    else if (sourceStr == "VISUAL_NOVEL")
    {
        return MediaSource::VISUAL_NOVEL;
    }
    else if (sourceStr == "VIDEO_GAME")
    {
        return MediaSource::VIDEO_GAME;
    }
    else if (sourceStr == "OTHER")
    {
        return MediaSource::OTHER;
    }
    else if (sourceStr == "NOVEL")
    {
        return MediaSource::NOVEL;
    }
    else if (sourceStr == "DOUJINSHI")
    {
        return MediaSource::DOUJINSHI;
    }
    else if (sourceStr == "ANIME")
    {
        return MediaSource::ANIME;
    }
    else if (sourceStr == "WEB_NOVEL")
    {
        return MediaSource::WEB_NOVEL;
    }
    else if (sourceStr == "LIVE_ACTION")
    {
        return MediaSource::LIVE_ACTION;
    }
    else if (sourceStr == "GAME")
    {
        return MediaSource::GAME;
    }
    else if (sourceStr == "COMIC")
    {
        return MediaSource::COMIC;
    }
    else if (sourceStr == "MULTIMEDIA_PROJECT")
    {
        return MediaSource::MULTIMEDIA_PROJECT;
    }
    else
    {
        return MediaSource::PICTURE_BOOK;
    }
}

