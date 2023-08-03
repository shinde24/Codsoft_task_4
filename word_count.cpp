#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int countWords(const string& filename){
    ifstream file(filename);

    // if file name is not in the form of .txt them output error.
    if(!file.is_open()){
        cout << "Error opening file: " << filename << endl;
        return -1;
    }

    // initialising wordCount to '0'.
    int wordCount = 0;
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string word;

        // if ss can extract word from line then loop is cotinued.
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


