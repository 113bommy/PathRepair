import sys
input=sys.stdin.buffer.readline

for t in range(int(input())):
  N,A,B=map(int,input().split())
  S=list(input())
  while len(S)>N:
    del S[-1]
  for i in range(N):
    S[i]-=48
  ANS=A*N
  if B>=0:
    ANS+=B*N
  else:
    C=1
    for i in range(1,N):
      if S[i]!=S[i-1]:
        C+=1
    ANS+=B*((C+1)>>1)
  print(ANS)
