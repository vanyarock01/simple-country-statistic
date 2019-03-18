#ifndef COUNTRY
#define COUNTRY

#include <cctype>
#include <string>
#include <vector>


class Country
{
public:
    Country(const std::string &country);
    ~Country() {};

    void insert(uint32_t count, uint32_t user);
    
    std::string get_country();
    
    uint32_t get_count();
    uint32_t get_user_number();
private:
    uint32_t count;
    std::string name;
    std::vector <uint32_t> users;
};

#endif