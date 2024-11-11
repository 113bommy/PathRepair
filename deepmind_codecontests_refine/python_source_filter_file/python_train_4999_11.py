import collections,sys
d=collections.deque()
input()
for e in sys.stdin.readlines():
 if'i'==e[0]:d.appendleft(e.split()[1])
 else:
  if' '==e[6]:
   m=e.split()[1]
   if m in d:d.remove(m)
  elif len(e)%2:d.popleft()
  else:d.pop()
print(*d)
