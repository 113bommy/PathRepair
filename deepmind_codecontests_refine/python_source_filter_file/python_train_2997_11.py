from collections import deque
K = int(input())
Q = deque([i for i in range(1,10)])

for _ in range(K-1):
  q = Q.popleft()
  if q%10 != 0:
    Q.append(q*10+q%10-1)
  Q.append(q*10+q%10)
  if q%9 != 0:
    Q.append(q*10+q%10+1)
print(Q.popleft())