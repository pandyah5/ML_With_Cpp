#include <iostream>
#include <string>
#include <unordered_map>
#include "string_parser.h"

void string_parser(std::unordered_map<std::string, int>& map, std::string& sentence){
    std::string word; int end = 0;
    while ((sentence.length()) > 0){
        if (sentence.find(' ') == std::string::npos){
            word = sentence;
            end = 1;
        }
        else{
            word = sentence.substr(0, sentence.find(' '));
            sentence.erase(0, sentence.find(' ') + 1);
        }
        std::cout << "Word: " << word << std::endl;

        if (map.find(word) == map.end()){
            map.insert({word, 1});
        }
        else{
            map[word] = map[word] + 1;
        }
        if (end){
            break;
        }
    }
}
