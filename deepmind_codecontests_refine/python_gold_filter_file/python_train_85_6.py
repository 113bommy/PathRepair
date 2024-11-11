N,M=map(int,input().split(' '))
S = [list(map(int,input().split(' '))) for i in range(N)]
C = [list(map(int,input().split(' '))) for i in range(M)]
for i in range(N):
  l = [abs(S[i][0]-C[j][0])+abs(S[i][1]-C[j][1]) for j in range(M)]
  print(l.index(min(l))+1)
