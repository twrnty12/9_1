#pragma once

#include <vector>
#include <string>
#include <map>

struct QueryParams 
{
    std::string from{};
    std::vector<std::string> columns{};
    std::vector<std::string> where{};
};


class SqlSelectQueryBuilder
{
    QueryParams params{};
public:
    SqlSelectQueryBuilder& AddColumn(std::string column_name);
    void AddFrom(std::string from);
    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;
    SqlSelectQueryBuilder& AddWhere(std::string name, std::string value);
    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
    std::string BuildQuery();
};