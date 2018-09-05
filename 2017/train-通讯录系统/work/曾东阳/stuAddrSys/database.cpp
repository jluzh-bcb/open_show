/* --------------database.cpp---------------
 * =========================================
 * This file is part of the stuAddrSys.
 * Created by zjzdy on 2018/1/14.
 * =========================================
 */

#include "database.h"
#define IO_ERROR_STR "DISK I/O ERROR"

//FIXME: Ignore Little-endian and Big-endian io problem
//LIMIT: Student data's string type property length must less than 256

static inline string readString(FILE *fp) {
    uint8_t length;
    char str[256] = {};
    fread(&length, 1, 1, fp);
    fread(str, 1, length, fp);
    return string(str, length);
}

static inline void checkWrite(const void* data, size_t length, FILE *fp) {
    if(fwrite(data, 1, length, fp) != length)
        throw IO_ERROR_STR;
}

static inline void writeString(FILE *fp, const string& str) {
    if(str.length() > 255)
        throw "String too long";
    uint8_t length = str.length();
    checkWrite(&length, 1, fp);
    checkWrite(str.data(), length, fp);
}

Database::Database(string path) : filePath(path), modify(false) {
    FILE *fp = fopen(filePath.c_str(),"rb");
    if(fp) {
        if(!feof(fp)) {
            uint64_t count = 0;
            fread(&count, 8, 1, fp);
            for(int i = 0; i < count; i++) {
                stuData stu;
                stu.code = readString(fp);
                stu.name = readString(fp);
                fread(&stu.age, 1, 1, fp);
                fread(&stu.sex, 1, 1, fp);
                if(stu.sex > 1)
                    throw IO_ERROR_STR;
                stu.phone = readString(fp);
                if(feof(fp))
                    throw IO_ERROR_STR;
                data[stu.code] = stu;
            }
        }
        fclose(fp);
    }
}

Database::~Database() {
    flush();
}

void Database::flush() {
    if(!modify)
        return;
    FILE *fp = fopen(filePath.c_str(),"wb");
    if(fp) {
        uint64_t count = data.size();
        checkWrite(&count, 8, fp);
        for(std::map<string, stuData>::iterator iter = data.begin(); iter != data.end(); ++iter){
            writeString(fp, iter->second.code);
            writeString(fp, iter->second.name);
            checkWrite(&iter->second.age, 1, fp);
            checkWrite(&iter->second.sex, 1, fp);
            writeString(fp, iter->second.phone);
        }
        fclose(fp);
        modify = false;
    }
}

void Database::addOrModifyStu(stuData stu) {
    modify = true;
    data[stu.code] = stu;
}

const stuData* Database::searchStu(string code) {
    std::map<string, stuData>::iterator result = data.find(code);
    if(result != data.end()) {
        return &(result->second);
    }
    else
        return NULL;
}

void Database::removeStu(string code) {
    modify = true;
    data.erase(code);
}

const std::map<string, stuData> &Database::getAllStu() {
    return data;
}
