# -*- coding: utf-8 -*-
p = int(input())
arr = list(map(int,input().split()))

t = 0
for i in range(7):
    t += arr[i]

i = 0
while p>0:
    p = p-arr[i]
    if i == 6:
        i = 0
    else:
        i += 1

if i == 0:
    print(i+1)
else:
    print(i)    