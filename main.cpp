#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include "main.h"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <string>
using namespace std;
using namespace boost;
//using namespace boost::filesystem;
//functions arent allowed in struct in c
struct version{
    int ver = 1.0;

};



struct stdp{
 void stdForm(string message){
 std::cout << message << std::endl;
 };



};


struct boostform{
 struct stdp stdPP;
 void workerFunc(){
    boost::posix_time::seconds workTime(3);
    stdPP.stdForm("hi");
    boost::this_thread::sleep(workTime);
    stdPP.stdForm("worker: finished");
 };




};
struct cases{
 struct stdp stdPP;
 void upCase(string str){
  to_upper(str);
  stdPP.stdForm(str);
 };




};










void workerFunc()
{
    boost::posix_time::seconds workTime(3);

    std::cout << "Worker: running" << std::endl;

    // Pretend to do something useful...
    boost::this_thread::sleep(workTime);

    std::cout << "Worker: finished" << std::endl;
}

int main(int argc, char* argv[])
{
    string str1("hello");
    struct cases c;
    c.upCase(str1);
    //to_upper(str1);
    trim(str1);

    struct boostform boostForm;
    boostForm.workerFunc();


    std::cout << "main: startup" << std::endl;

    boost::thread workerThread(workerFunc);

    std::cout << "main: waiting for thread" << std::endl;

    workerThread.join();

    std::cout << "main: done" << std::endl;

    return 0;
}
