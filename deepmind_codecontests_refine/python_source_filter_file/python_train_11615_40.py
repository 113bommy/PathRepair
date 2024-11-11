#! /usr/bin/env python3

fmt = int(input())
hh, mm = map(int, input().split(':'))

while mm > 60:
    mm -= 10

if fmt == 12 and hh > 12:
    while hh > 12:
        hh -= 10
elif fmt == 12 and hh == 0:
    hh = 1
elif fmt == 24 and hh > 23:
    while hh > 23:
        hh -= 10

print('%02d:%02d' % (hh, mm))
