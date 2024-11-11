import sys
#import math
from collections import deque

#input = sys.stdin.readline
        
li0 = [int(x) for x in input().split(' ')]
n = li0[0]
k = li0[1]
li = list(input())
li2 = set([x for x in input().split(' ')])

d = deque()
running = 0
for i in li:
    if i not in li2:
        if running > 0:
            d.append(running)
            running = 0
    else:
        running += 1
if running > 0:
    d.append(running)

tot = 0
for j in d:
    tot += j * (j + 1) // 2
print(tot)