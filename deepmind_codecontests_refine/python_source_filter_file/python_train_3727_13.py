import sys
input = sys.stdin.readline
from collections import *

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
q = deque([])

for i in range(N):
    if B[i]>A[i] and B[i]>B[(i-1)%N]+B[(i+1)%N]:
        q.append(i)

ans = 0

while q:
    i = q.popleft()
    sub = B[(i-1)%N]+B[(i+1)%N]
    
    if B[i]%sub>=A[i]:
        ans += (B[i]-B[i]%sub)//sub
        B[i] %= sub
    else:
        if (B[i]-A[i])%sub==0:
            ans += B[i]-A[i]//sub
            B[i] = A[i]
        else:
            print(-1)
            exit()
            
    for j in [(i-1)%N, (i+1)%N]:
        if B[j]>A[j] and B[j]>B[(j-1)%N]+B[(j+1)%N]:
            q.append(j)

if A==B:
    print(ans)
else:
    print(-1)