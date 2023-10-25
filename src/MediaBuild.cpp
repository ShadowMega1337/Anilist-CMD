//
// Created by user on 9/27/2023.
//

#include "MediaBuild.h"

std::vector<Media *> MediaBuild::readMediaJSON(bool isBrowseTab)
{
    std::ifstream jsonFile;
    if (isBrowseTab)
    {
        jsonFile.open("../resources/anime.json");
    }
    else
    {
        jsonFile.open("../resources/myList.json");
    }
    if (!jsonFile.is_open())
    {
        std::cerr << "Failed to open the JSON file." << std::endl;
    }

    Json::Value root;
    Json::CharReaderBuilder reader;
    std::string errs;

    if (!Json::parseFromStream(reader, jsonFile, &root, &errs))
    {
        std::cerr << "Failed to parse JSON: " << errs << std::endl;
    }

    // Create a vector to store Media objects
    std::vector<Media *> mediaArray;
    for (const Json::Value &mediaJson: root)
    {
        auto *media = new Media(
                mediaJson["id"].asInt(),
                new Title(mediaJson["title"]["english"].asString(), mediaJson["title"]["romaji"].asString()),
                new Date(mediaJson["startDate"]["day"].asInt(), mediaJson["startDate"]["month"].asInt(),
                         mediaJson["startDate"]["year"].asInt()),
                new Date(mediaJson["endDate"]["day"].asInt(), mediaJson["endDate"]["month"].asInt(),
                         mediaJson["endDate"]["year"].asInt()),
                EnumMapping::mapToMediaSeason(mediaJson["season"].asString()),
                mediaJson["seasonYear"].asInt(),
                EnumMapping::mapToMediaType(mediaJson["type"].asString()),
                EnumMapping::mapToMediaFormat(mediaJson["format"].asString()),
                EnumMapping::mapToMediaStatus(mediaJson["status"].asString()),
                mediaJson["episodes"].asInt(),
                mediaJson["duration"].asInt(),
                mediaJson["adult"].asBool(),
                getGenres(mediaJson["genres"]),
                mediaJson["averageScore"].asInt(),
                mediaJson["popularity"].asInt(),
                EnumMapping::mapToMediaSource(mediaJson["source"].asString()),
                mediaJson["countryOfOrigin"].asString()
        );
        if (mediaJson["watchedEpisodes"])
        {
            media->setWatchedEpisodes(mediaJson["watchedEpisodes"].asInt());
        }
        mediaArray.push_back(media);
    }
    jsonFile.close();
    return mediaArray;
}

void MediaBuild::writeListToFile(const std::vector<Media *> &mediaList)
{
    Json::Value jsonArray;

    for (const auto &media: mediaList)
    {
        Json::Value myList;

        Json::Value titleJson;
        if (media->getTitle())
        {
            const auto &title = media->getTitle();
            titleJson["english"] = title->getEnglish();
            titleJson["romaji"] = title->getRomaji();
        }

        Json::Value startDateJson;
        if (media->getStartDate())
        {
            const auto &startDate = media->getStartDate();
            startDateJson["year"] = startDate->getYear();
            startDateJson["month"] = startDate->getMonth();
            startDateJson["day"] = startDate->getDay();
        }

        Json::Value endDateJson;
        if (media->getEndDate())
        {
            const auto &endDate = media->getEndDate();
            endDateJson["year"] = endDate->getYear();
            endDateJson["month"] = endDate->getMonth();
            endDateJson["day"] = endDate->getDay();
        }

        myList["id"] = media->getId();
        myList["title"] = titleJson;
        myList["startDate"] = startDateJson;
        myList["endDate"] = endDateJson;
        myList["season"] = EnumMapping::mediaSeasonToString(media->getSeason());
        myList["seasonYear"] = media->getSeasonYear();
        myList["type"] = EnumMapping::mediaTypeToString(media->getType());
        myList["format"] = EnumMapping::formatToString(media->getFormat());
        myList["status"] = EnumMapping::mediaStatusToString(media->getStatus());
        myList["episodes"] = media->getEpisodes();
        myList["watchedEpisodes"] = media->getWatchedEpisodes();
        myList["duration"] = media->getDuration();
        myList["adult"] = media->isAdult();

        Json::Value genres;
        const auto &mediaGenres = media->getGenres();
        for (const auto &genre: mediaGenres)
        {
            genres.append(genre);
        }

        myList["genres"] = genres;
        myList["averageScore"] = media->getAverageScore();
        myList["popularity"] = media->getPopularity();
        myList["source"] = EnumMapping::mediaSourceToString(media->getSource());
        myList["countryOfOrigin"] = media->getCountryOfOrigin();

        jsonArray.append(myList);
    }
    // Write the JSON to a file
    std::ofstream outFile("../resources/myList.json");
    if (outFile.is_open())
    {
        outFile << jsonArray;
        outFile.close();
        std::cout << "Added to list" << std::endl;
    }
    else
    {
        std::cerr << "Error opening the file for writing." << std::endl;
    }
}

std::vector<std::string> MediaBuild::getGenres(const Json::Value &jsonGenres)
{
    std::vector<std::string> genres;
    for (const auto &genre: jsonGenres)
    {
        genres.push_back(genre.asString());
    }
    return genres;
}
