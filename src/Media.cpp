//
// Created by user on 9/26/2023.
//

#include "Media.h"

Media::Media()
{
}

Media::Media(
        int id,
        Title *title,
        Date *startDate,
        Date *endDate,
        MediaSeason season,
        int seasonYear,
        MediaType type,
        MediaFormat format,
        MediaStatus status,
        int episodes,
        int duration,
        bool isAdult,
        const std::vector<std::string> &genres,
        int averageScore,
        int popularity,
        MediaSource source,
        const std::string &countryOfOrigin)
        : id(id),
          title(title),
          startDate(startDate),
          endDate(endDate),
          season(season),
          seasonYear(seasonYear),
          type(type),
          format(format),
          status(status),
          episodes(episodes),
          duration(duration),
          adult(isAdult),
          genres(genres),
          averageScore(averageScore),
          popularity(popularity),
          source(source),
          countryOfOrigin(countryOfOrigin)
{
}


int Media::getId() const
{
    return id;
}

void Media::setId(int id)
{
    Media::id = id;
}

Title *Media::getTitle() const
{
    return title;
}

void Media::setTitle(Title *title)
{
    Media::title = title;
}

Date *Media::getStartDate() const
{
    return startDate;
}

void Media::setStartDate(Date *startDate)
{
    Media::startDate = startDate;
}

Date *Media::getEndDate() const
{
    return endDate;
}

void Media::setEndDate(Date *endDate)
{
    Media::endDate = endDate;
}

MediaSeason Media::getSeason() const
{
    return season;
}

void Media::setSeason(MediaSeason season)
{
    Media::season = season;
}

int Media::getSeasonYear() const
{
    return seasonYear;
}

void Media::setSeasonYear(int seasonYear)
{
    Media::seasonYear = seasonYear;
}

MediaType Media::getType() const
{
    return type;
}

void Media::setType(MediaType type)
{
    Media::type = type;
}

MediaFormat Media::getFormat() const
{
    return format;
}

void Media::setFormat(MediaFormat format)
{
    Media::format = format;
}

MediaStatus Media::getStatus() const
{
    return status;
}

void Media::setStatus(MediaStatus status)
{
    Media::status = status;
}

int Media::getEpisodes() const
{
    return episodes;
}

void Media::setEpisodes(int episodes)
{
    Media::episodes = episodes;
}

int Media::getWatchedEpisodes() const
{
    return watchedEpisodes;
}

void Media::setWatchedEpisodes(int watchedEpisodes)
{
    Media::watchedEpisodes = watchedEpisodes;
}

int Media::getDuration() const
{
    return duration;
}

void Media::setDuration(int duration)
{
    Media::duration = duration;
}

bool Media::isAdult() const
{
    return adult;
}

void Media::setAdult(bool isAdult)
{
    Media::adult = isAdult;
}

const std::vector<std::string> &Media::getGenres() const
{
    return genres;
}

void Media::setGenres(const std::vector<std::string> &genres)
{
    Media::genres = genres;
}

int Media::getAverageScore() const
{
    return averageScore;
}

void Media::setAverageScore(int averageScore)
{
    Media::averageScore = averageScore;
}

int Media::getPopularity() const
{
    return popularity;
}

void Media::setPopularity(int popularity)
{
    Media::popularity = popularity;
}

MediaSource Media::getSource() const
{
    return source;
}

void Media::setSource(MediaSource source)
{
    Media::source = source;
}

const std::string &Media::getCountryOfOrigin() const
{
    return countryOfOrigin;
}

void Media::setCountryOfOrigin(const std::string &countryOfOrigin)
{
    Media::countryOfOrigin = countryOfOrigin;
}

void Media::printAttributes()
{
    std::cout << "Id: " << id << std::endl;
    std::cout << "Title (english): " << title->getEnglish() << std::endl;
    std::cout << "Title (romaji): " << title->getRomaji()<< std::endl;
    std::cout << "StartDate: " << startDate->getYear() << "-" << startDate->getMonth() << "-" << startDate->getDay() << std::endl;
    std::cout << "EndDate: " << endDate->getYear() << "-" << endDate->getMonth() << "-" << endDate->getDay() << std::endl;
    std::cout << "Season: " << EnumMapping::mediaSeasonToString(season) << std::endl;
    std::cout << "SeasonYear: " << seasonYear << std::endl;
    std::cout << "Type: " << EnumMapping::mediaTypeToString(type) << std::endl;
    std::cout << "Format: " << EnumMapping::formatToString(format) << std::endl;
    std::cout << "Status: " << EnumMapping::mediaStatusToString(status) << std::endl;
    std::cout << "Episodes: " << episodes << std::endl;
    std::cout << "Duration: " << duration << std::endl;
    std::cout << "CountryOfOrigin: " << countryOfOrigin << std::endl;
    std::cout << "Adult: " << adult << std::endl;
    std::cout << "Genres: ";
    for (const auto &genre: genres)
    {
        std::cout << genre << " ";
    }
    std::cout << std::endl;
    std::cout << "AverageScore: " << averageScore << std::endl;
    std::cout << "Popularity: " << popularity << std::endl;
    std::cout << "Source: " << EnumMapping::mediaSourceToString(source) << std::endl;

}


