#include "util.h"
void NowTime(Date* T){
    time_t now;
    time(&now);
    struct tm *t;
    t = gmtime(&now);
    T->year =t->tm_year ;
    T->month =t->tm_mon ;
    T->day =t->tm_mday ;
    T->hour =t->tm_hour ;
    T->second =t->tm_sec ;
}