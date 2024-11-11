#!/usr/bin/python3

n = int(input())
s = str(input())

colors = set()
for i in s:
    colors.add(i)

if len(colors) == 1:
    print(s[0])
elif len(colors) == 3:
    print("RGB")
else:
    if s.count("R") == 0:
        if s.count("G") >= 2 and s.count("B") >= 2:
            print("RGB")
        elif s.count("G") >=2 and s.count("B") == 1:
            print("BR")
        elif s.count("G") == 1 and s.count("B") >= 2:
            print("GR")
        elif s.count("G") == 1 and s.count("B") == 1:
            print("R")
    elif s.count("G") == 0:
        if s.count("R") >= 2 and s.count("B") >= 2:
            print("RGB")
        elif s.count("R") >=2 and s.count("B") == 1:
            print("BG")
        elif s.count("R") == 1 and s.count("B") >= 2:
            print("GR")
        elif s.count("R") == 1 and s.count("B") == 1:
            print("G")
    elif s.count("B") == 0:
        if s.count("R") >= 2 and s.count("G") >= 2:
            print("RGB")
        elif s.count("R") >=2 and s.count("G") == 1:
            print("BG")
        elif s.count("R") == 1 and s.count("G") >= 2:
            print("BR")
        elif s.count("R") == 1 and s.count("G") == 1:
            print("B")
