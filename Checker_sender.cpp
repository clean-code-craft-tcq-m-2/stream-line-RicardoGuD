#include "test_sender.h"

using namespace std;
const string READINGPATH = "batteryReadings.csv";
int main()
{
runTests();
vector<string> readings = obtainReadings(READINGPATH);
vector<pair<int,int>> measurenments = obtainBatteryMeasurenments(readings);
sendData(measurenments);

return 0;
}