#!/usr/bin/python3
k, w, n = map(int, input().split())

totalcost = 0

for x in range(1, n + 1):
    totalcost += x * k

if w > totalcost:
    print("NO")
else:
    print(totalcost - w)