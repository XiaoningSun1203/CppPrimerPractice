#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int longestPalindrome(string s) {
    if(s.begin() == s.end()) return 0;

    unordered_map<char,int> table;
    for(auto ch : s){
        ++table[ch];
    }
    //统计所有value中的偶数，再加1就是最长
    int count = 0;
    auto iter = table.begin();
    if(iter != table.end()){
        if (iter->second % 2 != 0){
            iter->second--;
        }
        count = count + iter->second;
        cout << count <<endl;
        iter++;
    }
    return count+1;
}
int main(){
    string s{"abccccdd"};
    longestPalindrome(s);
    return 0;
}
