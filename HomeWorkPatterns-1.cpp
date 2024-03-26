#include <iostream>
#include "sql_query_builder.h"

int main () {
    SqlSelectQueryBuilder query_builder_task1;
    query_builder_task1.AddColumn("name").AddColumn("phone");
    query_builder_task1.AddFrom("students");
    query_builder_task1.AddWhere("id", "42").AddWhere("name", "John");
    std::cout << query_builder_task1.BuildQuery() <<" \n";

    SqlSelectQueryBuilder query_builder_task2;
    std::vector<std::string> cols{"id", "name", "last_name"};
    query_builder_task2.AddColumns(cols);
    query_builder_task2.AddFrom("students");
    std::map<std::string, std::string> kv {{"id", "50"}, {"name", "Ivan"}};
    query_builder_task2.AddWhere(kv).AddWhere("last_name", "Ivanov");;
    std::cout << query_builder_task2.BuildQuery();

}