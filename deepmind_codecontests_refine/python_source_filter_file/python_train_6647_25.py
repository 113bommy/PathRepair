N, *A = map(int, open(0).read().split())
M = (N+1)*N//2
S = sum(A)
if S%M!=0:
  print('NO')
  exit()
cnt = S//M
for i in range(N):
  df = A[(i+1)%N]-A[i]
  if (cnt-df)%N!=0 or cnt<df:
    print('NO')
    break
else:
  print('Yes')