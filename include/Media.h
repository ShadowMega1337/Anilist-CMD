//
// Created by user on 9/26/2023.
//

#ifndef M323_LB3_MEDIA_H
#define M323_LB3_MEDIA_H

#include <string>
#include <iostream>
#include <vector>

#include "MediaSeason.h"
#include "MediaType.h"
#include "MediaFormat.h"
#include "MediaStatus.h"
#include "MediaSource.h"
#include "MediaSort.h"
#include "Date.h"
#include "Title.h"
#include "EnumMapping.h"

class Media
{
private:
    int id;
    Title* title;
    Date* startDate;
    Date* endDate;
    MediaSeason season;
    int seasonYear;
    MediaType type;
    MediaFormat format;
    MediaStatus status;
    int episodes;
    int watchedEpisodes;
    int duration;
    bool adult;
    std::vector<std::string> genres;
    int averageScore;
    int popularity;
    MediaSource source;
    std::string countryOfOrigin;
public:
    Media();

    Media(int id, Title *title, Date *startDate, Date *endDate, MediaSeason season, int seasonYear, MediaType type,
          MediaFormat format, MediaStatus status, int episodes, int duration, bool isAdult,
          const std::vector<std::string> &genres, int averageScore, int popularity, MediaSource source,
          const std::string &countryOfOrigin);

    int getId() const;

    void setId(int id);

    Title *getTitle() const;

    void setTitle(Title *title);

    Date *getStartDate() const;

    void setStartDate(Date *startDate);

    Date *getEndDate() const;

    void setEndDate(Date *endDate);

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

    int getWatchedEpisodes() const;

    void setWatchedEpisodes(int watchedEpisodes);


    int getDuration() const;

    void setDuration(int duration);

    bool isAdult() const;

    void setAdult(bool isAdult);

    const std::vector<std::string> &getGenres() const;

    void setGenres(const std::vector<std::string> &genres);

    int getAverageScore() const;

    void setAverageScore(int averageScore);

    int getPopularity() const;

    void setPopularity(int popularity);

    MediaSource getSource() const;

    void setSource(MediaSource source);

    const std::string &getCountryOfOrigin() const;

    void setCountryOfOrigin(const std::string &countryOfOrigin);

    void printAttributes();
};

#endif //M323_LB3_MEDIA_H