N, C = map(int, input().split())
dic = []
for i in range(N):
  s, t, c = map(int, input().split())
  dic += [(c-1,s,t)]

L = 2*100000+1
sm = [0]*L
for c in range(C):
  tt = [0]*(L)
  for i in range(N):
    if dic[i][0]==c:
      tt[dic[i][1]*2-1] += 1
      tt[dic[i][2]*2] -= 1
  for i in range(1,L):
    tt[i] += tt[i-1]
  for i in range(L):
    if tt[i]>0:
      sm[i] += 1
print(max(sm))