#include "Utils.h"
#include "time.h"


string Utils::GetLineFromUser()
{
    string input;
    getline(cin, input);
    return input;
}

char Utils::GetCharFromUser()
{
    return toupper(GetLineFromUser()[0]);
}

bool Utils::StartsWith(string fullText, string searchText)
{
    if (fullText.find(searchText) != string::npos)
    {
        return true;
    }
    return false;
}

bool Utils::RangeWithin(string range, int gameCost)
{
    string minRange = "";
    string maxRange = "";
    for (int i = 0; i < range.length(); i++)
    {
        if (range[i] == '-')
        {
            for (int j = 0; j < i; j++)
            {
                minRange += range[j];
            }

            for (int k = i + 1; k < range.length(); k++)
            {
                maxRange += range[k];
            }

            i += range.length();
        }
    }
    int min, max;

    try {
        min = stoi(minRange);
        max = stoi(maxRange);
    }
    catch (exception)
    {
        return false;
    }

    if ((gameCost / 100.0f) >= min && (gameCost / 100.0f) <= max) { return true; }

    return false;
}

string Utils::ToUpperVersionA(string text)
{
    string returnString = "";

    for (int i = 0; i < text.length(); i++)
    {
        returnString += toupper(text[i]);
    }

    return returnString;
}

string Utils::ToUpperVersionB(string text)
{
    if (text.length() == 0) return "";
    return (char)toupper(text[0]) + ToUpperVersionB(text.substr(1));
}


string Utils::FormatCredit(int credit)
{
    string returnString = "";
    double creditInPounds = credit / 100.0f;
    string stringVersion = to_string(creditInPounds);
    for (int i = 0; i < stringVersion.length(); i++)
    {
        returnString += stringVersion[i];
        if (stringVersion[i] == '.')
        {
            for (int j = i + 1; j <= (i + 2); j++)
            {
                returnString += stringVersion[j];
            }
            i += stringVersion.length();
        }
    }
    return returnString;
}

int Utils::NumberOFPages(List<Game*>& games)
{
    int noOfPages = 0;

    if (games.isEmpty()) { return noOfPages; }

    noOfPages++;

    for (int i = 1; i <= games.length(); i++)
    {
        if (i % 6 == 0) { noOfPages++; }
    }

    return noOfPages;
}

string Utils::GetStringFromInt(int number)
{
    string numberString = to_string(number);

    return numberString;
}

string Utils::FormatPlayTime(int minutes)
{
    string returnFormat = "";
    if (minutes < 60)
    {

        returnFormat = GetStringFromInt(minutes);
        returnFormat += " minutes";
    }
    else if (minutes > 59 && minutes < 300)
    {
        double minutesInHoursWithDecimal = minutes / 60.0f;
        string stringVersion = to_string(minutesInHoursWithDecimal);
        for (int i = 0; i < stringVersion.length(); i++)
        {
            returnFormat += stringVersion[i];
            if (stringVersion[i] == '.')
            {
                for (int j = i + 1; j <= (i + 2); j++)
                {
                    returnFormat += stringVersion[j];
                }
                i += stringVersion.length();
            }
        }

        returnFormat += "hrs";
    }
    else
    {
        double minutesInHoursWithDecimal = minutes / 60.0f;
        int roundedHours = (int)round(minutesInHoursWithDecimal);
        returnFormat = GetStringFromInt(roundedHours);
        returnFormat += "hrs";
    }

    return returnFormat;
}

int Utils::RandomNumberWithinRange()
{
    srand(time(NULL));
    int randomGamePlayTime = rand() % 60 + 1;
    return randomGamePlayTime;
}
