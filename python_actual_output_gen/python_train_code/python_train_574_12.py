#! /usr/bin/python3

a = input().strip().split()
b = input().strip().split()
c = 0
for i in range (0, 3):
    if a[i] == b[i]:
        c = c + 1

if c >= 2:
    print("YES")
else:
    print("NO")