import sys
from collections import deque, defaultdict
import copy
import bisect
input=sys.stdin.readline
sys.setrecursionlimit(10 ** 9)


N, Q = list(map(int, input().split()))
STX=[]
D=[]
for i in range(N):
    S, T, X = list(map(int, input().split()))
    STX.append((X, S, T))
STX = sorted(STX, key=lambda x: x[0])

for i in range(Q):
    D.append(int(input()))

skip = [-1]*Q

dist = [-1]*Q

for X, S, T in STX:
    s = S - X
    t = T - X - 1
    a = bisect.bisect_left(D, s)
    b = bisect.bisect_right(D, t)
    #print(D)
    j = a
    while j < b:
        if skip[j] == -1:
            skip[j] = b
            dist[j] = X
            j+=1
        else:
            j=skip[j]


for i in range(Q):
    print(dist[i])