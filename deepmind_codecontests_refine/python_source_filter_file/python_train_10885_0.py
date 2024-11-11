#!/usr/bin/env python3
from sys import stdin,stdout

def readint():
    return map(int, stdin.readline().split())
#lines = stdin.readlines()


alpha = "abcdefghijklmnopqrstuvwxyz"
s = input()
p = []
pp = []
skip = 1
for c in s:
    if skip == 1:
        if c in alpha:
            continue
        else:
            skip = 0
            pp = []
            pp.append(c)
    else:
        if c in alpha:
            p.append(pp)
            skip = 1
        else:
            pp.append(c)

p.append(pp)

sum = 0
for pp in p:
    if len(pp)>=3:
        if pp[-3] != ".":
            pp.append("0")
            pp.append("0")
    else:
        pp.append("0")
        pp.append("0")

    pp2 = []
    for c in pp:
        if c == ".":
            pass
        else:
            pp2.append(c)

    sum += int("".join(pp2))

sumstr = str(sum)


if len(sumstr) == 1:
    sumstr = "00" + sumstr
elif len(sumstr) == 2:
    sumstr = "0" + sumstr
sumstr = list(sumstr)
sumstr.reverse()
ans = []
for i in range(len(sumstr)):
    if (i+1)%3 == 0:
        ans.append(".")
    ans.append(sumstr[i])
ans.reverse()
if ans[-1] == '0' and ans[-2] == 0:
    ans = ans[:-3]
print("".join(ans))
