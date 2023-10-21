//
// Created by user on 9/27/2023.
//

#ifndef M323_LB3_TITLE_H
#define M323_LB3_TITLE_H

#include <string>


class Title
{
private:
    std::string romaji;
    std::string english;
public:
    Title();

    Title(const std::string &english, const std::string &romaji);

    const std::string &getRomaji() const;

    void setRomaji(const std::string &romaji);

    const std::string &getEnglish() const;

    void setEnglish(const std::string &english);
};


#endif //M323_LB3_TITLE_H
