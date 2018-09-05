/* ---------------database.h----------------
 * =========================================
 * This file is part of the stuAddrSys.
 * Created by zjzdy on 2018/1/14.
 * =========================================
 */

#ifndef STUINFOSYS_DATABASE_H
#define STUINFOSYS_DATABASE_H

#include <string>
#include <map>
#include <cstdio>
#if __cplusplus >= 201103L
#include <cstdint>
#else
#include <stdint.h>
#endif

using std::string;

struct stuData {
    string code;
    string name;
    uint8_t age;
    uint8_t sex;// 0 is man; 1 is woman
    string phone;//ºÊ»›+86-(0)21-88888888
};

class Database {
public:
    explicit Database(string path = "data");
    void flush();
    void addOrModifyStu(stuData stu);
    const stuData* searchStu(string code);
    void removeStu(string code);
    const std::map<string, stuData>& getAllStu();

    virtual ~Database();

private:
    std::map<string, stuData> data;
    string filePath;
    bool modify;
};


#endif //STUINFOSYS_DATABASE_H
