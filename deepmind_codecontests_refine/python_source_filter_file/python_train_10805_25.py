from collections import deque
import time

zuru = time.time()
N = int(input())
A = [deque(map(int,input().split())) for _ in range(N)]
match = 0
que = [0 for _ in range(N+1)]

for day in range(1, (N-1) * N // 2 + 1):
  tsumi = True
  for i in range(1,N+1):
    if que[i]==0 and A[i-1]!=deque():
      que[i] = A[i-1].popleft()
  for i in range(1,N+1):
    if que[i]!=0 and que[que[i]]==i:    
      que[que[i]] = 0
      que[i] = 0
      match += 1
      tsumi = False
  if tsumi:
    ans = -1
    break
  if match==(N-1) * N / 2:
    ans = day
    break
  if time.time()-zuru > 1.5:
    ans = N*(N-1)/2
    break
print(ans)
