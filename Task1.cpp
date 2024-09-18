#include<iostream>
#include<string>

int main()
{
    float speed_delta = 0.f;
    float buffer = 0.f;
    char speed_str[1];

    do
    {
        std::cout<<"\nEnter speed delta: ";
        std::cin>>speed_delta;
        if(!std::cin)
        {
            std::cerr<<"\nWrong input ! Enter a number !";
            return 1;
        }
        buffer += speed_delta;
        sprintf(speed_str,"%.1f",buffer);
        std::cout<<"Speed is: "<<speed_str;

    }while(std::stof(speed_str) > 0.01f);
}