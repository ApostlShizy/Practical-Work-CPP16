#include<iostream>

enum note {DO = 1,RE = 2,MI = 4, FA = 8, SOL = 16,LA = 32,SI = 64};

bool check_str (std::string chord)
{
    for (int i = 0;i < chord.length();++i)
    {
        if (chord[i] < '1' || chord[i] > '7')
        {
            std::cout<<"\nWrong input try again"<<std::endl;
            return true;
        }
    }
    return false;
}

int main ()
{
    std::string chord;
    int notes = 0;
    do {
        std::cout<<"\nEnter chord (1-7): ";
        std::cin>>chord;
    } while (check_str(chord));

    for (int i = 0;i < chord.size();++i)
    {
        notes |= (1 << chord[i] - '0') >> 1;
    }

    std::cout<<"Chord is: ";

    if (notes & DO) {
        std::cout<<"DO ";
    }
    if (notes & RE) {
        std::cout<<"RE ";
    }
    if (notes & MI) {
        std::cout<<"MI ";
    }
    if (notes & FA) {
        std::cout<<"FA ";
    }
    if (notes & SOL) {
        std::cout<<"SOL ";
    }
    if (notes & LA) {
        std::cout<<"LA ";
    }
    if (notes & SI) {
        std::cout<<"SI ";
    }
}