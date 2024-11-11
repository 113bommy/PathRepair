#coding: utf-8


CASH_summary = int (input())

CASH_100 = CASH_summary // 100
CASH_20 = (CASH_summary % 100) // 20
CASH_10 = (CASH_summary % 100 % 20) // 10
CASH_5 = (CASH_summary % 100 % 20 % 10) // 5
CASH_1 = (CASH_summary % 100 % 20 % 10 % 5) 

print(CASH_100, CASH_20, CASH_10, CASH_5, CASH_1)