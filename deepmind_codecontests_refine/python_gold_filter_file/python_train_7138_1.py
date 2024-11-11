#!/usr/bin/env python3

n = int(input())
cury = 0
for i in range(n):
    k, d = input().split()
    k = int(k)
    if cury == 0 and d != "South":
        print("NO")
        exit()
    if cury == 20000 and d != "North":
        print("NO")
        exit()
    if d == "East" or d == "West":
        continue
    if d == "North":
        cury -= k
        if cury < 0:
            print("NO")
            exit()
    if d == "South":
        cury += k
        if cury > 20000:
            print("NO")
            exit()

if cury != 0:
    print("NO")
else:
    print("YES")



