#include "domain.h"

domain::domain()
{
}

void domain::connect()
{
    SQLQueryData init;
    init.InitConnect();
}


vector<computersabstract> domain::GetComputers(const QString &str, bool desc)
{
    SQLQueryData get;
    return get.GetComputers(str,desc);
}

vector<ComputerScientist> domain::GetComputerScientist(const QString &str, bool desc)
{
    SQLQueryData get;
    return get.GetComputerScientist(str,desc);
}

bool domain::AddComputerScientist(ComputerScientist& input)
{
    SQLQueryData add;
    return add.AddComputerScientist(input);
}

bool domain::AddComputer(computersabstract& input)
{
    SQLQueryData add;
    return add.AddComputer(input);
}

bool domain::MarkDeleted(const QString &tab, const int& id)
{
    SQLQueryData mark;
    return mark.MarkDeleted(tab,id);
}

bool domain::UnmarkDeleted(const QString& tab, const int& id)
{
    SQLQueryData unmark;
    return unmark.UnmarkDeleted(tab,id);
}

bool domain::DeleteAllMarked()
{
    SQLQueryData del;
    if(del.DeleteAllMarked())
    {
        return true;
    }
    return false;
}

vector<ComputerScientist> domain::GetDeletedCS()
{
    SQLQueryData tmp;
    return tmp.GetDeletedCS();
}

vector<computersabstract> domain::GetDeletedComputers()
{
    SQLQueryData tmp;
    return tmp.GetDeletedComputers();
}

vector<ComputerScientist> domain::SearchCS(const QString& search)
{
    SQLQueryData seek;
    return seek.SearchCS(search);
}

vector<ComputerScientist> domain::SearchCSID(const int& search)
{
    SQLQueryData seek;
    return seek.SearchCSID(search);
}

vector<computersabstract> domain::SearchComputerID(const int& search)
{
    SQLQueryData seek;
    return seek.SearchComputerID(search);
}

vector<computersabstract> domain::SearchComputer(const QString& search)
{
    SQLQueryData seek;
    return seek.SearchComputer(search);
}
