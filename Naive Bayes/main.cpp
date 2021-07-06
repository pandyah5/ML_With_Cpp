#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    ifstream input;
    input.open("spam.csv");

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
    cout << "Data: " << data_list[10] << std::endl;
    cout << "Label: " << label_list[10] << std::endl;
}
