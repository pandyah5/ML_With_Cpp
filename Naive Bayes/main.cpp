#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "string_parser.h"

using namespace std;

int main(void){
    ifstream input;
    input.open("spam.csv");

    // Parsing the data file
    string label = "";
    string data = "";

    std::vector<std::string> label_list;
    std::vector<std::string> data_list;

    while(!input.eof()){
        getline(input, label, ',');
        getline(input, data, ';');
        input.ignore(10, '\n');

        label_list.push_back(label);
        data_list.push_back(data);
        // cout << "Data: " << data << "  -  Label: " << label << endl;
    }
    cout << "Data: " << data_list.size() << std::endl;
    cout << "Label: " << label_list.size() << std::endl;

    // Making the unordered maps for naive bayes
    std::unordered_map<std::string, int> spam_map;
    std::unordered_map<std::string, int> ham_map;

    for (int iter = 0; iter < 1; iter++){
        if (label_list[iter] == "spam"){
            string_parser(spam_map, data_list[iter]);
        }
        else{
            string_parser(ham_map, data_list[iter]);
        }
    }

    for (auto iter = spam_map.begin(); iter != spam_map.end(); iter++){
        cout << iter->first << " " << iter->second << std::endl;
    }

    for (auto iter = ham_map.begin(); iter != ham_map.end(); iter++){
        cout << iter->first << " " << iter->second << std::endl;
    }
}
