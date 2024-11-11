import sys

s = sys.stdin.readline().strip()
l = len(s)
v = 0
h = 0

for i in range (0, l):
    if s[i] == "0":
        v = v + 1
        if v % 2 == 1:
            print("3 1")
        else:
            print("1 1")
    else:
        h = h + 1
        if v % 2 == 1:
            print("1 3")
        else:
            print("1 1")