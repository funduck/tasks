//
// Created by sancho on 04.06.19.
//

#include "func.h"


char func::GetMap(char *filename, std::vector <std::string> &v)
{
    std::ifstream fin(filename);

    if (!fin.is_open()) {// если файл не открыт
        std::cout << "Файл не может быть открыт!\n";
        return 0;
    }
    std::string str;
    while (fin){
        std::string str;
        std::getline(fin, str);
        v.push_back(str);
    }



    return 0;
}


