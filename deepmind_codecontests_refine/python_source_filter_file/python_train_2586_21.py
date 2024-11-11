N = int(input())
A = []
for i in range(N):
  A.append(int(input()))
now = 1
for i in range(15000):
  now = A[now-1]
  if now == 2:
    print(i+1)
    exit()
print(-1)
  
  
