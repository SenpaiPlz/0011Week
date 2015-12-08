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

vector<ComputerScientist> domain::GetCSInnerJoin()
{
    SQLQueryData join;
    return join.GetCSInnerJoin();
}
vector<computersabstract> domain::GetComputerInnerJoin()
{
    SQLQueryData join;
    return join.GetComputerInnerJoin();
}

bool domain::DeleteLink(const int& rowid)
{
    SQLQueryData join;
    return join.DeleteLink(rowid);
}

vector<int> domain::GetRowID()
{
    SQLQueryData data;
    return data.GetRowID();
}

bool domain::AddLink(const int& scientists_id, const int& computers_id)
{
    SQLQueryData data;
    return data.AddLink(scientists_id,computers_id);
}

bool domain::UpdateCS(const QString& tempfirst, const QString& tempmid, const QString& templast, const QString& tempgender, const int& bday, const int& dday, const int& id)
{
    SQLQueryData data;
    return data.UpdateCS(tempfirst,tempmid,templast,tempgender,bday,dday,id);
}

bool domain::UpdateComputer(const QString &tempname, const int &year, const QString &type, const bool& built, const int &id)
{
    SQLQueryData update;
    return update.UpdateComputer(tempname,year,type,built,id);
}
