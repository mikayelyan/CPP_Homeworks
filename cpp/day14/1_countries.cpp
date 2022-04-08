#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

enum PhoneCodes
{
    Afghanistan = 93,
    Albania = 355,
    Algeria = 213,
    Andorra = 376,
    Angola = 244,
    Argentina = 54,
    Armenia = 374,
    Australia = 61,
    Austria = 43,
    Azerbaijan = 994,
    Bahamas = 1242,
    Bahrain = 973,
    Bangladesh = 880,
    Barbados = 1246,
    Belarus = 375,
    Belgium = 32,
    Belize = 501,
    Benin = 229,
    Bhutan = 975,
    Bolivia = 591,
    Botswana = 267,
    Brazil = 55,
    Brunei = 673,
    Bulgaria = 359,
    Burundi = 257,
    Cambodia = 855,
    Cameroon = 237,
    Canada = 1,
    Chad = 235,
    Chile = 56,
    China = 86,
    Colombia = 57,
    Comoros = 269,
    Croatia = 385,
    Cuba = 53,
    Cyprus = 357,
    Denmark = 45,
    Djibouti = 253,
    Dominica = 1767,
    Ecuador = 593,
    Egypt = 20,
    Eritrea = 291,
    Estonia = 372,
    Ethiopia = 251,
    Fiji = 679,
    Finland = 358,
    France = 33,
    Gabon = 241,
    Gambia = 220,
    Georgia = 995,
    Germany = 49,
    Ghana = 233,
    Greece = 30,
    Grenada = 1473,
    Guatemala = 502,
    Guinea = 224,
    GuineaBissau = 245,
    Guyana = 592,
    Haiti = 509,
    Honduras = 504,
    Hungary = 36,
    Iceland = 354,
    India = 91,
    Indonesia = 62,
    Iran = 98,
    Iraq = 964,
    Ireland = 353,
    Israel = 972,
    Italy = 39,
    Jamaica = 1876,
    Japan = 81,
    Jordan = 962,
    Kazakhstan = 7,
    Kenya = 254,
    Kiribati = 686,
    Kosovo = 383,
    Kuwait = 965,
    Kyrgyzstan = 996,
    Laos = 856,
    Latvia = 371,
    Lebanon = 961,
    Lesotho = 266,
    Liberia = 231,
    Libya = 218,
    Liechtenstein = 423,
    Lithuania = 370,
    Luxembourg = 352,
    Madagascar = 261,
    Malawi = 265,
    Malaysia = 60,
    Maldives = 960,
    Mali = 223,
    Malta = 356,
    Mauritania = 222,
    Mauritius = 230,
    Mexico = 52,
    Micronesia = 691,
    Moldova = 373,
    Monaco = 377,
    Mongolia = 976,
    Montenegro = 382,
    Morocco = 212,
    Mozambique = 258,
    Namibia = 264,
    Nauru = 674,
    Nepal = 977,
    Netherlands = 31,
    Nicaragua = 505,
    Niger = 227,
    Nigeria = 234,
    Norway = 47,
    Oman = 968,
    Pakistan = 92,
    Palau = 680,
    Palestine = 970,
    Panama = 507,
    Paraguay = 595,
    Peru = 51,
    Philippines = 63,
    Poland = 48,
    Portugal = 351,
    Qatar = 974,
    Romania = 40,
    Russia = 7,
    Rwanda = 250,
    Samoa = 685,
    Senegal = 221,
    Serbia = 381,
    Seychelles = 248,
    Singapore = 65,
    Slovakia = 421,
    Slovenia = 386,
    Somalia = 252,
    Spain = 34,
    Sudan = 249,
    Suriname = 597,
    Sweden = 46,
    Switzerland = 41,
    Syria = 963,
    Taiwan = 886,
    Tajikistan = 992,
    Tanzania = 255,
    Thailand = 66,
    Togo = 228,
    Tonga = 676,
    Tunisia = 216,
    Turkey = 90,
    Turkmenistan = 993,
    Tuvalu = 688,
    Uganda = 256,
    Ukraine = 380,
    Uruguay = 598,
    Uzbekistan = 998,
    Vanuatu = 678,
    Vatican = 379,
    Venezuela = 58,
    Vietnam = 84,
    Yemen = 967,
    Zambia = 260,
    Zimbabwe = 263,
};
struct Country
{
    string country;
    string capital;
    string domain;
    int population{};
    int area{};
    long gdp{};
    int phoneCode{};
};

