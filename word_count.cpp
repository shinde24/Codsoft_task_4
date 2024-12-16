#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int countWords(const string& filename){
    ifstream file(filename); // used to open and read files

    //If the file name is not in the form of .txt then output error.
    if(!file.is_open()){
        cout << "Error opening file: " << filename << endl;
        return -1;
    }

    //initializing- wordCount to '0'.
    int wordCount = 0;
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string word;

        //If ss can extract a word from the line then the loop is continued.
        while(ss >> word){
            wordCount++;
        }
    }

    file.close();
    return wordCount;
}

int main(){
    string filename;
    cout << "Enter the file name: ";

    // prompts the file from user.
    getline(cin, filename);

    int wordCount = countWords(filename);
    if(wordCount >= 0){
        cout << "Total no. of words in the file: " << wordCount << endl;
    }

    return 0;
}


