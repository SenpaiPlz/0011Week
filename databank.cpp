#include "databank.h"
#include "computerscientist.h"



using namespace std;

DataBank::DataBank()
{
    //implying this does nothing...
}

vector<ComputerScientist> DataBank::GetDataBank()
{
    return css;
}

bool DataBank::isempty(ifstream& file)
{
    return file.peek() == ifstream::traits_type::eof();
}

void DataBank::PopulateWithCSV()
{
    //We clear the current css vector just incase we call PopulateWithCSV a second time,
    //So we dont end up with duplicate data. We can therefore use this to "Update".
    css.erase(css.begin(),css.end());
    const string filename = "testdata.csv";
    ifstream in(filename.c_str(), ios::in);

    if(!in.is_open())
    {
        cout << "FILE OPEN ERROR";
        exit(7);
    }
    string tmp;
    ComputerScientist Cstemp;

    //Simply iterate through the file and every ',' we set each value.
    //This requires that the data is standardized and not randomly placed within *.csv file.
    if(isempty(in) == false)
    {
        while(!in.eof())
        {
            getline(in,tmp,',');
            Cstemp.setname(tmp);
            getline(in,tmp,',');
            Cstemp.setbday(tmp);
            getline(in,tmp,',');
            Cstemp.setdday(tmp);
            getline(in,tmp,',');
            Cstemp.setgender(tmp);
            css.push_back(Cstemp);
        }
    }
    in.close();
}

void DataBank::AddToDataBank(const string& tmpname, const string& tmpbday, const string& tmpdday,const string& tmpgender)
{
    const string filename = "testdata.csv";
    ofstream out(filename.c_str(), ios_base::app);

    if(!out.is_open())
    {
        cout << "FILE OPEN ERROR";
        exit(8);
    }
    if(!css.empty())
    {
        out << ",";
    }
    out << tmpname << "," << tmpbday << "," << tmpdday << "," << tmpgender;

    //If file opens we write the data to the file.

    ComputerScientist Cstemp;

    Cstemp.setname(tmpname);
    Cstemp.setbday(tmpbday);
    Cstemp.setdday(tmpdday);
    Cstemp.setgender(tmpgender);

    css.push_back(Cstemp);

    //We also push the data to our active databank so we do not need to repopulate it.

    out.close();
}

void DataBank::DeleteFromDataBank(int ele)
{
    if(static_cast<unsigned>(ele) <= css.size())
    {
        css.erase(css.begin()+(ele-1));
    }
}

void DataBank::testDataBank()
{
    //Simply for testing purposes while we dont have an interface.

    for(size_t i = 0; i < css.size(); i++)
    {
        cout << css[i].getName() << " " << css[i].getBday() << " " << css[i].getDday()<< " " << css[i].getGender();
    }
}


