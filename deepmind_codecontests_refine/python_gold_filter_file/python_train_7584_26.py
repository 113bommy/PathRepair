from collections import deque

m = [deque(input()) for _ in range(3)]
t = 0

while True:
  if len(m[t]) == 0:
    print('ABC'[t])
    break
  
  t = 'abc'.find(m[t].popleft())
