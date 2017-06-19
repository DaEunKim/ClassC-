//
//  myDate.h
//  DateClass1
//
//  Created by 김다은 on 2017. 5. 31..
//  Copyright © 2017년 김다은. All rights reserved.
//

#ifndef myDate_h
#define myDate_h

#include <iostream>
using namespace std;
class myDate {
public:
    // Constructor (생성자)
    myDate(int year=1582, int month=1, int day=1);
    
    // Accessor functions (접근자)
    int getDayOfMonth() const;
    int getMonth() const;
    int getYear() const;
    
    // Mutator functions (변경자)
    void setDayOfMonth(int day);
    void setMonth(int month);
    void setYear(int year);
    void setDate(int year, int month, int day);
    
    // utility functions
    bool isLeapYear() const;
    int getDayOfWeek() const;
    int getDayOfYear() const;
    int getNumHolidays() const; //휴일수 계산
    int getNumSummerTimeDays()const; //써머타임 날짜수
    void printCalendarOfMonth() const; // 달력출력하기
    
private:
    // information hiding : implement as you wish
    int year;
    int month;
    int day;
};
#endif /* myDate_h */
