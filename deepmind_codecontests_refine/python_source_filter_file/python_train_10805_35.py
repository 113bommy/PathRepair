import sys
def input():
    return sys.stdin.readline()[:-1]
import time

N = int(input())
A = [[int(x)-1 for x in input().split()] for i in range(N)]
P = [0] * N
cnt = 0
ALL = N*(N-1)//2
s = time.time()
for day in range(ALL):
    if time.time()-s > 1.9:
        print(N*(N-1)//2)
        break
    used = [0] * N
    flag = 0
    for i, p in enumerate(P):
        if p != N-1 and used[i] == 0:
            x = A[i][p]
            if x < N and used[x] == 0 and A[x][P[x]] == i:
                P[i] += 1
                P[x] += 1
                used[i] = 1
                used[x] = 1
                flag = 1
                cnt += 1
    if cnt == ALL:
        print(day+1)
        break
    if flag == 0:
        print(-1)
        break
