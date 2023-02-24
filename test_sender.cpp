#include "test_sender.h"


void test_gettingReadings(){
    std::cout <<"[test_gettingReadings]--------------TEST STARTED--------------\n";
    std::cout <<"[test_gettingReadings]-----inputMeasurenments\n";

    const string READINGPATH = "TestMeasurenments.csv";

    vector<string>  expectedOutput =  {"10,2","20,3","99,10"};
    vector<string> actualOutput   =  obtainReadings(READINGPATH);
    assert(expectedOutput      == actualOutput);

    std::cout <<"[test_gettingReadings]--------------TEST OK--------------\n";
}

void test_gettingMeasurenments(){
 std::cout <<"[test_gettingMeasurenments]--------------TEST STARTED--------------\n";
  std::cout <<"[test_gettingMeasurenments]-----validValues\n";

    vector<string> readingsTest={"10,1", "15,2", "50,6"};
    std::vector<std::pair<int,int>> expectedOutput = {{10,1},{15,2},{50,6}};
    vector<pair<int,int>> actualOutput   =  obtainBatteryMeasurenments(readingsTest);
    assert(expectedOutput      == actualOutput);

 std::cout <<"[test_gettingMeasurenments]-----InvalidValues\n";

    vector<string> readingsTest1={"-10,-1", "101,16"};
    expectedOutput = {{-10,-1},{101,16}};
    actualOutput   =  obtainBatteryMeasurenments(readingsTest1);
    assert(expectedOutput      == actualOutput);

    std::cout <<"[test_gettingMeasurenments]--------------TEST OK--------------\n";
}
void test_outputFormat(){
 std::cout <<"[test_outputFormat]--------------TEST STARTED--------------\n";
 std::cout <<"[test_outputFormat]-----MaxValues\n";

    pair<int,int> batteryMeasurenmentsTest = make_pair(100,15);
    int measurenmentIndex = 50;
    std::string expectedOutput =  "[Measurenment Number: Battery Charge, Current] : [50: 100,15]";
    std::string actualOutput   =  formatBatteryData(batteryMeasurenmentsTest, measurenmentIndex);
    assert(expectedOutput      == actualOutput);

 std::cout <<"[test_outputFormat]-----MinValues\n";

    pair<int,int> batteryMeasurenmentsTest1 = make_pair(0,1);
    int measurenmentIndex1 = 1;
    expectedOutput =  "[Measurenment Number: Battery Charge, Current] : [1: 0,1]";
    actualOutput   =  formatBatteryData(batteryMeasurenmentsTest1, measurenmentIndex1);
    assert(expectedOutput      == actualOutput);

    std::cout <<"[test_outputFormat]--------------TEST OK--------------\n";
}

void runTests(){
    test_gettingReadings();
    test_gettingMeasurenments();
    test_outputFormat();
}