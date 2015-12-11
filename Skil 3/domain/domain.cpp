#include "domain.h"

Domain::Domain()
{
}

void Domain::connect()
{
    ScientistData init;
    init.InitConnect();
}

vector<ComputerScientist> Domain::GetComputerScientist(const QString &str, bool desc)
{
    ScientistData get;
    return get.GetComputerScientist(str,desc);
}

bool Domain::AddComputerScientist(ComputerScientist& input)
{
    ScientistData add;
    return add.AddComputerScientist(input);
}

bool Domain::MarkDeleted(const QString &tab, const int& id)
{
    ScientistData mark;
    return mark.MarkDeleted(tab,id);
}

bool Domain::UnmarkDeleted(const QString& tab, const int& id)
{
    ScientistData unmark;
    return unmark.UnmarkDeleted(tab,id);
}

bool Domain::DeleteAllMarked()
{
    ScientistData del;
    if(del.DeleteAllMarked())
    {
        return true;
    }
    return false;
}

vector<ComputerScientist> Domain::GetDeletedCS()
{
    ScientistData tmp;
    return tmp.GetDeletedCS();
}

vector<ComputerScientist> Domain::SearchCS(const QString& search)
{
    ScientistData seek;
    return seek.SearchCS(search);
}

vector<ComputerScientist> Domain::SearchCSID(const int& search)
{
    ScientistData seek;
    return seek.SearchCSID(search);
}

vector<ComputerScientist> Domain::GetCSInnerJoin()
{
    ScientistData join;
    return join.GetCSInnerJoin();
}

bool Domain::DeleteLink(const int& rowid)
{
    ScientistData join;
    return join.DeleteLink(rowid);
}

vector<int> Domain::GetRowID()
{
    ScientistData data;
    return data.GetRowID();
}

bool Domain::AddLink(const int& scientists_id, const int& computers_id)
{
    ScientistData data;
    return data.AddLink(scientists_id,computers_id);
}

bool Domain::UpdateCS(const QString& tempfirst, const QString& tempmid, const QString& templast, const QString& tempgender, const int& bday, const int& dday, const int& id)
{
    ScientistData data;
    return data.UpdateCS(tempfirst,tempmid,templast,tempgender,bday,dday,id);
}

vector<Computer> Domain::GetComputers(const QString &str, bool desc)
{
    ComputerData get;
    return get.GetComputers(str,desc);
}

bool Domain::AddComputer(Computer& input)
{
    ComputerData add;
    return add.AddComputer(input);
}

vector<Computer> Domain::GetDeletedComputers()
{
    ComputerData tmp;
    return tmp.GetDeletedComputers();
}

vector<Computer> Domain::SearchComputerID(const int& search)
{
    ComputerData seek;
    return seek.SearchComputerID(search);
}

vector<Computer> Domain::SearchComputer(const QString& search)
{
    ComputerData seek;
    return seek.SearchComputer(search);
}

vector<Computer> Domain::GetComputerInnerJoin()
{
    ComputerData join;
    return join.GetComputerInnerJoin();
}

bool Domain::UpdateComputer(const QString &tempname, const int &year, const QString &type, const bool& built, const int &id)
{
    ComputerData update;
    return update.UpdateComputer(tempname,year,type,built,id);
}
