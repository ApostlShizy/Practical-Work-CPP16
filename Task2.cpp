#include<iostream>
#include<string>

int main()
{
    std::string number;
    std::string buffer;
    std::cout<<"\nEnter actual number part: ";
    std::cin>> buffer;
    number += buffer + '.';    
    std::cout<<"Enter real number part: ";
    std::cin>>buffer;
    number += buffer;

    for(int i = 0;i < number.size();++i)
    {
        if(number[i] != '.' && (number[i] < '0'|| number[i] > '9'))
        {
            std::cerr<<"Wrong input enter number !";
            return 1;
        }
    }
    
    std::cout<<"\nNumber is: "<<std::stod(number);
}