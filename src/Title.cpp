//
// Created by user on 9/27/2023.
//

#include "Title.h"

Title::Title()
{

}

Title::Title(const std::string &english, const std::string &romaji) : romaji(romaji), english(english)
{
}

const std::string &Title::getRomaji() const
{
    return romaji;
}

void Title::setRomaji(const std::string &romaji)
{
    Title::romaji = romaji;
}

const std::string &Title::getEnglish() const
{
    return english;
}

void Title::setEnglish(const std::string &english)
{
    Title::english = english;
}
