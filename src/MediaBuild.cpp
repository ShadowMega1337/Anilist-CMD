//
// Created by user on 9/27/2023.
//

#include "MediaBuild.h"

std::vector<Media *> MediaBuild::readMediaJSON()
{
    std::ifstream jsonFile("../resources/anime.json");

    if (!jsonFile.is_open()) {
        std::cerr << "Failed to open the JSON file." << std::endl;
    }

    Json::Value root;
    Json::CharReaderBuilder reader;
    std::string errs;

    if (!Json::parseFromStream(reader, jsonFile, &root, &errs)) {
        std::cerr << "Failed to parse JSON: " << errs << std::endl;
    }

    // Create a vector to store Media objects
    std::vector<Media *> mediaArray;
    for (const Json::Value &mediaJson: root) {
        auto* media = new Media(
                mediaJson["id"].asInt(),
                Title(mediaJson["title"]["english"].asString(), mediaJson["title"]["romaji"].asString()),
                Date(mediaJson["startDate"]["day"].asInt(), mediaJson["startDate"]["month"].asInt(),
                     mediaJson["startDate"]["year"].asInt()),
                Date(mediaJson["endDate"]["day"].asInt(), mediaJson["endDate"]["month"].asInt(),
                     mediaJson["endDate"]["year"].asInt()),
                mapToMediaSeason(mediaJson["season"].asString()),
                mediaJson["seasonYear"].asInt(),
                mapToMediaType(mediaJson["type"].asString()),
                mapToMediaFormat(mediaJson["format"].asString()),
                mapToMediaStatus(mediaJson["status"].asString()),
                mediaJson["episodes"].asInt(),
                mediaJson["duration"].asInt(),
                mediaJson["adult"].asBool(),
                mediaJson["averageScore"].asInt(),
                mediaJson["popularity"].asInt(),
                mapToMediaSource(mediaJson["source"].asString()),
                mediaJson["countryOfOrigin"].asString()
        );
        mediaArray.push_back(media);
    }
    jsonFile.close();
    return mediaArray;
}


MediaSeason MediaBuild::mapToMediaSeason(const std::string &seasonStr)
{
    if (seasonStr == "SPRING") {
        return MediaSeason::SPRING;
    } else if (seasonStr == "SUMMER") {
        return MediaSeason::SUMMER;
    } else if (seasonStr == "FALL") {
        return MediaSeason::FALL;
    } else {
        return MediaSeason::WINTER;
    }
}

MediaType MediaBuild::mapToMediaType(const std::string &typeStr)
{
    if (typeStr == "ANIME") {
        return MediaType::ANIME;
    } else {
        return MediaType::MANGA;
    }
}


MediaFormat MediaBuild::mapToMediaFormat(const std::string &formatStr)
{
    if (formatStr == "TV") {
        return MediaFormat::TV;
    } else if (formatStr == "TV_SHORT") {
        return MediaFormat::TV_SHORT;
    } else if (formatStr == "MOVIE") {
        return MediaFormat::MOVIE;
    } else if (formatStr == "SPECIAL") {
        return MediaFormat::SPECIAL;
    } else if (formatStr == "OVA") {
        return MediaFormat::OVA;
    } else if (formatStr == "ONA") {
        return MediaFormat::ONA;
    } else if (formatStr == "MUSIC") {
        return MediaFormat::MUSIC;
    } else if (formatStr == "MANGA") {
        return MediaFormat::MANGA;
    } else if (formatStr == "NOVEL") {
        return MediaFormat::NOVEL;
    } else {
        return MediaFormat::ONE_SHOT;
    }
}


MediaStatus MediaBuild::mapToMediaStatus(const std::string &statusStr)
{
    if (statusStr == "FINISHED") {
        return MediaStatus::FINISHED;
    } else if (statusStr == "RELEASING") {
        return MediaStatus::RELEASING;
    } else if (statusStr == "NOT_YET_RELEASED") {
        return MediaStatus::NOT_YET_RELEASED;
    } else if (statusStr == "CANCELLED") {
        return MediaStatus::CANCELLED;
    } else {
        return MediaStatus::HIATUS;
    }
}

MediaSource MediaBuild::mapToMediaSource(const std::string &sourceStr)
{
    if (sourceStr == "ORIGINAL") {
        return MediaSource::ORIGINAL;
    } else if (sourceStr == "MANGA") {
        return MediaSource::MANGA;
    } else if (sourceStr == "LIGHT_NOVEL") {
        return MediaSource::LIGHT_NOVEL;
    } else if (sourceStr == "VISUAL_NOVEL") {
        return MediaSource::VISUAL_NOVEL;
    } else if (sourceStr == "VIDEO_GAME") {
        return MediaSource::VIDEO_GAME;
    } else if (sourceStr == "OTHER") {
        return MediaSource::OTHER;
    } else if (sourceStr == "NOVEL") {
        return MediaSource::NOVEL;
    } else if (sourceStr == "DOUJINSHI") {
        return MediaSource::DOUJINSHI;
    } else if (sourceStr == "ANIME") {
        return MediaSource::ANIME;
    } else if (sourceStr == "WEB_NOVEL") {
        return MediaSource::WEB_NOVEL;
    } else if (sourceStr == "LIVE_ACTION") {
        return MediaSource::LIVE_ACTION;
    } else if (sourceStr == "GAME") {
        return MediaSource::GAME;
    } else if (sourceStr == "COMIC") {
        return MediaSource::COMIC;
    } else if (sourceStr == "MULTIMEDIA_PROJECT") {
        return MediaSource::MULTIMEDIA_PROJECT;
    } else {
        return MediaSource::PICTURE_BOOK;
    }
}
