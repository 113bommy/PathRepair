import math
from sys import stdin

users = []
traffic = 0

for line in stdin:
    #line = input()
    if line[0] == '+':
        users.append(line[1:])
    if line[0] == '-':
        users.remove(line[1:])
    if line == '\n':
        break
    loc = None
    for i in range(0, len(line)):
        if line[i] == ':':
            loc = i
            size = len(line) - loc - 1
            traffic += size * len(users)

print(traffic)
