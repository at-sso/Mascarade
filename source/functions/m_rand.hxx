#ifndef M_RAND_H
#define M_RAND_H

#include <random>

class RANDOM_FUNCTIONS
{
public:
    // Fixed returnRand template for integer declarations.
    int returnRandInt(const int &x, const int &y)
    {
        return returnRand<int>("i", x, y);
    }

    // Fixed returnRand template for double declarations.
    double returnRandDouble(const double &x, const double &y)
    {
        return returnRand<double>("d", x, y);
    }

private:
    template <typename T>
    T returnRand(const char *typecase, const size_t &x, const size_t &y)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        switch (typecase[0])
        {
        case 'd':
        {
            std::uniform_real_distribution<double> dist(x, y);
            return static_cast<T>(dist(gen));
        }

        case 'i':
        {
            std::uniform_int_distribution<> dist(x, y);
            return static_cast<T>(dist(gen));
        }

        default:
            throw std::logic_error("returnRand: Impossible typecase.");
        }
    }
};

#endif