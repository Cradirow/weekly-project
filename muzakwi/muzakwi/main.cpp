//
//  main.cpp
//  muzakwi
//
//  Created by YunBum Han on 2020/01/26.
//  Copyright © 2020 YunBum Han. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

#define MAX_SIZE 1000
char inputString[MAX_SIZE];

vector<string> topics;

void setup();
void addTopic();
void loadTopic();
void printTopic();
void selectTopic();

int main(int argc, const char * argv[]) {
    setup();
    return 0;
}

void setup(){
    while(true){
        int cmd;
        cout << "┌────────────────────────┐" << endl;
        cout << "│  1. Add Topic          │"  << endl;
        cout << "│  2. Load Topic         │"  << endl;
        cout << "│  3. Print All Topic    │"  << endl;
        cout << "│  4. Select!            │"  << endl;
        cout << "└────────────────────────┘" << endl;
        cout << "Select Menu(Enter 0 to exit) : ";
        cin >> cmd;
        switch(cmd){
            case 0:
                return;
            case 1:
                addTopic();
                break;
            case 2:
                loadTopic();
                break;
            case 3:
                printTopic();
                break;
            case 4:
                selectTopic();
                break;
            default:
                cout << "Select right command!" << endl;
                break;
        }
    }
}

void addTopic(){
    string cmd, fileName;
    cout << "Do you want to make new topic file? (y/n) ";
    cin >> cmd;
    if(cmd == "y"){
        cout << "Enter new file name : ";
        cin >> fileName;
        ifstream read;
        read.open(fileName + ".txt");
        if(read){
            cout << "File is already exist!" << endl;
            return;
        }
        
        ofstream outFile(fileName + ".txt");
        while(true){
            cout << "Enter new topic(Enter 0 to exit): ";
            string str; cin >> str;
            if(str == "0") break;
            outFile << str << endl;
        }
        cout << "Complete!" << endl;
        outFile.close();
    }else{
        cout << "Enter existing file name : ";
        cin >> fileName;
        ifstream workingfile(fileName + ".txt");
        if(!workingfile.is_open()){
            cout << "File doesn't exist!" << endl;
            return;
        }else{
            ofstream outFile(fileName + ".txt", ios::app);
            while(true){
                cout << "Enter additional topic(Enter 0 to exit): ";
                string str; cin >> str;
                if(str == "0") break;
                outFile << str << endl;
            }
            cout << "Complete!" << endl;
        }
    }
//    system("clear");
}

void loadTopic(){
    string fileName;
    cout << "Enter topic file name : ";
    cin >> fileName;
    
    ifstream workingfile(fileName + ".txt");
    if(!workingfile.is_open()){
        cout << "File doesn't exist!" << endl;
        return;
    }
    
    topics.clear();
    string in_line;
    while(getline(workingfile, in_line)){
//        cout << in_line << endl;
        topics.push_back(in_line);
    }
    workingfile.close();
}

void printTopic(){
    int size = topics.size();
    if(size == 0){
        cout << "You need to load topic!" << endl;
    }else{
        cout << "Topic List -->" << endl;
        for(int i=0; i<size; i++){
            cout << topics[i] << endl;
        }
        cout << endl;
    }
}

void selectTopic(){
    int size = topics.size();
    if(size == 0){
        cout << "There's no topic to select!" << endl;
    }else{
        srand((unsigned int)time(0));
        int num = rand()%size;
        
        cout << topics[num] << " is selected!" << endl;
    }
}

// unicode
// getline 구현
// language, platform 추가
