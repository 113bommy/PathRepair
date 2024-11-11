import math
n = int(input())
a = [0,0,0,0,0,0]
for i in range(n):
    s = str(input())
    if s[0] == "p":
        a[0] = 1
    elif s[0] == "g":
        a[1] = 1
    elif s[0] == "b":
        a[2] = 1
    elif s[0] == "o":
        a[3] = 1
    elif s[0] == "r":
        a[4] = 1
    elif s[0] == "y":
        a[5] = 1
print(5 - a[0]-a[1]-a[2]-a[3]-a[4])
if a[0] == 0:
    print("Power")
if a[1] == 0:
    print("Time")
if a[2] == 0:
    print("Space")
if a[3] == 0:
    print("Soul")
if a[4] == 0:
    print("Reality")
if a[5] == 0:
    print("Mind")
