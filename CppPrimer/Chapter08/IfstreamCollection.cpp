#include <iostream>

#include <fstream>
#include <vector>

int main(){
    std::ifstream f1("1.txt");
    if(!f1){
        std::cout << "bad file 1" << std::endl;
        f1.close();
        return 1;
    }
    std::vector<std::ifstream> files;
    files.push_back(std::ifstream("3.txt"));
    files.push_back(std::ifstream("4.txt"));
    for(auto &f : files){
        f.close();
    }
    f1.close();
    return 0;
}
