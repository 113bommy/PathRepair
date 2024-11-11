N=int(input())
L=[input() for i in range(N)]
NL=sorted(L)
for i in range(N):
  if L[i-1]==NL[N-1]:
    print(NL[N-2])
  else:
    print(NL[N-1])