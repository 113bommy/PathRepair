import sys, copy, math, heapq, bisect
from itertools import accumulate
from collections import deque, defaultdict, Counter
sys.setrecursionlimit(500000)


N,A,B,C = map(int,input().split())
ABC = [A,B,C]
S = []
SS = ('A','B','C')
d = [0,0,0]
flag = True
for i in range(N):
    s = input()
    if s=="AB":
        S.append(2)
        d[0] += 1
        d[1] += 1
    elif s=="BC":
        S.append(0)
        d[1] += 1
        d[2] += 1
    else:
        S.append(1)
        d[2] += 1
        d[0] += 1
ans = []
for i in range(N):
    x,y = (S[i]+1)%3,(S[i]+2)%3
    if ABC[x]<ABC[y]:
        ans.append(SS[x])
        ABC[y] -= 1
        ABC[x] += 1
    elif ABC[x]>ABC[y]:
        ans.append(SS[y])
        ABC[y] += 1
        ABC[x] -= 1
    else:
        if i < N-1:
            if S[i+1]==y:
                ans.append(SS[x])
                ABC[y] -= 1
                ABC[x] += 1
            else:
                ans.append(SS[y])
                ABC[y] += 1
                ABC[x] -= 1
        else:
            ans.append(SS[y])
            ABC[y] += 1
            ABC[x] -= 1




    if ABC[0]<0 or ABC[1]<0 or ABC[2]<0:
        flag = False
        break


if flag:
    print('Yes')
    print(*ans,sep='\n')
else:
    print('No')