Country getCountry(string, string, Country *);
string getOperationMode();
string getSearchMode();
string getSearchParameter(string);
void initializeCountries(Country *data);
void printCountry(Country);
void compare(Country, Country);
int getPhoneCode(int);

int main()
{
    string operationMode = getOperationMode();
    if (operationMode == "exit")
        return 0;
    else if (operationMode == "search")
    {

        string searchMode = getSearchMode();
        string searchParameter = getSearchParameter(searchMode);
        Country data[160];
        initializeCountries(data);
        Country result = getCountry(searchMode, searchParameter, data);
        printCountry(result);
    }
    else if (operationMode == "compare")
    {
        string firstCountry;
        string secondCountry;
        cout << "Input first country: ";
        cin >> firstCountry;
        cout << "Input second country: ";
        cin >> secondCountry;
        Country data[160];
        initializeCountries(data);
        transform(firstCountry.begin(), firstCountry.end(), firstCountry.begin(), ::tolower);
        transform(secondCountry.begin(), secondCountry.end(), secondCountry.begin(), ::tolower);
        Country first = getCountry("countryname", firstCountry, data);
        Country second = getCountry("countryname", secondCountry, data);
        compare(first, second);
    }
    return 0;
}

string getOperationMode()
{
    char searchMode;
    while (searchMode != '1' && searchMode != '2' && searchMode != '3')
    {
        cout << "Please choose operating mode: " << endl;
        cout << "1.Search " << endl;
        cout << "2.Compare" << endl;
        cout << "3.Exit" << endl;
        cout << "Please choose operating mode: " << endl;
        cin >> searchMode;
        if (searchMode != '1' && searchMode != '2' && searchMode != '3')
        {
            cout << "Wrong input! Please enter 1, 2 or 3" << endl;
        }
        else if (searchMode == '1')
        {
            return "search";
        }
        else if (searchMode == '2')
        {
            return "compare";
        }
        else if (searchMode == '3')
        {
            return "exit";
        }
    }
    return "";
}

string getSearchMode()
{
    string searchMode;
    while (searchMode != "capital" && searchMode != "countryName" && searchMode != "domain")
    {
        cout << "Input search mode (countryName / capital / domain): ";
        cin >> searchMode;
        transform(searchMode.begin(), searchMode.end(), searchMode.begin(), ::tolower);
    }
    return searchMode;
}

string getSearchParameter(string searchMode)
{
    string searchParameter;
    cout << "Input " << searchMode << ": ";
    cin >> searchParameter;
    transform(searchParameter.begin(), searchParameter.end(), searchParameter.begin(), ::tolower);
    return searchParameter;
}

Country getCountry(string searchMode, string searchParameter, Country *data)
{
    for (int i{}; i < 160; ++i)
    {
        if (searchMode == "capital")
        {
            string capital = data[i].capital;
            transform(capital.begin(), capital.end(), capital.begin(), ::tolower);
            if (capital == searchParameter)
            {
                return data[i];
            }
        }
        else if (searchMode == "countryname")
        {
            string country = data[i].country;
            transform(country.begin(), country.end(), country.begin(), ::tolower);
            if (country == searchParameter)
            {
                return data[i];
            }
        }
        else if (searchMode == "domain")
        {
            string domain = data[i].domain;
            transform(domain.begin(), domain.end(), domain.begin(), ::tolower);
            if (domain == searchParameter)
            {
                return data[i];
            }
        }
    }
    return Country{};
}

void initializeCountries(Country *data)
{
    ifstream countries;
    countries.open("1_data.txt");
    if (countries)
    {
        int index{-1};
        while (!countries.eof())
        {
            string country;
            getline(countries, country);
            if (index != -1)
            {
                istringstream countryData{country};
                if (countryData)
                {
                    while (!countryData.eof())
                    {
                        string countryName{};
                        getline(countryData, countryName, ',');
                        string capital{};
                        getline(countryData, capital, ',');
                        string domain{};
                        getline(countryData, domain, ',');
                        string populationString{};
                        getline(countryData, populationString, ',');
                        string areaString{};
                        getline(countryData, areaString, ',');
                        string gdpString{};
                        getline(countryData, gdpString, ',');
                        countryData >> countryName >> capital >> domain >> populationString >> areaString >> gdpString;
                        int population = stoi(populationString);
                        int area = stoi(areaString);
                        long gdp = stol(gdpString);
                        int phoneCode = getPhoneCode(index);
                        data[index] = Country{countryName, capital, domain, population, area, gdp, phoneCode};
                    }
                }
            }
            index++;
        }
    }
}

