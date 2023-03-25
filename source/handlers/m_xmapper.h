#ifndef M_XMAPPER_H
#define M_XMAPPER_H

#include <map>
#include <string>
#include <functional>

class defaultMapper
{
private:
    std::map<std::string, bool> ANSWER_MAP = {
        {"y", true},
        {"n", false},
    };

public:
    std::map<std::string, bool> getAnswerMap() const
    {
        return ANSWER_MAP;
    }
};

#endif