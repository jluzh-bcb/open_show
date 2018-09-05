/* ----------------main.cpp-----------------
 * =========================================
 * This file is part of the stuAddrSys.
 * Created by zjzdy on 2018/1/14.
 * =========================================
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "database.h"

using namespace std;

//Suggestion: use map::cbegin()/cend() replace map::begin()/end() if c++ version > 201103L
//Warning: if want to export data in non-gbk code environment, please change this str:
#define MAN_STR "ÄÐ"
#define WOMAN_STR "Å®"
//Note: Memory consumption may be is big and load/save data may be is slow when data is big.
//      All data will load in memory from disk, and save in disk when quit.
//      If want to support more data, please use database(such as sqlite3), or use disk-based access with cache.

inline void ateALineForCIN() {
    cin.clear();
    string str;
    getline(cin, str);
}

inline void clearScreen() {
#if defined(_WIN32) || defined(__NT__)
    system("cls");
#else
    //printf("\033[2J");
    printf("\033c");
#endif
}

inline void waitEnterPress(string str = "Press Enter key to return") {
    cout << str << endl;
    getline(cin, str);
}
void parseAndDo(char c, Database &database);
void view(Database &database);
void add(Database &database);
void search(Database &database);
void remove(Database &database);
void exportData(Database &database);

int main() {
    cin >> noskipws;
    cout << "Loading..." << endl;
    Database database;
    while(true) {
        clearScreen();
        cout << "Welcome use student address system" << endl;
        cout << "\t0. View" << endl;
        cout << "\t1. Add" << endl;
        cout << "\t2. Search" << endl;
        cout << "\t3. Remove" << endl;
        cout << "\t4. Export" << endl;
        cout << "\t5. Quit" << endl;
        cout << "======================================" << endl;
        //user select support 0, 0. View, V, v, View, etc.
        cout << "Please tell me what do you want to do: ";
        char c;
        cin >> c;
        ateALineForCIN();
        try {
            parseAndDo(c, database);
        }
        catch (char* str) {
            cout << "\n==========================================" << endl;
            cout << "ERROR: " << str;
            return 0;
        }
    }
}

void parseAndDo(char c, Database &database) {
    switch(c) {
        case '0':
        case 'V':
        case 'v':
            view(database);
            break;
        case '1':
        case 'A':
        case 'a':
            add(database);
            break;
        case '2':
        case 'S':
        case 's':
            search(database);
            break;
        case '3':
        case 'R':
        case 'r':
            remove(database);
            break;
        case '4':
        case 'E':
        case 'e':
            exportData(database);
            break;
        case '5':
        case 'Q':
        case 'q':
            cout << "Saving..." << endl;
            database.flush();
            exit(0);
        default:
            return;
    }
}

void view(Database &database) {
    clearScreen();
    cout << "Main >> View" << endl;
    int count = 0;
    const int sep = 5;
    const std::map<string, stuData>& data = database.getAllStu();
    size_t size = data.size();
    if(size == 0) {
        cout << "The student address system is empty." << endl;
        waitEnterPress();
        return;
    }
    for(std::map<string, stuData>::const_iterator iter = data.begin(); iter != data.end(); ++iter){
        cout << "\tStudent Code: " << iter->second.code << endl;
        cout << "\tStudent Name: " << iter->second.name << endl;
        cout << "\tStudent Age: " << int(iter->second.age) << endl;
        cout << "\tStudent Sex: " << (iter->second.sex ? WOMAN_STR : MAN_STR) << endl;
        cout << "\tStudent Phone: " << iter->second.phone << endl;
        cout << "==========================================" << endl;
        count++;
        if(count%sep == 0 && count != size) {
            cout << "Current is " << count-sep+1 << '-' << count << " Record (Total " << size << " Record)" << endl;
            waitEnterPress("Press Enter key to view next page");
            clearScreen();
            cout << "Main >> View" << endl;
        }
    }
    cout << "View data finish." << endl;
    waitEnterPress();
}

void add(Database &database) {
    stuData stu;
    unsigned int i;
    clearScreen();
    cout << "Main >> Add" << endl;
    cout << "\tStudent Code: ";
    cin >> stu.code;
    ateALineForCIN();
    cout << "\tStudent Name: ";
    getline(cin, stu.name);
    cout << "\tStudent Age: ";
    cin >> i;
    ateALineForCIN();
    stu.age = i;
    if(cin.fail() || i < 0 || i > 150) {
        cout << "Sorry, you input data is invalid." << endl;
        waitEnterPress();
        return;
    }
    cout << "\tStudent Sex (0 is man, 1 is woman): ";
    cin >> i;
    ateALineForCIN();
    stu.sex = i;
    if(cin.fail() || i < 0 || stu.sex > 1) {
        cout << "Sorry, you input data is invalid." << endl;
        waitEnterPress();
        return;
    }
    cout << "\tStudent Phone: ";
    getline(cin, stu.phone);
    database.addOrModifyStu(stu);
    cout << "Add data finish." << endl;
    waitEnterPress();
}

void search(Database &database) {
    string code;
    clearScreen();
    cout << "Main >> Search" << endl;
    cout << "\tStudent Code: ";
    cin >> code;
    ateALineForCIN();
    const stuData *stu = database.searchStu(code);
    if(!stu) {
        cout << "Sorry, can't found this student." << endl;
        waitEnterPress();
        return;
    }
    cout << "\tStudent Name: " << stu->name << endl;
    cout << "\tStudent Age: " << int(stu->age) << endl;
    cout << "\tStudent Sex: " << (stu->sex ? WOMAN_STR : MAN_STR) << endl;
    cout << "\tStudent Phone: " << stu->phone << endl;
    cout << "Search data finish." << endl;
    waitEnterPress();
}

void remove(Database &database) {
    string code;
    clearScreen();
    cout << "Main >> Remove" << endl;
    cout << "\tStudent Code: ";
    cin >> code;
    ateALineForCIN();
    const stuData *stu = database.searchStu(code);
    if(!stu) {
        cout << "Sorry, can't remove this student, because can't found this student." << endl;
        waitEnterPress();
        return;
    }
    database.removeStu(code);
    cout << "Remove data finish." << endl;
    waitEnterPress();
}

void exportData(Database &database) {
    string path;
    clearScreen();
    cout << "Main >> Export" << endl;
    cout << "\tSave file path: ";
    cin >> path;
    ateALineForCIN();
    fstream fs(path.c_str(), fs.out);
    if(!fs.is_open()) {
        cout << "failed to open " << path << endl;
        waitEnterPress();
        return;
    }
    const std::map<string, stuData>& data = database.getAllStu();
    for(std::map<string, stuData>::const_iterator iter = data.begin(); iter != data.end(); ++iter){
        fs << "id: " << iter->second.code << endl;
        fs << "name: " << iter->second.name << endl;
        fs << "age: " << int(iter->second.age) << endl;
        fs << "sex: " << (iter->second.sex ? WOMAN_STR : MAN_STR) << endl;
        fs << "phone: " << iter->second.phone << endl;
        fs << endl;
    }
    cout << "Export data finish." << endl;
    waitEnterPress();
}