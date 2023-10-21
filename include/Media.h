//
// Created by user on 9/26/2023.
//

#ifndef M323_LB3_MEDIA_H
#define M323_LB3_MEDIA_H

#include <string>

#include "MediaSeason.h"
#include "MediaType.h"
#include "MediaFormat.h"
#include "MediaStatus.h"
#include "MediaSource.h"
#include "MediaSort.h"
#include "Date.h"
#include "Title.h"

class Media
{
private:
    int id;
    Title title;
    Date startDate;
    Date endDate;
    MediaSeason season;
    int seasonYear;
    MediaType type;
    MediaFormat format;
    MediaStatus status;
    int episodes;
    int duration;
    bool adult;
    long averageScore;
    int popularity;
    MediaSource source;
    std::string countryCode;
public:
    Media();

    Media(int id, const Title &title, const Date &startDate, const Date &endDate, MediaSeason season, int seasonYear,
          MediaType type, MediaFormat format, MediaStatus status, int episodes, int duration,
          bool adult, int averageScore, int popularity, MediaSource source,
          const std::string &countryCode);

    int getId() const;

    void setId(int id);

    const Title &getTitle() const;

    void setTitle(const Title &title);

    const Date &getStartDate() const;

    void setStartDate(const Date &startDate);

    const Date &getEndDate() const;

    void setEndDate(const Date &endDate);

    MediaSeason getSeason() const;

    void setSeason(MediaSeason season);

    int getSeasonYear() const;

    void setSeasonYear(int seasonYear);

    MediaType getType() const;

    void setType(MediaType type);

    MediaFormat getFormat() const;

    void setFormat(MediaFormat format);

    MediaStatus getStatus() const;

    void setStatus(MediaStatus status);

    int getEpisodes() const;

    void setEpisodes(int episodes);

    int getDuration() const;

    void setDuration(int duration);

    bool isAdult() const;

    void setAdult(bool adult);

    int getAverageScore() const;

    void setAverageScore(int averageScore);

    int getPopularity() const;

    void setPopularity(int popularity);

    MediaSource getSource() const;

    void setSource(MediaSource source);

    const std::string &getCountryCode() const;

    void setCountryCode(const std::string &countryCode);
};

#endif //M323_LB3_MEDIA_H