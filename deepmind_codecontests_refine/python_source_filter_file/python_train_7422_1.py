import sys
input=sys.stdin.buffer.readline

for t in range(int(input())):
  N=int(input())
  S=input()
  C=[[0]*(N+1) for i in range(4)]
  for i in range(N):
    for j in range(2):
      if (S[i]=='L')^bool((i^j)&1):
        C[j*2][i+1]=C[j*2][i]+1
      else:
        C[j*2][i+1]=0
  for i in range(N-1,-1,-1):
    for j in range(2):
      if (S[i]=='R')^bool((i^j)&1):
        C[1+j*2][i]=C[1+j*2][i+1]+1
      else:
        C[1+j*2][i]=0
  print(*[C[2-(i&1)*2][i]+C[(i&1)*2+1][i]+1 for i in range(N+1)])
