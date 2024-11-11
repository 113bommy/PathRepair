import sys
input=sys.stdin.readline
N=int(input())
F=[int(input().replace(' ',''),2) for _ in range(N)]
P=[list(map(int,input().split())) for _ in range(N)]

ans=0
for i in range(1,2**10):
  cnt=0
  for j in range(N):
    cnt+=P[j][bin(F[j] & i).count('1')]
  ans=max(ans,cnt)
print(ans)