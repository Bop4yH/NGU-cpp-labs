#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <map>
#include <ctype.h>
#include <io.h>
#include <fcntl.h>
#include <algorithm>

using namespace std;


class WordBook{
private:
    map<string, int> book;
    int weight;

public:
    WordBook(){
        weight = 0;
    }
    void addPair(vector<string> str){

        for(auto &elem : str) {
            weight++;
            book[elem] += 1;
           /* if (book.find(elem) == book.end())
                book.insert(pair<string, int>(elem, 1));
            else
                book.at(elem)++;*/
        }
    }

    map<string, int> getBook() {
        return book;
    }

    int getWeight(){
        return weight;
    }
};

class StringHandler{
private:

    vector<string> splitedStr;


public:

    vector<string> SplitString(string &str){
        splitedStr.clear();
        string buf;
        for(int i = 0; i < str.size(); i++){
            buf = "";
            while(isalpha(str[i]) || isdigit(str[i])) {

                buf += tolower(str[i]);
                i++;
            }

            if(!buf.empty())
                splitedStr.push_back(buf);

        }
      //  vector<string> s;


        return splitedStr;
    }

};


class TableMaker{
private:

    ofstream &stream;

public:
    explicit TableMaker(ofstream &stream):stream(stream){}


    int makeTable(vector< pair<string,int>> table, int weight){
        stream << "WORD, FREQUENCY, FREQUENCY(%)"<<endl;

        for(int i = table.size() - 1; i >= 0; i--){
            stream<<table[i].first<<","<<table[i].second<<","<<100.f*table[i].second/weight<<endl;
        }

        return 0;
    }

};


class TextHandler{
private:

    ifstream &stream;
    vector<string> text;

public:
    explicit TextHandler(ifstream &stream):stream(stream){}


    int processText(){
        string buf;


        while(!stream.eof()){
            getline(stream, buf);
            text.emplace_back(buf);

        }
        return 0;

    }


    vector<string> getText(){
        return text;
    }

};

int main(int argc, char **argv) {

    ofstream myfile;

    myfile.open ("frequency.csv");
    TableMaker tableMaker(myfile);

    string input = argv[1];
    string output = argv[2];

    ifstream file(input);

    if (file.is_open())
        cout << "all good\n\n" << endl;
    else
    {
        cout << "no good!\n\n" << endl;
        return 1;

    }

    TextHandler textHandler(file);
    textHandler.processText();
    WordBook book;
    StringHandler stringHandler;

    for(string elem: textHandler.getText()){

        book.addPair(stringHandler.SplitString(elem));

    }


    const map<string, int> &map = book.getBook();
    vector<pair<string, int>> table(map.begin(), map.end());
    sort(table.begin(), table.end(), [](pair<string,int> a, pair<string,int> b){
        if(a.second < b.second)
            return true;
        if(a.second > b.second)
            return false;
        return (a.first > b.first);
    });



    int weight = book.getWeight();

    tableMaker.makeTable(table, weight);


    return 0;
}

