#!/usr/bin/python3

import sys

r, c = [int(x) for x in sys.stdin.readline().split()]
m = []
for i in range(r):
    m.append(sys.stdin.readline().replace(".", "D").strip())

for i in range(r):
    for j in range(c):
        if m[i][j] == "W":
            if i >= 0:
                if m[i-1][j] == "S": print("No"); sys.exit()
            if j >= 0:
                if m[i][j-1] == "S": print("No"); sys.exit()
            if i < r:
                if m[i+1][j] == "S": print("No"); sys.exit()
            if j < c: 
                if m[i][j+1] == "S": print("No"); sys.exit()

print("Yes")
print("\n".join(m))


sys.exit()