void printCountry(Country country)
{
    cout << "Output: Country - " << country.country << endl;
    cout << setw(18) << right << "Capital - " << country.capital << endl;
    cout << setw(17) << right << "Domain - " << country.domain << endl;
    cout << setw(21) << right << "Population - " << country.population << endl;
    cout << setw(15) << right << "Area - " << country.area << endl;
    cout << setw(14) << right << "GDP - " << country.gdp << endl;
    cout << setw(21) << right << "Phone Code - " << country.phoneCode << endl;
}

void compare(Country first, Country second)
{

    cout << setfill('=') << setw(60) << '=' << right << setfill(' ') << endl;
    cout << setw(19) << right << "|" << setw(18) << left << first.country << "|" << second.country << endl;
    cout << setfill('=') << setw(60) << '=' << right << setfill(' ') << endl;
    cout << setw(18) << left << "Capital "
         << "|" << setw(18) << first.capital << "|" << second.capital << endl;
    cout << setw(18) << left << "Domain "
         << "|" << setw(18) << first.domain << "|" << second.domain << endl;
    cout << setw(18) << left << "Population "
         << "|" << setw(18) << first.population << (first.population > second.population ? ">" : "<") << second.population << endl;
    cout << setw(18) << left << "Area "
         << "|" << setw(18) << first.area << (first.area > second.area ? ">" : "<") << second.area << endl;
    cout << setw(18) << left << "GDP "
         << "|" << setw(18) << first.gdp << (first.gdp > second.gdp ? ">" : "<") << second.gdp << endl;
    cout << setw(18) << left << "Phone Code "
         << "|" << setw(18) << first.phoneCode << "|" << second.phoneCode << endl;
}

