import sys
import math
import collections
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

r = sys.stdin.readline

for _ in range(int(r())):
    N = int(r())
    L = []
    ans = -1

    for i in range(N):
        a = list(map(int, r().split())) + [i+1]
        L.append(a)

    L = L
    a = L[0]
    visit = [0]*(N)
    visit[0] = 1
    flag = 1
    for i in range(1, N):
        temp = 0
        for j in range(5):
            if a[j] > L[i][j]:
                temp += 1

        if temp >= 3:
            a = L[i]


    for i in range(1, N):
        temp = 0
        for j in range(5):
            if a[j] > L[i][j]:
                temp += 1

        if temp >= 3:
            flag = 0
            break

    if flag: print(a[5])
    else: print(-1)