N,M=map(int,input().split(' '))
S = [list(map(int,input().split(' '))) for i in range(N)]
C = [list(map(int,input().split(' '))) for i in range(M)]
for i in range(N):
  l = [abs(S[i][0]-C[i][0])+abs(S[i][1]-C[i][1]) for i in range(M)]
  print(l.index(min(l))+1)