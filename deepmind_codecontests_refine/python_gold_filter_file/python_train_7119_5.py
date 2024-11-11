import time
import datetime
import calendar

if __name__ == '__main__':


    date1 = input().split(":")
    date1 = [int(x) for x in date1]
    date2 = input().split(":")
    date2 = [int(x) for x in date2]
    #print(date2)
    if date1[0] > date2[0]:
        tmp = date1.copy()
        date1 = date2
        date2 = tmp

    sum = 0
    for i in range(date1[0]+1, date2[0]):
        if i % 4 == 0:
            if i % 100 != 0:
                sum += 366
                continue
            if i % 400 == 0:
                sum += 366
                continue
        sum += 365
        continue


    if date1[0] != date2[0]:
        sumdays = 0
        for i in range(date1[1], 13):
            sumdays += calendar.monthrange(date1[0], i)[1]
        sumdays -= date1[2]

        sumdays2 = 0
        for i in range(1, date2[1]):
            sumdays2 += calendar.monthrange(date2[0], i)[1]
        sumdays2 += date2[2]
        sum += sumdays + sumdays2
    else:
        sumdays = 0
        for i in range(min(date1[1], date2[1]), max(date1[1], date2[1])):
            sumdays += calendar.monthrange(date1[0], i)[1]

        if date1[1] < date2[1]:
            sumdays += -date1[2] + date2[2]
        else:
            sumdays += -date2[2] + date1[2]
        sum += sumdays

    if date2[0] == date1[0] and date2[1] == date1[1] and date2[2] == date1[2]:
        sum = 0
    print(abs(sum))






