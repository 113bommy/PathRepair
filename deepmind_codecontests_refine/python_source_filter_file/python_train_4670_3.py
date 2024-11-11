import sys
input = sys.stdin.readline
from collections import deque
N,M=map(int,input().split())
table=[[] for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    a,b=a-1,b-1
    table[a].append(b)
    table[b].append(a)
H=deque()
H.append(0)
S=set()
S.add(0)
flag=True
while flag:
    flag=False
    x=H[-1]
    for a in table[x]:
        if a not in S:
            flag=True
            S.add(a)
            H.append(a)
            break
flag=True
while flag:
    flag=False
    x=H[0]
    for a in table[x]:
        if a not in S:
            flag=True
            S.add(a)
            H.append(a)
            break
print(len(H))
print(' '.join(map(str,[h+1 for h in H])))