int getPhoneCode(int index)
{
    switch (index)
    {
    case 0:
        return PhoneCodes(Afghanistan);
        break;
    case 1:
        return PhoneCodes(Albania);
        break;
    case 2:
        return PhoneCodes(Algeria);
        break;
    case 3:
        return PhoneCodes(Andorra);
        break;
    case 4:
        return PhoneCodes(Angola);
        break;
    case 5:
        return PhoneCodes(Argentina);
        break;
    case 6:
        return PhoneCodes(Armenia);
        break;
    case 7:
        return PhoneCodes(Australia);
        break;
    case 8:
        return PhoneCodes(Austria);
        break;
    case 9:
        return PhoneCodes(Azerbaijan);
        break;
    case 10:
        return PhoneCodes(Bahamas);
        break;
    case 11:
        return PhoneCodes(Bahrain);
        break;
    case 12:
        return PhoneCodes(Bangladesh);
        break;
    case 13:
        return PhoneCodes(Barbados);
        break;
    case 14:
        return PhoneCodes(Belarus);
        break;
    case 15:
        return PhoneCodes(Belgium);
        break;
    case 16:
        return PhoneCodes(Belize);
        break;
    case 17:
        return PhoneCodes(Benin);
        break;
    case 18:
        return PhoneCodes(Bhutan);
        break;
    case 19:
        return PhoneCodes(Bolivia);
        break;
    case 20:
        return PhoneCodes(Botswana);
        break;
    case 21:
        return PhoneCodes(Brazil);
        break;
    case 22:
        return PhoneCodes(Brunei);
        break;
    case 23:
        return PhoneCodes(Bulgaria);
        break;
    case 24:
        return PhoneCodes(Burundi);
        break;
    case 25:
        return PhoneCodes(Cambodia);
        break;
    case 26:
        return PhoneCodes(Cameroon);
        break;
    case 27:
        return PhoneCodes(Canada);
        break;
    case 28:
        return PhoneCodes(Chad);
        break;
    case 29:
        return PhoneCodes(Chile);
        break;
    case 30:
        return PhoneCodes(China);
        break;
    case 31:
        return PhoneCodes(Colombia);
        break;
    case 32:
        return PhoneCodes(Comoros);
        break;
    case 33:
        return PhoneCodes(Croatia);
        break;
    case 34:
        return PhoneCodes(Cuba);
        break;
    case 35:
        return PhoneCodes(Cyprus);
        break;
    case 36:
        return PhoneCodes(Denmark);
        break;
    case 37:
        return PhoneCodes(Djibouti);
        break;
    case 38:
        return PhoneCodes(Dominica);
        break;
    case 39:
        return PhoneCodes(Ecuador);
        break;
    case 40:
        return PhoneCodes(Egypt);
        break;
    case 41:
        return PhoneCodes(Eritrea);
        break;
    case 42:
        return PhoneCodes(Estonia);
        break;
    case 43:
        return PhoneCodes(Ethiopia);
        break;
    case 44:
        return PhoneCodes(Fiji);
        break;
    case 45:
        return PhoneCodes(Finland);
        break;
    case 46:
        return PhoneCodes(France);
        break;
    case 47:
        return PhoneCodes(Gabon);
        break;
    case 48:
        return PhoneCodes(Gambia);
        break;
    case 49:
        return PhoneCodes(Georgia);
        break;
    case 50:
        return PhoneCodes(Germany);
        break;
    case 51:
        return PhoneCodes(Ghana);
        break;
    case 52:
        return PhoneCodes(Greece);
        break;
    case 53:
        return PhoneCodes(Grenada);
        break;
    case 54:
        return PhoneCodes(Guatemala);
        break;
    case 55:
        return PhoneCodes(Guinea);
        break;
    case 56:
        return PhoneCodes(GuineaBissau);
        break;
    case 57:
        return PhoneCodes(Guyana);
        break;
    case 58:
        return PhoneCodes(Haiti);
        break;
    case 59:
        return PhoneCodes(Honduras);
        break;
    case 60:
        return PhoneCodes(Hungary);
        break;
    case 61:
        return PhoneCodes(Iceland);
        break;
    case 62:
        return PhoneCodes(India);
        break;
    case 63:
        return PhoneCodes(Indonesia);
        break;
    case 64:
        return PhoneCodes(Iran);
        break;
    case 65:
        return PhoneCodes(Iraq);
        break;
    case 66:
        return PhoneCodes(Ireland);
        break;
    case 67:
        return PhoneCodes(Israel);
        break;
    case 68:
        return PhoneCodes(Italy);
        break;
    case 69:
        return PhoneCodes(Jamaica);
        break;
    case 70:
        return PhoneCodes(Japan);
        break;
    case 71:
        return PhoneCodes(Jordan);
        break;
    case 72:
        return PhoneCodes(Kazakhstan);
        break;
    case 73:
        return PhoneCodes(Kenya);
        break;
    case 74:
        return PhoneCodes(Kiribati);
        break;
    case 75:
        return PhoneCodes(Kosovo);
        break;
    case 76:
        return PhoneCodes(Kuwait);
        break;
    case 77:
        return PhoneCodes(Kyrgyzstan);
        break;
    case 78:
        return PhoneCodes(Laos);
        break;
    case 79:
        return PhoneCodes(Latvia);
        break;
    case 80:
        return PhoneCodes(Lebanon);
        break;
    case 81:
        return PhoneCodes(Lesotho);
        break;
    case 82:
        return PhoneCodes(Liberia);
        break;
    case 83:
        return PhoneCodes(Libya);
        break;
    case 84:
        return PhoneCodes(Liechtenstein);
        break;
    case 85:
        return PhoneCodes(Lithuania);
        break;
    case 86:
        return PhoneCodes(Luxembourg);
        break;
    case 87:
        return PhoneCodes(Madagascar);
        break;
    case 88:
        return PhoneCodes(Malawi);
        break;
    case 89:
        return PhoneCodes(Malaysia);
        break;
    case 90:
        return PhoneCodes(Maldives);
        break;
    case 91:
        return PhoneCodes(Mali);
        break;
    case 92:
        return PhoneCodes(Malta);
        break;
    case 93:
        return PhoneCodes(Mauritania);
        break;
    case 94:
        return PhoneCodes(Mauritius);
        break;
    case 95:
        return PhoneCodes(Mexico);
        break;
    case 96:
        return PhoneCodes(Micronesia);
        break;
    case 97:
        return PhoneCodes(Moldova);
        break;
    case 98:
        return PhoneCodes(Monaco);
        break;
    case 99:
        return PhoneCodes(Mongolia);
        break;
    case 100:
        return PhoneCodes(Montenegro);
        break;
    case 101:
        return PhoneCodes(Morocco);
        break;
    case 102:
        return PhoneCodes(Mozambique);
        break;
    case 103:
        return PhoneCodes(Namibia);
        break;
    case 104:
        return PhoneCodes(Nauru);
        break;
    case 105:
        return PhoneCodes(Nepal);
        break;
    case 106:
        return PhoneCodes(Netherlands);
        break;
    case 107:
        return PhoneCodes(Nicaragua);
        break;
    case 108:
        return PhoneCodes(Niger);
        break;
    case 109:
        return PhoneCodes(Nigeria);
        break;
    case 110:
        return PhoneCodes(Norway);
        break;
    case 111:
        return PhoneCodes(Oman);
        break;
    case 112:
        return PhoneCodes(Pakistan);
        break;
    case 113:
        return PhoneCodes(Palau);
        break;
    case 114:
        return PhoneCodes(Palestine);
        break;
    case 115:
        return PhoneCodes(Panama);
        break;
    case 116:
        return PhoneCodes(Paraguay);
        break;
    case 117:
        return PhoneCodes(Peru);
        break;
    case 118:
        return PhoneCodes(Philippines);
        break;
    case 119:
        return PhoneCodes(Poland);
        break;
    case 120:
        return PhoneCodes(Portugal);
        break;
    case 121:
        return PhoneCodes(Qatar);
        break;
    case 122:
        return PhoneCodes(Romania);
        break;
    case 123:
        return PhoneCodes(Russia);
        break;
    case 124:
        return PhoneCodes(Rwanda);
        break;
    case 125:
        return PhoneCodes(Samoa);
        break;
    case 126:
        return PhoneCodes(Senegal);
        break;
    case 127:
        return PhoneCodes(Serbia);
        break;
    case 128:
        return PhoneCodes(Seychelles);
        break;
    case 129:
        return PhoneCodes(Singapore);
        break;
    case 130:
        return PhoneCodes(Slovakia);
        break;
    case 131:
        return PhoneCodes(Slovenia);
        break;
    case 132:
        return PhoneCodes(Somalia);
        break;
    case 133:
        return PhoneCodes(Spain);
        break;
    case 134:
        return PhoneCodes(Sudan);
        break;
    case 135:
        return PhoneCodes(Suriname);
        break;
    case 136:
        return PhoneCodes(Sweden);
        break;
    case 137:
        return PhoneCodes(Switzerland);
        break;
    case 138:
        return PhoneCodes(Syria);
        break;
    case 139:
        return PhoneCodes(Taiwan);
        break;
    case 140:
        return PhoneCodes(Tajikistan);
        break;
    case 141:
        return PhoneCodes(Tanzania);
        break;
    case 142:
        return PhoneCodes(Thailand);
        break;
    case 143:
        return PhoneCodes(Togo);
        break;
    case 144:
        return PhoneCodes(Tonga);
        break;
    case 145:
        return PhoneCodes(Tunisia);
        break;
    case 146:
        return PhoneCodes(Turkey);
        break;
    case 147:
        return PhoneCodes(Turkmenistan);
        break;
    case 148:
        return PhoneCodes(Tuvalu);
        break;
    case 149:
        return PhoneCodes(Uganda);
        break;
    case 150:
        return PhoneCodes(Ukraine);
        break;
    case 151:
        return PhoneCodes(Uruguay);
        break;
    case 152:
        return PhoneCodes(Uzbekistan);
        break;
    case 153:
        return PhoneCodes(Vanuatu);
        break;
    case 154:
        return PhoneCodes(Vatican);
        break;
    case 155:
        return PhoneCodes(Venezuela);
        break;
    case 156:
        return PhoneCodes(Vietnam);
        break;
    case 157:
        return PhoneCodes(Yemen);
        break;
    case 158:
        return PhoneCodes(Zambia);
        break;
    case 159:
        return PhoneCodes(Zimbabwe);
        break;
    default:
        return 0;
        break;
    }
}
