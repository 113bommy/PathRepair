# D - Wizard in Maze
from collections import deque
import sys
INF = 10000000

H,W = map(int,input().split())
Ch,Cw = map(int,input().split())
Dh,Dw = map(int,input().split())
S = [input() for _ in range(H)]
C = [[INF]*W for _ in range(H)]
C[Ch-1][Cw-1] = 0
que = deque([(Ch,Cw)])
now = set()
tmp = 0

while True:
    while len(que)>0:
        i,j = que.popleft()
        now.add((i,j))
        for (h,w) in [(i-1,j),(i+1,j),(i,j-1),(i,j+1)]:
            if 1<=h<=H and i<=w<=W and S[h-1][w-1]=='.' and C[h-1][w-1]>tmp:
                C[h-1][w-1] = tmp
                que.append((h,w))
    for i,j in now:
        for h in range(i-2,i+3):
            for w in range(j-2,j+3):
                if 1<=h<=H and 1<=w<=W and S[h-1][w-1]=='.' and C[h-1][w-1]>tmp+1:
                    C[h-1][w-1] = tmp+1
                    que.append((h,w))
    now = set()
    tmp += 1
    if C[Dh-1][Dw-1]!=INF:
        print(C[Dh-1][Dw-1])
        break
    if len(que)==0:
        print(-1)
        break