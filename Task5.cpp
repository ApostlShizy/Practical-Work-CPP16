#include<iostream>
#include<string>
#include<sstream>

enum switches { LIGTHS_INSIDE = 1, LIGHTS_OUTSIDE = 2, HEATERS = 4, WATER_PIPE_HEATING = 8, CONDITIONER = 16 };

bool check(const int& temperature_inside, const int& temperature_outside, const std::string& movement, const std::string& lights)
{
    if (temperature_inside < -100 || temperature_inside > 100 || temperature_outside < -100 || temperature_outside > 100)
    {
        std::cout << "\nIt looks like the sensors have failed, try again.";
        return true;
    }
    if ((movement != "yes" && movement != "no") || (lights != "on" && lights != "off"))
    {
        std::cout << "\nIncorect answer try again.";
        return true;
    }
    return false;
}

void display_time(const int& hour)
{
    char time[] = "00";
    time[1] |= (hour % 10);
    time[0] |= (hour / 10);
    std::cout << "\nTime: " << time[0] << time[1] << ":00";
}

void display_state(int& state, const int& temperature_inside, const int& temperature_outside, const std::string& movement, const std::string& lights, const int& hour)
{
    if (temperature_inside > 30 && !(state & switches::CONDITIONER) && lights == "on")
    {
        std::cout << "\nConditioner ON !" << std::endl;
        state |= switches::CONDITIONER;
    }
    else if ((temperature_inside < 25 || lights == "off") && state & switches::CONDITIONER)
    {
        std::cout << "\nConditioner OFF !" << std::endl;
        state &= (~switches::CONDITIONER);
    }
    if (temperature_outside < 0 && !(state & switches::WATER_PIPE_HEATING) && lights == "on")
    {
        std::cout << "\nWater pipe heating ON !" << std::endl;
        state |= switches::WATER_PIPE_HEATING;
    }
    else if ((temperature_outside > 5 || lights == "off") && state & switches::WATER_PIPE_HEATING)
    {
        std::cout << "\nWater pipe heatin OFF !" << std::endl;
        state &= (~switches::WATER_PIPE_HEATING);
    }
    if (temperature_inside < 22 && !(state & switches::HEATERS) && lights == "on")
    {
        std::cout << "\nHeates ON !" << std::endl;
        state |= switches::HEATERS;
    }
    else if ((temperature_inside >= 25 || lights == "off") && state & switches::HEATERS)
    {
        std::cout << "\nHeaters OFF !" << std::endl;
        state &= (~switches::HEATERS);
    }
    if (movement == "yes" && (hour > 16 || hour < 5) && !(state & switches::LIGHTS_OUTSIDE) && lights == "on")
    {
        std::cout << "\nLighths outside ON !" << std::endl;
        state |= switches::LIGHTS_OUTSIDE;
    }
    else if (state & switches::LIGHTS_OUTSIDE && ((hour >= 5 && hour <= 16) || movement == "no" || lights == "off"))
    {
        std::cout << "\nLights outside OFF !" << std::endl;
        state &= (~switches::LIGHTS_OUTSIDE);
    }
}

int main()
{
    int lights_color = 5000;
    int day = 0;
    int state = 0;
    int hour = 0;
    int temperature_inside = 0;
    int temperature_outside = 0;
    std::string movement;
    std::string lights;

    while (day < 2)
    {
        std::cout<<'\n' + std::string(30,'-') +'\n';
        display_time(hour);
        std::cout << std::endl;
        do
        {
            std::cout << "\nEnter separeted by space: temperature inside, temperatur outside, movement (yes/no),lights (on/off).\nInput: ";
            std::string buffer;
            std::getline(std::cin, buffer);
            std::stringstream temp_stream(buffer);
            temp_stream >> temperature_inside >> temperature_outside >> movement >> lights;
        } while (check(temperature_inside, temperature_outside, movement, lights));
        std::cout << "\nColor temperature: " << lights_color<<"K"<<std::endl;
        if (hour >= 16 && hour < 20 && lights == "on")
        {            
            lights_color -= 575;
        }
        display_state(state, temperature_inside, temperature_outside, movement, lights, hour);
        hour++;
        if (hour == 24)
        {
            hour = 0;
            day++;
            lights_color = 5000;
        }
    }
}