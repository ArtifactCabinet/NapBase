//
// Created by slbtty on 3/11/21.
//

#include "db_instance.h"


void db_instance::insert_entry(int32_t id, const char * str) {
    data->push_back(entry{id, const_cast<char *>(str)});
    cur+=1;
}

void db_instance::dump() {
    for(auto & i : *data){
    db_file<<&i;
    }
    std::cout<<"dumped"<<std::endl;
}

void db_instance::close(){
    db_file.close();
}
void db_instance::print_entries() {
    for(auto & i : *data){
        std::cout<<i.id<<" "<<i.span<<std::endl;
    }
}

int main(){
    auto slb = new db_instance("nice.db");

    slb->insert_entry(1,"nice");
    slb->insert_entry(2,"cool");

    slb->print_entries();

    slb->dump();
    slb->close();

    return 0;
}