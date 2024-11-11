import sys
from collections import deque
input = sys.stdin.readline

n,k=map(int,input().split())

A=[2**i for i in range(29)]
A.reverse()

if n<k:
    print("NO")
    sys.exit()

LIST=[]
for i in range(29):
    if A[i]<=n:
        LIST.append(A[i])
        n-=A[i]

#print(LIST)
SUM=len(LIST)
if SUM>k:
    print("NO")
    sys.exit()
Q = deque(LIST)
#print(Q)
i=0
while SUM!=k:
    if Q[0]==1:
        print("NO")
        break
    elif Q[0]==2:
        Q.popleft()
        Q.append(1)
        Q.append(1)
        SUM+=1
    else:
        x=Q[0]//2
        Q.popleft()
        Q.appendleft(x)
        Q.appendleft(x)
        SUM+=1

else:
    print("YES")
    for l in Q:
        print(l,end=" ")
        
    
