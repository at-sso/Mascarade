#ifndef M_MAPPER_H
#define M_MAPPER_H

#include <map>
#include <functional>

class MAP_HANDLER
{
private:
    std::map<std::string, bool> ANSWER_MAP = {
        {"yes", true},
        {"no", false},
    };

    template <typename T>
    T TRY_STRING_TO_X(std::string input, bool negative)
    {
        if (ANSWER_MAP.count(input) == negative)
        {
            throw std::out_of_range("TRY_STRING_TO_X: Key: " + input + " does not exist in the map.");
        }
        return ANSWER_MAP.at(input);
    }

public:
    const bool AnswerTRUE = ANSWER_MAP.at("yes");
    const bool AnswerFALSE = ANSWER_MAP.at("no");

    bool AnswerMap(std::string input)
    {
        TRY_STRING_TO_X<bool>(input, false);
        return ANSWER_MAP.at(input);
    }
};

#endif