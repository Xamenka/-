#include <iostream>
#include <ctime>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

Date today() {
    time_t t = time(NULL);
    tm tl = *localtime(&t);
    
    Date currentDate;
    currentDate.year = tl.tm_year + 1900;
    currentDate.month = tl.tm_mon + 1;
    currentDate.day = tl.tm_mday;
    cout << tl.tm_year << " ";     // чому саме 1900
    return currentDate;
}

int daysBetween(Date d1, Date d2) {
    tm time1 = {0, 0, 0, d1.day, d1.month - 1, d1.year - 1900};
    tm time2 = {0, 0, 0, d2.day, d2.month - 1, d2.year - 1900};
    
    time_t timeStamp1 = mktime(&time1);
    time_t timeStamp2 = mktime(&time2);
    
    return difftime(timeStamp2, timeStamp1) / (60 * 60 * 24);
}

int main() {
    Date birthDate = {2005, 10, 6}; 
    Date currentDate = today();
    
    int daysPassed = daysBetween(birthDate, currentDate);
    cout << "Number of days since birth: " << daysPassed << endl;
    
    return 0;
}
