//
// Created by user on 9/26/2023.
//

#include "Media.h"

Media::Media()
{
}


Media::Media
        (
                int id,
                const Title &title,
                const Date &startDate,
                const Date &endDate,
                MediaSeason season,
                int seasonYear,
                MediaType type,
                MediaFormat format,
                MediaStatus status,
                int episodes,
                int duration,
                bool adult,
                int averageScore,
                int popularity,
                MediaSource source,
                const std::string &countryCode
        ) :
        id(id),
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
        adult(adult),
        averageScore(averageScore),
        popularity(popularity),
        source(source),
        countryCode(countryCode)
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

const Title &Media::getTitle() const
{
    return title;
}

void Media::setTitle(const Title &title)
{
    Media::title = title;
}

const Date &Media::getStartDate() const
{
    return startDate;
}

void Media::setStartDate(const Date &startDate)
{
    Media::startDate = startDate;
}

const Date &Media::getEndDate() const
{
    return endDate;
}

void Media::setEndDate(const Date &endDate)
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

void Media::setAdult(bool adult)
{
    Media::adult = adult;
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

const std::string &Media::getCountryCode() const
{
    return countryCode;
}

void Media::setCountryCode(const std::string &countryCode)
{
    Media::countryCode = countryCode;
}