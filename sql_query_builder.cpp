#include "sql_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string column_name) {
        params.columns.push_back(column_name);
        return *this;
    }

void SqlSelectQueryBuilder::AddFrom(std::string from) {
    params.from = from;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept{
    for (const auto &i: kv) {
        AddWhere(i.first, i.second);
    }
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::string name, std::string value) {
    std::string tmp {name + "=" + value};
    params.where.push_back(std::move(tmp));
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept {
    for (const auto &i: columns) {
        AddColumn(i);
    }
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
    std::string query{};

    if (params.columns.empty()) {
        AddColumn("*");
    }
    query += "SELECT ";
    for (const auto &i: params.columns) {
        query += i;
        query += ", ";
    }
    query.erase(query.end() - 2, query.end());
    query += " FROM ";
    query += params.from;
    query += " WHERE ";
    for (const auto &i: params.where) {
        query += i;
        query += " AND ";
    }
    query.erase(query.end() - 4, query.end());
    query += ";";
    return query;
}