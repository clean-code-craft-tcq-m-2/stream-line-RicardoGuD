#include "sender.h"
const int MAXCURRENTVALUE = 15;
const int MAXCHARGEVALUE = 100;
const int MINCURRENTVALUE = 0;
const int MINCHARGEVALUE = 0;

vector<string> obtainReadings(string readingsPath)
{
    string line;
    ifstream readingsInput;
    vector<string> battReadings;
    readingsInput.open(readingsPath, ios::in);

    while(getline(readingsInput, line))
    {
        battReadings.push_back(line);
    }

    readingsInput.close();
    return battReadings;
}

pair<int,int> getBattMeasurenmentPair(istringstream measurenments)
{
    string  battMeasurenment;
    pair<int,int> measurenmentPair;
    array<int,2> batteryparameters;
    int parameterIndex = 0;

     while (measurenments.good())
    {
        getline(measurenments, battMeasurenment, ',');
        batteryparameters[parameterIndex] = stoi(battMeasurenment);
        parameterIndex++;
    }
    measurenmentPair = make_pair(batteryparameters[0], batteryparameters[1]);
    return  measurenmentPair;
}

vector<pair<int,int>> obtainBatteryMeasurenments(vector<string> batteryReadings)
{
    vector<pair<int,int>> batteryMeasurenments;
    for(string batteryReading: batteryReadings)
    {
        pair<int,int> measurenmentPair = getBattMeasurenmentPair(static_cast<istringstream>(batteryReading));
        batteryMeasurenments.push_back(measurenmentPair);
    }
    return batteryMeasurenments;
}

string formatBatteryData(pair<int, int> measurenmets, int measurenmetIndex)
{
    string index = to_string(measurenmetIndex);
    string battCharge = to_string(measurenmets.first);
    string current = to_string(measurenmets.second);

    string headerString = "[Measurenment Number: Battery Charge, Current] : ";
    string measurenmentsString = "[" + index + ": " + battCharge + "," + current + "]";
    return   headerString + measurenmentsString;
}


void sendData(vector<pair<int,int>> batteryMeasurenments)
{
    const int LASTMEASURENMENT = batteryMeasurenments.size();

    for(int measurementIndex=0; measurementIndex<LASTMEASURENMENT; measurementIndex++)
    {
       cout <<  formatBatteryData(batteryMeasurenments.at(measurementIndex), measurementIndex+1)<<endl;
    }
}