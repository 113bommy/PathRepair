from collections import deque
S = input()
q = deque(S)
print(q)
c = 0
while len(q):
  l = q[0]
  r = q[len(q)-1]
  if l == r:
    if len(q) != 1:
      q.pop()
    q.popleft()
  elif l == 'x':
    q.append('x')
    c += 1
  elif r == 'x':
    q.appendleft('x')
    c += 1
  else:
    print(-1)
    exit()
print(c)
