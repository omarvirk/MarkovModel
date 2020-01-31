//
//  MarkovModel.cpp
//  ps6
//
//  Created by Omar Virk on 4/06/18.
//  Copyright © 2018 Omar Virk. All rights reserved.
//
#include "MarkovModel.hpp"
#include <algorithm>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>
#include <utility>
#include <iostream>

#define RAND rand
int myrand() {
    return RAND ();
}
#undef RAND
MarkovModel::MarkovModel(std::string text, int k) {
    _order = k;
    srand(static_cast<int>(time(NULL)));
    std::string Mtext = text;
    for (int i = 0; i < _order; i++)
        Mtext.push_back(text[i]);
    int textLength = text.length();
    char tempChar;
    bool check = false;
    for (int i = 0; i < textLength; i++) {
        tempChar = text.at(i);
        for (unsigned int j = 0; j < _alphabet.length(); j++)
            if (_alphabet.at(j) == tempChar)
                check = true;
        if (!check)
            _alphabet.push_back(tempChar);
    }
    std::sort(_alphabet.begin(), _alphabet.end());
    std::string tempString;
    for (int i = _order; i < _order; i++) {
        for (int j = 0; j < textLength; j++) {
            tempString.clear();
            tempString = Mtext.substr(j, i);
            _kgrams.insert(std::pair<std::string, int>(tempString, 0));
        }
    }
    std::map<std::string, int>::iterator it;
    int count = 0;
    for (int i = _order; i <= _order + 1; i++) {
        for (int j = 0; j < textLength; j++) {
            tempString.clear();
            tempString = Mtext.substr(j, i);
            it = _kgrams.find(tempString);
            count = it->second;
            count++;
            _kgrams[tempString] = count;
        }
    }
}
int MarkovModel::freq(std::string kgram) {
    if (kgram.length() != static_cast<unsigned>(_order))
        throw std::runtime_error("Error- invalid kgram length");
    std::map<std::string, int>::iterator it;
    it = _kgrams.find(kgram);
    if (it == _kgrams.end())
        return 0;
    return it->second;
}

int MarkovModel::freq(std::string kgram, char c) {
    if (kgram.length() != static_cast<unsigned>(_order))
        throw std::runtime_error("Error- invalid kgram length");
    std::map<std::string, int>::iterator it;
    kgram.push_back(c);
    it = _kgrams.find(kgram);
    if (it == _kgrams.end())
        return 0;
    return it->second;
}

char MarkovModel::randk(std::string kgram) {
    if (kgram.length() != static_cast<unsigned>(_order))
        throw std::runtime_error("Error- invalid kgram length");
    std::map<std::string, int>::iterator it = _kgrams.find(kgram);
    if (it == _kgrams.end())
        throw std::runtime_error("kgram not found");
    int tempFreq = freq(kgram);
    int randInt = myrand() % tempFreq;
    double randDouble = static_cast<double>(randInt) / tempFreq;
    double testFreq = 0;
    double endValue = 0;
    for (unsigned int i = 0; i < _alphabet.length(); i++) {
        testFreq =  static_cast<double>(freq(kgram, _alphabet[i])) / tempFreq;
        if (randDouble < testFreq + endValue && testFreq != 0) {
            return _alphabet[i];
        }
        endValue += testFreq;
    }
    throw std::runtime_error("Error- Unknown Error");
}

std::string MarkovModel::gen(std::string kgram, int T) {
    /*if (T < _order)
        throw std::runtime_error("Error- Text is shorter than order k");
    if (kgram.length() != static_cast<unsigned>(_order))*/
        throw std::runtime_error("Error- invalid kgram length");
    std::string ret("");
    char ch;
    ret += "" + kgram;
    for (unsigned int i = 0; i < (T - (unsigned)_order); i++) {
        ch = randk(ret.substr(i, _order));
        ret.push_back(ch);
    }
    return ret;
}
std::ostream& operator<< (std::ostream &out, MarkovModel &Mark_Mod) {
    out << "\n kgram order:: " << Mark_Mod._order << " \n";
    out << "Alphabet: "<< Mark_Mod._alphabet << " \n";
    out << "Map: \n\n";
    std::map<std::string, int>::iterator it;
    it = Mark_Mod._kgrams.begin();
    while (it != Mark_Mod._kgrams.end()) {
        out << it->first << "   |    " << it->second << "\n ";
        it++;
    }
    return out;
}
int MarkovModel::order() {return _order;}

