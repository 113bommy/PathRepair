N = int(input())
T = list(map(int,input().split()))
A = list(map(int,input().split()))

H = [[1,10 ** 9] for _ in range(N)]

for i in range(N):
  if i == 0:
    hmin = T[i]
    hmax = T[i]
  elif T[i-1] < T[i]:
    hmin = T[i]
    hmax = T[i]
  else:
    hmin = 1
  H[i][0] = hmin
  H[i][1] = hmax
  #print(H)
for i in range(N-1,-1,-1):
  if i == N-1:
    hmin = A[i]
    hmax = A[i]
  elif A[i] > A[i+1]:
    hmax = A[i]
    hmin = A[i]
  else:
    hmin = 1
  H[i][0] = max(hmin,H[i][0])
  H[i][1] = min(hmax,H[i][1])
  #print(H)

#print(H)
ans = 1
for i in range(N):
  if H[i][1] < H[i][0]:
    print(0)
    exit()
  ans *= (H[i][1] - H[i][0] + 1)
  ans %= 10 ** 9 + 7
print(ans)