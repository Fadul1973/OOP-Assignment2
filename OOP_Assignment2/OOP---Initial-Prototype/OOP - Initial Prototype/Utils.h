#pragma once

#include <string>
#include <iostream>
#include "ListT.h"
#include "Game.h"
#include <stdlib.h>

using namespace std;

class Utils
{
public:
    static string GetLineFromUser();
    static char GetCharFromUser();
    static bool StartsWith(string fullText, string searchText);
    static bool RangeWithin(string range, int gameCost);
    static string FormatCredit(int credit);
    static int NumberOFPages(List<Game*>& games);
    static string GetStringFromInt(int number);
    static string ToUpperVersionA(string text);
    static string ToUpperVersionB(string text);
    static string FormatPlayTime(int minutes);
    static int RandomNumberWithinRange();
};