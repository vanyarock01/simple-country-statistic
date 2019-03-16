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
                std::cout << str.length() << ' ' << last  << ' ' << curr << '\n';
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


void read_file(const std::string &file) {
    std::ifstream infile(file);
    if (!infile) return;

    std::string line;
    std::vector <Country> data;
    while ( std::getline(infile, line) ) {    
        if ( line.empty() || line_validator(line, ';') == false ) continue;
        uint32_t id, count;
        std::string country;
        
   }
}


int main(int argc, char const *argv[]) {
    read_file("small.txt");
    return 0;
}