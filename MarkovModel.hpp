//
//  MarkovModel.cpp
//  ps6
//  Created by Omar Virk on 4/06/18.
//  Copyright © 2018 Omar Virk. All rights reserved.
//
#include <string>
#include <map>

class MarkovModel {
 public:
    MarkovModel(std::string text, int k);
    int order();
    int freq(std::string kgram);
    int freq(std::string kgram, char c);
    char randk(std::string kgram);
    std::string gen(std::string kgram, int T);
    friend std::ostream& operator<< (std::ostream &out, MarkovModel &mm);
 private:
    int _order;
    std::map <std::string, int> _kgrams;  // must #include <map>
    std::string _alphabet;
};
