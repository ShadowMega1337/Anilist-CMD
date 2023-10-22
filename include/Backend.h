//
// Created by user on 10/22/2023.
//

#ifndef M323_LB3_BACKEND_H
#define M323_LB3_BACKEND_H

#include <iostream>
#include <vector>

#include "Media.h"


class Backend
{
public:
    static std::vector<Media*> getFilteredList(std::vector<Media*> media, std::string filter);
};


#endif //M323_LB3_BACKEND_H
