//
// Created by svalenti on 12/31/2021.
//


//// Find The Longest Palindrome In A String
////        October 15, 2010

/// Greplin issued a programming challenge recently that required programmers to solve three problems;
/// when completed, Greplin issued an invitation to send them a resume. The first problem required the programmer
/// to find the longest palindrome in the following 1169-character string:

#include <iostream>
#include <cctype>
#include <string>

using Str = std::string;

Str sentence{Str("Fourscoreandsevenyearsagoourfaathersbroughtforthonthisconta")+
        Str("inentanewnationconceivedinzLibertyanddedicatedtotheproposit")+
        Str("ionthatallmenarecreatedequalNowweareengagedinagreahtcivilwa")+
        Str("rtestingwhetherthatnaptionoranynartionsoconceivedandsodedic")+
        Str("atedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWeh")+
        Str("avecometodedicpateaportionofthatfieldasafinalrestingplacefo")+
        Str("rthosewhoheregavetheirlivesthatthatnationmightliveItisaltog")+
        Str("etherfangandproperthatweshoulddothisButinalargersensewecann")+
        Str("otdedicatewecannotconsecratewecannothallowthisgroundThebrav")+
        Str("elmenlivinganddeadwhostruggledherehaveconsecrateditfarabove")+
        Str("ourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorl")+
        Str("ongrememberwhatwesayherebutitcanneverforgetwhattheydidhereI")+
        Str("tisforusthelivingrathertobededicatedheretotheulnfinishedwor")+
        Str("kwhichtheywhofoughtherehavethusfarsonoblyadvancedItisrather")+
        Str("forustobeherededicatedtothegreattdafskremainingbeforeusthat")+
        Str("fromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwh")+
        Str("ichtheygavethelastpfullmeasureofdevotionthatweherehighlyres")+
        Str("olvethatthesedeadshallnothavediedinvainthatthisnationunsder")+
        Str("Godshallhaveanewbirthoffreedomandthatgovernmentofthepeopleb")+
        Str("ythepeopleforthepeopleshallnotperishfromtheearth")};

int main()
{
    std::cout << sentence.size() << '\n';

    for (char& c: sentence)
        c = static_cast<char>(std::tolower(c));

    int nr_even_palindromes = 0;
    int nr_odd_palindromes = 0;
    int palindrome_size_control = 2;
    int largest_odd_palindrome_index = 0;
    int largest_even_palindrome_index = 0;

    for (int ix = palindrome_size_control; ix<sentence.size()-palindrome_size_control; ++ix)
    {
        bool matching = true;
        for (int jx = 0; jx<palindrome_size_control; ++jx)
            if (sentence[ix-jx-1]!=sentence[ix+jx+1])
            {
                matching = false;
                break;
            }
        if (matching)
        {
            ++nr_odd_palindromes;
            largest_odd_palindrome_index = ix;
        }
    }

    for (int ix = palindrome_size_control-1; ix<sentence.size()-palindrome_size_control; ++ix)
    {
        bool matching = true;
        for (int jx = 0; jx<palindrome_size_control; ++jx)
            if (sentence[ix-jx]!=sentence[ix+jx+1])
            {
                matching = false;
                break;
            }

        if (matching)
        {
            ++nr_even_palindromes;
            largest_even_palindrome_index = ix;
        }
    }

    std::cout << "odd palindromes=" << nr_odd_palindromes <<
              "   even palindromes=" << nr_even_palindromes << '\n';
    std::cout << "Largest palindrome index = " << largest_odd_palindrome_index << '\n';
    std::cout << "Largest even palindrome index = " << largest_even_palindrome_index << '\n';
}
