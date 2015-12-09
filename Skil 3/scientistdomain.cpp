#include "scientistdomain.h"

ScientistDomain::ScientistDomain()
{
}

void ScientistDomain::connect()
{
    ScientistData init;
    init.InitConnect();
}

vector<ComputerScientist> ScientistDomain::GetComputerScientist(const QString &str, bool desc)
{
    ScientistData get;
    return get.GetComputerScientist(str,desc);
}

bool ScientistDomain::AddComputerScientist(ComputerScientist& input)
{
    ScientistData add;
    return add.AddComputerScientist(input);
}

bool ScientistDomain::MarkDeleted(const QString &tab, const int& id)
{
    ScientistData mark;
    return mark.MarkDeleted(tab,id);
}

bool ScientistDomain::UnmarkDeleted(const QString& tab, const int& id)
{
    ScientistData unmark;
    return unmark.UnmarkDeleted(tab,id);
}

bool ScientistDomain::DeleteAllMarked()
{
    ScientistData del;
    if(del.DeleteAllMarked())
    {
        return true;
    }
    return false;
}

vector<ComputerScientist> ScientistDomain::GetDeletedCS()
{
    ScientistData tmp;
    return tmp.GetDeletedCS();
}

vector<ComputerScientist> ScientistDomain::SearchCS(const QString& search)
{
    ScientistData seek;
    return seek.SearchCS(search);
}

vector<ComputerScientist> ScientistDomain::SearchCSID(const int& search)
{
    ScientistData seek;
    return seek.SearchCSID(search);
}

vector<ComputerScientist> ScientistDomain::GetCSInnerJoin()
{
    ScientistData join;
    return join.GetCSInnerJoin();
}

bool ScientistDomain::DeleteLink(const int& rowid)
{
    ScientistData join;
    return join.DeleteLink(rowid);
}

vector<int> ScientistDomain::GetRowID()
{
    ScientistData data;
    return data.GetRowID();
}

bool ScientistDomain::AddLink(const int& scientists_id, const int& computers_id)
{
    ScientistData data;
    return data.AddLink(scientists_id,computers_id);
}

bool ScientistDomain::UpdateCS(const QString& tempfirst, const QString& tempmid, const QString& templast, const QString& tempgender, const int& bday, const int& dday, const int& id)
{
    ScientistData data;
    return data.UpdateCS(tempfirst,tempmid,templast,tempgender,bday,dday,id);
}
