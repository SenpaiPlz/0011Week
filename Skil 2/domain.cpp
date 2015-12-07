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
