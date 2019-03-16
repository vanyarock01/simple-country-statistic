#include "country.h"



Country::Country(const std::string &country) {
    name = country;
    count = 0;
}


void Country::insert(uint32_t count, uint32_t user) {
    std::vector <uint32_t>::iterator it_user;
    for (it_user = users.begin(); it_user != users.end(); it_user++) {
        if ( *it_user == user ) {
            break;
        }
    }
    if ( it_user == users.end() ) {
        users.push_back(user);
    }
    this->count += count; 
}


std::string Country::get_country() {
    return this->name;
}


uint32_t Country::get_count() {
    return this->count;
}


uint32_t Country::get_user_number() {
    return this->users.size();
}
