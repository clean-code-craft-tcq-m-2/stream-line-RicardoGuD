#pragma once

#include <fstream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

pair<int,int> getBattMeasurenmentPair(istringstream measurenments);
vector<pair<int,int>> obtainBatteryMeasurenments(vector<string> batteryReadings);
vector<string> obtainReadings(string readingsPath);
string formatBatteryData(pair<int, int> measurenmets, int measurenmetIndex);
void sendData(vector<pair<int,int>> baterryMeasurenmets);