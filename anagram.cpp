/*
 * Name: Chris Hattan
 * Date Submitted:
 * Assignment Name: Anagram finder
 */

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>


using namespace std;

vector<string> loadWordlist(string filename);


vector<string> anagram(string word, vector<string> wordlist);

//takes words from the .txt and places them in an array
vector<string> loadWordlist(string filename) {
  vector<string> words;
  ifstream inFile;
  string word;
  inFile.open(filename);
  if (inFile.is_open()) {
    while (getline(inFile, word)) {
      if (word.length() > 0) {
        words.push_back(word);
      }
    }
    inFile.close();
  }
  return words;
}


vector<string> anagram(string word, vector<string> wordlist) {
  map<string,vector<string>> theMap;
  map<string,vector<string>>::iterator itr;
  string hashCode;
  string wordHash = "00000000000000000000000000";
  for (int i = 0; i < word.size(); ++i){
    wordHash[word[i] - 97]++;
  }
  
  for (int i = 0; i < wordlist.size(); ++i){
    hashCode = "00000000000000000000000000";
    for (int j = 0; j < wordlist[i].size(); ++j){
        hashCode[wordlist[i][j] - 97]++;
    }
    if (theMap.empty()){
      vector<string> space = {word};
      theMap.insert(pair<string,vector<string>>(hashCode,space));
    }
    for(itr = theMap.begin(); itr != theMap.end(); ++itr){
      if (itr->first == wordHash){
        itr->second.push_back(word);
      }
      else{
        vector<string> space = {word};
        theMap.insert(pair<string,vector<string>>(hashCode,space));
      }
    }
  }
  //loop that compares each word's hash to the original word's
  for(itr = theMap.begin(); itr != theMap.end(); ++itr){
    if (itr->first == wordHash){
      return itr->second;
    }
  }
}