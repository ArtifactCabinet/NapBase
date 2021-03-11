#ifndef NAPBASE_WRITER_H
#define NAPBASE_WRITER_H

#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <istream>
#include <string>
#include <string_view>
#include <vector>
#define BUFFER_SIZE 248// 256 (2^8) -8
#define POOL_SIZE BUFFER_SIZE*5000

struct entry {
    int32_t id;              //8 bytes
    char * span[BUFFER_SIZE];//
};

class db_instance {
public:
    explicit db_instance(const std::string& p)
        : path(p), db_file(p, std::ios_base::binary|std::ios::out){};

    std::fstream db_file;

    void dump();
    void close();

    void print_entries();

    void insert_entry(int id, const char *str);

private:
    int cur{0};
    std::filesystem::path path;
    std::vector<entry> data[POOL_SIZE];// datatype just for now.
};


#endif//NAPBASE_WRITER_H
