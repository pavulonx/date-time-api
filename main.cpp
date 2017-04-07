#include <iostream>
#include "DateTime.h"

using namespace std;

int main() {
    Date d(2012, 11, 11);
    d.print();
    d.getNewDateFrom(-1);
    std::cout << d.getNewDateFrom(-1).getNewDateFrom(1).str() << std::endl;
    d.print();
    std::cout << std::endl << std::endl;
    Date x (2016,1,5);
    std::cout << std::endl << x.getRepresentationInDays() << std::endl;
    std::cout <<d.str()<<"  "<< x.str();
    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;

    TimeStamp ts(2013,12,31,23,59);
    ts.print();
    ((Date)ts).print();
    ts.getNewTimeStampFrom(55).print();
    ts.getNewTimeStampFrom(56).print();
    ts.getNewTimeStampFrom(1).print();
    TimeStamp y = ts.getNewTimeStampFrom(0);
    std::cout << std::endl << (ts <= y)<< std::endl;
    std::cout <<ts.str()<<"  "<< y.str();

    std::cout << std::endl << ts.toString("ABCD EFGH KLMN MM x yyyy") << std::endl;

    return 0;
}
