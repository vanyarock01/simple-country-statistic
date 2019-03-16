#include "country.h"



Country::Country(const std::string &country) {
    name = country;
}


void Country::insert(uint32_t count, uint32_t user) {
    std::vector <uint32_t>::iterator usr_it;
    for (usr_it = users.begin(); usr_it != users.end(); usr_it++) {
        if ( *usr_it == user ) {
            break;
        }
    }
    if ( usr_it == users.end() ) {
        users.push_back(user);
    }
    this->count += count; 
}


std::string Country::get_county() {
    return this->name;
}


uint32_t Country::get_count() {
    return this->count;
}


uint32_t Country::get_user_number() {
    return this->users.size();
}
