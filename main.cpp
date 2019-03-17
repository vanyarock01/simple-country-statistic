#include <iostream>
#include <iomanip> 
#include <fstream>
#include <vector>
#include <string>
#include "country.h"
/*
11231;6;Russia
11232;1;Ukraine
1122;1;Ukraine
*/

std::vector <std::string> split(const std::string &str, const std::string &rex) {
    std::vector <std::string> vec;
    size_t last = 0;
    for (size_t curr = 0; curr < str.length() - rex.length() + 1; curr++) {
        if ( str.substr(curr, rex.length()) == rex ) {
            if ( curr - last ) {
                vec.push_back(str.substr(last, curr - last));
            }
            last = curr + 1;
        }
    }
    vec.push_back(str.substr(last, str.length() - last));
    return vec;
}


bool line_validator(const std::string &line, char rex) {
    size_t state = 0;

    for (size_t curr = 0; curr < line.length(); curr++) {
        switch (state) {
            case 0: {
                if ( line[curr] == rex )
                    state = 1;
                else if ( !std::isdigit(line[curr]) )
                    return false;         
                break;
            }
            case 1: {
                if ( line[curr] == rex )
                    state = 2;
                else if ( !std::isdigit(line[curr]) ) 
                    return false;
               break;     
            }
            case 2: {
                if ( !std::isalpha(line[curr]) )
                    return false;
                break;     
            }
        }
    }
    return (state == 2) ? true : false;
}


void read_file(const std::string &file, std::vector <Country> &data) {
    std::ifstream infile(file);
    if (!infile) return;

    std::string line;
    std::vector <Country>::iterator it_data;
    
    while ( std::getline(infile, line) ) {    
        if ( line.empty() || line_validator(line, ';') == false ) continue;
        
        std::vector <std::string> vec = split(line, ";");
        uint32_t id = std::stoi(vec[0]);
        uint32_t count = std::stoi(vec[1]);
        
        for (it_data = data.begin(); it_data != data.end(); it_data++) {
            if ( it_data->get_country() == vec[2] ) {
                it_data->insert(count, id);
                break;
            }
        }
        if ( it_data == data.end() ) {
            Country c(vec[2]);
            c.insert(count, id);
            data.push_back(c);
        }
    }
}


int main(int argc, char const *argv[]) {
    std::vector <Country> data;
    read_file("small.txt", data);
    std::vector <Country>::iterator it_data;
    for (it_data = data.begin(); it_data != data.end(); it_data++) {
        std::cout << it_data->get_country()     << ';' << 
                     it_data->get_count()       << ';' <<
                     it_data->get_user_number() << '\n';

    }
        
    return 0;
}
















