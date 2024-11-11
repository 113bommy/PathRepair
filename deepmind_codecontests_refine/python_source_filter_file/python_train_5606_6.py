import sys
input = sys.stdin.readline
from collections import deque
R,C,N=map(int,input().split())
table=[]
def f(i,j):
    if i==0:
        return j
    if j==C:
        return R+i
    if i==R:
        return R+C+C-j
    if j==0:
        return R+R+C+C-i
for i in range(N):
    a,b,c,d=map(int,input().split())
    if (0<a<R and 0<b<C) or (0<c<R and 0<d<C):
        continue
    table.append((f(a,b),i))
    table.append((f(c, d), i))
table.sort()
H=deque()
for i in range(len(table)):
    if len(H)!=0 and H[-1]==table[i][1]:
        H.pop()
    else:
        H.append(table[i][1])
#print(H,table)
while len(H)!=0 and H[0]==H[-1]:
    H.popleft()
    H.pop()
if len(H)==0:
    print('YES')
else:
    print('NO')