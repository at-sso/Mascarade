#ifndef M_RAND_H
#define M_RAND_H

#include <random>

class RANDOM_FUNCTIONS
{
public:
    // Fixed returnRand template for integer declarations.
    int returnRandInt(const int &__x, const int &__y)
    {
        return returnRand<int>("i", __x, __y);
    }

    // Fixed returnRand template for double declarations.
    double returnRandDouble(const double &__x, const double &__y)
    {
        return returnRand<double>("d", __x, __y);
    }

private:
    template <typename TempType>
    TempType returnRand(const char *_type, const size_t &x, const size_t &y)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        switch (_type[0])
        {
        case 'd':
        {
            std::uniform_real_distribution<double> dist(x, y);
            return static_cast<TempType>(dist(gen));
        }

        case 'i':
        {
            std::uniform_int_distribution<> dist(x, y);
            return static_cast<TempType>(dist(gen));
        }

        default:
            throw std::logic_error("returnRand: Impossible typecase.");
        }
    }
};

#endif