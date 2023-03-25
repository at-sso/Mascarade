#include <map>
#include <functional>
#include <vector>
#include <random>
#include <algorithm>

class MyClass
{
public:
    // Define a template function that takes a function pointer and returns a lambda
    template <typename T>
    auto make_lambda(T func_ptr)
    {
        return [=](auto... args)
        { return (this->*func_ptr)(args...); };
    }

    // Define the map with string keys and function values
    std::map<std::string, std::function<void()>> DEV_COMMANDS = {
        {"ply.array", make_lambda(&MyClass::getNamesArray)},
        {"ply.genage", make_lambda(&MyClass::generateAge)},
        {"ply.genname", make_lambda(&MyClass::generateNames)}};

private:
    std::vector<std::string> NAMES = {
        "Arvaela", "Sylvard", "Baeloria",
        "Zephyrin", "Quinleth", "Orynthea",
        "Xandrielle", "Kaelith", "Thalindor",
        "Vaelstryn", "Myryndor", "Ylvaine",
        "Rythandria", "Eryndelle", "Zaeloria",
        "Arinthea", "Lyvandria", "Orindale",
        "Faeloria", "Neryndor", "sso"};

    std::string getNamesArray(int index)
    {
        return NAMES[index];
    }

    std::string generateNames(std::vector<std::string> &existingNames)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, NAMES.size() - 1);

        std::string newName;
        do
        {
            newName = NAMES[dis(gen)];
        } while (std::find(existingNames.begin(), existingNames.end(), newName) != existingNames.end());

        existingNames.push_back(newName);
        return newName;
    }

    void generateAge(std::vector<int> &existingAge)
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(1.0, 20.0);
        existingAge.push_back(dist(mt));
    }
};

int main()
{
    MyClass myClass;

    // Call the functions in the map
    std::vector<std::string> existingNames;
    std::vector<int> existingAge;

    myClass.DEV_COMMANDS["ply.array"](0);
    myClass.DEV_COMMANDS["ply.genage"](existingAge);
    myClass.DEV_COMMANDS["ply.genname"](existingNames);

    return 0;
}