//
//  myDate.cpp
//  DateClass1
//
//  Created by 김다은 on 2017. 5. 31..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <stdio.h>
#include "myDate.h"

myDate::myDate(int y,int m,int d){
    year = y;
    month = m;
    day = d;
}

int myDate::getDayOfMonth() const{
    return day;
}

int myDate::getMonth() const{
    return month;
}

int myDate::getYear() const{
    return year;
}

void myDate::setDayOfMonth(int day){
    this->day = day;
}

void myDate::setMonth(int month){
    this->month = month;
}

void myDate::setYear(int year){
    this->year = year;
}

void myDate::setDate(int year, int month, int day){
    this->year = year;
    this->month = month;
    this->day = day;
}

bool myDate::isLeapYear() const{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int myDate::getDayOfWeek() const{
    int sum = 5;
    
    for (int i=1582; i < year; i++){
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
            sum += 366;
        else
            sum += 365;
    }
    for (int i = 1; i < month; i++){
        switch (i){
            case 2:
                if (isLeapYear())
                    sum += 29;
                else
                    sum += 28;
                break;
            case 4: case 6: case 9: case 11:
                sum += 30;
                break;
            default:
                sum += 31;
                break;
        }
    }
    sum += day-1;
    
    return sum % 7;
}

int myDate::getDayOfYear() const{
    int sum = 1;
    
    for (int i = 1; i < month; i++){
        for (int j = 1; j < day; j++){
            sum++;
        }
    }
    return sum;
}
