from collections import deque
s = deque(input())
q = int(input())

flag = 1
for i in range(q):
  st = input().split()
  if int(st[0]) == 1:
    flag *= -1
  else:
    tmp = int(st[1])*flag
    if tmp == 1 or tmp == -2:
      s.appendleft(st[2])
    else:
      s.append(st[2])

if flag == -1:
  s.reverse()
print(''.join(s))