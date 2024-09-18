#include<iostream>
#include<sstream>

int main()
{
    std::string inputString;
    std::cout<<"\nEnter a mathematical expression: ";
    std::cin>>inputString;
    std::stringstream temp_stream(inputString);

    double a;
    double b;   
    char operation;    

    temp_stream>> a >> operation >> b;
    
    if(operation == '+')
    {
        std::cout<<"\nExpression: " << a <<" + "<< b << " = "<< a + b; 
    }
    else if(operation == '-')
    {
        std::cout<<"\nExpression: " << a <<" - "<< b << " = "<< a - b;
    }
    else if(operation == '*')
    {
        std::cout<<"\nExpression: " << a <<" * "<< b << " = "<< a * b;
    }
    else if(operation == '/' && b != 0)
    {
        std::cout<<"\nExpression: " << a <<" / "<< b << " = "<< a / b;
    }
    else
    {
        std::cout<<"\nIncorrect input.";
    }    
}