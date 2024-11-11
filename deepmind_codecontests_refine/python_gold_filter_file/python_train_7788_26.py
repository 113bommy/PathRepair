from collections import *
N = int(input())
V = list(map(int,input().split()))
C1 = Counter(V[0::2]).most_common()
C2 = Counter(V[1::2]).most_common()

if len(set(V))==1:
  ans = N//2
else:
  if C1[0][0]==C2[0][0]:
    ans = min(N-C1[0][1]-C2[1][1],N-C1[1][1]-C2[0][1])
  else:
    ans = N-C1[0][1]-C2[0][1]

print(ans)